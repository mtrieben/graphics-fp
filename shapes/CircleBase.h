#ifndef CIRCLEBASE_H
#define CIRCLEBASE_H

#include "Shape.h"

class CircleBase : public Shape
{
public:
    CircleBase();
    CircleBase(int param2, int sign, float y, float radius);
    ~CircleBase();
    std::vector<glm::vec3> getVertices();
    int getParam2();
    int getSign();
    float getY();
private:
    int m_param2;
    int sign;
    float y_level;
    float radius;
    void generatePoints();
    std::vector<glm::vec3> m_vertices;

};

#endif // CIRCLEBASE_H
