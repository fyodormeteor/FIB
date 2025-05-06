#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent)
    : QLCDNumber(parent) {
    setZeroOddEvenColor();
}

MyLCDNumber::~MyLCDNumber() { }

void MyLCDNumber::displayOddEvenColor(int num) {
    display(num);
    if (num == 0) setStyleSheet("color: green;");
    else {
        if (num % 2 == 0)   setStyleSheet("color: blue;");
        else                setStyleSheet("color: red;");
    }
}

void MyLCDNumber::setZeroOddEvenColor() {
    displayOddEvenColor(0);
}