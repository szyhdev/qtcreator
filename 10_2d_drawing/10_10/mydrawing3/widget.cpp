#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>
#include <QDebug>
#include <QLabel>
#include <QWindow>
#include <QScreen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // grab
    QPixmap grab = QWidget::grab();
    grab.save("../mydrawing3/screen.png");

    // QLabel
    QLabel *label = new QLabel(this);
    label->setStyleSheet("QLabel { border: 1px solid black; }");
    label->resize(300, 150);
    QPixmap pix = grab.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(pix);
    label->move(50, 100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // QPixmap
    QPixmap pix;
    pix.load("../mydrawing3/penguin.png");

    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(255, 255, 255, 100));
    painter.drawRect(0, 0, pix.width(), pix.height());

    painter.drawPixmap(100, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(0, 0, 255, 100));
    painter.drawRect(100, 0, pix.width(), pix.height());
}
