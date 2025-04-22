#include <QLabel>

class MyLabel: public QLabel
{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        ~MyLabel();
    public slots:
        void changeToRed();
        void changeToBlue();
};