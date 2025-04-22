#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent) {
        
}

MyLabel::~MyLabel() { }

void MyLabel::changeToRed() {
    setStyleSheet("background-color: red;");
}

void MyLabel::changeToBlue() {
    setStyleSheet("background-color: blue;");
}
