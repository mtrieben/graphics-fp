#include "VoronoiEdge.h"
#include <iostream>

VoronoiEdge::VoronoiEdge()
{

}

VoronoiEdge::VoronoiEdge(float x0, float y0, float x1, float y1, int width){
    generateVertices(x0, y0, x1, y1, width);
    //generateTriangles(baseVertices);
    //();
}



void VoronoiEdge::generateVertices(float x0, float y0, float x1, float y1, int width){
//    int cutoff = 100;
//    x0 = std::min(std::max(x0,-cutoff),cutoff);
//    y0(std::max(y0,-cutoff),cutoff); = std::min
//    x1 = std::min(std::max(x1,-cutoff),cutoff);
//    y1 = std::min(std::max(y1,-cutoff),cutoff);
    glm::vec3 right0;
    glm::vec3 left0;
    glm::vec3 right1;
    glm::vec3 left1;

    glm::vec3 start = glm::vec3((float)x0,(float)y0,0.f);
    glm::vec3 end = glm::vec3((float)x1,(float)y1,0.f);

    float slope = ((float)y1-y0) /((float)x1-x0);
    if(slope <= 0.05f && slope >= -0.05f){
        left0 = glm::vec3(start[0], start[1]-(width/2.f), 0.f);
        left1 = glm::vec3(end[0], end[1]-(width/2.f), 0.f);
        right0 = glm::vec3(start[0], start[1]+(width/2.f), 0.f);
        right1 = glm::vec3(end[0], end[1]+(width/2.f), 0.f);

    }else{

        float slope2 = -1.f / slope;
        glm::vec3 v = glm::normalize(glm::vec3(1.f, slope2,0.f));
        if(slope2 < 0){
            right0 = start + (width/2.f)*v;
            right1 = end + (width/2.f)*v;
            left0 = start - (width/2.f)*v;
            left1 = end - (width/2.f)*v;
        }else{
            right0 = start - (width/2.f)*v;
            right1 = end - (width/2.f)*v;
            left0 = start + (width/2.f)*v;
            left1 = end + (width/2.f)*v;
        }
    }

    left0[2] = 0.001f;
    right0[2] = 0.001f;
    left1[2] = 0.001f;
    right1[2] = 0.001f;
    std::cout << left0[0] << ", " << left0[1] << ", " << left1[0] << ", " << left1[1] << std::endl;

    glm::vec3 normal = glm::vec3(0,0,1);
    this->addToVector(left0);
    this->addToVector(normal);
    this->addToVector(right1);
    this->addToVector(normal);
    this->addToVector(left1);
    this->addToVector(normal);

    this->addToVector(left0);
    this->addToVector(normal);
    this->addToVector(right0);
    this->addToVector(normal);
    this->addToVector(right1);
    this->addToVector(normal);

    this->addToVector(left0);
    this->addToVector(normal);
    this->addToVector(left1);
    this->addToVector(normal);
    this->addToVector(right1);
    this->addToVector(normal);

    this->addToVector(left0);
    this->addToVector(normal);
    this->addToVector(right1);
    this->addToVector(normal);
    this->addToVector(right0);
    this->addToVector(normal);

}

std::vector<GLfloat> VoronoiEdge::getVertexData(){
    return m_vertexData;
}

void VoronoiEdge::addToVector(glm::vec3 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
    m_vertexData.push_back(vec[2]);
}
