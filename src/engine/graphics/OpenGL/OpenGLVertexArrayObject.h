#pragma once
#include "../VertexArrayObject.h"

namespace nova {
    class OpenGLVertexArrayObject final : public VertexArrayObject {  
        public:
            OpenGLVertexArrayObject();
            virtual ~OpenGLVertexArrayObject();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
            virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_vertexBuffers; }
            virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return m_indexBuffer; }

        private:
            GLuint m_id;
            std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
            std::shared_ptr<IndexBuffer> m_indexBuffer;
            uint32_t m_VertexBufferIndex = 0;
    };
}