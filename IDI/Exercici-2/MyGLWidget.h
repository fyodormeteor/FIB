#include "LL2GLWidget.h"
#include <vector>
#include <QTimer>

class MyGLWidget : public LL2GLWidget {
    Q_OBJECT

    public:
        MyGLWidget(QWidget *parent);
        ~MyGLWidget();

    protected:
        virtual void keyPressEvent (QKeyEvent *event);
        // per al moviment automàtic
        QTimer timer;

        void paintGL();

        void mouseMoveEvent(QMouseEvent *event);

        void iniEscena();
        void iniCamera();

        void viewTransform();
        void projectTransform();

        void modelTransformTerra();
        void modelTransformRick(glm::vec3 pos);
        void modelTransformVideoCam();
        void modelTransformParet(glm::vec3 pos);
        void modelTransformPorta();
        
        // Uniform locations
        GLuint portaLoc;

        // Camara
        glm::vec3 VRP;
        float d;
        float psi;
        float theta;

    public slots:
        void updatePosition();

    private:
        int printOglError(const char file[], int line, const char func[]);
        // Aquí tots els atributs privats que necessitis

        // Interaccion Rick
        bool rickMirandoHaciaXPositivo;
        bool movimientoAutomatico;

        // Interaccion Camara
        bool videocamaraActiva;
};
