#include "textkeypad.h"
#include "ui_textkeypad.h"

#include <QPushButton>

textkeypad::textkeypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textkeypad)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &textkeypad::entertext);


for (int i = 2; i <= 41; ++i) {
    QPushButton *button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
    if (button) {
        connect(button, &QPushButton::clicked, this, &textkeypad::entertext);
    }
}

    connect(ui->pushButton_11, &QPushButton::clicked, this, &textkeypad::enterback);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &textkeypad::enterenter);
    connect(ui->pushButton_42, &QPushButton::clicked, this, &textkeypad::spaceenter);

}

textkeypad::~textkeypad()
{
    delete ui;
}

void textkeypad::entertext()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
     if (button)
     {
         digit = button->text();


             emit textsignal(digit);


     }
}

void textkeypad::enterback()
{

    emit backsignal();
}
void textkeypad::spaceenter()
{

    emit spacesignal();
}

void textkeypad::enterenter()
{
    emit entersignal();


}
