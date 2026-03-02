#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // window
    painter.setWindow(-50, -50, 100, 100);
    painter.setBrush(Qt::green);
    painter.drawRect(0, 0, 20, 20);

    // window and viewport
    painter.save();
    painter.setWindow(0, 0, 100, 100);
    int side = qMin(width(), height());
    int x = (width() / 2);
    int y = (height() / 2);
    painter.setViewport(x, y, side, side);
    painter.setBrush(Qt::yellow);
    painter.drawRect(0, 25, 20, 20);
    painter.restore();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1, %2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}
