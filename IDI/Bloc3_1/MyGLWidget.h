// MyGLWidget.h
#include "BL3GLWidget.h"

class MyGLWidget : public BL3GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL3GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent* event);

    void initializeGL();
    void iniMaterialTerra();

    // focus (llum) uniform locations
    GLuint posFocusLoc, colFocusLoc;

    glm::vec3 posFocus = glm::vec3(1.0f, 0.0f, 1.0f);

  private:
    int printOglError(const char file[], int line, const char func[]);
};
