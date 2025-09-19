#include "VertexArrayObject.h"

namespace nova {
    std::shared_ptr<VertexArrayObject> CreateOpenGLVertexArrayObject();
}

namespace nova {
    std::shared_ptr<VertexArrayObject> VertexArrayObject::Create()
    {
        return CreateOpenGLVertexArrayObject();
    }
}
