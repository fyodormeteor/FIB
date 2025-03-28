#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <QKeyEvent>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();
    
  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ();

    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ();
 
    // resize - Es cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);  

    // key events QT
    virtual void keyPressEvent(QKeyEvent *e);

  private:
    void creaBuffers ();
    void carregaShaders ();

    void modelTransform();
    
    // attribute locations
    GLuint vertexLoc;
    GLuint colorLoc;
    GLuint transLoc;
    
    // Program
    QOpenGLShaderProgram *program; 

    GLuint VAO1;
    GLint ample, alt;

    // Posicio
    float posx = 0;
    float posy = 0;

    // Angle respecte z
    float angle = 0;

    // Escala
    float scl = 1.0;

    float spd = 0.1;
};