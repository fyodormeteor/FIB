#include <QLabel>

class MyLabel: public QLabel
{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        ~MyLabel();
    public slots:
        void actualitzarText(QString text);
        void actualitzarTrunc(int trunc);
    signals:

    private:
        QString _text;
        int _trunc;
};