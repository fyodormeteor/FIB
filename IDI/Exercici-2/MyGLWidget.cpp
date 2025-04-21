#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

MyGLWidget::MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {
    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
}

int MyGLWidget::printOglError(const char file[], int line, const char func[]) {
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

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
    makeCurrent();
    switch (event->key()) {
        case Qt::Key_Up: { 
            if (movimientoAutomatico) break;

            if (posRick.x < 5.5f) {
                posRick.x += 0.25;
                rickMirandoHaciaXPositivo = true;
                if (videocamaraActiva) viewTransform(); // VRP (posRick) se ha actualizado
            }
            break;
        }
        case Qt::Key_Down: { 
            if (movimientoAutomatico) break;

            if (posRick.x > -5.5f) {
                posRick.x -= 0.25;
                rickMirandoHaciaXPositivo = false;
                if (videocamaraActiva) viewTransform(); // VRP (posRick) se ha actualizado
            }
            break;
        }           
        case Qt::Key_C: { 
            videocamaraActiva = !videocamaraActiva;
            viewTransform();
            projectTransform();
            break;
        }           
        case Qt::Key_A: { 
            movimientoAutomatico = !movimientoAutomatico;
            if (movimientoAutomatico) timer.start(100);
            else timer.stop();
            break;
        }  
        case Qt::Key_R: { 
            videocamaraActiva = false;
            movimientoAutomatico = false;
            timer.stop();
            psi = 45.0f;
            theta = 45.0f;
            posRick = glm::vec3(-5.0f, 0.0f, 0.0f);
            rickMirandoHaciaXPositivo = true;

            viewTransform();
            projectTransform();
            break;
        }  
        default: event->ignore(); break;
    }
    update();
}

void MyGLWidget::updatePosition() {
    makeCurrent();
    
    if (rickMirandoHaciaXPositivo) {
        posRick.x += 0.25f;
        if (posRick.x >= 5.5f) rickMirandoHaciaXPositivo = false;
    } else {
        posRick.x -= 0.25f;
        if (posRick.x <= -5.5f) rickMirandoHaciaXPositivo = true;
    }

    if (videocamaraActiva) viewTransform();

    update();
}

void MyGLWidget::paintGL()
{
    // descomentar per canviar paràmetres
    // glViewport (0, 0, ample, alt);

    // Esborrem el frame-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Rick
    glBindVertexArray (VAO_Rick);
    modelTransformRick (posRick);
    glDrawArrays(GL_TRIANGLES, 0, rick.faces().size()*3);

    // Video Camera
    if (!videocamaraActiva) {
        glBindVertexArray (VAO_VideoCam);
        modelTransformVideoCam ();
        glDrawArrays(GL_TRIANGLES, 0, videoCam.faces().size()*3);
    }

    // Paredes
    glBindVertexArray (VAO_Cub);
    modelTransformParet(glm::vec3(0.0f, 0.0f, -2.5f)); // Primera pared en 0,0,-2.5
    glDrawArrays(GL_TRIANGLES, 0, 36);
    modelTransformParet(glm::vec3(0.0f, 0.0f,  2.5f)); // Segunda pared en 0,0,2.5
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // Puerta
    modelTransformPorta();
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Terra
    glBindVertexArray (VAO_Terra);
    modelTransformTerra ();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindVertexArray (0);
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (videocamaraActiva) return; // No actualizamos ang.Euler cuando en modo videocam
    
    makeCurrent();

    int xCurrent = e->x();
    int yCurrent = e->y();

    psi -= (xCurrent - xClick) * glm::degrees(factorAngleY);
    theta += (yCurrent - yClick) * glm::degrees(factorAngleX);

    xClick = xCurrent;
    yClick = yCurrent;

    viewTransform();
    update();
}

void MyGLWidget::iniEscena() {
    // Posicion inicial del Rick es (-5, 0, 0)
    posRick = glm::vec3(-5.0f, 0.0f, 0.0f);

    rickMirandoHaciaXPositivo = true;
    movimientoAutomatico = false;

    // Uniforms adicionales
    portaLoc = glGetUniformLocation(program->programId(), "porta");
}

void MyGLWidget::iniCamera() {
    videocamaraActiva = false;

    psi = 45.0f;
    theta = 45.0f;
    
    radiEscena = glm::distance(glm::vec3(0.0f,1.25f,0.0f), glm::vec3(6.0f,2.5f,4.0f));
    VRP = glm::vec3(0.0f, 1.25f, 0.0f);
    d = 2.0f*radiEscena;
    viewTransform();
}

void MyGLWidget::viewTransform()
{
    glm::mat4 View(1.0f);
    
    if (videocamaraActiva) {
        View = glm::lookAt(glm::vec3(0.0f,2.25f,-1.0f), posRick, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
        return;
    }
    
    // Con angulos de euler
    View = glm::translate(View, glm::vec3(0.0f,0.0f,-d));
    View = glm::rotate(View, glm::radians(theta), glm::vec3(1.0f,0.0f,0.0f));
    View = glm::rotate(View, glm::radians(-psi), glm::vec3(0.0f,1.0f,0.0f));
    View = glm::translate(View, -VRP);

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform()
{
    float z_near, z_far, alpha, fov;
    
    if (videocamaraActiva) {
        z_near = 0.1;
        z_far  = 10;
        alpha = 45;
    } else {
        z_near = d - radiEscena;
        z_far  = d + radiEscena;
        alpha = glm::asin(radiEscena/d);

        if (ra < 1) {
            alpha = glm::atan(glm::tan(alpha)/ra);
        }

    }

    fov = 2*alpha;
    
    glm::mat4 Proj(1.0f);
    Proj = glm::perspective(fov, ra, z_near, z_far);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::modelTransformTerra() {
    // Inicialmente 8x8 (X,Z)
    // Quieremos 12x8
    
    glm::mat4 TG(1.0f);
    TG = glm::scale(TG, glm::vec3(12.0f/8.0f, 1.0f, 1.0f));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(portaLoc, false); // es puerta? no
}

void MyGLWidget::modelTransformRick(glm::vec3 pos) {
    // Quieremos Rick con altura 1.5 (inicialmente 2.0)
    // Con centro base en pos y mirando hacia X+ o X-
    
    float escalaRickFinal = (1.5f/2.0f) * escalaRick;

    glm::mat4 TG(1.0f);
    TG = glm::translate(TG, pos);
    TG = glm::rotate(TG, glm::radians(-90.0f + 180.0f*rickMirandoHaciaXPositivo), glm::vec3(0.0f, 1.0f, 0.0f));
    TG = glm::scale(TG, glm::vec3(escalaRickFinal, escalaRickFinal, escalaRickFinal));
    TG = glm::translate(TG, -centreBaseRick);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(portaLoc, false); // es puerta? no
}

void MyGLWidget::modelTransformVideoCam()
{
    // Quieremos camara de altura 0.4 (inicialmente 1.0) con centro base en 0,2,-1
    // Primero rotar 30º sobre X y luego -80º sobre Y.
    
    glm::mat4 TG(1.0f);
    TG = glm::translate(TG, glm::vec3(0.0f,2.0f,-1.0f));
    TG = glm::rotate(TG, glm::radians(-80.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    TG = glm::rotate(TG, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    TG = glm::scale(TG, glm::vec3(0.4f*escalaVideoCam));
    TG = glm::translate(TG, -centreBaseVideoCam);
    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(portaLoc, false); // es puerta? no
}

void MyGLWidget::modelTransformParet(glm::vec3 pos) {
    // Pared de tamaño 0.5x2.0x3.0 con centro base en pos

    glm::mat4 TG(1.0f);
    TG = glm::translate(TG, pos);
    TG = glm::scale(TG, glm::vec3(0.5f, 2.0f, 3.0f));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(portaLoc, false); // es puerta? no
}

void MyGLWidget::modelTransformPorta() {
    // Puerta de tamaño 0.25x1.9x2.0 con centro base en 0,0,0
    // posPortaZ = 2-abs(posRickX), si posRickX esta entre -2 y 2

    glm::mat4 TG(1.0f);
    if (abs(posRick.x) <= 2.0f) {
        float posPortaZ = 2-abs(posRick.x);
        TG = glm::translate(TG, glm::vec3(0.0f, 0.0f, posPortaZ));
    }
    TG = glm::scale(TG, glm::vec3(0.25f, 1.9f, 2.0f));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(portaLoc, true); // es puerta? si
}