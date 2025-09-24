#shader vertex
#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;

uniform mat4 u_transform;
uniform mat4 u_viewProj;

out vec2 v_texCoord;

void main() {
    gl_Position = u_viewProj * u_transform * vec4(aPosition, 1.0);
    v_texCoord = aTexCoord;
}

#shader fragment 
#version 330 core
out vec4 FragColor;

in vec2 v_texCoord;

uniform sampler2D u_texture;
uniform vec4 u_texColor;
void main() {
    vec4 texColor = texture(u_texture, v_texCoord);
    FragColor = texColor * u_texColor;
}