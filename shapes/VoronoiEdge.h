#ifndef VORONOIEDGE_H
#define VORONOIEDGE_H

#include "Shape.h"


class VoronoiEdge
{
public:
    VoronoiEdge();
    VoronoiEdge(int x0, int y0, int x1, int y1, int width);
    std::vector<GLfloat> getVertexData();

protected:
    void generateVertices(int x0, int y0, int x1, int y1, int width);
    void addToVector(glm::vec3 vec);
    std::vector<GLfloat> m_vertexData;

};

#endif // VORONOIEDGE_H
