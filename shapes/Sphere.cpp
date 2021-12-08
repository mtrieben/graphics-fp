#include "Sphere.h"
#include "CircleBase.h"
#include "BaseShape.h"
#include <math.h>

Sphere::Sphere()
{
}

Sphere::Sphere(int param1, int param2):
    Shape(),
    m_param1(param1),
    m_param2(param2)
{
    std::vector<std::vector<glm::vec3>> baseVertices = generateVertices();
    generateTriangles(baseVertices);
    initializeOpenGLShapeProperties();
}


// generates a CircleBase for every "slice" of the Sphere, increasing and then decreasing the radius according to phi
std::vector<std::vector<glm::vec3>> Sphere::generateVertices(){
    std::vector<std::vector<glm::vec3>> baseVertices;
    for (int i = 1; i < m_param1; i++){
        float phi = M_PI - ((M_PI / m_param1) * i);
        float y = 0.5*cos(phi);
        if (y < 0){
            bases.push_back(std::make_unique<CircleBase>(m_param2, -1, -1*y, 0.5*sin(phi)));
        }
        else{
            bases.push_back(std::make_unique<CircleBase>(m_param2, 1, y, 0.5*sin(phi)));
        }
        baseVertices.push_back(bases[i-1]->getVertices());
    }
    return baseVertices;
}

void Sphere::generateTriangles(std::vector<std::vector<glm::vec3>> baseVertices){
    // genereates the bottom triangles by connecting the lowest CircleBase to the bottom point
    glm::vec3 bottom = glm::vec3(0,-0.5,0);
    for(int i = 1; i < baseVertices[0].size()-1;i++){

        addToVector(bottom);
        addToVector(glm::normalize(bottom));

        addToVector(baseVertices[0][i]);
        addToVector(glm::normalize(baseVertices[0][i]));

        addToVector(baseVertices[0][i+1]);
        addToVector(glm::normalize(baseVertices[0][i+1]));

    }

    // generates all the intermediate triangles
   for(int base = 0; base < baseVertices.size()-1; base++){
        for(int i = 1; i < baseVertices[base].size()-1; i++){

            addToVector(baseVertices[base][i+1]);
            addToVector(glm::normalize(baseVertices[base][i+1]));

            addToVector(baseVertices[base][i]);
            addToVector(glm::normalize(baseVertices[base][i]));

            addToVector(baseVertices[base+1][i]);
            addToVector(glm::normalize(baseVertices[base+1][i]));

            addToVector(baseVertices[base][i+1]);
            addToVector(glm::normalize(baseVertices[base][i+1]));

            addToVector(baseVertices[base+1][i]);
            addToVector(glm::normalize(baseVertices[base+1][i]));

            addToVector(baseVertices[base+1][i+1]);
            addToVector(glm::normalize(baseVertices[base+1][i+1]));

        }
    }

   // genereates the top triangles by connecting the highest CircleBase to the top point
    glm::vec3 top = glm::vec3(0,0.5,0);
    for(int i = 1; i < baseVertices[baseVertices.size()-1].size()-1;i++){
        addToVector(top);
        addToVector(glm::normalize(top));

        addToVector(baseVertices[baseVertices.size()-1][i+1]);
        addToVector(glm::normalize(baseVertices[baseVertices.size()-1][i+1]));

        addToVector(baseVertices[baseVertices.size()-1][i]);
        addToVector(glm::normalize(baseVertices[baseVertices.size()-1][i]));
    }
}

// Returns lowest t-val (if any) for sphere/ray intersection
ShapeInfo Sphere::implicitIntersection(Ray ray){
    std::vector<ShapeInfo> ret(0);

    // Sphere only has one implicit equation with up to 2 possible options
    std::vector<float> base = baseIntersection(ray.m_start, ray.m_d);
    for(int i = 0; i < base.size(); i++){
        glm::vec4 xyz = ray.m_start + (base[i]*ray.m_d);
        if(xyz[1] < (0.5) && xyz[1] > (-0.5)){
            ret.push_back(ShapeInfo{glm::vec3(xyz), getNormal(glm::vec3(xyz)), glm::vec3(ray.m_d), base[i]});
        }
    }

    // If no intersection, return t-val of -1
    ShapeInfo r = ShapeInfo{glm::vec3(0), glm::vec3(0), glm::vec3(ray.m_d), INFINITY};
    if(ret.size() == 0){
        r.t = -1;
        return r;
    }

    // Finds lowest t-val to return
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

// Given coords, returns the normal at that point
glm::vec3 Sphere::getNormal(glm::vec3 coord){
    return glm::vec3(2.f*coord[0], 2.f*coord[1], 2.f*coord[2]);
}

// Implicit equation for sphere
std::vector<float> Sphere::baseIntersection(glm::vec4 p, glm::vec4 d){
    std::vector<float> ret = std::vector<float>(0);
    float a = (d[0] * d[0]) + (d[2] * d[2]) + (d[1] * d[1]);
    float b = (2.0f*p[0]*d[0]) + (2.0f*p[2]*d[2]) + (2.0f*p[1]*d[1]);
    float c = (p[0] * p[0]) + (p[2] * p[2]) + (p[1]*p[1]) - 0.25;

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

// Maps xyz point on sphere to a uv point on a unit square
glm::vec2 Sphere::getTextureColor(glm::vec3 xyz){
    float theta = atan2(xyz[2], xyz[0]);
    float u;
    if(abs(xyz[1] - 0.5f) < 0.01f){
        u = 0.5f;
    }
    else if (theta < 0.f){
        u = -theta / (2.f*M_PI);
    }
    else{
        u = 1.f - (theta / (2.f*M_PI));
    }
    float phi = asin(xyz[1]/0.5f);
    return glm::vec2(u,1-((phi/M_PI)+0.5f));
}

Sphere::~Sphere(){
}
