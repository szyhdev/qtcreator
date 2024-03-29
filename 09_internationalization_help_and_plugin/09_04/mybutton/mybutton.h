#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyButton(QWidget *parent = nullptr);

    QString getName() {
        return "My Button!";
    }
};

#endif // MYBUTTON_H
