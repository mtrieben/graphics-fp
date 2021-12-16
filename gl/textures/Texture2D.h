#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "Texture.h"

#include "GL/glew.h"

namespace CS123 { namespace GL {

class Texture2D : public Texture {
public:
    Texture2D(unsigned char *data1, int width, int height, GLenum type = GL_UNSIGNED_BYTE);

    virtual void bind() const override;
    virtual void unbind() const override;
    GLuint getTextureId1();


private:
    int m_texture_id;
};

}}

#endif // TEXTURE2D_H
