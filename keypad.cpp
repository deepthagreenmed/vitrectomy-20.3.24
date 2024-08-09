#include "keypad.h"
#include "ui_keypad.h"

#include <iostream>
#include <chrono>
#include <thread>

#include <QDebug>

keypad::keypad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keypad)
{
    ui->setupUi(this);

    clicktimer=new QTimer;

    connect(ui->pushButton, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &keypad::entertext);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &keypad::enterback);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &keypad::enterenter);

    clicktimer->setInterval(200);
    clicktimer->setSingleShot(true);

    hhandler = new hwHandler;





}

keypad::~keypad()
{
    delete ui;
}

void keypad::entertext()
{
    if(!clicktimer->isActive()) {

    QPushButton* button = qobject_cast<QPushButton*>(sender());

     if (button)
     {
        digit = button->text();
        emit textsignal(digit);
     }
     hhandler->buzz();

     clicktimer->start();
    }
}

void keypad::enterback()
{
    if(!clicktimer->isActive()) {

    back = true;
    emit backsignal();
    hhandler->buzz();

    clicktimer->start();
   }
}

void keypad::enterenter()
{
    if(!clicktimer->isActive()) {

    emit entersignal();
    hhandler->buzz();

    clicktimer->start();
   }
}

