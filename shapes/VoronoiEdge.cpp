#include "VoronoiEdge.h"

VoronoiEdge::VoronoiEdge()
{

}

VoronoiEdge::VoronoiEdge(int x0, int y0, int x1, int y1, int width){
    generateVertices(x0, y0, x1, y1, width);
    //generateTriangles(baseVertices);
    //();
}



void VoronoiEdge::generateVertices(int x0, int y0, int x1, int y1, int width){
    float slope = ((float)y1-y0) /((float)x1-x0);
    glm::vec3 start = glm::vec3((float)x0,(float)y0,0.f);
    glm::vec3 end = glm::vec3((float)x1,(float)y1,0.f);
    float slope2 = -1.f / slope;
    glm::vec3 v = glm::normalize(glm::vec3(1.f, slope2,0.f));
    glm::vec3 right0;
    glm::vec3 left0;
    glm::vec3 right1;
    glm::vec3 left1;

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
    float cutoff = 200.f;
    left0[0] = std::min(std::max(left0[0],-cutoff),cutoff);
    right0[0] = std::min(std::max(right0[0],-cutoff),cutoff);
    left1[0] = std::min(std::max(left1[0],-cutoff),cutoff);
    right1[0] = std::min(std::max(right1[0],-cutoff),cutoff);

    left0[1] = std::min(std::max(left0[1],-cutoff),cutoff);
    right0[1] = std::min(std::max(right0[1],-cutoff),cutoff);
    left1[1] = std::min(std::max(left1[1],-cutoff),cutoff);
    right1[1] = std::min(std::max(right1[1],-cutoff),cutoff);


    left0[2] = 0.5f;
    right0[2] = 0.5f;
    left1[2] = 0.5f;
    right1[2] = 0.5f;
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
}

std::vector<GLfloat> VoronoiEdge::getVertexData(){
    return m_vertexData;
}

void VoronoiEdge::addToVector(glm::vec3 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
    m_vertexData.push_back(vec[2]);
}