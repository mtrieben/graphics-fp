#include "Shape.h"
#include <cmath>
#include <iostream>

Shape::Shape()
{

}

void Shape::setVertexData(std::vector<GLfloat> data){
    m_vertexData = data;
    initializeOpenGLShapeProperties();
}

std::vector<GLfloat> Shape::getVertexData(){
    return m_vertexData;
}

// Method that adds a vector to m_vertexData
void Shape::addToVector(glm::vec3 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
    m_vertexData.push_back(vec[2]);
}

void Shape::addToVector(glm::vec2 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
}

// Method used in finding t for implicit intersection
float Shape::quadratic(float a, float b, float c, int sign){
    if((b*b)-(4.f*a*c) < 0){
        return -1;
    }
    else{
        return (-b + (sign*sqrt((b*b)-(4.f*a*c)))) / (2.f*a);
    }
}

// Intersection for cone/cube/cylinder planes
float Shape::capIntersection(glm::vec3 norm, glm::vec3 coord, glm::vec3 d, glm::vec3 p){
    if(abs(glm::dot(norm, d)) < 0.01){
        return -1;
    }
    return (glm::dot(norm, coord) - glm::dot(norm, p)) / glm::dot(norm,d);
}

Shape::~Shape()
{

}

