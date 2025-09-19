#include "OpenGLTexture.h"
#include <stb_image.h>
namespace nova {
    std::shared_ptr<Texture> CreateOpenGLTexture(const std::string& path) {
        return std::make_shared<OpenGLTexture>(path);
    }  

     std::shared_ptr<Texture> CreateOpenGLTexture(const TextureSpecification& spec) {
        return std::make_shared<OpenGLTexture>(spec);
    }  

    OpenGLTexture::OpenGLTexture(const std::string& path) {
        int height, width, channels; 
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    }
    OpenGLTexture::OpenGLTexture(const TextureSpecification &spec)
    {
    }
    OpenGLTexture::~OpenGLTexture()
    {
    }
    void OpenGLTexture::Bind(uint32_t slot) const
    {
    }
    void OpenGLTexture::Unbind() const
    {
    }
}