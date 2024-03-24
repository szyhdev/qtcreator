#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) :
        QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)  // 键盘按下事件
{
    // case 1
    // qDebug() << tr("MyLineEdit键盘按下事件");

    // case 2
    // qDebug() << tr("MyLineEdit键盘按下事件");
    // QLineEdit::keyPressEvent(event);         // 执行QLineEdit类的默认事件处理

    // case 3
    qDebug() << tr("MyLineEdit键盘按下事件");
    QLineEdit::keyPressEvent(event);         // 执行QLineEdit类的默认事件处理
    event->ignore();                         // 忽略该事件
}
