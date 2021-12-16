#ifndef SCENEVIEWSCENE_H
#define SCENEVIEWSCENE_H

#include "OpenGLScene.h"
#include "shapes/Shape.h"
#include "shapes/VoronoiEdge.h"
#include "shapes/Polygon.h"


#include <memory>


namespace CS123 { namespace GL {

    class Shader;
    class CS123Shader;
    class Texture2D;
}}

struct PrimShape {
    TransformedPrimative prim;
    std::vector<GLfloat> data;
};

/**
 *
 * @class SceneviewScene
 *
 * A complex scene consisting of multiple objects. Students will implement this class in the
 * Sceneview assignment.
 *
 * Here you will implement your scene graph. The structure is up to you - feel free to create new
 * classes and data structures as you see fit. We are providing this SceneviewScene class for you
 * to use as a stencil if you like.
 *
 * Keep in mind that you'll also be rendering entire scenes in the next two assignments, Intersect
 * and Ray. The difference between this assignment and those that follow is here, we are using
 * OpenGL to do the rendering. In Intersect and Ray, you will be responsible for that.
 */
class SceneviewScene : public OpenGLScene {

public:
    SceneviewScene();
    virtual ~SceneviewScene();

    virtual void render(SupportCanvas3D *context) override;
    virtual void settingsChanged() override;

    // Use this method to set an internal selection, based on the (x, y) position of the mouse
    // pointer.  This will be used during the "modeler" lab, so don't worry about it for now.
    void setSelection(int x, int y);
    void addEdge(VoronoiEdge edge);
    void addBuilding(Polygon building);
    void addGreen(Polygon green);

private:


private:
    void initializeTesselations();
    void loadPhongShader();
    void loadWireframeShader();
    void loadNormalsShader();
    void loadNormalsArrowShader();

    void setGlobalData();
    void setSceneUniforms(SupportCanvas3D *context);
    void setMatrixUniforms(CS123::GL::Shader *shader, SupportCanvas3D *context);
    void setLights();
    void renderGeometry();
    void initializeEdgeMaterial();
    void initializeGreenMaterial();
    void initializeImage();

    std::unique_ptr<CS123::GL::CS123Shader> m_phongShader;
    std::unique_ptr<CS123::GL::Shader> m_wireframeShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsArrowShader;

    int m_param1;
    int m_param2;
    bool m_tesselate;
    bool m_initialize;
    std::unique_ptr<Shape> m_shape;
    std::vector<PrimShape> m_primShapes;
    std::vector<VoronoiEdge> m_edges;
    std::vector<Polygon> m_greens;
    std::vector<Polygon> m_buildings;
    CS123SceneMaterial m_edgeMaterial;
    CS123SceneMaterial m_greenMaterial;
    QImage m_image;

};

#endif // SCENEVIEWSCENE_H
