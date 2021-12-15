/**
 * @file Canvas2D.cpp
 *
 * CS123 2-dimensional canvas. Contains support code necessary for Brush, Filter, Intersect, and
 * Ray.
 *
 * YOU WILL NEED TO FILL THIS IN!
 *
 */

// For your convenience, a few headers are included for you.
#include <assert.h>
#include <iostream>
#include <math.h>
#include <memory>
#include <unistd.h>
#include "Canvas2D.h"
#include "Settings.h"
#include "RayScene.h"

#include <QCoreApplication>
#include <QPainter>

#include "voronoi/Voronoi_Main.h"
#include "voronoi/PerlinNoise.h"

Canvas2D::Canvas2D() :
    m_rayScene(nullptr)
{
}

Canvas2D::~Canvas2D()
{
}

// This is called when the canvas size is changed. You can change the canvas size by calling
// resize(...). You probably won't need to fill this in, but you can if you want to.
void Canvas2D::notifySizeChanged(int w, int h) {
}

void Canvas2D::paintEvent(QPaintEvent *e) {
    // You probably won't need to fill this in, but you can if you want to override any painting
    // events for the 2D canvas. For now, we simply call the superclass.
    SupportCanvas2D::paintEvent(e);

}

void Canvas2D::settingsChanged() {
    // TODO: Process changes to the application settings.
    std::cout << "Canvas2d::settingsChanged() called. Settings have changed" << std::endl;
    if(m_rayScene){
        m_rayScene->updateSettings(settings);
    }
}

// ********************************************************************************************
// ** BRUSH
// ********************************************************************************************

void plotLineLow(int x0, int y0, int x1, int y1, Canvas2D *canvas, RGBA color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = 2*dy - dx;
    int yY = y0;

    for (int xX = x0; xX < x1; xX++) {
        if (!(xX > canvas->width() || xX < 0 || yY > canvas->height() || yY < 0)) {
            canvas->data()[xX*canvas->width()+yY].r = color.r;
            canvas->data()[xX*canvas->width()+yY].g = color.g;
            canvas->data()[xX*canvas->width()+yY].b = color.b;
        }
        if (D > 0) {
            yY += yi;
            D += 2*(dy-dx);
        } else {
            D += 2 * dy;
        }
    }
}

void plotLineHigh(int x0, int y0, int x1, int y1, Canvas2D *canvas, RGBA color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = 2*dx - dy;
    int xX = x0;

    for (int yY = y0; yY < y1; yY++) {
        if (!(xX > canvas->width() || xX < 0 || yY > canvas->height() || yY < 0)) {
            canvas->data()[xX*canvas->width()+yY].r = color.r;
            canvas->data()[xX*canvas->width()+yY].g = color.g;
            canvas->data()[xX*canvas->width()+yY].b = color.b;
        }
        if (D > 0) {
            xX += xi;
            D += 2*(dx-dy);
        } else {
            D += 2 * dx;
        }
    }
}

void plotLine(int x0, int y0, int x1, int y1, Canvas2D *canvas, RGBA color) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            plotLineLow(x1, y1, x0, y0, canvas, color);
        } else {
            plotLineLow(x0, y0, x1, y1, canvas, color);
        }
    } else {
        if (y0 > y1) {
            plotLineHigh(x1, y1, x0, y0, canvas, color);
        } else {
            plotLineHigh(x0, y0, x1, y1, canvas, color);
        }
    }
}

void Canvas2D::setEdges(std::vector<std::vector<std::vector<float>>> e){
    m_edges = e;
}

void Canvas2D::mouseDown(int x, int y) {

    // You're going to need to leave the alpha value on the canvas itself at 255, but you will
    // need to use the actual alpha value to compute the new color of the pixel


//    std::cout << "Canvas2d::mouseDown() called" << x << y << std::endl;
//    //std::vector<float> edges = Voronoi_Main::main();

//    for (int i = 0; i < m_edges.size(); i += 4) {
//      //  std::cout << (int) m_edges[i] << ", " << (int) m_edges[i+1] << ", " << (int) m_edges[i+2] << ", " << (int) m_edges[i+3] << std::endl;
//        plotLine((int) m_edges[i], (int) m_edges[i+1], (int) m_edges[i+2], (int) m_edges[i+3], this);

    std::cout << "Canvas2d::mouseDown() called" << std::endl;
  //  std::vector<std::vector<std::vector<float>>> edges = Voronoi_Main::main();
    RGBA color = RGBA{255, 255, 255};
    std::unique_ptr<PerlinNoise> perlin = std::make_unique<PerlinNoise>();
    for (int set = 0; set < m_edges.size(); set++) {
        if (set == m_edges.size() - 1) color = RGBA{255, 0, 0};
        for (int i = 0; i < m_edges[set].size(); i+=2) {
            plotLine((int) m_edges[set][i][0], (int) m_edges[set][i][1], (int) m_edges[set][i+1][0], (int) m_edges[set][i+1][1], this, color);
            std::cout << perlin->perlin(m_edges[set][i][0], m_edges[set][i][1], 0.f) << std::endl;
        }
    }

}

void Canvas2D::mouseDragged(int x, int y) {
    std::cout << "Canvas2d::mouseDragged() called" << std::endl;

}

void Canvas2D::mouseUp(int x, int y) {
    std::cout << "Canvas2d::mouseUp() called" << std::endl;
}



// ********************************************************************************************
// ** FILTER
// ********************************************************************************************

void Canvas2D::filterImage() {
//    switch(settings.filterType) {
//        case FILTER_BLUR:
//            BlurFilter::apply(this, (2*settings.blurRadius)+1);
//            break;
//        case FILTER_EDGE_DETECT:
//            SobelFilter::apply(this, settings.edgeDetectSensitivity);
//            break;
//        case FILTER_SCALE:
//            ResizeFilter::apply(this, settings.scaleX, settings.scaleY);
//            break;
//        default:
//            break;
//    }

//    // Leave this code here! This code ensures that the Canvas2D will be completely wiped before
//    // drawing the new image.
//    repaint(rect());
//    QCoreApplication::processEvents();
}

// ********************************************************************************************
// ** RAY
// ********************************************************************************************

void Canvas2D::setScene(RayScene *scene) {
    m_rayScene.reset(scene);
}

void Canvas2D::renderImage(CS123SceneCameraData *camera, int width, int height) {
  if (m_rayScene) {
        // @TODO: raytrace the scene based on settings
        //        YOU MUST FILL THIS IN FOR INTERSECT/RAY
        // If you want the interface to stay responsive, make sure to call
        // QCoreApplication::processEvents() periodically during the rendering.
        camera->aspectRatio = ((float) width) / height;
        resize(width, height);
        update();
        m_rayScene->updateSettings(settings);
        m_rayScene->render(this, width, height, camera);

    }
}

void Canvas2D::cancelRender() {
    // TODO: cancel the raytracer (optional)
}




