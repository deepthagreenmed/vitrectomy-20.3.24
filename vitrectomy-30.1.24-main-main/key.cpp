#include "key.h"
#include "ui_key.h"

key::key(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::key)
{
    ui->setupUi(this);
}
void key::addPasswdChar(QString value)
{
    this->ui->lineEdit->setText(this->ui->lineEdit->text() + value);
}
void key::on_pushButton_clicked()
{
    addPasswdChar("Q");
}

void key::on_pushButton_2_clicked()
{
     addPasswdChar("W");
}

void key::on_pushButton_4_clicked()
{
     addPasswdChar("E");
}

void key::on_pushButton_3_clicked()
{
     addPasswdChar("R");
}

void key::on_pushButton_5_clicked()
{
     addPasswdChar("T");
}

void key::on_pushButton_6_clicked()
{
     addPasswdChar("Y");
}

void key::on_pushButton_7_clicked()
{
     addPasswdChar("U");
}

void key::on_pushButton_8_clicked()
{
     addPasswdChar("I");
}

void key::on_pushButton_9_clicked()
{
     addPasswdChar("O");
}

void key::on_pushButton_10_clicked()
{
     addPasswdChar("P");
}

void key::on_pushButton_11_clicked()
{
     addPasswdChar("A");
}

void key::on_pushButton_12_clicked()
{
     addPasswdChar("S");
}

void key::on_pushButton_13_clicked()
{
     addPasswdChar("D");
}

void key::on_pushButton_14_clicked()
{
     addPasswdChar("F");
}

void key::on_pushButton_15_clicked()
{
     addPasswdChar("G");
}

void key::on_pushButton_19_clicked()
{
     addPasswdChar("H");
}

void key::on_pushButton_16_clicked()
{
     addPasswdChar("J");
}

void key::on_pushButton_20_clicked()
{
     addPasswdChar("K");
}

void key::on_pushButton_17_clicked()
{
     addPasswdChar("L");
}

void key::on_pushButton_18_clicked()
{
    this->ui->lineEdit->backspace();
}

void key::on_pushButton_21_clicked()
{
    addPasswdChar("Z");

}

void key::on_pushButton_22_clicked()
{
    addPasswdChar("X");

}

void key::on_pushButton_23_clicked()
{
    addPasswdChar("C");

}

void key::on_pushButton_24_clicked()
{
    addPasswdChar("V");

}

void key::on_pushButton_25_clicked()
{
    addPasswdChar("B");

}

void key::on_pushButton_26_clicked()
{
    addPasswdChar("N");

}

void key::on_pushButton_27_clicked()
{
    addPasswdChar("M");

}

void key::on_pushButton_28_clicked()
{
    addPasswdChar(",");

}

void key::on_pushButton_29_clicked()
{
    addPasswdChar(".");

}

void key::on_pushButton_30_clicked()
{
    addPasswdChar("/");

}

void key::on_pushButton_31_clicked()
{
    addPasswdChar(" ");

}
key::~key()
{
    delete ui;
}

void key::on_pushButton_42_clicked()
{
    data=ui->lineEdit->text();

}
