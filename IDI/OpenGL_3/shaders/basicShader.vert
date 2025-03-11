#version 330 core

in vec3 vertex;
in vec3 color;
out vec3 colorf;

uniform mat4 TG;

void main()  {
    colorf = color;
    gl_Position = TG * vec4(vertex, 1);
}
