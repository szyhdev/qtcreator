#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyDialog *dlg = new MyDialog(this);
    connect(dlg, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)), Qt::QueuedConnection);

    // connect(dlg, &MyDialog::dlgReturn, this, &Widget::showValue);

    // connect(dlg, &MyDialog::dlgReturn, this, [=] (int value){
    //         ui->label->setText(tr("value: %1").arg(value));
    // });

    dlg->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int value)
{
    ui->label->setText(tr("value: %1").arg(value));
    qDebug() << "setText: " << value;
}
