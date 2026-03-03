#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>

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
    QPainter painter;

    // QImage
    QImage image(100, 100, QImage::Format_ARGB32);
    painter.begin(&image);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QImage"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    // QPixmap
    QPixmap pix(100, 100);
    painter.begin(&pix);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QPixmap"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    // QBitmap
    QBitmap bit(100, 100);
    bit.fill(Qt::color0);
    painter.begin(&bit);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QBitmap"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    // QPicture
    QPicture picture;
    painter.begin(&picture);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QPicture"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    painter.begin(this);
    painter.drawImage(70, 30, image);
    painter.drawPixmap(210, 30, pix);
    painter.drawPixmap(70, 170, bit);
    painter.drawPicture(210, 170, picture);
}
