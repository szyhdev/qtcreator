#include "widget.h"
#include "ui_widget.h"
#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);
    lineEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug() << tr("Widget keyPressEvent");
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit) {
        if (event->type() == QEvent::KeyPress) {
            qDebug() << tr("Widget eventFilter");
        }
    }

    return QWidget::eventFilter(obj, event);
}
