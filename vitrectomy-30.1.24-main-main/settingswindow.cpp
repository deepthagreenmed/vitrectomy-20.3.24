#include "settingswindow.h"
#include "ui_settingswindow.h"
#include"mainwindow.h"
#include<QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QtDebug>
#include<QMessageBox>
#include<QLineEdit>
#include<QProgressBar>
#include<QMouseEvent>
#include<QObject>
#include<QIcon>
#include<QStyleFactory>
#include <QScrollBar>

//#define PATH "/home/main.db"
//#define PATH "/home/amt-04/QtWorkspace/vitrectomy-24.1.24-main/database/main.db"

settingswindow::settingswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingswindow)
{
    ui->setupUi(this);
connect(ui->pushButton_12, &QPushButton::clicked, this, &settingswindow::on_pushButton_12_clicked);
//code to load database in the starting
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);

     mydb.open();



         QScrollBar *verticalScrollBar = ui->listWidget->verticalScrollBar();

         // Set the width of the vertical scrollbar
         verticalScrollBar->setStyleSheet("QScrollBar:vertical { width: 30px; }");
         QSqlQuery query;
         query.exec("SELECT surgeon FROM maindb");

 while (query.next()) {
     QString itemName = query.value(0).toString();


     ui->listWidget->addItem(itemName);


}

 //populatetype();



ui->tabWidget_2->removeTab(1);
ui->tabWidget_2->setCurrentIndex(0);
//ui->listWidget->setCurrentRow(0);
ui->vit->setStyleSheet("image: url(:/new/prefix1/img/diaicon2.png);");


ui->lineEdit->installEventFilter(this);
ui->lineEdit_8->installEventFilter(this);


ui->lineEdit_3->installEventFilter(this);
ui->lineEdit_5->installEventFilter(this);


query.exec("select * from maindb where surgeon='Surgeon 2'");
if(query.next()){
QString itemname1 = query.value(0).toString();
QString itemname2 = query.value(1).toString();
QString itemname3 = query.value(2).toString();
QString itemname4 = query.value(3).toString();
QString itemname5 = query.value(4).toString();
QString itemname6 = query.value(5).toString();
QString itemname7 = query.value(6).toString();
QString itemname8 = query.value(7).toString();
QString itemname9 = query.value(8).toString();
QString itemname10 = query.value(9).toString();
QString itemname11= query.value(10).toString();
QString itemname12 = query.value(11).toString();
QString itemname13 = query.value(12).toString();
QString itemname14 = query.value(13).toString();
QString itemname15 = query.value(14).toString();
QString itemname16 = query.value(15).toString();
QString itemname17 = query.value(16).toString();
QString itemname18= query.value(17).toString();
QString itemname19= query.value(18).toString();
QString itemname20= query.value(19).toString();
QString itemname21= query.value(20).toString();
QString itemname22= query.value(21).toString();
QString itemname23= query.value(22).toString();
QString itemname24= query.value(23).toString();
QString itemname25= query.value(24).toString();
QString itemname26= query.value(25).toString();
QString itemname27 = query.value(26).toString();
QString itemname28 = query.value(27).toString();
QString itemname29 = query.value(28).toString();
QString itemname30= query.value(29).toString();
QString itemname31 = query.value(30).toString();
QString itemname32 = query.value(31).toString();
QString itemname33 = query.value(32).toString();
QString itemname34 = query.value(33).toString();
QString itemname35 = query.value(34).toString();
QString itemname36 = query.value(35).toString();
QString itemname37 = query.value(36).toString();
QString itemname38 = query.value(37).toString();
QString itemname39 = query.value(38).toString();
QString itemname40 = query.value(39).toString();
QString itemname41 = query.value(40).toString();
QString itemname42 = query.value(41).toString();
QString itemname43 = query.value(42).toString();
QString itemname44 = query.value(43).toString();
QString itemname45 = query.value(44).toString();
QString itemname46 = query.value(45).toString();
QString itemname47 = query.value(46).toString();
QString itemname48 = query.value(47).toString();
//QString itemname48= query.value(47).toString();
//QString itemname49 = query.value(48).toString();


QRegExp regex("^[0-8]{0,1}[0-9]{0,3}$");
QRegExpValidator* validator = new QRegExpValidator(regex, ui->lineEdit);
ui->lineEdit->setValidator(validator);
ui->lineEdit->setMaxLength(4);

QRegExp regex2("^(?:[0-4]?\\d{1,2}|500)$");
QRegExpValidator* validator2 = new QRegExpValidator(regex2, ui->lineEdit_3);
ui->lineEdit_3->setValidator(validator2);
ui->lineEdit_3->setMaxLength(3);

QRegExp regex3("^(?:100|[1-9]\\d?|0)$");
QRegExpValidator* validator3 = new QRegExpValidator(regex3, ui->lineEdit_8);
ui->lineEdit_8->setValidator(validator3);
ui->lineEdit_8->setMaxLength(3);




ui->lineEdit_8->setText(itemname1);

ui->lineEdit->setText(itemname34);
ui->comboBox_10->setCurrentText(itemname35);
ui->comboBox->setCurrentText(itemname48);
ui->lineEdit_3->setText(itemname36);
ui->comboBox_11->setCurrentText(itemname37);

ui->comboBox_20->setCurrentText(itemname39);
ui->comboBox_23->setCurrentText(itemname40);
ui->comboBox_21->setCurrentText(itemname41);
ui->comboBox_24->setCurrentText(itemname42);
ui->lineEdit_5->setText(itemname43);



ui->lineEdit_21->setText(itemname44);
ui->progressBar_4->setValue(ui->lineEdit_21->text().toInt());

ui->lineEdit_2->setText(itemname45);
ui->progressBar->setValue(ui->lineEdit_2->text().toInt());

ui->lineEdit_4->setText(itemname46);
ui->progressBar_2->setValue(ui->lineEdit_4->text().toInt());

ui->lineEdit_7->setText(itemname47);
ui->progressBar_3->setValue(ui->lineEdit_7->text().toInt());


}



mydb.close();


flag = false;

key = new keypad;
connect(key, &keypad::textsignal, this, &settingswindow::on_clicked);
connect(key, &keypad::backsignal, this, &settingswindow::on_clickedbackspace);
connect(key, &keypad::entersignal, this, &settingswindow::on_clickedenter);
text=new textkeypad;
connect(text, &textkeypad::textsignal, this, &settingswindow::on_clickedtext);
connect(text, &textkeypad::backsignal, this, &settingswindow::on_clickedbackspacetext);
connect(text, &textkeypad::entersignal, this, &settingswindow::on_clickedentertext);
connect(text, &textkeypad::spacesignal, this, &settingswindow::on_clickedspace);
ui->lineEdit_8->clearFocus();



ui->lineEdit->clearFocus();
ui->lineEdit_3->clearFocus();


// for 0
connect(ui->pushButton_35, &QPushButton::clicked, this, &settingswindow::zeroinc);
connect(ui->pushButton_34, &QPushButton::clicked, this, &settingswindow::zerodec);
// for 1
connect(ui->pushButton_28, &QPushButton::clicked, this, &settingswindow::oneinc);
connect(ui->pushButton_29, &QPushButton::clicked, this, &settingswindow::onedec);
// for 2
connect(ui->pushButton_30, &QPushButton::clicked, this, &settingswindow::twoinc);
connect(ui->pushButton_31, &QPushButton::clicked, this, &settingswindow::twodec);
// for 3
connect(ui->pushButton_32, &QPushButton::clicked, this, &settingswindow::threeinc);
connect(ui->pushButton_33, &QPushButton::clicked, this, &settingswindow::threedec);
int s0,s1,s2,s3;
    s0=ui->lineEdit_21->text().toInt();
    s1=ui->lineEdit_2->text().toInt();
    s2=ui->lineEdit_4->text().toInt();
    s3=ui->lineEdit_7->text().toInt();
    ui->label_110->setText(QString::number(s0+s1+s2+s3));

int sum=s0+s1+s2+s3;
if(sum==100)
{
    ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
}
else
{
    ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
}

ui->listWidget->setCurrentRow(currentindex);

}

void settingswindow::keypadshow(int oldPos, int newPos)
{
    if((ui->lineEdit->isModified())==0)
    {


    }

}
// keypad showing code
bool settingswindow::eventFilter(QObject* object, QEvent* event)
{
  if(object == ui->lineEdit && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(980,280);
        key->show();
      //qDebug() << "Left click";
    } else if ( k->button() == Qt::RightButton ) {
      //qDebug() << "Right click";
    }
  }
  if(object == ui->lineEdit_8 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(980,290);
        key->show();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->lineEdit_5 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
    text->move(20,686);
    text->show();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->lineEdit_3 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
           key->resize(491,271);
          key->move(980,290);
          key->show();

      } else if ( k->button() == Qt::RightButton ) {

      }
    }
  return false;
}
//settings focus and insert digit
void settingswindow::on_clicked(const QString& digit)
{

  if(ui->lineEdit_8->focusWidget()) {
      ui->lineEdit->clearFocus();
      ui->lineEdit_3->clearFocus();
      if(!flag)
      {
      ui->lineEdit_8->setFocus();
      ui->lineEdit_8->insert(digit);

   }
  }
  if(ui->lineEdit->focusWidget()) {
      ui->lineEdit_8->clearFocus();
      ui->lineEdit_3->clearFocus();
      if(!flag)
      {
      ui->lineEdit->setFocus();
      ui->lineEdit->insert(digit);

   }
  }




if(ui->lineEdit_3->focusWidget())
  {
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    flag = false;
    if(!flag) {
    ui->lineEdit_3->setFocus();
      ui->lineEdit_3->insert(digit);

 }
}


}

void settingswindow::on_clickedbackspace()
{
//if(key->digit == "backspace")
//{

    if (ui->lineEdit_8->focusWidget())
    {

        QString data = ui->lineEdit_8->text();
        data.chop(3);
        ui->lineEdit_8->setText(data);



    }

    if(ui->lineEdit->focusWidget())
    {
        QString data = ui->lineEdit->text();
        data.chop(3);
        ui->lineEdit->setText(data);

    }
    if(ui->lineEdit_3->focusWidget())
    {
        QString data = ui->lineEdit_3->text();
        data.chop(3);
        ui->lineEdit_3->setText(data);


    }


}

void settingswindow::on_clickedenter()
{
    key->hide();
}

settingswindow::~settingswindow()
{
    delete ui;

}
// save buttons code

void settingswindow::on_pushButton_4_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();

    QSqlQuery query;
    QString diapm;

    //surgeon=ui->comboBox->currentText();
    surgeonid=ui->lineEdit_5->text();
    diapm=ui->lineEdit_8->text();
    query.prepare("update maindb set diapm='"+diapm+"'where surgeon='"+surgeonid+"'");
    query.exec();

    query.bindValue(diapm,"diapm");

        mydb.close();

}

void settingswindow::on_pushButton_5_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString peaspmax,pevacmax,pepowmax,pevacmode,pevpowmode1,pevpowmode2;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
//     peaspmax=ui->lineEdit_12->text();
//     pevacmax=ui->lineEdit_13->text();
//     pepowmax=ui->lineEdit_9->text();
//     pevacmode=ui->comboBox_2->currentText();
//     pevpowmode1=ui->comboBox_3->currentText();
//     pevpowmode2=ui->comboBox_4->currentText();
     query.prepare("update maindb set peaspmax='"+peaspmax+"',pevacmax='"+pevacmax+"',pepowmax='"+pepowmax+"',pevacmode='"+pevacmode+"',pevpowmode1='"+pevpowmode1+"',pevpowmode2='"+pevpowmode2+"'where surgeon='"+surgeonid+"'");
    query.exec();
    query.bindValue(peaspmax,"peaspmax");
    query.bindValue(pevacmax,"pevacmax");
    query.bindValue(pepowmax,"pepowmax");
    query.bindValue(pevacmode,"pevacmode");
    query.bindValue(pevpowmode1,"pevpowmode1");
    query.bindValue(pevpowmode2,"pevpowmode2");
    mydb.close();

}



void settingswindow::on_pushButton_8_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString pqaspmax,pqvacmax,pqpowmax,pqvacmode,pqpowmode1,pqpowmode2;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
//     pqaspmax=ui->lineEdit_14->text();
//     pqvacmax=ui->lineEdit_15->text();
//     pqpowmax=ui->lineEdit_10->text();
//     pqvacmode=ui->comboBox_8->currentText();
//     pqpowmode1=ui->comboBox_12->currentText();
//     pqpowmode2=ui->comboBox_13->currentText();
     query.prepare("update maindb set pqaspmax='"+pqaspmax+"',pqvacmax='"+pqvacmax+"',pqpowmax='"+pqpowmax+"',pqvacmode='"+pqvacmode+"',pqpowmode1='"+pqpowmode1+"',pqpowmode2='"+pqpowmode2+"'where surgeon='"+surgeonid+"'");
    query.exec();
    query.bindValue(pqaspmax,"pqaspmax");
    query.bindValue(pqvacmax,"pqvacmax");
    query.bindValue(pqpowmax,"pqpowmax");
    query.bindValue(pqvacmode,"pqvacmode");
    query.bindValue(pqpowmode1,"pqvpowmode1");
    query.bindValue(pqpowmode2,"pqvpowmode2");
    mydb.close();
}

void settingswindow::on_pushButton_9_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString pqaspmax,pqvacmax,pqpowmax,pqvacmode,pqpowmode1,pqpowmode2;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
//     pqaspmax=ui->lineEdit_16->text();
//     pqvacmax=ui->lineEdit_17->text();
//     pqpowmax=ui->lineEdit_11->text();
//     pqvacmode=ui->comboBox_14->currentText();
//     pqpowmode1=ui->comboBox_15->currentText();
//     pqpowmode2=ui->comboBox_16->currentText();
     query.prepare("update maindb set pcaspmax='"+pqaspmax+"',pcvacmax='"+pqvacmax+"',pcpowmax='"+pqpowmax+"',pcvacmode='"+pqvacmode+"',pcpowmode1='"+pqpowmode1+"',pcpowmode2='"+pqpowmode2+"'where surgeon='"+surgeonid+"'");
    query.exec();
    query.bindValue(pqaspmax,"pcaspmax");
    query.bindValue(pqvacmax,"pcvacmax");
    query.bindValue(pqpowmax,"pcpowmax");
    query.bindValue(pqvacmode,"pcvacmode");
    query.bindValue(pqpowmode1,"pcvpowmode1");
    query.bindValue(pqpowmode2,"pcvpowmode2");
    mydb.close();
}

void settingswindow::on_pushButton_10_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString pqaspmax,pqvacmax,pqpowmax,pqvacmode,pqpowmode1,pqpowmode2;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
//     pqaspmax=ui->lineEdit_18->text();
//     pqvacmax=ui->lineEdit_19->text();
//     pqpowmax=ui->lineEdit_20->text();
//     pqvacmode=ui->comboBox_17->currentText();
//     pqpowmode1=ui->comboBox_18->currentText();
//     pqpowmode2=ui->comboBox_19->currentText();
     query.prepare("update maindb set psaspmax='"+pqaspmax+"',psvacmax='"+pqvacmax+"',pspowmax='"+pqpowmax+"',psvacmode='"+pqvacmode+"',pspowmode1='"+pqpowmode1+"',pspowmode2='"+pqpowmode2+"'where surgeon='"+surgeonid+"'");
    query.exec();
    query.bindValue(pqaspmax,"psaspmax");
    query.bindValue(pqvacmax,"psvacmax");
    query.bindValue(pqpowmax,"pspowmax");
    query.bindValue(pqvacmode,"psvacmode");
    query.bindValue(pqpowmode1,"psvpowmode1");
    query.bindValue(pqpowmode2,"psvpowmode2");
    mydb.close();
}

void settingswindow::on_pushButton_6_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
    QString vvmax,vvmin,vaspmax;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
     vvmax=ui->lineEdit_3->text();
     vvmin=ui->comboBox_11->currentText();
//     vaspmax=ui->lineEdit_5->text();
//     acaspmax=ui->lineEdit_6->text();
//     acaspmode=ui->comboBox_9->currentText();
//     acvacmax=ui->lineEdit_27->text();
//     acvacmode=ui->comboBox_7->currentText();
//     apaspmax=ui->lineEdit_22->text();
//     apaspmode=ui->comboBox_5->currentText();
//     apvacmax= ui->lineEdit_25->text();
//     apvacmode=ui->comboBox_6->currentText();
     query.prepare("update maindb set vvmax='"+vvmax+"',vvmin='"+vvmin+"'where surgeon='"+surgeonid+"'");
     query.exec();
     query.bindValue(vvmax,"vvmax");
     query.bindValue(vvmin,"vvmin");
//     query.bindValue(vaspmax,"vaspmax");
//     query.bindValue(acaspmax,"acaspmax");
//     query.bindValue(acaspmode,"acaspmode");
//     query.bindValue(acvacmax,"acvacmode");
//     query.bindValue(acvacmode,"acvacmode");
//     query.bindValue(apaspmax,"apaspmax");
//     query.bindValue(apaspmode,"apaspmode");
//     query.bindValue(apvacmax,"apvacmax");
//     query.bindValue(apvacmode,"apvacmode");

     mydb.close();
}

void settingswindow::on_pushButton_7_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString surgeon,vcmax,vcmin,vvmax,vvmin,vaspmax,type;
     //surgeon=ui->comboBox->currentText();
     surgeonid=ui->lineEdit_5->text();
     vcmax=ui->lineEdit->text();
     vcmin=ui->comboBox_10->currentText();
     type=ui->comboBox->currentText();

     query.prepare("update maindb set vcmax='"+vcmax+"',vcmin='"+vcmin+"',type='"+type+"'where surgeon='"+surgeonid+"'");
     query.exec();
     query.bindValue(vcmax,"vcmax");
     query.bindValue(vcmin,"vcmin");
     query.bindValue(type, "type");

     mydb.close();

}



// going back to home screen
void settingswindow::on_pushButton_12_clicked()
{
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    key->hide();
    text->hide();
    this->close();
    parentWidget()->show();
}

void settingswindow::on_pushButton_clicked()
{
  flag = true;

  ui->lineEdit_8->clearFocus();




  ui->lineEdit->clearFocus();
  ui->lineEdit_3->clearFocus();

}


void settingswindow::on_pushButton_15_clicked()
{

    db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName(PATH);
     db1.open();



    QSqlQuery qry;
    QString tl,tr,bl,br;

    tl=ui->comboBox_20->currentText();
    tr=ui->comboBox_23->currentText();
    bl=ui->comboBox_21->currentText();
    br=ui->comboBox_24->currentText();
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

void settingswindow::on_pushButton_23_clicked()
{
    db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName(PATH);
     db1.open();



    QSqlQuery qry;
    QString tl,tr,bl,br,surgeon;
    surgeon=ui->lineEdit_5->text();
    tl=ui->comboBox_20->currentText();
    tr=ui->comboBox_23->currentText();
    bl=ui->comboBox_21->currentText();
    br=ui->comboBox_24->currentText();
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




// loading database from list
void settingswindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    key->hide();
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    ui->lineEdit_5->setText(currentText);
    surgeonid=ui->lineEdit_5->text();
//    qDebug() << currentText;

//    qDebug()<<docnameold;
   // emit stringPassed(surgeonid);



    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
    QSqlQuery query;


   query.exec("select * from maindb where surgeon='"+surgeonid+"'");
   if(query.next()){
   QString itemname1 = query.value(0).toString();
   QString itemname2 = query.value(1).toString();
   QString itemname3 = query.value(2).toString();
   QString itemname4 = query.value(3).toString();
   QString itemname5 = query.value(4).toString();
   QString itemname6 = query.value(5).toString();
   QString itemname7 = query.value(6).toString();
   QString itemname8 = query.value(7).toString();
   QString itemname9 = query.value(8).toString();
   QString itemname10 = query.value(9).toString();
   QString itemname11= query.value(10).toString();
   QString itemname12 = query.value(11).toString();
   QString itemname13 = query.value(12).toString();
   QString itemname14 = query.value(13).toString();
   QString itemname15 = query.value(14).toString();
   QString itemname16 = query.value(15).toString();
   QString itemname17 = query.value(16).toString();
   QString itemname18= query.value(17).toString();
   QString itemname19= query.value(18).toString();
   QString itemname20= query.value(19).toString();
   QString itemname21= query.value(20).toString();
   QString itemname22= query.value(21).toString();
   QString itemname23= query.value(22).toString();
   QString itemname24= query.value(23).toString();
   QString itemname25= query.value(24).toString();
   QString itemname26= query.value(25).toString();
   QString itemname27 = query.value(26).toString();
   QString itemname28 = query.value(27).toString();
   QString itemname29 = query.value(28).toString();
   QString itemname30= query.value(29).toString();
   QString itemname31 = query.value(30).toString();
   QString itemname32 = query.value(31).toString();
   QString itemname33 = query.value(32).toString();
   QString itemname34 = query.value(33).toString();
   QString itemname35 = query.value(34).toString();
   QString itemname36 = query.value(35).toString();
   QString itemname37 = query.value(36).toString();
   QString itemname38 = query.value(37).toString();
   QString itemname39 = query.value(38).toString();
   QString itemname40 = query.value(39).toString();
   QString itemname41 = query.value(40).toString();
   QString itemname42 = query.value(41).toString();
   QString itemname43 = query.value(42).toString();
   QString itemname44 = query.value(43).toString();
   QString itemname45= query.value(44).toString();
   QString itemname46 = query.value(45).toString();
  QString itemname47 = query.value(46).toString();
  QString itemname48 = query.value(47).toString();


//   QString itemname48= query.value(47).toString();
//   QString itemname49 = query.value(48).toString();

//  emit stringPassed0(itemname44);
  emit stringPassed1(itemname45);
   emit stringPassed2(itemname46);
   emit stringPassed3(itemname47);



ui->lineEdit_8->setText(itemname1);


ui->lineEdit->setText(itemname34);
ui->comboBox_10->setCurrentText(itemname35);
ui->comboBox->setCurrentText(itemname48);
ui->lineEdit_3->setText(itemname36);
ui->comboBox_11->setCurrentText(itemname37);
// ui->lineEdit_5->setText(itemname38);
ui->comboBox_20->setCurrentText(itemname39);
ui->comboBox_23->setCurrentText(itemname40);
ui->comboBox_21->setCurrentText(itemname41);
ui->comboBox_24->setCurrentText(itemname42);
ui->lineEdit_5->setText(itemname43);

//ui->horizontalSlider->setValue(itemname44.toInt());
//ui->horizontalSlider_3->setValue(itemname45.toInt());

 ui->lineEdit_21->setText(itemname44);
 ui->progressBar_4->setValue(ui->lineEdit_21->text().toInt());

 ui->lineEdit_2->setText(itemname45);
 ui->progressBar->setValue(ui->lineEdit_2->text().toInt());

 ui->lineEdit_4->setText(itemname46);
 ui->progressBar_2->setValue(ui->lineEdit_4->text().toInt());

 ui->lineEdit_7->setText(itemname47);
 ui->progressBar_3->setValue(ui->lineEdit_7->text().toInt());
//ui->horizontalSlider_4->setValue(itemname46.toInt());

// qDebug()<<itemname46;
// qDebug()<<itemname48;
// qDebug()<<itemname49;
int s0,s1,s2,s3;
    s0=ui->lineEdit_21->text().toInt();
    s1=ui->lineEdit_2->text().toInt();
    s2=ui->lineEdit_4->text().toInt();
    s3=ui->lineEdit_7->text().toInt();
    ui->label_110->setText(QString::number(s0+s1+s2+s3));

int sum=s0+s1+s2+s3;
if(sum==100)
{
    ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
}
else
{
    ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
}
//qDebug()<<s1+s2+s3;


}
   docnameold=ui->listWidget->currentItem()->text();
   currentindex=ui->listWidget->currentIndex().row();


mydb.close();
}
// code to inc / dec in footpedal preset
void settingswindow::zeroinc()
{
    int value=ui->lineEdit_21->text().toInt();
    int newvalue=value+1;
   ui->lineEdit_21->setText(QString::number(newvalue));
   ui->progressBar_4->setValue(newvalue);
   int s0,s1,s2,s3;
       s0=ui->lineEdit_21->text().toInt();
       s1=ui->lineEdit_2->text().toInt();
       s2=ui->lineEdit_4->text().toInt();
       s3=ui->lineEdit_7->text().toInt();
       ui->label_110->setText(QString::number(s0+s1+s2+s3));

   int sum=s0+s1+s2+s3;
   if(sum==100)
   {
       ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
   }
   else
   {
       ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
   }
   //qDebug()<<s1+s2+s3;




}
void settingswindow::zerodec()
{
    int value=ui->lineEdit_21->text().toInt();
    int newvalue=value-1;
      ui->lineEdit_21->setText(QString::number(newvalue));
      ui->progressBar_4->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_21->text().toInt();
          s1=ui->lineEdit_2->text().toInt();
          s2=ui->lineEdit_4->text().toInt();
          s3=ui->lineEdit_7->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
      //qDebug()<<s1+s2+s3;




}
void settingswindow::oneinc()
{
    int value=ui->lineEdit_2->text().toInt();
    int newvalue=value+1;
   ui->lineEdit_2->setText(QString::number(newvalue));
   ui->progressBar->setValue(newvalue);
   int s0,s1,s2,s3;
       s0=ui->lineEdit_21->text().toInt();
       s1=ui->lineEdit_2->text().toInt();
       s2=ui->lineEdit_4->text().toInt();
       s3=ui->lineEdit_7->text().toInt();
       ui->label_110->setText(QString::number(s0+s1+s2+s3));

   int sum=s0+s1+s2+s3;
   if(sum==100)
   {
       ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
   }
   else
   {
       ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
   }
}
void settingswindow::twoinc()
{
    int value=ui->lineEdit_4->text().toInt();
    int newvalue=value+1;
      ui->lineEdit_4->setText(QString::number(newvalue));
      ui->progressBar_2->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_21->text().toInt();
          s1=ui->lineEdit_2->text().toInt();
          s2=ui->lineEdit_4->text().toInt();
          s3=ui->lineEdit_7->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}
void settingswindow::threeinc()
{
    int value=ui->lineEdit_7->text().toInt();
    int newvalue=value+1;
      ui->lineEdit_7->setText(QString::number(newvalue));
      ui->progressBar_3->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_21->text().toInt();
          s1=ui->lineEdit_2->text().toInt();
          s2=ui->lineEdit_4->text().toInt();
          s3=ui->lineEdit_7->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}
void settingswindow::onedec()
{
    int value=ui->lineEdit_2->text().toInt();
    int newvalue=value-1;
      ui->lineEdit_2->setText(QString::number(newvalue));
      ui->progressBar->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_21->text().toInt();
          s1=ui->lineEdit_2->text().toInt();
          s2=ui->lineEdit_4->text().toInt();
          s3=ui->lineEdit_7->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}
void settingswindow::twodec()
{
    int value=ui->lineEdit_4->text().toInt();
    int newvalue=value-1;
     ui->lineEdit_4->setText(QString::number(newvalue));
     ui->progressBar_2->setValue(newvalue);
     int s0,s1,s2,s3;
         s0=ui->lineEdit_21->text().toInt();
         s1=ui->lineEdit_2->text().toInt();
         s2=ui->lineEdit_4->text().toInt();
         s3=ui->lineEdit_7->text().toInt();
         ui->label_110->setText(QString::number(s0+s1+s2+s3));

     int sum=s0+s1+s2+s3;
     if(sum==100)
     {
         ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
     }
     else
     {
         ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
     }
}
void settingswindow::threedec()
{
    int value=ui->lineEdit_7->text().toInt();;
    int newvalue=value-1;
      ui->lineEdit_7->setText(QString::number(newvalue));
      ui->progressBar_3->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_21->text().toInt();
          s1=ui->lineEdit_2->text().toInt();
          s2=ui->lineEdit_4->text().toInt();
          s3=ui->lineEdit_7->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_13->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}



void settingswindow::on_pushButton_13_clicked()
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName(PATH);
    db1.open();
     QSqlQuery query;
     QString surgeon;
     QString fp0,fp1,fp2,fp3;
     int Fp0,Fp1,Fp2,Fp3;
     //surgeon=ui->comboBox->currentText();

     surgeonid=ui->lineEdit_5->text();
     fp0=ui->lineEdit_21->text();
     Fp0=fp0.toInt();

     fp1=ui->lineEdit_2->text();
     Fp1=fp1.toInt();

     fp2=ui->lineEdit_4->text();
     Fp2=fp2.toInt();

     fp3=ui->lineEdit_7->text();
     Fp3=fp3.toInt();


        int sum=Fp0+Fp1+Fp2+Fp3;
        qDebug()<<sum;
     if(sum==100){
     query.prepare("update maindb set fp0='"+fp0+"',fp1='"+fp1+"',fp2='"+fp2+"',fp3='"+fp3+"'where surgeon='"+surgeonid+"'");

     if(!(query.exec()))
     {
         qDebug()<<"yes";
     }


     query.bindValue(fp0,"fp0");
     query.bindValue(fp1,"fp1");
     query.bindValue(fp2,"fp2");
     query.bindValue(fp3,"fp3");

        }else
     {QMessageBox::information(nullptr, "Information", "check the Total of positons 0,1,2,3.");}
      db1.close();
      emit stringPassed0(QString::number(Fp0));
      emit stringPassed1(QString::number(Fp1));
      emit stringPassed2(QString::number(Fp2));
      emit stringPassed3(QString::number(Fp3));
QSqlDatabase::removeDatabase("QSQLITE");
}

// ring of tabs code

void settingswindow::on_pushButton_2_clicked()
{
key->hide();
ui->lineEdit->clearFocus();
ui->lineEdit_8->clearFocus();
ui->lineEdit_3->clearFocus();
    ui->tabWidget_2->setCurrentIndex(0);
    ui->label_21->setText("Diathermy");
    ui->label_27->show();
    ui->vit->setStyleSheet("image: url(:/new/prefix1/img/diaicon2.png);");

}

void settingswindow::on_pushButton_3_clicked()
{key->hide();
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    ui->tabWidget_2->setCurrentIndex(1);
    ui->label_21->setText("I/A");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/iaicon3.png);");
        ui->label_27->hide();

}

void settingswindow::on_pushButton_8vit_clicked()
{key->hide();
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    ui->tabWidget_2->setCurrentIndex(2);
    ui->label_21->setText("Vitrectomy");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/viticon1.png);");
            ui->label_27->hide();

}

void settingswindow::on_pushButton_5fp_clicked()
{key->hide();
    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    ui->tabWidget_2->setCurrentIndex(3);

    ui->label_21->setText("FS buttons");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/fpicon.png);");
            ui->label_27->hide();

}

void settingswindow::on_pushButton_fps_clicked()
{

    ui->lineEdit->clearFocus();
    ui->lineEdit_8->clearFocus();
    ui->lineEdit_3->clearFocus();
    key->hide();
    ui->tabWidget_2->setCurrentIndex(4);
    ui->label_21->setText("FS preset");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/fpsicon1.png);");
            ui->label_27->hide();

}
void settingswindow::on_clickedtext(const QString& digit)
{

  if(ui->lineEdit_5->focusWidget()) {
      QString text= ui->lineEdit_5->text();
       ui->lineEdit_5->setText(text+digit);

   }
 }



void settingswindow::on_clickedbackspacetext()
{


  QString text= ui->lineEdit_5->text();

            // Remove the last letter
            if (!text.isEmpty())
            {
                text.chop(1);
               ui->lineEdit_5->setText(text);
            }
}

void settingswindow::on_clickedspace()
{

  QString text= ui->lineEdit_5->text();

           // Add a space to the end of the text
           text.append(' ');

           // Set the modified text back to the QTextEdit
ui->lineEdit_5->setText(text);
}

void settingswindow::on_clickedentertext()
{
    QString docnamenew = ui->lineEdit_5->text();
    qDebug()<<ui->lineEdit_5->text();
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName(PATH);

    if (!db1.open())
    {
        qDebug() << "Error opening database:";
        return;
    }

    QSqlQuery query;
    QString queryString = "UPDATE maindb SET surgeon = :docnamenew WHERE surgeon = :docnameold";
    query.prepare(queryString);
    query.bindValue(":docnamenew", docnamenew);
    query.bindValue(":docnameold", docnameold);

    if (!query.exec()) {
        qDebug() << "Error updating surgeon name:";
        db1.close();
        return;
    }
    ui->listWidget->currentItem()->setText(docnamenew);

    db1.close();
    //QSqlDatabase::removeDatabase("QSQLITE");
    text->hide();
}


//void settingswindow::on_pushButton_14_clicked()
//{
//     ui->listWidget->clear();
//    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName(PATH);

//     mydb.open();



//         QSqlQuery query;
//         query.exec("SELECT surgeon FROM maindb");

// while (query.next()) {
//     QString itemName = query.value(0).toString();


//     ui->listWidget->addItem(itemName);


//}




//ui->listWidget->setCurrentRow(currentindex);
//ui->vit->setStyleSheet("image: url(:/new/prefix1/img/diaicon2.png);");


//ui->lineEdit->installEventFilter(this);
//ui->lineEdit_8->installEventFilter(this);


//ui->lineEdit_3->installEventFilter(this);
//ui->lineEdit_5->installEventFilter(this);


//query.exec("select * from maindb where surgeon='"+surgeonid+"'");
//if(query.next()){
//QString itemname1 = query.value(0).toString();
//QString itemname2 = query.value(1).toString();
//QString itemname3 = query.value(2).toString();
//QString itemname4 = query.value(3).toString();
//QString itemname5 = query.value(4).toString();
//QString itemname6 = query.value(5).toString();
//QString itemname7 = query.value(6).toString();
//QString itemname8 = query.value(7).toString();
//QString itemname9 = query.value(8).toString();
//QString itemname10 = query.value(9).toString();
//QString itemname11= query.value(10).toString();
//QString itemname12 = query.value(11).toString();
//QString itemname13 = query.value(12).toString();
//QString itemname14 = query.value(13).toString();
//QString itemname15 = query.value(14).toString();
//QString itemname16 = query.value(15).toString();
//QString itemname17 = query.value(16).toString();
//QString itemname18= query.value(17).toString();
//QString itemname19= query.value(18).toString();
//QString itemname20= query.value(19).toString();
//QString itemname21= query.value(20).toString();
//QString itemname22= query.value(21).toString();
//QString itemname23= query.value(22).toString();
//QString itemname24= query.value(23).toString();
//QString itemname25= query.value(24).toString();
//QString itemname26= query.value(25).toString();
//QString itemname27 = query.value(26).toString();
//QString itemname28 = query.value(27).toString();
//QString itemname29 = query.value(28).toString();
//QString itemname30= query.value(29).toString();
//QString itemname31 = query.value(30).toString();
//QString itemname32 = query.value(31).toString();
//QString itemname33 = query.value(32).toString();
//QString itemname34 = query.value(33).toString();
//QString itemname35 = query.value(34).toString();
//QString itemname36 = query.value(35).toString();
//QString itemname37 = query.value(36).toString();
//QString itemname38 = query.value(37).toString();
//QString itemname39 = query.value(38).toString();
//QString itemname40 = query.value(39).toString();
//QString itemname41 = query.value(40).toString();
//QString itemname42 = query.value(41).toString();
//QString itemname43 = query.value(42).toString();
//QString itemname44= query.value(43).toString();
//QString itemname45 = query.value(44).toString();
//QString itemname46 = query.value(45).toString();
//QString itemname47 = query.value(46).toString();
//QString itemname48= query.value(47).toString();
//QString itemname49 = query.value(48).toString();







//ui->lineEdit_8->setText(itemname1);

//ui->lineEdit->setText(itemname34);
//ui->comboBox_10->setCurrentText(itemname35);
//ui->lineEdit_3->setText(itemname36);
//ui->comboBox_11->setCurrentText(itemname37);

//ui->comboBox_20->setCurrentText(itemname39);
//ui->comboBox_23->setCurrentText(itemname40);
//ui->comboBox_21->setCurrentText(itemname41);
//ui->comboBox_24->setCurrentText(itemname42);
//ui->lineEdit_5->setText(itemname43);



//ui->lineEdit_21->setText(itemname44);
//ui->progressBar_4->setValue(ui->lineEdit_21->text().toInt());

//ui->lineEdit_2->setText(itemname45);
//ui->progressBar->setValue(ui->lineEdit_2->text().toInt());

//ui->lineEdit_4->setText(itemname46);
//ui->progressBar_2->setValue(ui->lineEdit_4->text().toInt());

//ui->lineEdit_7->setText(itemname47);
//ui->progressBar_3->setValue(ui->lineEdit_7->text().toInt());


//}



//mydb.close();

//}

//void settingswindow::populatetype()
//{
//    int count=0;
//    QSqlQuery query;
//    query.exec("SELECT type FROM maindb");
//    QList<QString> values;
//    while(query.next() && count<3)
//    {
//        QString value = query.value(0).toString();
//        values.append(value);
//        count++;
//    }
//    foreach(const QString& value, values)
//    {
//        ui->comboBox->addItem(value);
//    }
//}
