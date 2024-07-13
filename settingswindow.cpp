#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QProgressBar>
#include <QMouseEvent>
#include <QObject>
#include <QIcon>
#include <QStyleFactory>
#include <QScrollBar>

settingswindow::settingswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingswindow)
{
    ui->setupUi(this);


    connect(ui->pushButton_save, &QPushButton::clicked, this, &settingswindow::on_dia_clicked);
    connect(ui->pushButton_save_2, &QPushButton::clicked, this, &settingswindow::on_led_clicked);
    connect(ui->pushButton_save_3, &QPushButton::clicked, this, &settingswindow::on_ia_clicked);
    connect(ui->pushButton_save_4, &QPushButton::clicked, this, &settingswindow::on_vit_clicked);
    connect(ui->pushButton_goback, &QPushButton::clicked, this, &settingswindow::show_surgery_screen);
    connect(ui->pushButton_save_5, &QPushButton::clicked, this, &settingswindow::on_save_clicked);
    connect(ui->pushButton_saveforall, &QPushButton::clicked, this, &settingswindow::on_saveforall_clicked);

    connect(ui->listWidget, &QListWidget::currentTextChanged, this, &settingswindow::loadDatabaseFromList);
    connect(ui->pushButton_save_6, &QPushButton::clicked, this, &settingswindow::on_fp_settings_clicked);
    connect(ui->pushButton_dia, &QPushButton::clicked, this, &settingswindow::on_tab_dia_clicked);
    connect(ui->pushButton_led, &QPushButton::clicked, this, &settingswindow::on_tab_led_clicked);
    connect(ui->pushButton_ia, &QPushButton::clicked, this, &settingswindow::on_tab_ia_clicked);
    connect(ui->pushButton_vit, &QPushButton::clicked, this, &settingswindow::on_tab_vit_clicked);
    connect(ui->pushButton_fp, &QPushButton::clicked, this, &settingswindow::on_tab_fp_clicked);
    connect(ui->pushButton_fps, &QPushButton::clicked, this, &settingswindow::on_tab_fppreset_clicked);



    //code to load database in the starting
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);

     mydb.open();

     QScrollBar *verticalScrollBar = ui->listWidget->verticalScrollBar();

     // Set the width of the vertical scrollbar
     verticalScrollBar->setStyleSheet("QScrollBar:vertical { width: 45px; }");
     QSqlQuery query;
     query.exec("SELECT surgeon FROM maindb");

     while (query.next()) {
         QString itemName = query.value(0).toString();
         ui->listWidget->addItem(itemName);
     }



    //ui->tabWidget_2->removeTab(1);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->vit->setStyleSheet("image: url(:/new/prefix1/img/diaicon2.png);");


    ui->lineEdit_cutrate->installEventFilter(this);
    ui->lineEdit_powmax->installEventFilter(this);


    ui->lineEdit_vac->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);

    ui->lineEdit_led1->installEventFilter(this);
    ui->lineEdit_led2->installEventFilter(this);

    surgeonid=ui->lineEdit_5->text();


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
    QString itemname11 = query.value(10).toString();
    QString itemname12 = query.value(11).toString();
    QString itemname13 = query.value(12).toString();
    QString itemname14 = query.value(13).toString();
    QString itemname15 = query.value(14).toString();
    QString itemname16 = query.value(15).toString();
    QString itemname17 = query.value(16).toString();
    QString itemname18 = query.value(17).toString();
    QString itemname19 = query.value(18).toString();
    QString itemname20 = query.value(19).toString();
    QString itemname21 = query.value(20).toString();
    QString itemname22 = query.value(21).toString();
    QString itemname23 = query.value(22).toString();
    QString itemname24 = query.value(23).toString();
    QString itemname25 = query.value(24).toString();
    QString itemname26 = query.value(25).toString();
    QString itemname27 = query.value(26).toString();
    QString itemname28 = query.value(27).toString();
    QString itemname29 = query.value(28).toString();
    QString itemname30 = query.value(29).toString();
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
    QString itemname48 = query.value(48).toString();
    QString itemname49 = query.value(49).toString();
    QString itemname50 = query.value(50).toString();


    QRegExp regex("^(60|120|180|240|300|360|420|480|540|600|660|720|780|840|900|960|1020|1080|1140|1200|1260|1320|1380|1440|1500|1560|1620|1680|1740|1800|1860|1920|1980|2040|2100|2160|2220|2280|2340|2400|2460|2520|2580|2640|2700|2760|2820|2880|2940|3000|3060|3120|3180|3240|3300|3360|3420|3480|3540|3600|3660|3720|3780|3840|3900|3960|4020|4080|4140|4200|4260|4320|4380|4440|4500|4560|4620|4680|4740|4800|4860|4920|4980|5040|5100|5160|5220|5280|5340|5400|5460|5520|5580|5640|5700|5760|5820|5880|5940|6000|6060|6120|6180|6240|6300|6360|6420|6480|6540|6600|6660|6720|6780|6840|6900|6960|7020|7080|7140|7200|7260|7320|7380|7440|7500|7560|7620|7680|7740|7800|7860|7920|7980|8040|8100|8160|8220|8280|8340|8400|8460|8520|8580|8640|8700|8760|8820|8880|8940|9000|9060|9120|9180|9240|9300|9360|9420|9480|9540|9600)$");
    QRegExpValidator* validator = new QRegExpValidator(regex, ui->lineEdit_cutrate);
    ui->lineEdit_cutrate->setValidator(validator);
    ui->lineEdit_cutrate->setMaxLength(4);

    QRegExp regex2("^(?:[0-4]?\\d{1,2}|500)$");
    QRegExpValidator* validator2 = new QRegExpValidator(regex2, ui->lineEdit_vac);
    ui->lineEdit_vac->setValidator(validator2);
    ui->lineEdit_vac->setMaxLength(3);

    QRegExp regex3("^(?:100|[1-9]\\d?|0)$");
    QRegExpValidator* validator3 = new QRegExpValidator(regex3, ui->lineEdit_powmax);
    ui->lineEdit_powmax->setValidator(validator3);
    ui->lineEdit_powmax->setMaxLength(3);

    QRegExp regex4("^(?:100|[1-9]\\d?|0)$");
    QRegExpValidator* validator4 = new QRegExpValidator(regex4, ui->lineEdit_led1);
    ui->lineEdit_led1->setValidator(validator4);
    ui->lineEdit_led1->setMaxLength(3);

    QRegExp regex5("^(?:100|[1-9]\\d?|0)$");
    QRegExpValidator* validator5 = new QRegExpValidator(regex5, ui->lineEdit_led2);
    ui->lineEdit_led2->setValidator(validator5);
    ui->lineEdit_led2->setMaxLength(3);




    ui->lineEdit_powmax->setText(itemname1);
    ui->lineEdit_led1->setText(itemname49);
    ui->lineEdit_led2->setText(itemname50);

    ui->lineEdit_cutrate->setText(itemname34);
    ui->comboBox_cuttermode->setCurrentText(itemname35);
    ui->comboBox_cuttertype->setCurrentText(itemname48);
    ui->lineEdit_vac->setText(itemname36);
    ui->comboBox_mode->setCurrentText(itemname37);

    ui->comboBox_20->setCurrentText(itemname39);
    ui->comboBox_23->setCurrentText(itemname40);
    ui->comboBox_21->setCurrentText(itemname41);
    ui->comboBox_24->setCurrentText(itemname42);
    ui->lineEdit_5->setText(itemname43);



    ui->lineEdit_zero->setText(itemname44);
    ui->progressBar_zero->setValue(ui->lineEdit_zero->text().toInt());

    ui->lineEdit_one->setText(itemname45);
    ui->progressBar_one->setValue(ui->lineEdit_one->text().toInt());

    ui->lineEdit_two->setText(itemname46);
    ui->progressBar_two->setValue(ui->lineEdit_two->text().toInt());

    ui->lineEdit_three->setText(itemname47);
    ui->progressBar_three->setValue(ui->lineEdit_three->text().toInt());


    }

    mydb.close();


    flag = false;

    key = new keypad;
    connect(key, &keypad::textsignal, this, &settingswindow::on_clicked);
    connect(key, &keypad::entersignal, this, &settingswindow::on_clickedenter);
    connect(key, &keypad::backsignal, this, &settingswindow::on_clickedbackspace);

    text=new textkeypad;

    connect(text, &textkeypad::textsignal, this, &settingswindow::on_clickedtext);
    connect(text, &textkeypad::backsignal, this, &settingswindow::on_clickedbackspacetext);
    connect(text, &textkeypad::entersignal, this, &settingswindow::on_clickedentertext);
    connect(text, &textkeypad::spacesignal, this, &settingswindow::on_clickedspace);

    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();


    // for 0
    connect(ui->pushButton_zeroinc, &QPushButton::clicked, this, &settingswindow::zeroinc);
    connect(ui->pushButton_zerodec, &QPushButton::clicked, this, &settingswindow::zerodec);
    // for 1
    connect(ui->pushButton_oneinc, &QPushButton::clicked, this, &settingswindow::oneinc);
    connect(ui->pushButton_onedec, &QPushButton::clicked, this, &settingswindow::onedec);
    // for 2
    connect(ui->pushButton_twoinc, &QPushButton::clicked, this, &settingswindow::twoinc);
    connect(ui->pushButton_twodec, &QPushButton::clicked, this, &settingswindow::twodec);
    // for 3
    connect(ui->pushButton_threeinc, &QPushButton::clicked, this, &settingswindow::threeinc);
    connect(ui->pushButton_threedec, &QPushButton::clicked, this, &settingswindow::threedec);

    int s0,s1,s2,s3;
        s0=ui->lineEdit_zero->text().toInt();
        s1=ui->lineEdit_one->text().toInt();
        s2=ui->lineEdit_two->text().toInt();
        s3=ui->lineEdit_three->text().toInt();
        ui->label_110->setText(QString::number(s0+s1+s2+s3));

    int sum=s0+s1+s2+s3;
    if(sum==100)
    {
        ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
    }
    else
    {
        ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
    }

    ui->listWidget->setCurrentRow(currentindex);

    // Connect the combo box's index changed signal to the slot
    connect(ui->comboBox_cuttertype, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &settingswindow::onComboBoxTypeChanged);

    items << "LED1 On/Off" << "LED2 On/Off" << "Vitrectomy On/Off" << "Diathermy On/Off" << "Silicon Oil On/Off";

    // Connect signals to slot
    connect(ui->comboBox_20, SIGNAL(currentIndexChanged(int)), this, SLOT(updateComboBoxes(int)));
    connect(ui->comboBox_21, SIGNAL(currentIndexChanged(int)), this, SLOT(updateComboBoxes(int)));
    connect(ui->comboBox_23, SIGNAL(currentIndexChanged(int)), this, SLOT(updateComboBoxes(int)));
    connect(ui->comboBox_24, SIGNAL(currentIndexChanged(int)), this, SLOT(updateComboBoxes(int)));


}

// Show keypad
bool settingswindow::eventFilter(QObject* object, QEvent* event)
{
  if(object == ui->lineEdit_cutrate && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(980,280);
        key->show();

    } else if ( k->button() == Qt::RightButton ) {
    }
  }
  if(object == ui->lineEdit_powmax && event->type() == QEvent::MouseButtonPress) {
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
  if(object == ui->lineEdit_vac && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
           key->resize(491,271);
          key->move(980,290);
          key->show();

      } else if ( k->button() == Qt::RightButton ) {

      }
    }
  if(object == ui->lineEdit_led1 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(980,290);
        key->show();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->lineEdit_led2 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        ui->lineEdit_led1->clearFocus();
         key->resize(491,271);
        key->move(980,380);
        key->show();


    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  return false;
}

// Set limits and input validation
void settingswindow::updateLineEditValue(QLineEdit* label, int dig, int value, int maxValue) {
    //qDebug()<<value;
    if (value > maxValue) {
        int temp=value;
        //value=0;
        //dig=0;
        label->setText("");
       // msg->setText(QString("Value must be between 0 and %1.").arg(maxValue));
       // msg->show();
       // timermsg->start(1000);
        label->setText(QString::number(dig));
    } else {
        label->setText(QString::number(value));
       // msg->close();
       // timermsg->stop();
    }
}


// Insert digit from keypad
void settingswindow::on_clicked(const QString& digit)
{

  if(ui->lineEdit_powmax->focusWidget()) {
      ui->lineEdit_cutrate->clearFocus();
      ui->lineEdit_vac->clearFocus();
      ui->lineEdit_led1->clearFocus();
      ui->lineEdit_led2->clearFocus();
      if(!flag)
      {
      ui->lineEdit_powmax->setFocus();
      int dig = digit.toInt();
      int value = (ui->lineEdit_powmax->text()+digit).toInt();
      updateLineEditValue(ui->lineEdit_powmax, dig, value, 100);

   }
  }
  if(ui->lineEdit_cutrate->focusWidget()) {
      ui->lineEdit_powmax->clearFocus();
      ui->lineEdit_vac->clearFocus();
      ui->lineEdit_led1->clearFocus();
      ui->lineEdit_led2->clearFocus();
      if(!flag)
      {
      ui->lineEdit_cutrate->setFocus();
      int dig = digit.toInt();
      int value = (ui->lineEdit_cutrate->text()+digit).toInt();
      updateLineEditValue(ui->lineEdit_cutrate, dig, value, 9600);

   }
  }
if(ui->lineEdit_vac->focusWidget())
  {
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    flag = false;
    if(!flag) {
    ui->lineEdit_vac->setFocus();
    int dig = digit.toInt();
    int value = (ui->lineEdit_vac->text()+digit).toInt();
    updateLineEditValue(ui->lineEdit_vac, dig, value, 650);

 }
}
if(ui->lineEdit_led1->focusWidget())
  {
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->lineEdit_vac->clearFocus();
    flag = false;
    if(!flag) {
    ui->lineEdit_led1->setFocus();
    int dig = digit.toInt();
    int value = (ui->lineEdit_led1->text()+digit).toInt();
    updateLineEditValue(ui->lineEdit_led1, dig, value, 100);
 }
}
if(ui->lineEdit_led2->focusWidget())
  {
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_vac->clearFocus();
    flag = false;
    if(!flag) {
    ui->lineEdit_led2->setFocus();
    int dig = digit.toInt();
    int value = (ui->lineEdit_led2->text()+digit).toInt();
    updateLineEditValue(ui->lineEdit_led2, dig, value, 100);

 }
}


}

// Hide keypad
void settingswindow::on_clickedenter()
{
    key->hide();

    ui->lineEdit_powmax->setText(QString::number(static_cast<int>(std::round(ui->lineEdit_powmax->text().toInt()/5))*5));
    ui->lineEdit_led1->setText(QString::number(static_cast<int>(std::round(ui->lineEdit_led1->text().toInt()/5))*5));
    ui->lineEdit_led2->setText(QString::number(static_cast<int>(std::round(ui->lineEdit_led2->text().toInt()/5))*5));
    ui->lineEdit_cutrate->setText(QString::number(static_cast<int>(std::round(ui->lineEdit_cutrate->text().toInt()/60))*60));
    ui->lineEdit_vac->setText(QString::number(static_cast<int>(std::round(ui->lineEdit_vac->text().toInt()/5))*5));

}

settingswindow::~settingswindow()
{
    delete ui;

}

// Diathermy power maximum
void settingswindow::on_dia_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);

    mydb.open();

    QSqlQuery query;
    QString diapm;

    surgeonid=ui->lineEdit_5->text();
    diapm=ui->lineEdit_powmax->text();

    emit diastr(diapm);

    query.prepare("update maindb set diapm='"+diapm+"'where surgeon='"+surgeonid+"'");
    query.exec();

    query.bindValue(diapm,"diapm");

    mydb.close();

}

// LED1 and LED2
void settingswindow::on_led_clicked()
{

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
    QSqlQuery query;
    QString led1, led2;

    surgeonid = ui->lineEdit_5->text();
    led1 = ui->lineEdit_led1->text();
    led2 = ui->lineEdit_led2->text();

    emit led1str(led1);
    emit led2str(led2);

    query.prepare("update maindb set led1='"+led1+"',led2='"+led2+"'where surgeon='"+surgeonid+"'");
    query.exec();
    query.bindValue(led1,"led1");
    query.bindValue(led2,"led2");
    mydb.close();

}

// Vaccum (mm/hg) and mode
void settingswindow::on_ia_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
    QString vvmax,vvmin,vaspmax;

     surgeonid=ui->lineEdit_5->text();
     vvmax=ui->lineEdit_vac->text();
     vvmin=ui->comboBox_mode->currentText();

     emit vacstr(vvmax);
     emit vacmode(vvmin);

     query.prepare("update maindb set vvmax='"+vvmax+"',vvmin='"+vvmin+"'where surgeon='"+surgeonid+"'");
     query.exec();
     query.bindValue(vvmax,"vvmax");
     query.bindValue(vvmin,"vvmin");

     mydb.close();
}

// Cutrate (cuts/min), mode, cutter type
void settingswindow::on_vit_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
     QSqlQuery query;
     QString surgeon,vcmax,vcmin,vvmax,vvmin,vaspmax,type;

     surgeonid=ui->lineEdit_5->text();
     vcmax=ui->lineEdit_cutrate->text();
     vcmin=ui->comboBox_cuttermode->currentText();
     type=ui->comboBox_cuttertype->currentText();

     emit vitstr(vcmax);
     emit vitmode(vcmin);
     emit vittype(type);

//     if(type == "Midlabs")
//     {
//         ui->lineEdit_maxcutrate->setText("8000");
//     }
//     else if(type == "Aktive")
//     {
//          ui->lineEdit_maxcutrate->setText("7500");
//     }
//     else if(type == "Dorc")
//     {
//          ui->lineEdit_maxcutrate->setText("8000");
//     }


     query.prepare("update maindb set vcmax='"+vcmax+"',vcmin='"+vcmin+"',type='"+type+"'where surgeon='"+surgeonid+"'");
     query.exec();
     query.bindValue(vcmax,"vcmax");
     query.bindValue(vcmin,"vcmin");
     query.bindValue(type, "type");

     mydb.close();

}

// Go to surgery screen
void settingswindow::show_surgery_screen()
{
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    key->hide();
    text->hide();
    this->close();
    parentWidget()->show();
}

// Save footpedal settings for all surgeons
void settingswindow::on_saveforall_clicked()
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

// Save footpedal settings for current surgeon
void settingswindow::on_save_clicked()
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




// Load database from list
void settingswindow::loadDatabaseFromList(const QString &currentText)
{
    key->hide();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->lineEdit_5->setText(currentText);
    surgeonid=ui->lineEdit_5->text();


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
  QString itemname48 = query.value(48).toString();
  QString itemname49 = query.value(49).toString();
  QString itemname50 = query.value(50).toString();

  emit stringPassed1(itemname45);
   emit stringPassed2(itemname46);
   emit stringPassed3(itemname47);



ui->lineEdit_powmax->setText(itemname1);
ui->lineEdit_led1->setText(itemname49);
ui->lineEdit_led2->setText(itemname50);


ui->lineEdit_cutrate->setText(itemname34);
ui->comboBox_cuttermode->setCurrentText(itemname35);
ui->comboBox_cuttertype->setCurrentText(itemname48);
ui->lineEdit_vac->setText(itemname36);
ui->comboBox_mode->setCurrentText(itemname37);
ui->comboBox_20->setCurrentText(itemname39);
ui->comboBox_23->setCurrentText(itemname40);
ui->comboBox_21->setCurrentText(itemname41);
ui->comboBox_24->setCurrentText(itemname42);
ui->lineEdit_5->setText(itemname43);

 ui->lineEdit_zero->setText(itemname44);
 ui->progressBar_zero->setValue(ui->lineEdit_zero->text().toInt());

 ui->lineEdit_one->setText(itemname45);
 ui->progressBar_one->setValue(ui->lineEdit_one->text().toInt());

 ui->lineEdit_two->setText(itemname46);
 ui->progressBar_two->setValue(ui->lineEdit_two->text().toInt());

 ui->lineEdit_three->setText(itemname47);
 ui->progressBar_three->setValue(ui->lineEdit_three->text().toInt());

int s0,s1,s2,s3;
    s0=ui->lineEdit_zero->text().toInt();
    s1=ui->lineEdit_one->text().toInt();
    s2=ui->lineEdit_two->text().toInt();
    s3=ui->lineEdit_three->text().toInt();
    ui->label_110->setText(QString::number(s0+s1+s2+s3));

int sum=s0+s1+s2+s3;
if(sum==100)
{
    ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
}
else
{
    ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
}
//qDebug()<<s1+s2+s3;


}
   docnameold=ui->listWidget->currentItem()->text();
   currentindex=ui->listWidget->currentIndex().row();


mydb.close();
}

// Footpedal 0 (increase)
void settingswindow::zeroinc()
{
    int value=ui->lineEdit_zero->text().toInt();
    int newvalue=value+1;
   ui->lineEdit_zero->setText(QString::number(newvalue));
   ui->progressBar_zero->setValue(newvalue);
   int s0,s1,s2,s3;
       s0=ui->lineEdit_zero->text().toInt();
       s1=ui->lineEdit_one->text().toInt();
       s2=ui->lineEdit_two->text().toInt();
       s3=ui->lineEdit_three->text().toInt();
       ui->label_110->setText(QString::number(s0+s1+s2+s3));

   int sum=s0+s1+s2+s3;
   if(sum==100)
   {
       ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
   }
   else
   {
       ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
   }
}

//  Footpedal 0 (decrease)
void settingswindow::zerodec()
{
    int value=ui->lineEdit_zero->text().toInt();
    int newvalue=value-1;
      ui->lineEdit_zero->setText(QString::number(newvalue));
      ui->progressBar_zero->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_zero->text().toInt();
          s1=ui->lineEdit_one->text().toInt();
          s2=ui->lineEdit_two->text().toInt();
          s3=ui->lineEdit_three->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}

// Footpedal 1 (increase)
void settingswindow::oneinc()
{
    int value=ui->lineEdit_one->text().toInt();
    int newvalue=value+1;
   ui->lineEdit_one->setText(QString::number(newvalue));
   ui->progressBar_one->setValue(newvalue);
   int s0,s1,s2,s3;
       s0=ui->lineEdit_zero->text().toInt();
       s1=ui->lineEdit_one->text().toInt();
       s2=ui->lineEdit_two->text().toInt();
       s3=ui->lineEdit_three->text().toInt();
       ui->label_110->setText(QString::number(s0+s1+s2+s3));

   int sum=s0+s1+s2+s3;
   if(sum==100)
   {
       ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
   }
   else
   {
       ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
   }
}

// Footpedal 2 (increase)
void settingswindow::twoinc()
{
    int value=ui->lineEdit_two->text().toInt();
    int newvalue=value+1;
      ui->lineEdit_two->setText(QString::number(newvalue));
      ui->progressBar_two->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_zero->text().toInt();
          s1=ui->lineEdit_one->text().toInt();
          s2=ui->lineEdit_two->text().toInt();
          s3=ui->lineEdit_three->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}

// Footpedal 3 (increase)
void settingswindow::threeinc()
{
    int value=ui->lineEdit_three->text().toInt();
    int newvalue=value+1;
      ui->lineEdit_three->setText(QString::number(newvalue));
      ui->progressBar_three->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_zero->text().toInt();
          s1=ui->lineEdit_one->text().toInt();
          s2=ui->lineEdit_two->text().toInt();
          s3=ui->lineEdit_three->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}

// Footpedal 1 (decrease)
void settingswindow::onedec()
{
    int value=ui->lineEdit_one->text().toInt();
    int newvalue=value-1;
      ui->lineEdit_one->setText(QString::number(newvalue));
      ui->progressBar_one->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_zero->text().toInt();
          s1=ui->lineEdit_one->text().toInt();
          s2=ui->lineEdit_two->text().toInt();
          s3=ui->lineEdit_three->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}

// Footpedal 2 (decrease)
void settingswindow::twodec()
{
    int value=ui->lineEdit_two->text().toInt();
    int newvalue=value-1;
     ui->lineEdit_two->setText(QString::number(newvalue));
     ui->progressBar_two->setValue(newvalue);
     int s0,s1,s2,s3;
         s0=ui->lineEdit_zero->text().toInt();
         s1=ui->lineEdit_one->text().toInt();
         s2=ui->lineEdit_two->text().toInt();
         s3=ui->lineEdit_three->text().toInt();
         ui->label_110->setText(QString::number(s0+s1+s2+s3));

     int sum=s0+s1+s2+s3;
     if(sum==100)
     {
         ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
     }
     else
     {
         ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
     }
}

// Footpedal 3 (decrease)
void settingswindow::threedec()
{
    int value=ui->lineEdit_three->text().toInt();;
    int newvalue=value-1;
      ui->lineEdit_three->setText(QString::number(newvalue));
      ui->progressBar_three->setValue(newvalue);
      int s0,s1,s2,s3;
          s0=ui->lineEdit_zero->text().toInt();
          s1=ui->lineEdit_one->text().toInt();
          s2=ui->lineEdit_two->text().toInt();
          s3=ui->lineEdit_three->text().toInt();
          ui->label_110->setText(QString::number(s0+s1+s2+s3));

      int sum=s0+s1+s2+s3;
      if(sum==100)
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/save-button 1.png);background-color: transparent; border:none;");
      }
      else
      {
          ui->pushButton_save_6->setStyleSheet("image: url(:/new/prefix1/img/notsave1.png);background-color: transparent; border:none;");
      }
}

// Footpedal settings
void settingswindow::on_fp_settings_clicked()
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName(PATH);
    db1.open();
     QSqlQuery query;
     QString surgeon;
     QString fp0,fp1,fp2,fp3;
     int Fp0,Fp1,Fp2,Fp3;

     surgeonid=ui->lineEdit_5->text();
     fp0=ui->lineEdit_zero->text();
     Fp0=fp0.toInt();

     fp1=ui->lineEdit_one->text();
     Fp1=fp1.toInt();

     fp2=ui->lineEdit_two->text();
     Fp2=fp2.toInt();

     fp3=ui->lineEdit_three->text();
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

// Diathermy tab
void settingswindow::on_tab_dia_clicked()
{
key->hide();
ui->lineEdit_cutrate->clearFocus();
ui->lineEdit_powmax->clearFocus();
ui->lineEdit_vac->clearFocus();
ui->lineEdit_led1->clearFocus();
ui->lineEdit_led2->clearFocus();
    ui->tabWidget_2->setCurrentIndex(0);
    ui->label_title->setText("Diathermy");
    ui->label_27->show();
    ui->vit->setStyleSheet("image: url(:/new/prefix1/img/diaicon2.png);");

}

// LED tab
void settingswindow::on_tab_led_clicked()
{
    key->hide();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->tabWidget_2->setCurrentIndex(1);
    ui->label_title->setText("LED");
    ui->label_27->hide();
    ui->vit->setStyleSheet("image: url(:/new/prefix1/img/ledsw.png);");

}

// Irrigation/aspiration tab
void settingswindow::on_tab_ia_clicked()
{key->hide();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->tabWidget_2->setCurrentIndex(2);
    ui->label_title->setText("I/A");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/iaicon3.png);");
        ui->label_27->hide();

}

// Vitrectomy tab
void settingswindow::on_tab_vit_clicked()
{key->hide();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->tabWidget_2->setCurrentIndex(3);
    ui->label_title->setText("Vitrectomy");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/viticon1.png);");
            ui->label_27->hide();

}

// Footpedal tab
void settingswindow::on_tab_fp_clicked()
{key->hide();
    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    ui->tabWidget_2->setCurrentIndex(4);

    ui->label_title->setText("FS buttons");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/fpicon.png);");
            ui->label_27->hide();

}

// Footpedal preset tab
void settingswindow::on_tab_fppreset_clicked()
{

    ui->lineEdit_cutrate->clearFocus();
    ui->lineEdit_powmax->clearFocus();
    ui->lineEdit_vac->clearFocus();
    ui->lineEdit_led1->clearFocus();
    ui->lineEdit_led2->clearFocus();
    key->hide();
    ui->tabWidget_2->setCurrentIndex(5);
    ui->label_title->setText("FS preset");
        ui->vit->setStyleSheet("image: url(:/new/prefix1/img/fpsicon1.png);");
            ui->label_27->hide();

}

// Update surgeon name (insert)
void settingswindow::on_clickedtext(const QString& digit)
{

  if(ui->lineEdit_5->focusWidget()) {
      QString text= ui->lineEdit_5->text();
       ui->lineEdit_5->setText(text+digit);

   }
 }

// Update surgeon name (backspace)
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

// Update surgeon name (space bar)
void settingswindow::on_clickedspace()
{

  QString text= ui->lineEdit_5->text();

   // Add a space to the end of the text
   text.append(' ');

   // Set the modified text back to the QTextEdit
    ui->lineEdit_5->setText(text);
}

// Update surgeon name (load in database)
void settingswindow::on_clickedentertext()
{
    QString docnamenew = ui->lineEdit_5->text();
    qDebug()<<ui->lineEdit_5->text();
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName(PATH);

    if (!db1.open())
    {
        qDebug()  << "Error opening database:";
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

    text->hide();
}

void settingswindow::on_clickedbackspace()
{
    if(ui->lineEdit_powmax->focusWidget()) {
        QString data = ui->lineEdit_powmax->text();
        data.chop(1);
        ui->lineEdit_powmax->setText(data);
    }
    if(ui->lineEdit_cutrate->focusWidget()) {
        QString data = ui->lineEdit_cutrate->text();
        data.chop(1);
        ui->lineEdit_cutrate->setText(data);
    }
  if(ui->lineEdit_vac->focusWidget())
    {
      QString data = ui->lineEdit_vac->text();
      data.chop(1);
      ui->lineEdit_vac->setText(data);
  }
  if(ui->lineEdit_led1->focusWidget())
    {
      QString data = ui->lineEdit_led1->text();
      data.chop(1);
      ui->lineEdit_led1->setText(data);
  }
  if(ui->lineEdit_led2->focusWidget())
    {
      QString data = ui->lineEdit_led2->text();
      data.chop(1);
      ui->lineEdit_led2->setText(data);
  }
}

void settingswindow::updateComboBoxes(int index) {
        QList<QComboBox *> combos = {ui->comboBox_20, ui->comboBox_21, ui->comboBox_23, ui->comboBox_24};

        // Collect selected items
        QSet<QString> selectedItems;
        for (QComboBox *comboBox : combos) {
            if (comboBox->currentIndex() != -1) {
                selectedItems.insert(comboBox->currentText());
            }
        }

        // Update each combo box
        for (QComboBox *comboBox : combos) {
            QString currentText = comboBox->currentText();
            comboBox->blockSignals(true); // Block signals to prevent recursive updates
            comboBox->clear();

            for (const QString &item : items) {
                if (!selectedItems.contains(item) || item == currentText) {
                    comboBox->addItem(item);
                }
            }

            comboBox->setCurrentText(currentText);
            comboBox->blockSignals(false); // Unblock signals
        }
    }

void settingswindow::onComboBoxTypeChanged(int index)
{
    switch (index) {
    //Midlabs
    case 0:
        ui->lineEdit_maxcutrate->setText("8000");
        break;
    //Aktive
    case 1:
        ui->lineEdit_maxcutrate->setText("7500");
        break;
    //Dorc
    case 2:
        ui->lineEdit_maxcutrate->setText("8000");
        break;
    default:
        break;
    }
}

