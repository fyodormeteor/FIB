#include <QLabel>
#include <QKeyEvent>

class MyLabel: public QLabel
{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        ~MyLabel();
    protected:
        void keyPressEvent(QKeyEvent *event) override;
    public slots:
        void toggleEncriptacio();
        void toggleDesencriptacio();
        void textCanviat(QString newtext);
        void nCanviat(int newn);
        void estatInicial();
    signals:
        void encriptar();
        void desencriptar();
        void setN(int n);
        void sortir();
        void reset(int a); // "a" siempre igual a 1 (para poner el spinbox y slider a 1)
    private:
        bool encriptacio = true;
        QString text = "";
        int n = 1;

        void actualitzar();
};