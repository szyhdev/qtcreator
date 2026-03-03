#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPainterPath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    // QPainterPath
    QPainter painter(this);
    QPainterPath path;
    path.addEllipse(30, 70, 100, 100);
    path.addRect(80, 120, 100, 100);
    painter.setBrush(Qt::cyan);
    painter.drawPath(path);

    painter.translate(180, 0);
    path.setFillRule(Qt::WindingFill);
    painter.drawPath(path);
}
