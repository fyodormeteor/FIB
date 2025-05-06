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

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / ample;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  update ();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  /*case : 
      ...
      break;
  */  

    case Qt::Key_K: {
        posFocus -= glm::vec3(0.1f, 0.0f, 0.0f);
        break;
    }
    case Qt::Key_L: {
        posFocus += glm::vec3(0.1f, 0.0f, 0.0f);
        break;
    }
    default: BL3GLWidget::keyPressEvent(event); break;
  }
  glUniform3f(posFocusLoc, posFocus.x, posFocus.y, posFocus.z);
  update();
}

void MyGLWidget::initializeGL() {
    BL3GLWidget::initializeGL();
    
    posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");
    colFocusLoc = glGetUniformLocation (program->programId(), "colorFocus");
    glUniform3f(posFocusLoc, posFocus.x, posFocus.y, posFocus.z);
    glUniform3f(colFocusLoc, 0.8f, 0.8f, 0.8f);

}

void MyGLWidget::iniMaterialTerra() {

    amb  = glm::vec3(0, 0, 0.2);
    diff = glm::vec3(0, 0, 0.8);
    spec = glm::vec3(0, 0, 1);
    shin = 100;
}