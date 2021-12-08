#include "BaseShape.h"
#include "CircleBase.h"
#include <math.h>

BaseShape::BaseShape() : Shape()
{
}

// Generates the triangles between two CircleBases for Cone and Cylinder (Sphere could not be inlcuded because its normals are different)
void BaseShape::generatePoints(std::vector<std::vector<glm::vec3>> baseVertices, int m_param2, float y){
    for(int base = 0; base < baseVertices.size()-1; base++){
        for(int i = 1; i < baseVertices[base].size()-1; i++){
            float theta_i = ((2.0*M_PI)/m_param2)*(i-1);
            float theta_i1 = ((2.0*M_PI)/m_param2)*(i);

            addToVector(baseVertices[base][i+1]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));

            addToVector(baseVertices[base][i]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));

            addToVector(baseVertices[base+1][i]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));

            addToVector(baseVertices[base][i+1]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));

            addToVector(baseVertices[base+1][i]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i), y, sin(theta_i))));

            addToVector(baseVertices[base+1][i+1]);
            addToVector(glm::normalize(glm::vec3(cos(theta_i1), y, sin(theta_i1))));
        }
    }
}

// function that tesselates a CircleBase based on the number of slices
void BaseShape::expandCircleBase(std::unique_ptr<CircleBase> b, int slices){
    std::vector<std::unique_ptr<CircleBase>> bases;
    std::vector<std::vector<glm::vec3>> baseVertices;
    // Generates smaller CircleBases for each slice
    baseVertices.push_back(b->getVertices());
    for (int i = 1; i < slices; i++){
        float radius = 0.5 - (0.5/slices)*i;
        bases.push_back(std::make_unique<CircleBase>(b->getParam2(), b->getSign(), b->getY(), radius));
        baseVertices.push_back(bases[i-1]->getVertices());
    }

    // Makes the triangles between two CircleBases
    glm::vec3 normal = glm::normalize(glm::vec3(0,b->getSign()*1,0));
    for(int base = 0; base < baseVertices.size()-1; base++){

        for(int i = 1; i < baseVertices[base].size()-1; i++){
            // Takes into account the two dirrections of tesselation for cylinder faces
            if (b->getSign() > 0){
                addToVector(baseVertices[base+1][i]);
                addToVector(normal);

                addToVector(baseVertices[base+1][i+1]);
                addToVector(normal);

                addToVector(baseVertices[base][i+1]);
                addToVector(normal);

                addToVector(baseVertices[base][i+1]);
                addToVector(normal);

                addToVector(baseVertices[base][i]);
                addToVector(normal);

                addToVector(baseVertices[base+1][i]);
                addToVector(normal);
            }
            else{
                addToVector(baseVertices[base+1][i+1]);
                addToVector(normal);

                addToVector(baseVertices[base+1][i]);
                addToVector(normal);

                addToVector(baseVertices[base][i]);
                addToVector(normal);

                addToVector(baseVertices[base][i]);
                addToVector(normal);

                addToVector(baseVertices[base][i+1]);
                addToVector(normal);

                addToVector(baseVertices[base+1][i+1]);
                addToVector(normal);
            }
        }
    }

    // Makes the innermost triangles between the smallest CircleBase and the center point
    glm::vec3 center = glm::vec3(0,b->getSign()*b->getY(),0);
    for(int i = 1; i < baseVertices[baseVertices.size()-1].size()-1;i++){
        addToVector(center);
        addToVector(normal);
        if(b->getSign() > 0){
            addToVector(baseVertices[baseVertices.size()-1][i+1]);
            addToVector(normal);
            addToVector(baseVertices[baseVertices.size()-1][i]);
            addToVector(normal);
        }
        else{
            addToVector(baseVertices[baseVertices.size()-1][i]);
            addToVector(normal);
            addToVector(baseVertices[baseVertices.size()-1][i+1]);
            addToVector(normal);
        }
    }
}

BaseShape::~BaseShape(){
}
