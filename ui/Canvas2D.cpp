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


void Canvas2D::mouseDown(int x, int y) {

    // You're going to need to leave the alpha value on the canvas itself at 255, but you will
    // need to use the actual alpha value to compute the new color of the pixel

    std::cout << "Canvas2d::mouseDown() called" << std::endl;

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




