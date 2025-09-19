#pragma once
#include <glad/glad.h>
#include "../IndexBuffer.h"

namespace nova {
class OpenGLIndexBuffer final : public IndexBuffer
{
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        virtual ~OpenGLIndexBuffer();
        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual uint32_t GetCount() const override { return m_count; }
    private:
        GLuint m_id;
        uint32_t m_count;
};
}