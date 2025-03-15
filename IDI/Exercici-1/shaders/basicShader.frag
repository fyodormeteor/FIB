#version 330 core

out vec4 FragColor;
in vec4 vertex_color;
in vec4 gl_FragCoord;

uniform bool es_base;

void main() {
    FragColor = vertex_color;
    
    if (es_base) {
        int x = int(gl_FragCoord.x);
        int y = int(gl_FragCoord.y);

        if (((x%10) < 5) && ((y%10) < 5)) discard;
    }
}

