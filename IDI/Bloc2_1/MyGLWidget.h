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
    void modelTransform();
    void keyPressEvent (QKeyEvent *event);
    GLuint projLoc;
    GLuint viewLoc;

    GLuint VAO_Homer;
  
  private:
    int printOglError(const char file[], int line, const char func[]);

    void projectTransform();
    void viewTransform();

    void creaBuffersHomer();
    Model homer;
    float rotacion;
    
};
