// MyGLWidget.h
#include "BL2GLWidget.h"
#include "./Model/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    void initializeGL();
    void paintGL();
    void creaBuffers();
    void carregaShaders();

    void keyPressEvent (QKeyEvent *event);
    GLuint projLoc;
    GLuint viewLoc;

    GLuint VAO_Homer;
    GLuint VAO_Terra;
  
  private:
    int printOglError(const char file[], int line, const char func[]);

    // Camera
    glm::vec3 centre_escena;
    float     radi_escena;
    void calcularCentreRadi(glm::vec3 min, glm::vec3 max);
    void updateCamera();
    void projectTransform(float FOV, float ra, float zn, float zf);
    void viewTransform(glm::vec3 OBS, glm::vec3 VRP, glm::vec3 UP);

    // Homer
    void modelTransformHomer();
    void creaBuffersHomer();
    Model homer;
    float rotacion = 0;

    // Terra
    void modelTransformTerra();
    void creaBuffersTerra();



    

};
