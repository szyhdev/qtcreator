#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QPushButton *button = new QPushButton(this);
    button->setObjectName("myButton");
    button->setText(tr("Close Window"));
    button->move(150, 120);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_myButton_clicked()
{
    close();
}
