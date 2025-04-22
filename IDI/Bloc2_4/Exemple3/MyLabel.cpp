#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent) {
    _text = "Hola!";
}

MyLabel::~MyLabel() { }

void MyLabel::actualitzarText(QString text) {
    _text = text;
    QString newText = _text;
    newText.truncate(_trunc);
    setText(newText);
}

void MyLabel::actualitzarTrunc(int trunc) {
    _trunc = trunc;
    QString newText = _text;
    newText.truncate(_trunc);
    setText(newText);
} 
