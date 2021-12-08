#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "CircleBase.h"

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(int param1, int param2);
    ~Sphere();
    static ShapeInfo implicitIntersection(Ray ray);
    static glm::vec2 getTextureColor(glm::vec3 xyz);
private:
    std::vector<std::vector<glm::vec3>> generateVertices();
    void generateTriangles(std::vector<std::vector<glm::vec3>> baseVertices);
    std::vector<std::unique_ptr<CircleBase>> bases;
    int m_param1;
    int m_param2;
    static std::vector<float> baseIntersection(glm::vec4 p, glm::vec4 d);
    static glm::vec3 getNormal(glm::vec3 coord);

};

#endif // SPHERE_H
