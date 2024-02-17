#include "keybord.h"
#include "ui_keybord.h"
#include"settingswindow.h"
Keybord::Keybord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keybord)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Keybord::mainLineEditTextChanged);

}

Keybord::~Keybord()
{
    delete ui;
}
void Keybord::addPasswdChar(QString value)
{
    this->ui->lineEdit->setText(this->ui->lineEdit->text() + value);
}
void Keybord::on_pushButton_clicked()
{
    addPasswdChar("Q");
}

void Keybord::on_pushButton_2_clicked()
{
     addPasswdChar("W");
}

void Keybord::on_pushButton_4_clicked()
{
     addPasswdChar("E");
}

void Keybord::on_pushButton_3_clicked()
{
     addPasswdChar("R");
}

void Keybord::on_pushButton_5_clicked()
{
     addPasswdChar("T");
}

void Keybord::on_pushButton_6_clicked()
{
     addPasswdChar("Y");
}

void Keybord::on_pushButton_7_clicked()
{
     addPasswdChar("U");
}

void Keybord::on_pushButton_8_clicked()
{
     addPasswdChar("I");
}

void Keybord::on_pushButton_9_clicked()
{
     addPasswdChar("O");
}

void Keybord::on_pushButton_10_clicked()
{
     addPasswdChar("P");
}

void Keybord::on_pushButton_11_clicked()
{
     addPasswdChar("A");
}

void Keybord::on_pushButton_12_clicked()
{
     addPasswdChar("S");
}

void Keybord::on_pushButton_13_clicked()
{
     addPasswdChar("D");
}

void Keybord::on_pushButton_14_clicked()
{
     addPasswdChar("F");
}

void Keybord::on_pushButton_15_clicked()
{
     addPasswdChar("G");
}

void Keybord::on_pushButton_19_clicked()
{
     addPasswdChar("H");
}

void Keybord::on_pushButton_16_clicked()
{
     addPasswdChar("J");
}

void Keybord::on_pushButton_20_clicked()
{
     addPasswdChar("K");
}

void Keybord::on_pushButton_17_clicked()
{
     addPasswdChar("L");
}

void Keybord::on_pushButton_18_clicked()
{
    this->ui->lineEdit->backspace();
}

void Keybord::on_pushButton_21_clicked()
{
    addPasswdChar("Z");

}

void Keybord::on_pushButton_22_clicked()
{
    addPasswdChar("X");

}

void Keybord::on_pushButton_23_clicked()
{
    addPasswdChar("C");

}

void Keybord::on_pushButton_24_clicked()
{
    addPasswdChar("V");

}

void Keybord::on_pushButton_25_clicked()
{
    addPasswdChar("B");

}

void Keybord::on_pushButton_26_clicked()
{
    addPasswdChar("N");

}

void Keybord::on_pushButton_27_clicked()
{
    addPasswdChar("M");

}

void Keybord::on_pushButton_28_clicked()
{
    addPasswdChar(",");

}

void Keybord::on_pushButton_29_clicked()
{
    addPasswdChar(".");

}

void Keybord::on_pushButton_30_clicked()
{
    addPasswdChar("/");

}

void Keybord::on_pushButton_31_clicked()
{
    addPasswdChar(" ");

}

