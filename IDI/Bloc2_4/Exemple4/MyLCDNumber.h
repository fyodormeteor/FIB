#include <QLCDNumber>

class MyLCDNumber: public QLCDNumber {
    Q_OBJECT
    public:
        MyLCDNumber(QWidget *parent);
        ~MyLCDNumber();
    public slots:
        void displayOddEvenColor(int num);
        void setZeroOddEvenColor();
    signals:

    private:
};