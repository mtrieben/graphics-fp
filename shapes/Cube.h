#ifndef CUBE_H
#define CUBE_H
#include "Shape.h"

class Cube : public Shape
{
public:
    Cube();
    Cube(int param1, int param2);

    ~Cube();
    static ShapeInfo implicitIntersection(Ray ray);
    static glm::vec2 getTextureColor(glm::vec3 xyz);
private:
    int m_param1;
    int m_param2;
    std::vector<glm::vec2> m_face;
    void generateFace(int index1, int index2, int index3, int sign);
    void generatePoints();

};

#endif // CUBE_H
