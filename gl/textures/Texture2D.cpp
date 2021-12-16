#include "Texture2D.h"
#include <iostream>

#include <utility>

namespace CS123 { namespace GL {

Texture2D::Texture2D(unsigned char *data, int width, int height, GLenum type)
{
    m_texture_id = 0;
    GLenum internalFormat = type == GL_FLOAT ? GL_RGBA32F : GL_RGBA;

    // TODO [Task 2]
    // Bind the texture by calling bind() and filling it in
    bind();
    //glGenTextures(1, &m_handle);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // Generate the texture with glTexImage2D
    glBindTexture(GL_TEXTURE_2D, m_handle);
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);




    // TODO Don't forget to unbind!
    unbind();

}

GLuint Texture2D::getTextureId1(){
    return m_handle;
}



void Texture2D::bind() const {
    // TODO [Task 2]

//    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBindTexture(GL_TEXTURE_2D, m_handle);
}

void Texture2D::unbind() const {
//    glBindTexture(GL_TEXTURE_2D, 0);
    // TODO Don't forget to unbind!
   // glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

}

}}
