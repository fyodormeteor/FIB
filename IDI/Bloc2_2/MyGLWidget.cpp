// MyGLWidget.cpp
#include "MyGLWidget.h"
#include "Model/model.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

void MyGLWidget::initializeGL() {
    //carregaShaders
    //carregaBuffers
    BL2GLWidget::initializeGL();

    updateCamera();

    CHECK();
}

void MyGLWidget::paintGL() {
    
    // Esborrem el frame-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    modelTransformTerra();
    glBindVertexArray (VAO_Terra);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    modelTransformHomer();
    glBindVertexArray (VAO_Homer);
    glDrawArrays(GL_TRIANGLES, 0, homer.faces().size()*3);
    glBindVertexArray(0);
}

void MyGLWidget::creaBuffers() {
    creaBuffersHomer();
    creaBuffersTerra();
}

void MyGLWidget::creaBuffersHomer() {
    homer.load("./HomerProves/HomerProves.obj");

    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Homer);
    glBindVertexArray(VAO_Homer);

    GLuint VBO_Homer[2];
    auto buffersize = sizeof(GLfloat)*homer.faces().size()*3*3;
    glGenBuffers(2, VBO_Homer);

    // Buffer vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[0]);
    glBufferData(GL_ARRAY_BUFFER, buffersize, homer.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);  
    glEnableVertexAttribArray(vertexLoc);

    // Buffer color
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[1]);
    glBufferData(GL_ARRAY_BUFFER, buffersize, homer.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray(0);
}

void MyGLWidget::creaBuffersTerra() {
    
    glm::vec3 vertices[6] = {
        glm::vec3(-2.0f,-1.0f,-2.0f),
        glm::vec3( 2.0f,-1.0f,-2.0f),
        glm::vec3(-2.0f,-1.0f, 2.0f),

        glm::vec3( 2.0f,-1.0f, 2.0f),
        glm::vec3( 2.0f,-1.0f,-2.0f),
        glm::vec3(-2.0f,-1.0f, 2.0f)
    };

    glm::vec3 colores[6] = {
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 1),
        glm::vec3(1, 0, 1)
    };
    
    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Terra);
    glBindVertexArray(VAO_Terra);

    GLuint VBO_Terra[2];
    glGenBuffers(2, VBO_Terra);

    // Buffer vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);  
    glEnableVertexAttribArray(vertexLoc);

    // Buffer color
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colores), colores, GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray(0);
}

void MyGLWidget::carregaShaders() {
    BL2GLWidget::carregaShaders();

    glEnable(GL_DEPTH_TEST);

    projLoc = glGetUniformLocation(program->programId(), "proj");
    viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::modelTransformHomer() 
{
    glm::mat4 TG(1.0f);
    TG = glm::rotate(TG, glm::radians(rotacion), glm::vec3(0.0f, 1.0f, 0.0f));
    TG = glm::scale(TG, glm::vec3(escala));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformTerra() 
{
    glm::mat4 TG(1.0f);
    TG = glm::scale(TG, glm::vec3(escala));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::keyPressEvent(QKeyEvent *event) {
    makeCurrent();
    switch (event->key()) {
        case Qt::Key_S: { // escalar a més gran
            escala += 0.05;
            break;
        }
        case Qt::Key_D: { // escalar a més petit
            escala -= 0.05;
            break;
        }
        case Qt::Key_R: {
            rotacion += 45;
            break;
        }
        default: event->ignore(); break;
    }
    update();
}

void MyGLWidget::projectTransform(float FOV, float ra, float zn, float zf) {
    // glm::perspective (FOV en radians, ra window, znear, zfar)
    // glm::mat4 Proj = glm::perspective(float(M_PI)/2.0f, 1.0f, 0.4f, 3.0f);
    glm::mat4 Proj = glm::perspective(FOV, ra, zn, zf);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform(glm::vec3 OBS, glm::vec3 VRP, glm::vec3 UP) {
    // glm::lookAt (OBS, VRP, UP)
    // glm::mat4 View = glm::lookAt(glm::vec3(0,0,1), glm::vec3(0,0,0), glm::vec3(0,1,0));
    glm::mat4 View = glm::lookAt(OBS, VRP, UP);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::calcularCentreRadi(glm::vec3 min, glm::vec3 max) {
    centre_escena = (min+max)/2.0f;
    radi_escena = glm::distance(centre_escena, max);
}

void MyGLWidget::updateCamera() {
    
    calcularCentreRadi(glm::vec3(-2.0f,-1.0f,-2.0f), glm::vec3(2.0f, 1.0f, 2.0f));

    float d = radi_escena * 2;

    auto VRP = centre_escena;
    auto OBS = VRP + d*glm::vec3(0,0,1);
    auto UP  = glm::vec3(0,1,0);

    viewTransform(OBS, VRP, UP);

    float z_near = d - radi_escena;
    float z_far  = d + radi_escena;
    float ra = 1;
    float fov = 2*glm::asin(radi_escena/d);

    projectTransform(fov, ra, z_near, z_far);
}




