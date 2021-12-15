#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include "GL/glew.h"
#include "OpenGLShape.h"
#include "scenegraph/Ray.h"

#include<memory>
#include <vector>

struct ShapeInfo {
    glm::vec3 obj_coord;
    glm::vec3 normal;
    glm::vec3 eye;
    float t;

};

class Shape : public OpenGLShape
{
public:
    Shape();
    ~Shape();
    static ShapeInfo implicitIntersection(Ray ray);
    static glm::vec3 getNormal(glm::vec3 coord);
    static glm::vec2 getTextureColor(glm::vec3 xyz);
    void setVertexData(std::vector<GLfloat> data);
    std::vector<GLfloat> getVertexData();
protected:
    void addToVector(glm::vec3 vec);
    void addToVector(glm::vec2 vec);
    static float quadratic(float a, float b, float c, int sign);
    static float capIntersection(glm::vec3 norm, glm::vec3 coord, glm::vec3 d, glm::vec3 p);
};

#endif // SHAPE_H
