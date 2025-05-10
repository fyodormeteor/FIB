#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent) {
    actualitzar();
    setFocus();
}

MyLabel::~MyLabel() { }

void MyLabel::keyPressEvent(QKeyEvent *event) {    
    if (event->modifiers() & (Qt::AltModifier)) {
        if (event->key() == Qt::Key_R) {
            estatInicial();
        } else
        if (event->key() == Qt::Key_S) {
            emit sortir();
        }
    } else {
        switch (event->key()) {
            case Qt::Key_1: emit setN(1); break;
            case Qt::Key_2: emit setN(2); break;
            case Qt::Key_3: emit setN(3); break;
            case Qt::Key_4: emit setN(4); break;
            case Qt::Key_5: emit setN(5); break;

            case Qt::Key_E: emit encriptar(); break;
            case Qt::Key_D: emit desencriptar(); break;

            default: QLabel::keyPressEvent(event); break;
        }
    }
}

void MyLabel::toggleEncriptacio() {
    encriptacio = true;
    actualitzar();
}

void MyLabel::toggleDesencriptacio() {
    encriptacio = false;
    actualitzar();
}

void MyLabel::textCanviat(QString newtext) {
    text = newtext;
    actualitzar();
}

void MyLabel::nCanviat(int newn) {
    n = newn;
    actualitzar();
}

void MyLabel::actualitzar() {
    std::string treatedtext = text.toStdString();

    // Encriptacio / desencriptacio
    for (int i = 0; i < int(treatedtext.length()); i++) {
        if (encriptacio)
            treatedtext[i] = int(treatedtext[i]) + n;
        else
            treatedtext[i] = int(treatedtext[i]) - n;
    }

    setText(QString::fromStdString(treatedtext));
}

void MyLabel::estatInicial() {
    emit reset(1);
    setFocus();
}