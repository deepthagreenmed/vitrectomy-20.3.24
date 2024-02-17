#include "vitrectomy.h"
#include "ui_vitrectomy.h"

vitrectomy::vitrectomy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vitrectomy)
{
    ui->setupUi(this);
}

vitrectomy::~vitrectomy()
{
    delete ui;
}

void vitrectomy::on_pushButton_clicked()
{
    this->close();
    parentWidget()->show();
}
