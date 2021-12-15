#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"


class Polygon
{
public:
    Polygon();
    Polygon(glm::vec2 l, glm::vec2 r, glm::vec2 t, float height);
    Polygon(glm::vec2 l0 , glm::vec2 l1 , glm::vec2 r0, glm::vec2 r1, float height);
    Polygon(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d, glm::vec2 e, float height);
    std::vector<GLfloat> getVertexData();

protected:
    void generateVertices(float x0, float y0, float x1, float y1, int width);
    void generatePoints(std::vector<glm::vec3> base1, std::vector<glm::vec3> base2, int m_param2, float y);
    void addToVector(glm::vec3 vec);
    void addToVector(glm::vec2 vec);
    glm::vec3 surfaceNormal(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
    std::vector<GLfloat> m_vertexData;

};

#endif // POLYGON_H
