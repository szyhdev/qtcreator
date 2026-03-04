#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) :
        QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit keyPressEvent");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyLineEdit::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        qDebug() << tr("MyLineEdit event");
    }
    return QLineEdit::event(event);
}
