#include "Ray.h"

#include <iostream>
#include "glm/gtx/string_cast.hpp"


Ray::Ray()
{

}

// constructor for intersect
Ray::Ray(glm::vec4 start, glm::vec4 uvk):
    m_start(start),
    m_d(glm::normalize(uvk-start))
{

}

// constructor for ray
Ray::Ray(glm::vec4 start, glm::vec4 dir, int i):
    m_start(start),
    m_d(glm::normalize(dir))
{

}

// Method that applies a matrix transformation to a Ray
void Ray::transformRay(glm::mat4x4 trans){
    m_start = trans*m_start;
    m_d = trans*m_d;
}

Ray::~Ray(){
}
