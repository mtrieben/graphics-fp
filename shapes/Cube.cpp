#include "Cube.h"
#include "Shape.h"


Cube::Cube() :
    Shape()
{

}

Cube::Cube(int param1, int param2) :
    Shape(),
    m_param1(param1),
    m_param2(param2)
{
    generatePoints();
    initializeOpenGLShapeProperties();

}

void Cube::generatePoints(){
    // Makes a 2D matrix of points based on m_param1 (the 3rd dimension will be constant depending on which face its on)
    for(int x = 0; x <= m_param1; x++){
        for(int y = 0; y <= m_param1; y++){
            float x_val = -0.5 + (1.0/m_param1)*x;
            float y_val = -0.5 + (1.0/m_param1)*y;
            m_face.push_back(glm::vec2(x_val,y_val));
        }
    }

    // Generates each of the faces separately
    generateFace(0,1,2,-1);
    generateFace(0,2,1,1);
    generateFace(1,0,2,1);
    generateFace(2,0,1,-1);
    generateFace(1,2,0,-1);
    generateFace(2,1,0,1);
}

void Cube::generateFace(int index1, int index2, int index3, int sign){

    int count = 0;
    // Offsets used to index into m_face to make triangles
    std::vector<int> offsets = {0, 1, m_param1+1, 1, m_param1 + 2, m_param1 + 1};

    for (int i = 0; i <= m_face.size() - 2 - m_param1; i++){
        count++;
        if (count % (m_param1 + 1) != 0){
            for(int off: offsets){

                // Add vertex to m_vertexData
                glm::vec3 v_temp = glm::vec3(0.0);
                v_temp[index1] = m_face[i+off][0];
                v_temp[index2] = m_face[i+off][1];
                v_temp[index3] = 0.5*sign;
                addToVector(v_temp);

                // Add normal to m_vertexData
                glm::vec3 n_temp = glm::vec3(0);
                n_temp[index3] = 1*sign;
                addToVector(n_temp);
            }
        }
    }
}

// Returns lowest t-val for intersection between cube and ray
ShapeInfo Cube::implicitIntersection(Ray ray){
    std::vector<ShapeInfo> ret;

    // Adds intersection point for each cube face if in range
    float neg_y = capIntersection(glm::vec3(0.f,-1.f,0.f), glm::vec3(0.f, -0.5f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 negY_coords = ray.m_start + (neg_y*ray.m_d);
    if (negY_coords[0] <= 0.5 && negY_coords[0] >= -0.5 && negY_coords[2] <= 0.5 && negY_coords[2] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(negY_coords), glm::vec3(0.f, -1.f, 0.f),glm::vec3(ray.m_d), neg_y});
    }

    float pos_y = capIntersection(glm::vec3(0.f,1.f,0.f), glm::vec3(0.f, 0.5f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 posY_coords = ray.m_start + (pos_y*ray.m_d);
    if (posY_coords[0] <= 0.5 && posY_coords[0] >= -0.5 && posY_coords[2] <= 0.5 && posY_coords[2] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(posY_coords), glm::vec3(0.f, 1.f, 0.f),glm::vec3(ray.m_d), pos_y});
    }

    float neg_x = capIntersection(glm::vec3(-1.f,0.f,0.f), glm::vec3(-0.5f, 0.f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 negX_coords = ray.m_start + (neg_x*ray.m_d);
    if (negX_coords[1] <= 0.5 && negX_coords[1] >= -0.5 && negX_coords[2] <= 0.5 && negX_coords[2] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(negX_coords), glm::vec3(-1.f,0.f,0.f), glm::vec3(ray.m_d),neg_x});
    }

    float pos_x = capIntersection(glm::vec3(1.f,0.f,0.f), glm::vec3(0.5f, 0.f, 0.f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 posX_coords = ray.m_start + (pos_x*ray.m_d);
    if (posX_coords[1] <= 0.5 && posX_coords[1] >= -0.5 && posX_coords[2] <= 0.5 && posX_coords[2] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(posX_coords), glm::vec3(1.f,0.f,0.f), glm::vec3(ray.m_d),pos_x});
    }

    float neg_z = capIntersection(glm::vec3(0.f,0.f,-1.f), glm::vec3(0.f, 0.f, -0.5f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 negZ_coords = ray.m_start + (neg_z*ray.m_d);
    if (negZ_coords[1] <= 0.5 && negZ_coords[1] >= -0.5 && negZ_coords[0] <= 0.5 && negZ_coords[0] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(negZ_coords), glm::vec3(0.f,0.f,-1.f), glm::vec3(ray.m_d),neg_z});
    }

    float pos_z = capIntersection(glm::vec3(0.f,0.f,1.f), glm::vec3(0.f, 0.f, 0.5f), glm::vec3(ray.m_d),glm::vec3(ray.m_start));
    glm::vec4 posZ_coords = ray.m_start + (pos_z*ray.m_d);
    if (posZ_coords[1] <= 0.5 && posZ_coords[1] >= -0.5 && posZ_coords[0] <= 0.5 && posZ_coords[0] >= -0.5){
        ret.push_back(ShapeInfo{glm::vec3(posZ_coords), glm::vec3(0.f,0.f,1.f), glm::vec3(ray.m_d),pos_z});
    }

    // If no valid intersections, return -1
    ShapeInfo r = {glm::vec3(0), glm::vec3(), glm::vec3(ray.m_d), INFINITY};
    if(ret.size() == 0){
        r.t = -1;
        return r;
    }

    // Return lowest t-val
    for (int i = 0; i < ret.size(); i++){
        if (ret[i].t >= 0 && ret[i].t < r.t){
            r = ret[i];
        }
    }
    if (r.t == INFINITY){
        r.t = -1;
        return r;
    }
    return r;
}

// Maps xyz point on cube to a uv point on a unit square
glm::vec2 Cube::getTextureColor(glm::vec3 xyz){
    if(abs(xyz[0] - 0.5f) < 0.0001){ // negative x plane
        return glm::vec2(-xyz[2] + 0.5f, -xyz[1] + 0.5f);
    }
    else if(abs(xyz[0] + 0.5f) < 0.0001){ // positive x plane
        return glm::vec2(xyz[2] + 0.5f, -xyz[1] + 0.5f);
    }
    else if(abs(xyz[1] - 0.5f) < 0.0001){ // negative y plane
        return glm::vec2(xyz[0] + 0.5f, xyz[2] + 0.5f);
    }
    else if(abs(xyz[1] + 0.5f) < 0.0001){ // positive y plane
        return glm::vec2(xyz[0] + 0.5f, -xyz[2] + 0.5f);
    }
    else if(abs(xyz[2] - 0.5f) < 0.0001){ // negative x plane
        return glm::vec2(xyz[0] + 0.5f, -xyz[1] + 0.5f);
    }
    else{ // positive x plane
        return glm::vec2(-xyz[0] + 0.5f, -xyz[1] + 0.5f);
    }
}

Cube::~Cube(){

}
