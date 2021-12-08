#include "Cone.h"
#include "CircleBase.h"
#include "BaseShape.h"
#include <math.h>
#include <iostream>
#include "glm/gtx/string_cast.hpp"


Cone::Cone()
{
}

Cone::Cone(int param1, int param2):
    m_param1(param1),
    m_param2(param2)
{
    std::vector<std::vector<glm::vec3>> baseVertices = generateVertices();
    generatePoints(baseVertices, m_param2, 1.0/sqrt(5));
    generateTopTriangles(baseVertices);
    initializeOpenGLShapeProperties();
}

// generates a CircleBase for every "slice" of the cone, decreasing the radius as we go
std::vector<std::vector<glm::vec3>> Cone::generateVertices(){
    std::vector<std::vector<glm::vec3>> baseVertices;
    for(int i = 0; i < m_param1; i++){
        float y = -0.5 + (1.0/m_param1)*i;
        float radius = (-0.5*(y))+0.25;
        if (y < 0){
            bases.push_back(std::make_unique<CircleBase>(m_param2, -1, y*-1, radius));
        }
        else{
            bases.push_back(std::make_unique<CircleBase>(m_param2, 1, y, radius));
        }
        baseVertices.push_back(bases[i]->getVertices());
    }
    return baseVertices;
}


// Generates the last row of triangles by connecting the last circle base with the top point.
void Cone::generateTopTriangles(std::vector<std::vector<glm::vec3>> baseVertices){
    glm::vec3 center = glm::vec3(0,0.5,0);

    for(int i = 1; i < baseVertices[baseVertices.size()-1].size()-1;i++){
        float theta_i = ((2.0*M_PI)/m_param2)*(i-1);
        float theta_i1 = ((2.0*M_PI)/m_param2)*(i);
        addToVector(center);
        addToVector(glm::normalize(glm::vec3((cos(theta_i) + cos(theta_i1))/2.0, 1.0/sqrt(5), (sin(theta_i) + sin(theta_i1)/2.0))));
        addToVector(baseVertices[baseVertices.size()-1][i+1]);
        addToVector(glm::normalize(glm::vec3(cos(theta_i1), 1.0/sqrt(5), sin(theta_i1))));
        addToVector(baseVertices[baseVertices.size()-1][i]);
        addToVector(glm::normalize(glm::vec3(cos(theta_i), 1.0/sqrt(5), sin(theta_i))));
    }

    // tessalates the CircleBase based on m_param1
    expandCircleBase(std::move(bases[0]), m_param1);
}

// Returns lowest t-val for cone/ray intersection
ShapeInfo Cone::implicitIntersection(Ray ray){
    std::vector<ShapeInfo> ret(0);

    // Gets possible intersection points for cone body and checks if they're in bounds
    std::vector<float> base = baseIntersection(ray.m_start, ray.m_d);
    for(int i = 0; i < base.size(); i++){
        glm::vec4 xyz = ray.m_start + (base[i]*ray.m_d);
        if(xyz[1] < (0.5f) && xyz[1] > (-0.5)){
            ret.push_back(ShapeInfo{glm::vec3(xyz), getNormal(glm::vec3(xyz)), glm::vec3(ray.m_d), base[i]});
        }
    }

    // Gets intersection for cone cap if in bounds
    float cap = capIntersection(glm::vec3(0.f,-1.f,0.f), glm::vec3(0.f, -0.5f, 0.f), glm::vec3(ray.m_d), glm::vec3(ray.m_start));
    glm::vec4 xyz = ray.m_start + (cap*ray.m_d);
    if(((xyz[0] * xyz[0]) + (xyz[2]*xyz[2])) <= 0.25){
        ret.push_back(ShapeInfo{glm::vec3(xyz), glm::vec3(0.f,-1.f,0.f), glm::vec3(ray.m_d), cap});
    }

    ShapeInfo r = ShapeInfo{glm::vec3(0), glm::vec3(0), glm::vec3(ray.m_d), INFINITY};

    // If no valid t-vals, return 0
    if(ret.size() == 0){
        r.t = -1;
        return r;
    }

    // Finds and returns lowest t-val
    for(int i = 0; i < ret.size(); i++){
        if (ret[i].t > 0.f && ret[i].t < r.t){
            r = ret[i];
        }
    }
    if(r.t == INFINITY){
        r.t = -1;
        return r;
    }
    return r;
}

// Implicit equation for cone body intersection
std::vector<float> Cone::baseIntersection(glm::vec4 p, glm::vec4 d){
    float a = (d[0] * d[0]) + (d[2] * d[2]) - (0.25f*(d[1] * d[1]));
    float b = (2.0f*p[0]*d[0]) + (2.0f*p[2]*d[2]) - (0.5f*p[1]*d[1]) + (0.25f*d[1]);
    float c = (p[0] * p[0]) + (p[2] * p[2]) - (0.25f*p[1]*p[1]) + (0.25f*p[1]) - 0.0625;
    std::vector<float> ret = std::vector<float>(0);

    float pos =  quadratic(a,b,c, 1);
    float neg = quadratic(a,b,c,-1);
    if (neg > 0){
        ret.push_back(neg);
    }
    if (pos > 0){
        ret.push_back(pos);
    }
    return ret;
}

// Given coords on cone body, returns normal at that point
glm::vec3 Cone::getNormal(glm::vec3 coord){
    return glm::vec3(2.f*coord[0], (0.25f - (0.5f*coord[1])), 2.f*coord[2]);
}

// Maps xyz point on cone to a uv point on a unit square
glm::vec2 Cone::getTextureColor(glm::vec3 xyz){
    // If on capx of cone
    if(abs(xyz[1] + 0.5f) < 0.01){
        return glm::vec2(xyz[0] + 0.5f, -xyz[2] + 0.5f);
    }
    // If on cone body
    else{
        float theta = atan2(xyz[2], xyz[0]);
        float u;
        if (theta < 0.f){
            u = -theta / (2.f*M_PI);
        }
        else{
            u = 1.f - (theta / (2.f*M_PI));
        }
        return glm::vec2(u, 1-(xyz[1]+0.5f));
    }
}

Cone::~Cone(){
}
