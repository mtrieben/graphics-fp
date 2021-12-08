#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "CircleBase.h"
#include "Shape.h"

class BaseShape: public Shape
{
public:
    BaseShape();
    ~BaseShape();
protected:
    void expandCircleBase(std::unique_ptr<CircleBase> b, int slices);
    void generatePoints(std::vector<std::vector<glm::vec3>> baseVertices, int m_param2, float y);
};

#endif // BASESHAPE_H
