#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMouseEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "model.h"


class LL2GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    LL2GLWidget (QWidget *parent=0);
    ~LL2GLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del context gràfic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - És cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    // mouse{Press/Release/Move}Event - Són cridades quan es realitza l'event
    // corresponent de ratolí
    virtual void mousePressEvent (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent (QMouseEvent *event);

    // iniEscena - Aqui incluim les inicialitzacions de l'escena
    virtual void iniEscena ();
    // iniCamera - Aqui incluim les inicialitzacions de la camera
    virtual void iniCamera ();    
    
    // viewTransform i projecTransform - Es fan servir per construir i enviar als shader les matrius de càmera (View i Projection respectivament).
    virtual void viewTransform ();
    virtual void projectTransform ();
    
    virtual void modelTransformRick (glm::vec3 pos);
    virtual void modelTransformVideoCam ();
    virtual void modelTransformTerra ();
    virtual void modelTransformCub ();

    // calculaCapsaModel - Calcula la capsa contenidora d'un Model p retornant el centre de la seva base a CentreBase, i el factor d'escala necessari per a que la seva alçada (y) sigui alçadaDesitjada.
    void calculaCapsaModel (Model &p, float &escala, float alcadaDesitjada, glm::vec3 &CentreBase);

    // creaBuffersTerra - Inicialitzem el VAO i els VBO d'un model fet a mà que representa un terra
    void creaBuffersTerra ();
    // creaBuffersCub - Inicialitzem el VAO i els VBO d'un model fet a mà que representa un cub
    void creaBuffersCub ();
    // creaBuffersModels - Carreguem els fitxers obj i fem la inicialització dels diferents VAOS i VBOs
    void creaBuffersModels ();
    // carregaShaders - Carreguem els shaders, els compilem i els linkem. També busquem els uniform locations que fem servir.
    void carregaShaders ();
    
    // attribute locations
    GLuint vertexLoc, colorLoc;

    // uniform locations
    GLuint transLoc, viewLoc, projLoc;

    // VAO names
    GLuint VAO_Rick, VAO_VideoCam;
    GLuint VAO_Terra, VAO_Cub;

    // Program
    QOpenGLShaderProgram *program;

    // Viewport
    GLint ample, alt;

    // Mouse interaction
    typedef  enum {NONE, ROTATE} InteractiveAction;
    InteractiveAction DoingInteractive;
    int xClick, yClick;
    float factorAngleX, factorAngleY;

    // Models, capses contenidores i escales
    Model rick, videoCam;
    glm::vec3 centreBaseRick, centreBaseVideoCam;
    float escalaRick, escalaVideoCam;        

    // Internal vars
    float radiEscena;
    float ra=1;

    // posició del Rick
    glm::vec3 posRick = glm::vec3(0,0,-3);
};

