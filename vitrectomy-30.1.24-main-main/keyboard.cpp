#include "keyboard.h"
#include "ui_keyboard.h"
#include"settingswindow.h"
keyboard::keyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);
}

keyboard::~keyboard()
{
    delete ui;
}

void keyboard::addPasswdChar(QString value)
{
this->ui->lineEdit->setText(this->ui->lineEdit->text() + value);
    input=(this->ui->lineEdit->text());
}
void keyboard::on_pushButton_clicked()
{
    addPasswdChar("Q");
}

void keyboard::on_pushButton_2_clicked()
{
     addPasswdChar("W");
}

void keyboard::on_pushButton_4_clicked()
{
     addPasswdChar("E");
}

void keyboard::on_pushButton_3_clicked()
{
     addPasswdChar("R");
}

void keyboard::on_pushButton_5_clicked()
{
     addPasswdChar("T");
}

void keyboard::on_pushButton_6_clicked()
{
     addPasswdChar("Y");
}

void keyboard::on_pushButton_7_clicked()
{
     addPasswdChar("U");
}

void keyboard::on_pushButton_8_clicked()
{
     addPasswdChar("I");
}

void keyboard::on_pushButton_9_clicked()
{
     addPasswdChar("O");
}

void keyboard::on_pushButton_10_clicked()
{
     addPasswdChar("P");
}

void keyboard::on_pushButton_11_clicked()
{
     addPasswdChar("A");
}

void keyboard::on_pushButton_12_clicked()
{
     addPasswdChar("S");
}

void keyboard::on_pushButton_13_clicked()
{
     addPasswdChar("D");
}

void keyboard::on_pushButton_14_clicked()
{
     addPasswdChar("F");
}

void keyboard::on_pushButton_15_clicked()
{
     addPasswdChar("G");
}

void keyboard::on_pushButton_19_clicked()
{
     addPasswdChar("H");
}

void keyboard::on_pushButton_16_clicked()
{
     addPasswdChar("J");
}

void keyboard::on_pushButton_20_clicked()
{
     addPasswdChar("K");
}

void keyboard::on_pushButton_17_clicked()
{
     addPasswdChar("L");
}

void keyboard::on_pushButton_18_clicked()
{
    this->ui->lineEdit->backspace();
}

void keyboard::on_pushButton_21_clicked()
{
    addPasswdChar("Z");

}

void keyboard::on_pushButton_22_clicked()
{
    addPasswdChar("X");

}

void keyboard::on_pushButton_23_clicked()
{
    addPasswdChar("C");

}

void keyboard::on_pushButton_24_clicked()
{
    addPasswdChar("V");

}

void keyboard::on_pushButton_25_clicked()
{
    addPasswdChar("B");

}

void keyboard::on_pushButton_26_clicked()
{
    addPasswdChar("N");

}

void keyboard::on_pushButton_27_clicked()
{
    addPasswdChar("M");

}

void keyboard::on_pushButton_28_clicked()
{
    addPasswdChar(",");

}

void keyboard::on_pushButton_29_clicked()
{
    addPasswdChar(".");

}

void keyboard::on_pushButton_30_clicked()
{
    addPasswdChar("/");

}

void keyboard::on_pushButton_31_clicked()
{
    addPasswdChar(" ");

}

void keyboard::on_pushButton_32_clicked()
{
    this->close();
    settingswindow().show();
}
