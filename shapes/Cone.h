#ifndef CONE_H
#define CONE_H

#include "CircleBase.h"
#include "BaseShape.h"


class Cone : public BaseShape
{
public:
    Cone();
    ~Cone();
    Cone(int param_1, int param_2);
    static ShapeInfo implicitIntersection(Ray ray);
    static glm::vec2 getTextureColor(glm::vec3 xyz);
private:
    int m_param1;
    int m_param2;
    std::vector<std::unique_ptr<CircleBase>> bases;
    void generateTopTriangles(std::vector<std::vector<glm::vec3>> baseVertices);
    std::vector<std::vector<glm::vec3>> generateVertices();
    static std::vector<float> baseIntersection(glm::vec4 p, glm::vec4 d);
    static glm::vec3 getNormal(glm::vec3 coord);




};

#endif // CONE_H
