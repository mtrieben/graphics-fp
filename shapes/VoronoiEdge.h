#ifndef VORONOIEDGE_H
#define VORONOIEDGE_H

#include "Shape.h"


class VoronoiEdge
{
public:
    VoronoiEdge();
    VoronoiEdge(float x0, float y0, float x1, float y1, int width);
    std::vector<GLfloat> getVertexData();

protected:
    void generateVertices(float x0, float y0, float x1, float y1, int width);
    void addToVector(glm::vec3 vec);
    std::vector<GLfloat> m_vertexData;

};

#endif // VORONOIEDGE_H
