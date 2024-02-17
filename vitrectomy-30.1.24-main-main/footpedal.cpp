#include "footpedal.h"
#include "ui_footpedal.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlDatabase>
#include"settingswindow.h"

footpedal::footpedal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::footpedal)
{
    ui->setupUi(this);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/amt-05/Downloads/main.db");

     mydb.open();

 QSqlQuery query;
 query.exec("SELECT surgeon FROM maindb");

 while (query.next()) {
     QString itemName = query.value(0).toString();
ui->comboBox->addItem(itemName);


}
mydb.close();


//    QString itemname39 = query.value(38).toString();
//    QString itemname40 = query.value(39).toString();
//    QString itemname41 = query.value(40).toString();
//    QString itemname42 = query.value(41).toString();
//    ui->comboBox_2->currentText();
//    ui->comboBox_3->currentText();
//    ui->comboBox_4->currentText();
//    ui->comboBox_5->currentText();



 }
footpedal::~footpedal()
{
    delete ui;

}




void footpedal::on_pushButton_3_clicked()
{
    this->close();
    parentWidget()->show();
}



void footpedal::on_pushButton_clicked()
{
    db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName("/home/amt-05/Downloads/main.db");
     db1.open();



    QSqlQuery qry;
    QString tl,tr,bl,br;

    tl=ui->comboBox_2->currentText();
    tr=ui->comboBox_3->currentText();
    bl=ui->comboBox_4->currentText();
    br=ui->comboBox_5->currentText();
    db1.open();

    qry.prepare("update maindb set ftopleft='"+tl+"',ftopright='"+tr+"',fbottomleft='"+bl+"',fbottomright='"+br+"'");
    qry.exec();
    qry.bindValue(tl,"ftopleft");
    qry.bindValue(tr,"ftopright");
    qry.bindValue(bl,"fbottomleft");
    qry.bindValue(br,"fbottomright");

db1.close();
QSqlDatabase::removeDatabase("QSQLITE");
}

void footpedal::on_pushButton_2_clicked()
{
    db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName("/home/amt-05/Downloads/main.db");
     db1.open();



    QSqlQuery qry;
    QString tl,tr,bl,br,surgeon;
    surgeon=ui->comboBox->currentText();
    tl=ui->comboBox_2->currentText();
    tr=ui->comboBox_3->currentText();
    bl=ui->comboBox_4->currentText();
    br=ui->comboBox_5->currentText();
    db1.open();

    qry.prepare("update maindb set ftopleft='"+tl+"',ftopright='"+tr+"',fbottomleft='"+bl+"',fbottomright='"+br+"' where surgeon='"+surgeon+"'");
    qry.exec();
    qry.bindValue(tl,"ftopleft");
    qry.bindValue(tr,"ftopright");
    qry.bindValue(bl,"fbottomleft");
    qry.bindValue(br,"fbottomright");

db1.close();
QSqlDatabase::removeDatabase("QSQLITE");
}
