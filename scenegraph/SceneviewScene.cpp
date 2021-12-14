#include "SceneviewScene.h"
#include "GL/glew.h"
#include <QGLWidget>
#include "Camera.h"
#include <iostream>

#include "Settings.h"
#include "SupportCanvas3D.h"
#include "ResourceLoader.h"
#include "gl/shaders/CS123Shader.h"
#include "shapes/Cone.h"
#include "shapes/Cylinder.h"
#include "shapes/Sphere.h"
#include "shapes/Cube.h"
#include "shapes/VoronoiEdge.h"
using namespace CS123::GL;


SceneviewScene::SceneviewScene():
    m_param1(0),
    m_param2(0),
    m_tesselate(false),
    m_initialize(true)
{
    loadPhongShader();
    loadWireframeShader();
    loadNormalsShader();
    loadNormalsArrowShader();
    initializeEdgeMaterial();
}

SceneviewScene::~SceneviewScene()
{
}

void SceneviewScene::initializeEdgeMaterial(){
    m_edgeMaterial = CS123SceneMaterial();
    m_edgeMaterial.cDiffuse = CS123SceneColor(glm::vec4(1,1,1,0));
    m_edgeMaterial.cAmbient = CS123SceneColor(glm::vec4(.5f, .5f,.5f,0));
    m_edgeMaterial.cReflective = CS123SceneColor(glm::vec4(0,0,0,0));
    m_edgeMaterial.cSpecular = CS123SceneColor(glm::vec4(0,0,0,0));
    m_edgeMaterial.cTransparent = CS123SceneColor(glm::vec4(0,0,0,0));
    m_edgeMaterial.cEmissive = CS123SceneColor(glm::vec4(0,0,0,0));
    m_edgeMaterial.textureMap = CS123SceneFileMap();
    m_edgeMaterial.textureMap.isUsed = false;
    m_edgeMaterial.blend = 1.f;
    m_edgeMaterial.shininess = 0.5f;
}


void SceneviewScene::addEdge(VoronoiEdge edge){
    m_edges.push_back(edge);
}

void SceneviewScene::loadPhongShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/default.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/default.frag");
    m_phongShader = std::make_unique<CS123Shader>(vertexSource, fragmentSource);
}

void SceneviewScene::loadWireframeShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.frag");
    m_wireframeShader = std::make_unique<Shader>(vertexSource, fragmentSource);
}

void SceneviewScene::loadNormalsShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normals.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.frag");
    m_normalsShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void SceneviewScene::loadNormalsArrowShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.frag");
    m_normalsArrowShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void SceneviewScene::render(SupportCanvas3D *context) {
    if(m_primatives.size() == 0){
        return;
    }
    setClearColor();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_phongShader->bind();
    setGlobalData();
    setSceneUniforms(context);
    setLights();
    renderGeometry();
    glBindTexture(GL_TEXTURE_2D, 0);
    m_phongShader->unbind();

}

void SceneviewScene::setGlobalData(){
    // passes global data to shader.vert using m_phongShader

    m_phongShader->setUniform("ka", m_globalData->ka);
    m_phongShader->setUniform("kd", m_globalData->kd);
    m_phongShader->setUniform("ks", m_globalData->ks);


}


void SceneviewScene::setSceneUniforms(SupportCanvas3D *context) {
    Camera *camera = context->getCamera();
    m_phongShader->setUniform("useLighting", settings.useLighting);
    m_phongShader->setUniform("useArrowOffsets", false);
    m_phongShader->setUniform("isShapeScene", false);
    m_phongShader->setUniform("p" , camera->getProjectionMatrix());
    m_phongShader->setUniform("v", camera->getViewMatrix());
}

void SceneviewScene::setMatrixUniforms(Shader *shader, SupportCanvas3D *context) {
    shader->setUniform("p", context->getCamera()->getProjectionMatrix());
    shader->setUniform("v", context->getCamera()->getViewMatrix());
}

void SceneviewScene::setLights()
{

    // Set up the lighting for your scene using m_phongShader.
    // The lighting information will most likely be stored in CS123SceneLightData structures.
    for(int i = 0; i < m_lights.size(); i++){
        m_phongShader->setLight(m_lights[i].operator*());
    }
}

// Helper method that will initialize the vector that maps primative to its m_vertexData vector
void SceneviewScene::initializeTesselations(){
    m_primShapes.clear();
    m_shape = std::make_unique<Shape>();
    for(int i = 0; i < m_primatives.size(); i++){
        std::unique_ptr<Shape> shape = std::make_unique<Cube>();
        switch(m_primatives[i]->primative.type){
            case PrimitiveType::PRIMITIVE_CUBE:
                shape = std::make_unique<Cube>(glm::max(settings.shapeParameter1, 1), settings.shapeParameter2);
                break;
            case PrimitiveType::PRIMITIVE_CONE:
                shape = std::make_unique<Cone>(glm::max(settings.shapeParameter1, 1), glm::max(settings.shapeParameter2, 3));
                break;
            case PrimitiveType::PRIMITIVE_CYLINDER:
                shape = std::make_unique<Cylinder>(glm::max(settings.shapeParameter1, 1), glm::max(settings.shapeParameter2, 3));
                break;
            case PrimitiveType::PRIMITIVE_SPHERE:
                shape = std::make_unique<Sphere>(glm::max(settings.shapeParameter1, 2), glm::max(settings.shapeParameter2, 3));
                break;
            default:
                shape = std::make_unique<Cube>(glm::max(settings.shapeParameter1, 1), settings.shapeParameter2);
                break;
        }
        m_primShapes.push_back(PrimShape{m_primatives[i].operator*(), shape->getVertexData()});
    }
}

void SceneviewScene::renderGeometry() {
    // Initialize tesselations only when first rendering scene
    if(m_initialize){
        this->initializeTesselations();
        m_initialize = false;
    }

    // For each primitive, if we need to re-tesselate we do, if not, re-draw the existing tesselations
    for (int i = 0; i < m_primatives.size(); i++){
        continue;
        if(m_tesselate){
            std::unique_ptr<Shape> shape;
            switch(m_primatives[i]->primative.type){
                case PrimitiveType::PRIMITIVE_CUBE:
                    shape = std::make_unique<Cube>(glm::max(m_param1, 1), m_param2);
                    break;
                case PrimitiveType::PRIMITIVE_CONE:
                    shape = std::make_unique<Cone>(glm::max(m_param1, 1), glm::max(m_param2, 3));
                    break;
                case PrimitiveType::PRIMITIVE_CYLINDER:
                    shape = std::make_unique<Cylinder>(glm::max(m_param1, 1), glm::max(m_param2, 3));
                    break;
                case PrimitiveType::PRIMITIVE_SPHERE:
                    shape = std::make_unique<Sphere>(glm::max(m_param1, 2), glm::max(m_param2, 3));
                    break;
                default:
                    shape = std::make_unique<Cube>(glm::max(m_param1, 1), m_param2);
                    break;
            }
            m_primShapes[i].data = shape->getVertexData();
        }
        m_phongShader->applyMaterial(m_primatives[i]->primative.material);
        m_phongShader->setUniform("m", m_primatives[i]->transformation);
        m_shape->setVertexData(m_primShapes[i].data);
        m_shape->draw();
    }
    for(int i = 0; i < m_edges.size(); i++){
        m_phongShader->applyMaterial(m_edgeMaterial);
        m_phongShader->setUniform("m", glm::mat4x4());
        m_shape->setVertexData(m_edges[i].getVertexData());
        m_shape->draw();
    }
    m_tesselate = false;
}

// Updates parameters based on gui params
void SceneviewScene::settingsChanged() {
    if(m_primatives.size() != m_primShapes.size()){
        this->initializeTesselations();
    }
    if (m_param1 != settings.shapeParameter1 || m_param2 != settings.shapeParameter2){
        m_tesselate = true;
    }
    m_param1 = settings.shapeParameter1;
    m_param2 = settings.shapeParameter2;
}

