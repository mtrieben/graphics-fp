#include "RayScene.h"
#include "Settings.h"
#include "CS123SceneData.h"
#include "Ray.h"
#include "shapes/Shape.h"
#include "shapes/Cylinder.h"
#include "shapes/Cube.h"
#include "shapes/Sphere.h"
#include "shapes/Cone.h"
#include "Canvas2D.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <QString>
#include <QImage>
#include <QCoreApplication>


RayScene::RayScene(Scene &scene) :
    Scene(scene)
{
}

// Renders the scene !!
void RayScene::render(Canvas2D* canvas, int width, int height, CS123SceneCameraData *camera){

    setUpCamera(camera);
    m_canvas = canvas;
    RGBA *pix = canvas->data();
    float theta_h = camera->heightAngle * M_PI / 180.f;
    float theta_w = atan(((float)width) / ((float)height) * tan((theta_h)));
    float k = 5.f;
    for(int i = 0; i < m_primatives.size(); i++){
        if(m_primatives[i]->primative.material.textureMap.isUsed){
            QString filepath = QString::fromStdString(m_primatives[i]->primative.material.textureMap.filename);
            std::unique_ptr<QImage> image = std::make_unique<QImage>(filepath);
            m_primatives[i]->image = image.operator*();
        }
    }

    // Loops through all pixels
    for(int j = 0; j < height; j++){
        for(int i = 0; i < width; i++){
            float x = ((i+0.5f) / width) - 0.5f;

            float y = 0.5f - ((j+0.5f) / height);

            float U = 2*k*tan(theta_w / 2.0f);

            float V = 2*k*tan(theta_h / 2.0f);

            glm::vec4 uvk = glm::vec4(glm::vec3(U*x, V*y, -1.f*k),1.f);
            // Shoots ray through the center of the pixel
            std::unique_ptr<Ray> ray = std::make_unique<Ray>(Ray(glm::vec4(0.f,0.f,0.f,1.f), uvk));

            // Applies inverse camera matrix to get ray into world space
            ray.operator*().transformRay(glm::inverse(m_cameraMatrix));

            // Gets color value of closest object
            /*
             * THIS IS WHERE YOU CAN CHANGE DEPTH OF REFLECTION !
             * Right now, its set at 4, but feel free to modify :)
             */
            glm::vec4 color = traceRay(ray.operator*(), INFINITY, false, 4);
            if(color[0] != -1){
                pix[j*width + i].r = color[0]*255;
                pix[j*width + i].g = color[1]*255;
                pix[j*width + i].b = color[2]*255;
            }
        }
        QCoreApplication::processEvents();
        canvas->update();
    }
    canvas->update();
}

// Given a ray, finds its closest primative (if any) and sets color
glm::vec4 RayScene::traceRay(Ray ray, float dist, bool shadow, int depth){
    ShapeInfo lowest_t = ShapeInfo{glm::vec3(0),glm::vec3(0), glm::vec3(ray.m_d), dist};
    TransformedPrimative* lowest_prim;

    // For each primative, find lowest t-val, and among these, the lowest is the intersection
    for(int i=0; i < m_primatives.size(); i++){
        CS123ScenePrimitive prim = m_primatives[i]->primative;

        // transforms ray into object space for this primative
        ray.transformRay(glm::inverse(m_primatives[i]->transformation));

        // Gets t-val based on shape type
        ShapeInfo shapeIntersection;
        switch(prim.type){
            case PrimitiveType::PRIMITIVE_CONE:
                shapeIntersection = Cone::implicitIntersection(ray);
                break;
            case PrimitiveType::PRIMITIVE_CUBE:
                shapeIntersection = Cube::implicitIntersection(ray);
                break;
            case PrimitiveType::PRIMITIVE_CYLINDER:
                shapeIntersection = Cylinder::implicitIntersection(ray);
                break;
            case PrimitiveType::PRIMITIVE_SPHERE:
                shapeIntersection = Sphere::implicitIntersection(ray);
                break;
            default:
                shapeIntersection = Cone::implicitIntersection(ray);
                break;
        }
        // gets lowest t-val
        if (shapeIntersection.t >= 0.0 && shapeIntersection.t < lowest_t.t){
            lowest_t = shapeIntersection;
            lowest_prim = m_primatives[i].get();
        }
        // Transform ray back so it's ready for next primative
        ray.transformRay(m_primatives[i]->transformation);

    }

    // Find lighting for the closest primative
    if(lowest_t.t >= 0.0 && lowest_t.t != dist){
        lowest_t.normal = glm::inverse(glm::transpose(glm::mat3x3(lowest_prim->transformation)))*lowest_t.normal;
        glm::vec3 eye_vec = glm::vec3(lowest_prim->transformation*glm::vec4(lowest_t.eye, 0));
        if(!shadow){
            return getLighting(lowest_prim->image, glm::inverse(lowest_prim->transformation), eye_vec, glm::normalize(lowest_t.normal), glm::vec3(lowest_prim->transformation*glm::vec4(lowest_t.obj_coord,1.f)), lowest_prim->primative, depth);
        }
        else{
            return glm::vec4(1,-1,-1,-1);
        }
    }
    else{
        return glm::vec4(-1,-1,-1,-1);
    }
}

// Makes camera matrix based on the camera data passed in
void RayScene::setUpCamera(CS123SceneCameraData *camera){

    glm::vec4 w = glm::normalize(-camera->look);
    glm::vec4 v = glm::normalize(camera->up - (glm::dot(camera->up, w)* w));
    glm::vec3 u = glm::cross(glm::vec3(v), glm::vec3(w));

    glm::mat4x4 m_translate = glm::mat4x4(1.f, 0.f, 0.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            -camera->pos[0], -camera->pos[1], -camera->pos[2], 1.f);
    glm::mat4x4 m_rotate = glm::mat4x4(u[0], v[0], w[0], 0.f,
            u[1], v[1], w[1], 0.f,
            u[2], v[2], w[2], 0.f,
            0.f, 0.f, 0.f, 1.f);

    m_cameraMatrix = m_rotate * m_translate;
}

glm::vec4 RayScene::getLighting(QImage image, glm::mat4x4 trans, glm::vec3 eye, glm::vec3 normals, glm::vec3 xyz, CS123ScenePrimitive prim, int depth){
    // Calculates RGB val from lighting equation
    float r = this->m_globalData->ka * prim.material.cAmbient[0];
    float g = this->m_globalData->ka * prim.material.cAmbient[1];
    float b = this->m_globalData->ka * prim.material.cAmbient[2];

    for(int i = 0; i < this->m_lights.size(); i++){
        glm::vec3 v; // reverse vector from xyz point to light
        glm::vec3 r_vec;
        glm::vec4 li;
        float attenuation = 1.f;
        float rvn = 0.f;
        float distance = 0.f; // distance to compare to for shadow ray tracing
        if(m_lights[i]->type == LightType::LIGHT_POINT){
            if(m_pointLights == false){
                continue;
            }
            v = glm::vec3(m_lights[i]->pos) - xyz;
            li = glm::vec4(glm::normalize(glm::vec3(m_lights[i]->pos)-xyz),0.f);
            distance = glm::distance(glm::vec3(m_lights[i]->pos), xyz);
            // if point light calculate attenuation
            attenuation = glm::min(1.f / (m_lights[i]->function[0] +
                    (distance*m_lights[i]->function[1]) + (distance*distance*m_lights[i]->function[2])), 1.f);
        }
        else if(m_lights[i]->type == LightType::LIGHT_DIRECTIONAL){

            if(m_directionalLights == false){
                continue;
            }
            v = -glm::vec3(m_lights[i]->dir);
            li = glm::vec4(glm::normalize(-m_lights[i]->dir));
            distance = INFINITY;

        }
        // specular component of light
        r_vec = glm::normalize((2.f*normals*(glm::dot(normals, v))) - v);
        rvn = pow(glm::clamp(glm::dot(r_vec,-glm::normalize(eye)), 0.f, 1.f), prim.material.shininess);

        // add diffuse and specular component
        if(m_lights[i]->type == LightType::LIGHT_POINT || m_lights[i]->type == LightType::LIGHT_DIRECTIONAL){

            // If texture mapping for this primitive, get texture val
            glm::vec3 texture = glm::vec3(1.f);
            float blend = 0.f;
            if(m_textureMapping && prim.material.textureMap.isUsed){
                texture = getTexture(image, prim, glm::vec3(trans*glm::vec4(xyz, 1.f)));
                blend = prim.material.blend;
            }

            // If calculating shadows, see if reverse direction ray intersects another object before the light
            // If so, skip this light
            if(m_shadows){
                glm::vec3 dir = glm::normalize(v);
                glm::vec3 start = glm::vec3(xyz[0]+(dir[0]*0.001f),xyz[1]+(dir[1]*0.001f),xyz[2]+(dir[2]*0.001f));
                std::unique_ptr<Ray> ray = std::make_unique<Ray>(glm::vec4(start, 1.f), glm::vec4(v,0.f), 1);
                glm::vec4 res = traceRay(ray.operator*(), distance, true, 0);
                if(res[0] != -1){
                    continue;
                }
            }

            // Calculates rgb contribution for diffuse (with texture) and specular light
            float r_temp = attenuation*m_lights[i]->color[0] *(((1.f - blend)*this->m_globalData->kd*prim.material.cDiffuse[0] +
                                                               (blend * texture[0]))*
                    glm::dot(glm::normalize(glm::vec4(normals, 0.f)),
                             li)  +
                    this->m_globalData->ks*prim.material.cSpecular[0]*rvn);
            float g_temp = attenuation*m_lights[i]->color[1] * (((1.f - blend)*this->m_globalData->kd*prim.material.cDiffuse[1] +
                                                                (blend * texture[1]))*
                    glm::dot(glm::normalize(glm::vec4(normals, 0.f)),
                             li) +
                    this->m_globalData->ks*prim.material.cSpecular[1]*rvn);
            float b_temp = attenuation*m_lights[i]->color[2] * (((1.f - blend)*this->m_globalData->kd*prim.material.cDiffuse[2] +
                                                                (blend * texture[2]))*
                    glm::dot(glm::normalize(glm::vec4(normals, 0.f)),
                             li) +
                    this->m_globalData->ks*prim.material.cSpecular[2]*rvn);
            // Only adds positive vals
            r += glm::clamp(r_temp, 0.f, 1.f);
            g += glm::clamp(g_temp, 0.f, 1.f);
            b += glm::clamp(b_temp, 0.f, 1.f);
        }
    }

    // If calculating reflection and not at base case of recursive call
    if(m_reflection && depth > 0){
        glm::vec3 v1 = glm::reflect(eye, normals); // reflect vector about normal
        glm::vec3 dir = glm::normalize(v1);
        glm::vec3 start = glm::vec3(xyz[0]+(dir[0]*0.001f),xyz[1]+(dir[1]*0.001f),xyz[2]+(dir[2]*0.001f));
        // If tracing new vector intersects object, add fraction of that objects lighting eq to this objects result
        std::unique_ptr<Ray> ray = std::make_unique<Ray>(glm::vec4(start, 1.f), glm::vec4(v1,0.f), 1);
        glm::vec4 res = this->m_globalData->ks*prim.material.cReflective*traceRay(ray.operator*(), INFINITY, false, depth-1);
        r += glm::clamp(res[0],0.f,1.f);
        g += glm::clamp(res[1],0.f,1.f);
        b += glm::clamp(res[2],0.f,1.f);
    }

    return glm::vec4(glm::clamp(r,0.f,1.f),glm::clamp(g,0.f,1.f),glm::clamp(b,0.f,1.f),1.f);
}

// Gets color contributions for a point from a texture map
glm::vec3 RayScene::getTexture(QImage image, CS123ScenePrimitive prim, glm::vec3 xyz){
    // Gets mapping to uv point on unit square based on PrimitiveType
    glm::vec2 uv;
    switch(prim.type){
        case PrimitiveType::PRIMITIVE_CONE:
            uv = Cone::getTextureColor(xyz);
            break;
        case PrimitiveType::PRIMITIVE_CUBE:
            uv = Cube::getTextureColor(xyz);
            break;
        case PrimitiveType::PRIMITIVE_CYLINDER:
            uv = Cylinder::getTextureColor(xyz);
            break;
        case PrimitiveType::PRIMITIVE_SPHERE:
            uv = Sphere::getTextureColor(xyz);
            break;
        default:
            uv = Cone::getTextureColor(xyz);
            break;
    }

    // Maps from uv point to st on texture map
    glm::vec2 st = glm::vec2(((int)(uv[0] * prim.material.textureMap.repeatU * image.width())) % image.width(),
            ((int) (uv[1] * prim.material.textureMap.repeatV * image.height())) % image.height());

    // returns color from st point on texture map
    QRgb rgb = image.pixel(st[0], st[1]);
    return glm::vec3(qRed(rgb) / 255.f, qGreen(rgb) /255.f, qBlue(rgb)/255.f);
}

// From Canvas2D settings, update configurations for ray
void RayScene::updateSettings(Settings settings){
    m_pointLights = settings.usePointLights;
    m_directionalLights = settings.useDirectionalLights;
    m_textureMapping = settings.useTextureMapping;
    m_shadows = settings.useShadows;
    m_reflection = settings.useReflection;
}

RayScene::~RayScene()
{
}

