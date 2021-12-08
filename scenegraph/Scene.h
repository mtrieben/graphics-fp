#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include "CS123SceneData.h"
#include <QImage>


class Camera;
class CS123ISceneParser;

struct TransformedPrimative {
    TransformedPrimative(CS123ScenePrimitive prim, glm::mat4x4 trans):
        primative(prim),
        transformation(trans){
    }
    CS123ScenePrimitive primative;
    glm::mat4x4 transformation;
    QImage image;

};

/**
 * @class Scene
 *
 * @brief This is the base class for all scenes. Modify this class if you want to provide
 * common functionality to all your scenes.
 */
class Scene {
public:
    Scene();
    Scene(Scene &scene);
    virtual ~Scene();

    virtual void settingsChanged() {}

    static void parse(Scene *sceneToFill, CS123ISceneParser *parser);

protected:

    // Adds a primitive to the scene.
    virtual void addPrimitive(const CS123ScenePrimitive &scenePrimitive, const glm::mat4x4 &matrix);

    // Adds a light to the scene.
    virtual void addLight(const CS123SceneLightData &sceneLight);

    // Sets the global data for the scene.
    virtual void setGlobal(const CS123SceneGlobalData &global);

    void traverseTree(CS123SceneNode node, glm::mat4x4 matrix);

    std::unique_ptr<CS123SceneGlobalData> m_globalData;
    std::vector<std::unique_ptr<CS123SceneLightData>> m_lights;
    std::vector<std::unique_ptr<TransformedPrimative>> m_primatives;
};



#endif // SCENE_H
