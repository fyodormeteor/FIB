#version 330 core

in vec3 vertex;
in vec3 color;

uniform int porta;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec3 fcolor;

void main() {
    fcolor = color;
    if (porta == 1) fcolor = vec3(1.0,0.0,0.0);
    gl_Position = Proj * View * TG * vec4 (vertex, 1.0);
}
