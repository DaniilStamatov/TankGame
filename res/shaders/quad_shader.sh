#shader vertex
#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;
out vec4 vColor;
uniform vec4 u_color;
uniform mat4 u_transform;
uniform mat4 u_viewProj;
void main() {
    vColor = u_color;
    gl_Position = u_viewProj *  u_transform * vec4(aPosition, 1.0);
}

#shader fragment
#version 330 core
in vec4 vColor;
out vec4 FragColor;
void main() {
    FragColor = vColor;
}