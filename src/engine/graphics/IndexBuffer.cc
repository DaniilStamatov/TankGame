#include "IndexBuffer.h"


namespace nova {
    std::unique_ptr<IndexBuffer> CreateOpenGLIndexBuffer(uint32_t* indices, uint32_t count);
}

namespace nova {
std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t *indices, uint32_t count)
{
    return CreateOpenGLIndexBuffer(indices, count);
}
}
