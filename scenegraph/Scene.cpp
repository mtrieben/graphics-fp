#include "Scene.h"
#include "Camera.h"
#include "CS123ISceneParser.h"

#include <iostream>
#include "glm/gtx/string_cast.hpp"

#include "glm/gtx/transform.hpp"


Scene::Scene()
{
}

Scene::Scene(Scene &scene)
{
    // copies all member vars over to new scene
    setGlobal(scene.m_globalData.operator*());
    for(int i = 0; i < scene.m_lights.size(); i++){
        addLight((scene.m_lights[i]).operator*());
    }
    for(int i = 0; i < scene.m_primatives.size(); i++){
        addPrimitive(scene.m_primatives[i]->primative, scene.m_primatives[i]->transformation);
    }
}

Scene::~Scene()
{
    // Do not delete m_camera, it is owned by SupportCanvas3D
}

void Scene::parse(Scene *sceneToFill, CS123ISceneParser *parser) {
    // sets global data
    CS123SceneGlobalData global;
    parser->getGlobalData(global);
    sceneToFill->setGlobal(global);

    // sets light data for each light
    for(int i = 0; i < parser->getNumLights(); i++){
        CS123SceneLightData temp;
        parser->getLightData(i, temp);
        sceneToFill->addLight(temp);
    }

    // traverses scene graph
    sceneToFill->traverseTree(*parser->getRootNode(), glm::mat4x4());
}

// method to recursively traverse scene graph, calculating transform matrix for each primative
void Scene::traverseTree(CS123SceneNode node, glm::mat4x4 matrix){
    glm::mat4x4 totalMatrix = matrix;
    for (int t = 0; t < node.transformations.size(); t++){
        switch(node.transformations[t]->type){
            case TRANSFORMATION_TRANSLATE:
                totalMatrix = totalMatrix*glm::translate(node.transformations[t]->translate);
                break;
            case TRANSFORMATION_SCALE:
                totalMatrix =  totalMatrix*glm::scale(node.transformations[t]->scale);
                break;
            case TRANSFORMATION_ROTATE:
                totalMatrix =  totalMatrix*glm::rotate(node.transformations[t]->angle, node.transformations[t]->rotate);
                break;
            default:
                totalMatrix = totalMatrix*node.transformations[t]->matrix;
                break;
        }
    }

    for(CS123ScenePrimitive* prim: node.primitives){
        this->addPrimitive(*prim, totalMatrix);
    }

    for(CS123SceneNode* node: node.children){
        this->traverseTree(*node, totalMatrix);
    }
}

// stores primative in member variable
void Scene::addPrimitive(const CS123ScenePrimitive &scenePrimitive, const glm::mat4x4 &matrix) {
    std::unique_ptr<CS123ScenePrimitive> primative = std::make_unique<CS123ScenePrimitive>(CS123ScenePrimitive(scenePrimitive));
    m_primatives.push_back(std::make_unique<TransformedPrimative>(TransformedPrimative(primative.operator*(), matrix)));
}

// stores light data in member variable
void Scene::addLight(const CS123SceneLightData &sceneLight) {
    m_lights.push_back(std::make_unique<CS123SceneLightData>(CS123SceneLightData(sceneLight)));
}

// stores global data in member variable
void Scene::setGlobal(const CS123SceneGlobalData &global) {
    m_globalData = std::make_unique<CS123SceneGlobalData>(CS123SceneGlobalData(global));
}

