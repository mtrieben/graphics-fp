/**
 * @file   CamtransCamera.cpp
 *
 * This is the perspective camera class you will need to fill in for the Camtrans lab.  See the
 * lab handout for more details.
 */

#include "CamtransCamera.h"
#include <Settings.h>

CamtransCamera::CamtransCamera()
{
    m_far = 30.f;
    m_near = 1.0f;
    m_thetaH = 60.f;
    m_aspectRatio = 1.f;
    m_eye = glm::vec4(2.f, 2.f, 2.f, 1.f);
    m_w = glm::normalize(glm::vec4(2.0f, 2.0f, 2.0f, 0.0f));
    m_up = glm::vec4(0.f, 1.f, 0.f, 0.f);
}

void CamtransCamera::setAspectRatio(float a)
{
    m_aspectRatio = a;
    updateProjectionMatrix();
}

glm::mat4x4 CamtransCamera::getProjectionMatrix() const {
    return m_perspectiveTransformation*m_scaleMatrix;
}

glm::mat4x4 CamtransCamera::getViewMatrix() const {
    return m_rotationMatrix*m_translationMatrix;
}

glm::mat4x4 CamtransCamera::getScaleMatrix() const {
    return m_scaleMatrix;
}

glm::mat4x4 CamtransCamera::getPerspectiveMatrix() const {
    return m_perspectiveTransformation;
}

glm::vec4 CamtransCamera::getPosition() const {
    return m_eye;
}

glm::vec4 CamtransCamera::getLook() const {
    return -1.f * m_w;
}

glm::vec4 CamtransCamera::getU() const {
    return m_u;
}

glm::vec4 CamtransCamera::getV() const {
    return m_v;
}

glm::vec4 CamtransCamera::getW() const {
    return m_w;
}

glm::vec4 CamtransCamera::getUp() const {
    return m_up;
}

float CamtransCamera::getAspectRatio() const {
    return m_aspectRatio;
}

float CamtransCamera::getHeightAngle() const {
    return m_thetaH;
}

void CamtransCamera::orientLook(const glm::vec4 &eye, const glm::vec4 &look, const glm::vec4 &up) {
    m_eye = eye;
    m_up = up;
    glm::vec4 w = glm::normalize(-1.0f * look);
    glm::vec4 v = glm::normalize(up - glm::dot(up, w)*w);
    m_w = w;
    m_v = v;
    m_u = glm::vec4(glm::cross(glm::vec3(v), glm::vec3(w)), 0.0f);

    updateViewMatrix();
    updateProjectionMatrix();

}

void CamtransCamera::setHeightAngle(float h) {
    m_thetaH = h;
    updateProjectionMatrix();

}

void CamtransCamera::translate(const glm::vec4 &v) {
    m_eye += v;
    updateViewMatrix();

}

void CamtransCamera::rotateU(float degrees) {
    float radian = glm::radians(degrees);
    glm::vec4 v = m_v;
    m_v =  m_v * std::cos(radian) + m_w * std::sin(radian);
    m_w = v * -std::sin(radian) + m_w * std::cos(radian);
    updateViewMatrix();
}

void CamtransCamera::rotateV(float degrees) {
    float radian = glm::radians(degrees);
    glm::vec4 u = m_u;
    m_u = u * std::cos(radian) + m_w*-std::sin(radian);
    m_w = u * std::sin(radian) + m_w*std::cos(radian);
    updateViewMatrix();

}

void CamtransCamera::rotateW(float degrees) {
    float radian = glm::radians(degrees);
    glm::vec4 u = m_u;
    m_u = u * std::cos(radian) + m_v*std::sin(radian);
    m_v = u * -std::sin(radian) + m_v*std::cos(radian);
    updateViewMatrix();

}

void CamtransCamera::setClip(float nearPlane, float farPlane) {
    m_near = nearPlane;
    m_far = farPlane;
    updateProjectionMatrix();

}

void CamtransCamera::updateProjectionMatrix(){
    updatePerspectiveMatrix();
    updateScaleMatrix();

}
void CamtransCamera::updatePerspectiveMatrix(){
    float c = (-m_near) / m_far;
    m_perspectiveTransformation = glm::mat4(1.f, 0.f, 0.f, 0.f,
                                            0.f, 1.f, 0.f, 0.f,
                                            0.f, 0.f, -1.f / (1.f + c), -1.f,
                                            0.f, 0.f, (c) / (1.f + c), 0.f);

}
void CamtransCamera::updateScaleMatrix(){
    float h = m_far * std::tan(glm::radians(m_thetaH) / 2.f);
    float w = getAspectRatio() * h;
    m_scaleMatrix = glm::mat4(1.f / w, 0.f, 0.f, 0.f,
                       0.f, 1.f / h, 0.f, 0.f,
                        0.f, 0.f, 1/m_far, 0.f,
                        0.f, 0.f, 0.f, 1.f);
}
void CamtransCamera::updateViewMatrix(){
    updateTranslationMatrix();
    updateRotationMatrix();

}
void CamtransCamera::updateRotationMatrix(){
    m_rotationMatrix = glm::mat4(m_u[0], m_v[0], m_w[0], 0.f,
            m_u[1], m_v[1], m_w[1], 0.f,
            m_u[2], m_v[2], m_w[2], 0.f,
            0.f, 0.f, 0.f, 1.f);

}
void CamtransCamera::updateTranslationMatrix(){
    m_translationMatrix = glm::mat4(1.f, 0.f, 0.f, 0.f,
                                    0.f, 1.f, 0.f, 0.f,
                                    0.f, 0.f, 1.f, 0.f,
                                    -m_eye[0], -m_eye[1], -m_eye[2], 1.f);

}

