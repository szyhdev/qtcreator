#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) :
        QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    // case 1
    // qDebug() << tr("MyLineEdit keyPressEvent");

    // case 2
    // qDebug() << tr("MyLineEdit keyPressEvent");
    // QLineEdit::keyPressEvent(event);

    // case 3
    qDebug() << tr("MyLineEdit keyPressEvent");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
