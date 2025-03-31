// MyGLWidget.cpp
#include "MyGLWidget.h"
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

    modelTransformModelo();
    glBindVertexArray (VAO_Modelo);
    glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);
    glBindVertexArray(0);
}

void MyGLWidget::resizeGL(int width, int height) {
    BL2GLWidget::resizeGL(width,height);
    relacio_aspecte = float(width)/float(height);
    updateCamera();
}

void MyGLWidget::creaBuffers() {
    creaBuffersModelo();
    creaBuffersTerra();
}

void MyGLWidget::creaBuffersModelo() {
    m.load("../Models/Patricio.obj");

    // iterar sobre cada vertice y determinar m_min y m_max
    for (unsigned int i = 0; i < m.vertices().size(); i+=3) {
        m_min.x = std::min(m_min.x, float(m.vertices()[i]));
        m_min.y = std::min(m_min.y, float(m.vertices()[i+1]));
        m_min.z = std::min(m_min.z, float(m.vertices()[i+2]));
        
        m_max.x = std::max(m_max.x, float(m.vertices()[i]));
        m_max.y = std::max(m_max.y, float(m.vertices()[i+1]));
        m_max.z = std::max(m_max.z, float(m.vertices()[i+2]));
    }

    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Modelo);
    glBindVertexArray(VAO_Modelo);

    GLuint VBO_Modelo[2];
    auto buffersize = sizeof(GLfloat)*m.faces().size()*3*3;
    glGenBuffers(2, VBO_Modelo);

    // Buffer vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Modelo[0]);
    glBufferData(GL_ARRAY_BUFFER, buffersize, m.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);  
    glEnableVertexAttribArray(vertexLoc);

    // Buffer color
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Modelo[1]);
    glBufferData(GL_ARRAY_BUFFER, buffersize, m.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray(0);
}

void MyGLWidget::creaBuffersTerra() {
    
    glm::vec3 vertices[6] = {
        glm::vec3(-2.5f,0.0f,-2.5f),
        glm::vec3( 2.5f,0.0f,-2.5f),
        glm::vec3(-2.5f,0.0f, 2.5f),

        glm::vec3( 2.5f,0.0f, 2.5f),
        glm::vec3( 2.5f,0.0f,-2.5f),
        glm::vec3(-2.5f,0.0f, 2.5f)
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

void MyGLWidget::modelTransformModelo() 
{
    // Cálculo de escala tal que altura modelo sea 4
    float escala_modelo = 4.0f / (m_max.y - m_min.y);
    
    // Cálculo de x y z central
    float x_centro = (m_min.x + m_max.x)/2.0f;
    float z_centro = (m_min.z + m_max.z)/2.0f;
    
    glm::mat4 TG(1.0f);
    TG = glm::rotate(TG, glm::radians(rotacion), glm::vec3(0.0f, 1.0f, 0.0f));
    TG = glm::scale(TG, glm::vec3(escala*escala_modelo));
    // traslado modelo a y = 0
    TG = glm::translate(TG, glm::vec3(-x_centro, -m_min.y, -z_centro));
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
        case Qt::Key_O: {
            ortogonal = !ortogonal;
            updateCamera();
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

void MyGLWidget::projectTransformOrto(float l, float r, float b, float t, float zn, float zf) {
    glm::mat4 Proj = glm::ortho(l, r, b, t, zn, zf);
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
    
    calcularCentreRadi(glm::vec3(-2.5f,0.0f,-2.5f), glm::vec3(2.5f, 4.0f, 2.5f));

    float d = radi_escena * 2;
    auto VRP = centre_escena;
    auto OBS = VRP + d*glm::vec3(0,0,1);
    auto UP  = glm::vec3(0,1,0);
    viewTransform(OBS, VRP, UP);

    float z_near = d - radi_escena;
    float z_far  = d + radi_escena;
    if (ortogonal) {
        float w = radi_escena;
        float h = radi_escena;
        if (relacio_aspecte > 1) {
            w = relacio_aspecte * w;
        } else if (relacio_aspecte < 1) {
            h = h / relacio_aspecte;
        }
        
        projectTransformOrto(-w, w, -h, h, z_near, z_far);
    } else {
        float alpha = glm::asin(radi_escena/d);
        if (relacio_aspecte < 1) {
            alpha = glm::atan(glm::tan(alpha)/relacio_aspecte);
        }
        float fov = 2*alpha;

        projectTransform(fov, relacio_aspecte, z_near, z_far);
    }
}




