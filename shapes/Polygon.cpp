#include "Polygon.h"
#include <iostream>

Polygon::Polygon()
{

}

Polygon::Polygon(glm::vec2 l, glm::vec2 r, glm::vec2 t, float height){
    std::vector<glm::vec3> base1;
    base1.push_back(glm::vec3(l.x, l.y, 0.01f));
    base1.push_back(glm::vec3(r.x, r.y, 0.01f));
    base1.push_back(glm::vec3(t.x, t.y, 0.01f));
    base1.push_back(glm::vec3(l.x, l.y, 0.01f));


    std::vector<glm::vec3> base2;
    base2.push_back(glm::vec3(l.x, l.y, height+0.01f));
    base2.push_back(glm::vec3(r.x, r.y, height+0.01f));
    base2.push_back(glm::vec3(t.x, t.y, height+0.01f));
    base2.push_back(glm::vec3(l.x, l.y, height+0.01f));

    generatePoints(base1, base2, 3, 0);

    glm::vec3 normal = glm::vec3(0.f,0.f,-1.f);
    glm::vec2 uv = glm::vec2(0.f,0.f);
    addToVector(base1[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[3]);
    addToVector(normal);
    addToVector(uv);


    normal[2] = 1.f;

    addToVector(base2[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[3]);
    addToVector(normal);
    addToVector(uv);

}

Polygon::Polygon(glm::vec2 l0 , glm::vec2 l1 , glm::vec2 r0, glm::vec2 r1, float height){
    std::vector<glm::vec3> base1;
    base1.push_back(glm::vec3(l0.x, l0.y, 0.01f));
    base1.push_back(glm::vec3(l1.x, l1.y, 0.01f));
    base1.push_back(glm::vec3(r1.x, r1.y, 0.01f));
    base1.push_back(glm::vec3(r0.x, r0.y, 0.01f));
    base1.push_back(glm::vec3(l0.x, l0.y, 0.01f));

    std::vector<glm::vec3> base2;
    base2.push_back(glm::vec3(l0.x, l0.y, height+0.01f));
    base2.push_back(glm::vec3(l1.x, l1.y, height+0.01f));
    base2.push_back(glm::vec3(r1.x, r1.y, height+0.01f));
    base2.push_back(glm::vec3(r0.x, r0.y, height+0.01f));
    base2.push_back(glm::vec3(l0.x, l0.y, height+0.01f));

    generatePoints(base1, base2, 4, 0);

    glm::vec3 normal = glm::vec3(0.f,0.f,-1.f);
    glm::vec2 uv = glm::vec2(0.f,0.f);

    addToVector(base1[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[2]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base1[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[3]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[4]);
    addToVector(normal);
    addToVector(uv);

    normal[2] = 1.f;

    addToVector(base2[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[2]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base2[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[3]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[4]);
    addToVector(normal);
    addToVector(uv);

}

Polygon::Polygon(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d, glm::vec2 e, float height){

    std::vector<glm::vec3> base1;
    base1.push_back(glm::vec3(a.x, a.y, 0.01f));
    base1.push_back(glm::vec3(b.x, b.y, 0.01f));
    base1.push_back(glm::vec3(c.x, c.y, 0.01f));
    base1.push_back(glm::vec3(d.x, d.y, 0.01f));
    base1.push_back(glm::vec3(e.x, e.y, 0.01f));
    base1.push_back(glm::vec3(a.x, a.y, 0.01f));


    std::vector<glm::vec3> base2;
    base2.push_back(glm::vec3(a.x, a.y, height+0.01f));
    base2.push_back(glm::vec3(b.x, b.y, height+0.01f));
    base2.push_back(glm::vec3(c.x, c.y, height+0.01f));
    base2.push_back(glm::vec3(d.x, d.y, height+0.01f));
    base2.push_back(glm::vec3(e.x, e.y, height+0.01f));
    base2.push_back(glm::vec3(a.x, a.y, height+0.01f));


    generatePoints(base1, base2, 5, 0);

    glm::vec3 normal = glm::vec3(0.f,0.f,-1.f);
    glm::vec2 uv = glm::vec2(0.f,0.f);
    addToVector(base1[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[2]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base1[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[3]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base1[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[3]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base1[4]);
    addToVector(normal);
    addToVector(uv);

    normal[2] = 1.f;

    addToVector(base2[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[1]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[2]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base2[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[2]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[3]);
    addToVector(normal);
    addToVector(uv);

    addToVector(base2[0]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[3]);
    addToVector(normal);
    addToVector(uv);
    addToVector(base2[4]);
    addToVector(normal);
    addToVector(uv);

}

void Polygon::generatePoints(std::vector<glm::vec3> base1, std::vector<glm::vec3> base2, int m_param2, float y){
        for(int i = 0; i < base1.size()-1; i++){
          //  float theta_i = ((2.0*M_PI)/m_param2)*(i-1);
          //  float theta_i1 = ((2.0*M_PI)/m_param2)*(i);
            glm::vec3 norm1 = surfaceNormal(base1[i],base1[i+1], base2[i+1]);
            addToVector(base1[i]);
            addToVector(norm1);
            addToVector(glm::vec2(0.f,1.f));
           //addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));

            addToVector(base1[i+1]);
            addToVector(norm1);
            addToVector(glm::vec2(1.f,1.f));

        //   addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));

            addToVector(base2[i+1]);
           addToVector(norm1);
           addToVector(glm::vec2(1.f,0.f));

        //  addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));

            glm::vec3 norm2 = surfaceNormal(base1[i],base2[i+1], base2[i]);

            addToVector(base1[i]);
            addToVector(norm2);
            addToVector(glm::vec2(0.f,1.f));

          //  addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));

            addToVector(base2[i+1]);
            addToVector(norm2);
            addToVector(glm::vec2(1.f,0.f));

           // addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));

            addToVector(base2[i]);
            addToVector(norm2);
            addToVector(glm::vec2(0.f,0.f));

         //   addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));
        }

}

std::vector<GLfloat> Polygon::getVertexData(){
    return m_vertexData;
}

void Polygon::addToVector(glm::vec3 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
    m_vertexData.push_back(vec[2]);
}

void Polygon::addToVector(glm::vec2 vec){
    m_vertexData.push_back(vec[0]);
    m_vertexData.push_back(vec[1]);
}

glm::vec3 Polygon::surfaceNormal(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3){
    glm::vec3 V1 = p2-p1;
    glm::vec3 V2 = p2-p3;
    glm::vec3 surfaceNormal;
    surfaceNormal.x = V1.y * V2.z - V1.z * V2.y;
    surfaceNormal.y = V1.z * V2.x - V1.x * V2.z;
    surfaceNormal.z = V1.x * V2.y - V1.y * V2.x;
    return glm::normalize(surfaceNormal);

}
