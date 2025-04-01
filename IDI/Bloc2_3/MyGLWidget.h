// MyGLWidget.h
#include "BL2GLWidget.h"
#include "../ModelClass/model.h"
#include <QTimer>

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  public slots:
    void animar();

  protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void creaBuffers();
    void carregaShaders();

    void keyPressEvent (QKeyEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    GLuint projLoc;
    GLuint viewLoc;

    GLuint VAO_Modelo;
    GLuint VAO_Terra;
  
  private:
    int printOglError(const char file[], int line, const char func[]);

    // Camera
    bool ortogonal = false;
    glm::vec3 centre_escena;
    float radi_escena;
    float relacio_aspecte = 1.0f;
    float zoom = 1.0f;
    void calcularCentreRadi(glm::vec3 min, glm::vec3 max);
    void updateCamera();
    void projectTransform(float FOV, float ra, float zn, float zf);
    void projectTransformOrto(float l, float r, float b, float t, float zn, float zf);
    void viewTransform(glm::vec3 VRP, float d, float psi, float theta);
      // Angles de euler
      float angle_y = 45;
      float angle_x = 45;
      // Posicio ratoli
      int mouse_x = 0;
      int mouse_y = 0;


    // Modelo
    void modelTransformModelo();
    void creaBuffersModelo();
    Model m;
    glm::vec3 m_min = glm::vec3(999.0f, 999.0f, 999.0f);
    glm::vec3 m_max = glm::vec3(-999.0f, -999.0f, -999.0f);
    float rotacion = 0;

    // Terra
    void modelTransformTerra();
    void creaBuffersTerra();

    // Timer
    QTimer timer;
};
