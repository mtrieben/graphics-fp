#include "Texture2D.h"
#include <iostream>

#include <utility>

namespace CS123 { namespace GL {

Texture2D::Texture2D(unsigned char *data, int width, int height, GLenum type)
{
    GLenum internalFormat = type == GL_FLOAT ? GL_RGBA32F : GL_RGBA;

    // TODO [Task 2]
    // Bind the texture by calling bind() and filling it in
    bind();
    // Generate the texture with glTexImage2D
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, type, data);


    // TODO Don't forget to unbind!
    unbind();

}

void Texture2D::bind() const {
    // TODO [Task 2]
    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glBindBuffer(GL_TEXTURE_BUFFER, m_handle);
}

void Texture2D::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
    // TODO Don't forget to unbind!
    glBindBuffer(GL_TEXTURE_BUFFER, 0);
}

}}
