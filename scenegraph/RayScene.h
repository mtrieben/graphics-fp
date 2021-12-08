#ifndef RAYSCENE_H
#define RAYSCENE_H

#include "Scene.h"
#include "RGBA.h"
#include "Ray.h"
#include "Canvas2D.h"
#include <vector>

/**
 * @class RayScene
 *
 *  Students will implement this class as necessary in the Ray project.
 */
class RayScene : public Scene {
public:
    RayScene(Scene &scene);
    virtual ~RayScene();
    void render(Canvas2D* canvas, int width, int height, CS123SceneCameraData *camera);
    void updateSettings(Settings settings);
private:
    void setUpCamera(CS123SceneCameraData* camera);
    Canvas2D* m_canvas;
    glm::mat4x4 m_cameraMatrix;
    glm::vec4 traceRay(Ray ray, float dist, bool shadow, int depth);
    glm::vec4 getLighting(QImage image, glm::mat4x4 trans, glm::vec3 eye, glm::vec3 normals, glm::vec3 xyz, CS123ScenePrimitive prim, int depth);
    glm::vec3 getTexture(QImage image, CS123ScenePrimitive prim, glm::vec3 xyz);

    // Booleans for configuring settings in ray
    bool m_pointLights;
    bool m_directionalLights;
    bool m_textureMapping;
    bool m_shadows;
    bool m_reflection;
};
#endif // RAYSCENE_H
