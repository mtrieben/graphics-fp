#include "CircleBase.h"
#include <math.h>


CircleBase::CircleBase()
{

}

CircleBase::CircleBase(int param2, int sign, float y, float radius):
    m_param2(param2),
    sign(sign),
    y_level(y),
    radius(radius)
{
    generatePoints();
}

void CircleBase::generatePoints(){
    // Generates the vertices on the circle for a CircleBase according to m_param2
    m_vertices.push_back(glm::vec3(0.0,sign*radius,0));
    for(float theta = 0; theta <= 2*M_PI + .01; theta += (2.0*M_PI)/m_param2){
        m_vertices.push_back(glm::vec3(radius*cos(theta), sign*y_level,radius*sin(theta)));
    }
}

// accessor functions for a CircleBase
std::vector<glm::vec3> CircleBase::getVertices(){
    return m_vertices;
}

int CircleBase::getParam2(){
    return m_param2;
}

int CircleBase::getSign(){
    return sign;
}

float CircleBase::getY(){
    return y_level;
}

CircleBase::~CircleBase(){
}
