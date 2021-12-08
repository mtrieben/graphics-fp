#ifndef CYLINDER_H
#define CYLINDER_H

#include "BaseShape.h"


class Cylinder : public BaseShape
{
public:
    Cylinder();
    Cylinder(int param1, int param2);
    ~Cylinder();
    static ShapeInfo implicitIntersection(Ray ray);
    static glm::vec2 getTextureColor(glm::vec3 xyz);
private:
    int m_param1;
    int m_param2;
    std::vector<std::unique_ptr<CircleBase>> bases;
    std::vector<std::vector<glm::vec3>> generateVertices();
    static std::vector<float> baseIntersection(Ray ray);
    static glm::vec3 getNormal(glm::vec3 coord);

};

#endif // CYLINDER_H
