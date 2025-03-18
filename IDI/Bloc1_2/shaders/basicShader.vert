#version 330 core

in vec3 vertex;
in vec3 color;
out vec3 colorf;

void main()  {
    colorf = color;
    gl_Position = vec4 (vertex*0.5, 1);
}
