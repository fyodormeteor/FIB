// MyGLWidget.h
#include "BL2GLWidget.h"
#include "../ModelClass/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void creaBuffers();
    void carregaShaders();

    void keyPressEvent (QKeyEvent *event);
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
    void calcularCentreRadi(glm::vec3 min, glm::vec3 max);
    void updateCamera();
    void projectTransform(float FOV, float ra, float zn, float zf);
    void projectTransformOrto(float l, float r, float b, float t, float zn, float zf);
    void viewTransform(glm::vec3 OBS, glm::vec3 VRP, glm::vec3 UP);

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
};
