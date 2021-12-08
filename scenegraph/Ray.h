#ifndef RAY_H
#define RAY_H

#include "Settings.h"
#include "CS123SceneData.h"

class Ray
{
public:
    Ray();
    Ray(glm::vec4 start, glm::vec4 dir, int i);
    Ray(glm::vec4 start, glm::vec4 uvk);
    ~Ray();
    glm::vec4 m_start;
    glm::vec4 m_d;
    void transformRay(glm::mat4x4 trans);
};


#endif // RAY_H
