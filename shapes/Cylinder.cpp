#include "Cylinder.h"
#include "CircleBase.h"
#include "BaseShape.h"
#include <math.h>

#include <iostream>


Cylinder::Cylinder() :
    BaseShape()
{
}

Cylinder::Cylinder(int param1, int param2):
    BaseShape(),
    m_param1(param1),
    m_param2(param2)
{
    generatePoints(generateVertices(), m_param2,0);

    // tessalates the bottom CircleBase based on m_param1
    expandCircleBase(std::move(bases[0]), m_param1);
    // tessalates the top CircleBase based on m_param1
    expandCircleBase(std::move(bases[bases.size()-1]), m_param1);
    initializeOpenGLShapeProperties();
}

// generates a CircleBase for every "slice" of the cylinder
std::vector<std::vector<glm::vec3>> Cylinder::generateVertices(){
    std::vector<std::vector<glm::vec3>> baseVertices;
    for (int i = 0; i <= m_param1; i++){
        float y = -0.5 + (1.0/m_param1)*i;
        float radius = 0.5;
        if(y < 0){
            bases.push_back(std::make_unique<CircleBase>(m_param2, -1, -1*y, radius));
        }
        else{
            bases.push_back(std::make_unique<CircleBase>(m_param2, 1, y, radius));
        }
        baseVertices.push_back(bases[i]->getVertices());
    }
    return baseVertices;
}

// returns lowest t-val for cylinder/ray intersection
ShapeInfo Cylinder::implicitIntersection(Ray ray){
    std::vector<ShapeInfo> ret(0);

    // Gets possible intersection points for cylinder body
    std::vector<float> base = baseIntersection(ray);

    // Checks which body intersections are in range
    for(float vec: base){
       glm::vec4 xyz = ray.m_start + (vec*ray.m_d);
       if(xyz[1] <= 0.5 && xyz[1] >= -0.5){
           ret.push_back(ShapeInfo{glm::vec3(xyz), getNormal(glm::vec3(xyz)),glm::vec3(ray.m_d), vec});
        }
    }

    // Gets intersection point on the bottom plane and checks if its on the bottom cap
    float bottom = capIntersection(glm::vec3(0.f,-1.f,0.f), glm::vec3(0.f, -0.5f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 bottom_xyz = ray.m_start + (bottom*ray.m_d);
    if(((bottom_xyz[0] * bottom_xyz[0]) + (bottom_xyz[2]*bottom_xyz[2])) <= 0.25){
        ret.push_back(ShapeInfo{glm::vec3(bottom_xyz), glm::vec3(0.f,-1.f,0.f),glm::vec3(ray.m_d), bottom});
    }

    // Gets intersection point on the top plane and checks if its on the top cap
    float top = capIntersection(glm::vec3(0.f,1.f,0.f), glm::vec3(0.f, 0.5f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 top_xyz = ray.m_start + (top*ray.m_d);
    if(((top_xyz[0] * top_xyz[0]) + (top_xyz[2]*top_xyz[2])) <= 0.25){
        ret.push_back(ShapeInfo{glm::vec3(top_xyz), glm::vec3(0.f,1.f,0.f),glm::vec3(ray.m_d), top});
    }

    // if no valid intersections, return -1
    ShapeInfo r = ShapeInfo{glm::vec3(0), glm::vec3(0), glm::vec3(ray.m_d), INFINITY};
    if(ret.size() == 0){
        r.t = -1;
        return r;
    }

    // Finds lowest t-val
    for(int i = 0; i < ret.size(); i++){
        if (ret[i].t >= 0 && ret[i].t < r.t){
            r = ret[i];
        }
    }
    if(r.t == INFINITY){
        r.t = -1;
        return r;
    }
    return r;
}

// Implicit equation for intersection on cylinder body
std::vector<float> Cylinder::baseIntersection(Ray ray){
    float a = (ray.m_d[0] * ray.m_d[0]) + (ray.m_d[2] * ray.m_d[2]);
    float b = (2*ray.m_d[0]*ray.m_start[0]) + (2*ray.m_d[2]*ray.m_start[2]);
    float c = (ray.m_start[0] * ray.m_start[0]) + (ray.m_start[2] * ray.m_start[2]) - 0.25f;

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

// Given cylinder coords, return normal at that point
glm::vec3 Cylinder::getNormal(glm::vec3 coord){
    return glm::vec3(2.f*coord[0], 0.f, 2.f*coord[2]);
}

// Maps xyz point on cylinder to a uv point on a unit square
glm::vec2 Cylinder::getTextureColor(glm::vec3 xyz){
    // If on bottom cap
    if(abs(xyz[1] - 0.5f) < 0.01){
        return glm::vec2(xyz[0] + 0.5f, xyz[2] + 0.5f);
    }
    // If on top cap
    else if(abs(xyz[1] + 0.5f) < 0.01){
        return glm::vec2(xyz[0] + 0.5f, -xyz[2] + 0.5f);
    }
    // If on cylinder body
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

Cylinder::~Cylinder(){
}
