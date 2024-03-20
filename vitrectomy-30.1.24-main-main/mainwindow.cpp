#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QLabel>
#include <QtDebug>
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QStyleFactory>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QRegExp>
#include <QRegExpValidator>

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define PATH "/home/main.db"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    fp = new footpedal;
    hhandler = new hwHandler;
    vac = new Vaccum;

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxClicked);

     timerforondscreen = new QTimer;
     timerforondscreen->start(7000);
     connect(timerforondscreen, &QTimer::timeout, this, &MainWindow::timerCompleted);

    //code to load database
    QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName(PATH);

     mydb1.open();


    QSqlQuery  query;
    QString itemname1;
    QString itemname34;
    QString itemname35;
    QString itemname36;
     QString itemname43;
     QString itemname44;
     QString itemname45;
     QString itemname46;
     QString itemname47;
     query.exec("SELECT lastselected FROM maindb LIMIT 1");
    QString itemname48;
    if(query.next()){
        itemname48=query.value(0).toString();
        qDebug()<<itemname48;
        surgeonind=itemname48.toInt();
    }
     query.exec("select * from maindb where surgeon='DEFAULT SURGEON'");
     if(query.next()){
        itemname1 = query.value(0).toString();
          ui->label_6->setText(itemname1);
          itemname34 = query.value(33).toString();
          ui->label_4->setText(itemname34);

          itemname35 = query.value(34).toString();
          if(itemname35=="Linear")
          {
                ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");


          }
          else
          {

               ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");

          }
               itemname36 = query.value(35).toString();
               ui->label_3->setText(itemname36);
        itemname43 = query.value(42).toString();

          itemname44= query.value(43).toString();
          fp0=itemname44.toDouble()*40.95;
          itemname45 = query.value(44).toString();
          fp1=itemname45.toDouble()*40.95;
          itemname46 = query.value(45).toString();
          fp2=itemname46.toDouble()*40.95;
          itemname47 = query.value(46).toString();
          fp3=itemname47.toDouble()*40.95;
          itemname48 = query.value(47).toString();

     }



mydb1.close();
comboboxload();
ui->comboBox_2->setCurrentIndex(surgeonind);

    win2=new settingswindow(this);



  QObject::connect(win2, &settingswindow::stringPassed, this, &MainWindow::receiveString);

    hhandler->vit_off();
   \
    avg=fp->convert(CHANNEL_0);

    ui->label_4->setText(QString::number(vit_value));

    timer48.start(100);
    connect(&timer48,&QTimer::timeout, this, &MainWindow::label48);

    QTimer *timer = new QTimer(this);
    QTimer *timerfortd = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel);
    connect(timerfortd, &QTimer::timeout, this, &MainWindow::updatetimedate);

    frequency = 1000 * vit_value/60;
    dutycycle = frequency - 40;

    hhandler->ai_off();
    hhandler->ai_preset_count(0);
    hhandler->ai_actual_count(0);

    led1 = new LED(PORT1);
    led2 = new LED(PORT2);

    timerfortd->start(1000);
    timer->start(30);

    // code for animations
    animation = new QPropertyAnimation(ui->label_31, "pos");
    animation1 = new QPropertyAnimation(ui->label_33, "pos");
    animation2 = new QPropertyAnimation(ui->label_32, "pos");
    animation3 = new QPropertyAnimation(ui->label_30, "pos");
    animation4 = new QPropertyAnimation(ui->label_29, "pos");
    animation5 = new QPropertyAnimation(ui->label_42, "pos");

    ui->dial->setStyleSheet("");
    ui->dial->setStyle(QStyleFactory::create("Fusion"));
    ui->dial->setStyleSheet("background-color: rgb(26, 95, 180);");
    ui->dial->setRange(0, 4096);

    ui->dial->setValue(avg);

    connect(win2, &settingswindow::led1str, this, &MainWindow::led1val);
    connect(win2, &settingswindow::led2str, this, &MainWindow::led2val);

    connect(&timeai3, &QTimer::timeout, this, &MainWindow::aibackground);
    timeai3.start(10);

    key = new keypad;
    connect(key, &keypad::textsignal, this, &MainWindow::on_clicked);
    connect(key, &keypad::backsignal, this, &MainWindow::on_clickedbackspace);
    connect(key, &keypad::entersignal, this, &MainWindow::on_clickedenter);


    ui->label_5->installEventFilter(this);
    ui->label_4->installEventFilter(this);
    ui->label_8->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->label_6->installEventFilter(this);
    ui->label_37->installEventFilter(this);
    ui->label_9->installEventFilter(this);

    ui->label_4->clearFocus();
    ui->label_8->clearFocus();
    ui->label_3->clearFocus();
    ui->label_6->clearFocus();
    ui->label_37->clearFocus();
    ui->label_5->clearFocus();
    ui->label_9->clearFocus();


    QTimer *timermain = new QTimer(this);
    timermain->setSingleShot(true);
    timermain->start(3000); // 3 seconds
    connect(timermain, &QTimer::timeout, this, &MainWindow::transitionToNewScreen);



}

void MainWindow::transitionToNewScreen() {
    ui->label_22->hide();
    ui->label_12->hide();
    ui->comboBox_2->move(30,34);
    ui->pushButton_25->hide();
}


void MainWindow::updateLabelValue(QLabel* label, int value, int maxValue) {
    if (value > maxValue) {
        label->setText(QString::number(maxValue));
    } else {
        label->setText(QString::number(value));
    }
}

// keypad showing code
bool MainWindow::eventFilter(QObject* object, QEvent* event)
{
  if(object == ui->label_5 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(180,400);
        key->show();
        ui->label_5->setFocus();
        ui->label_4->clearFocus();
        ui->label_8->clearFocus();
        ui->label_3->clearFocus();
        ui->label_6->clearFocus();
        ui->label_37->clearFocus();
        ui->label_9->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {
    }
  }
  if(object == ui->label_4 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(110,500);
        key->show();
        ui->label_4->setFocus();
        ui->label_5->clearFocus();
        ui->label_8->clearFocus();
        ui->label_3->clearFocus();
        ui->label_6->clearFocus();
        ui->label_37->clearFocus();
        ui->label_9->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_8 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
    key->resize(491, 271);
    key->move(850,450);
    key->show();
    ui->label_8->setFocus();
    ui->label_4->clearFocus();
    ui->label_5->clearFocus();
    ui->label_3->clearFocus();
    ui->label_6->clearFocus();
    ui->label_37->clearFocus();
    ui->label_9->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_3 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
           key->resize(491,271);
          key->move(1400,390);
          key->show();
          ui->label_3->setFocus();
          ui->label_4->clearFocus();
          ui->label_8->clearFocus();
          ui->label_5->clearFocus();
          ui->label_6->clearFocus();
          ui->label_37->clearFocus();
          ui->label_9->clearFocus();

      } else if ( k->button() == Qt::RightButton ) {

      }
    }
  if(object == ui->label_6 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(1400,450);
        key->show();
        ui->label_6->setFocus();
        ui->label_4->clearFocus();
        ui->label_8->clearFocus();
        ui->label_3->clearFocus();
        ui->label_5->clearFocus();
        ui->label_37->clearFocus();
        ui->label_9->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_37 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(550,400);
        key->show();
        ui->label_37->setFocus();
        ui->label_4->clearFocus();
        ui->label_8->clearFocus();
        ui->label_3->clearFocus();
        ui->label_6->clearFocus();
        ui->label_5->clearFocus();
        ui->label_9->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_9 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
         key->resize(491,271);
        key->move(500,400);
        key->show();
        ui->label_9->setFocus();
        ui->label_4->clearFocus();
        ui->label_8->clearFocus();
        ui->label_3->clearFocus();
        ui->label_6->clearFocus();
        ui->label_37->clearFocus();
        ui->label_5->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  return false;
}

//settings focus and insert digit
void MainWindow::on_clicked(const QString& digit)
{

  if(ui->label_5->focusWidget()) {
      ui->label_4->clearFocus();
      ui->label_8->clearFocus();
      ui->label_3->clearFocus();
      ui->label_6->clearFocus();
      ui->label_37->clearFocus();
      ui->label_9->clearFocus();
      if(!flag)
      {
      ui->label_5->setFocus();
      ui->label_5->setText(ui->label_5->text()+digit);
      updateLabelValue(ui->label_5, ui->label_5->text().toInt(), 500);

   }
  }
  if(ui->label_4->focusWidget()) {
      ui->label_5->clearFocus();
      ui->label_8->clearFocus();
      ui->label_3->clearFocus();
      ui->label_6->clearFocus();
      ui->label_37->clearFocus();
      ui->label_9->clearFocus();
      if(!flag)
      {
      ui->label_4->setFocus();
      ui->label_4->setText(ui->label_4->text()+digit);
      updateLabelValue(ui->label_4, ui->label_4->text().toInt(), 9600);

   }
  }
if(ui->label_8->focusWidget()) {
    ui->label_4->clearFocus();
    ui->label_5->clearFocus();
    ui->label_3->clearFocus();
    ui->label_6->clearFocus();
    ui->label_37->clearFocus();
    ui->label_9->clearFocus();
    if(!flag)
    {
    ui->label_8->setFocus();
    ui->label_8->setText(ui->label_8->text()+digit);
    updateLabelValue(ui->label_8, ui->label_8->text().toInt(), 100);


 }
}
if(ui->label_3->focusWidget()) {
    ui->label_4->clearFocus();
    ui->label_8->clearFocus();
    ui->label_5->clearFocus();
    ui->label_6->clearFocus();
    ui->label_37->clearFocus();
    ui->label_9->clearFocus();
    if(!flag)
    {
    ui->label_3->setFocus();
    ui->label_3->setText(ui->label_3->text()+digit);
    updateLabelValue(ui->label_3, ui->label_3->text().toInt(), 100);

 }
}
if(ui->label_6->focusWidget()) {
    ui->label_4->clearFocus();
    ui->label_8->clearFocus();
    ui->label_3->clearFocus();
    ui->label_5->clearFocus();
    ui->label_37->clearFocus();
    ui->label_9->clearFocus();
    if(!flag)
    {
    ui->label_6->setFocus();
    ui->label_6->setText(ui->label_6->text()+digit);
     updateLabelValue(ui->label_6, ui->label_6->text().toInt(), 100);

 }
}
if(ui->label_37->focusWidget()) {
    ui->label_4->clearFocus();
    ui->label_8->clearFocus();
    ui->label_3->clearFocus();
    ui->label_6->clearFocus();
    ui->label_5->clearFocus();
    ui->label_9->clearFocus();
    if(!flag)
    {
    ui->label_37->setFocus();
    ui->label_37->setText(ui->label_37->text()+digit);
    updateLabelValue(ui->label_37, ui->label_37->text().toInt(), 100);

 }
}
if(ui->label_9->focusWidget()) {
    ui->label_4->clearFocus();
    ui->label_8->clearFocus();
    ui->label_3->clearFocus();
    ui->label_6->clearFocus();
    ui->label_37->clearFocus();
    ui->label_5->clearFocus();
    if(!flag)
    {
    ui->label_9->setFocus();
    ui->label_9->setText(ui->label_9->text()+digit);
     updateLabelValue(ui->label_9, ui->label_9->text().toInt(), 100);

 }
}


}

void MainWindow::on_clickedbackspace()
{
    if (ui->label_5->focusWidget())
    {

        QString data = ui->label_5->text();
        data.chop(3);
        ui->label_5->setText(data);

    }

    if (ui->label_4->focusWidget())
    {

        QString data = ui->label_4->text();
        data.chop(3);
        ui->label_4->setText(data);

    }

    if (ui->label_8>focusWidget())
    {

        QString data = ui->label_8->text();
        data.chop(3);
        ui->label_8->setText(data);

    }

    if (ui->label_3->focusWidget())
    {

        QString data = ui->label_3->text();
        data.chop(3);
        ui->label_3->setText(data);

    }

    if (ui->label_6->focusWidget())
    {

        QString data = ui->label_6->text();
        data.chop(3);
        ui->label_6->setText(data);

    }

    if (ui->label_37->focusWidget())
    {

        QString data = ui->label_37->text();
        data.chop(3);
        ui->label_37->setText(data);

    }

    if (ui->label_9->focusWidget())
    {

        QString data = ui->label_9->text();
        data.chop(3);
        ui->label_9->setText(data);

    }
}

void MainWindow::on_clickedenter()
{
    key->hide();
    led1->processUserInput(round(30-(ui->label_9->text().toInt()*27/100)));
    led2->processUserInput(round(30-(ui->label_37->text().toInt()*27/100)));
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::aibackground()
{
    if(aiflag)
    {
        airinjector();
        //qDebug()<<"On";
    }
    if(!aiflag)
    {
        airinjector2();
        //qDebug()<<"Off";
    }
}

//settings window showing

void MainWindow::on_pushButton_6_clicked()
{

    win2->show();
}


// on off buttons
void MainWindow::on_pushButton_2_clicked()
{  if(sp==0)
    {
        ui->label_19->setStyleSheet("background-color: rgb(116, 184, 222);");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_18->raise();
        ui->pushButton_19->raise();
        ui->label_8->raise();

        animation->setStartValue(QPoint(930,160));
        animation->setEndValue(QPoint(980, 160));
        animation->setDuration(250);
        animation->start();

        ui->label_31->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");
        connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::increasesiliconoil);
        connect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::decreasesiliconoil);
        sp=1;

        }
        else
        {
        ui->label_19->setStyleSheet("");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_18->lower();
        ui->pushButton_19->lower();
        ui->label_8->lower();

        animation->setStartValue(QPoint(980,160));
        animation->setEndValue(QPoint(930, 160));
        animation->setDuration(250);
        animation->start();

        ui->label_31->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");
        disconnect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::increasesiliconoil);
        disconnect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::decreasesiliconoil);
        sp=0;
        }

}


void MainWindow::on_pushButton_20_clicked()
{
    if(vp==0)
    {
       ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/nonbg1.png);");
       vp=1;
    }
    else
    {

        ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/linbg3.png);");
        vp=0;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
        if(lp==0)
        {
            ui->label_27->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");

            animation3->setStartValue(QPoint(800,640));
            animation3->setEndValue(QPoint(850,640));
            animation3->setDuration(250);
            animation3->start();
            ui->label_30->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");

            led1->processUserInput(1);


            connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
            connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);


    lp=1;

        }
        else
        {    ui->label_27->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
            animation3->setStartValue(QPoint(850,640));
            animation3->setEndValue(QPoint(800,640));
            animation3->setDuration(250);
            animation3->start();
            ui->label_30->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");

            led1->processUserInput(2);

            disconnect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
            disconnect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);
           lp=0;
        }

}
void MainWindow::on_pushButton_23_clicked()
{
    if(lp2==0)
    {
        ui->label_41->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        animation5->setStartValue(QPoint(1060,640));
        animation5->setEndValue(QPoint(1110,640));
        animation5->setDuration(250);
        animation5->start();
        ui->label_42->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");

        led2->processUserInput(1);

        connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::increaseledvalue2);
        connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::decreaseledvalue2);


        lp2=1;

    }
    else
    {   ui->label_41->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        animation5->setStartValue(QPoint(1110,640));
        animation5->setEndValue(QPoint(1060,640));
        animation5->setDuration(250);
        animation5->start();
        ui->label_42->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");

        led2->processUserInput(2);

        disconnect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::increaseledvalue2);
        disconnect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::decreaseledvalue2);
       lp2=0;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
        if(dp==0)
        {
            ui->label_14->setStyleSheet("background-color: rgb(116, 184, 222);");
            ui->label_25->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
            ui->pushButton_10->raise();
            ui->pushButton_14->raise();
            ui->label_6->raise();
            animation2->setStartValue(QPoint(1440,620));
            animation2->setEndValue(QPoint(1490,620));
            animation2->setDuration(250);
            animation2->start();
            ui->label_32->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");

            timedia.start(1000);
            connect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);


            connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
            connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);
            dp=1;

        }
        else
        {
            ui->label_14->setStyleSheet("");
            ui->label_25->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
            ui->pushButton_10->lower();
            ui->pushButton_14->lower();
            ui->label_6->lower();
            animation2->setStartValue(QPoint(1490,620));
            animation2->setEndValue(QPoint(1440,620));
            animation2->setDuration(250);
            animation2->start();
            ui->label_32->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");

            hhandler->dia_off();

            timedia.stop();
            disconnect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);

            disconnect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
            disconnect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);
           dp=0;
        }
}

void MainWindow::on_pushButton_7_clicked()
{
        if(ap==0)
        {
            ui->label_13->setStyleSheet("background-color: rgb(116, 184, 222);");
            ui->label_23->setStyleSheet("font: 40pt;color: rgb(0, 0, 0);");
            ui->pushButton_13->raise();
            ui->pushButton_9->raise();
            ui->label_3->raise();
            ui->label_10->raise();

            animation4->setStartValue(QPoint(1300,160));
            animation4->setEndValue(QPoint(1350,160));
            animation4->setDuration(250);
            animation4->start();
            ui->label_29->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");

            timeai.start(100);
            connect(&timeai, &QTimer::timeout, this, &MainWindow::airinjector);

            timeai2.stop();
            disconnect(&timeai2, &QTimer::timeout, this, &MainWindow::airinjector2);


            connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
            connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);

            ap=1;

        }
        else if(ap==1)
        {
            ui->label_13->setStyleSheet("");
            ui->label_23->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
            ui->pushButton_13->lower();
            ui->pushButton_9->lower();
            ui->label_10->lower();
            ui->label_3->lower();
            animation4->setStartValue(QPoint(1350,160));
            animation4->setEndValue(QPoint(1300,160));
            animation4->setDuration(250);
            animation4->start();
            ui->label_29->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");

            timeai2.start(100);
            connect(&timeai2, &QTimer::timeout, this, &MainWindow::airinjector2);

            timeai.stop();
            disconnect(&timeai, &QTimer::timeout, this, &MainWindow::airinjector);

            disconnect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
            disconnect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);

            ap=0;
        }
}

void MainWindow::on_pushButton_4_clicked()
{
        if(vip==0)
        {
            ui->label_38->setStyleSheet("background-color: rgb(116, 184, 222);");

            ui->label_24->setStyleSheet("font: 40pt ;color: rgb(0, 0, 0);");
            ui->pushButton_11->raise();
            ui->pushButton_15->raise();
            ui->label_4->raise();
            ui->label_48->raise();

            animation1->setStartValue(QPoint(380,640));
            animation1->setEndValue(QPoint(430,640));
            animation1->setDuration(250);
            animation1->start();
            ui->label_33->setStyleSheet("image: url(:/new/prefix1/img/on1.png);");
            vip=1;

            if(avg>= (fp1+fp2+fp0)){hhandler->vit_on(1000/(vit_value/60));}

            connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
            connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);



        }

        else if(vip==1)
            {   ui->label_38->setStyleSheet("");
                ui->label_24->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
                ui->pushButton_11->lower();
                ui->pushButton_15->lower();
                ui->label_4->lower();
                ui->label_48->lower();

                animation1->setStartValue(QPoint(430,640));
                animation1->setEndValue(QPoint(380,640));
                animation1->setDuration(250);
                ui->label_33->setStyleSheet("image: url(:/new/prefix1/img/fpled.png);");
                animation1->start();
                vip=0;

                if(avg<= (fp1+fp2+fp0)){hhandler->vit_off();}


            disconnect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
            disconnect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);



        }
}
//update label from hardware values
void MainWindow::updateLabel()
{

    // FOOTPEDAL

// setting value for dial
    avg = fp->convert(CHANNEL_0);


  if(vp==0)
  {//linear

      ui->dial->setValue(avg);

      if(avg >= 0 && avg <= fp0)
      {
          ui->label_36->setText("0");
          hhandler->vso_off();
           int avg1=vac->stabilize();
           ui->label_2->setText(QString::number(avg1));
         if(vip==1){hhandler->vit_off();}
         if(vip==0){hhandler->vit_off();}




      }
      if(avg > fp0&& avg <= (fp1+fp0))
      {
        //irrigation
          ui->label_36->setText("1");
          hhandler->vso_off();
          int avg1=vac->stabilize();
          ui->label_2->setText(QString::number(avg1));
          if(vip==1){hhandler->vit_off();}
          if(vip==0){hhandler->vit_off();}



      }
      if((avg > (fp1+fp0) && avg <= (fp1+fp2+fp0))&&fp2!=0)
      {
          if(flag2==0)
          {
          //vaccum
          ui->label_36->setText("2");

          float freq = 12000;
          float timeon;

          std::string col1, col2;
          std::ifstream file(PATH2);
            int lineCount=0;
          while(file >> col1 >> col2)
          {
              if(std::stoi(col2) <= (ui->label_5->text().toInt()))
              {
                  lineCount++;
              }
              else
              {
                  lineCount = lineCount;
              }
          }

        std::string line;
        idx = ((avg-fp0-fp1)/fp2)*lineCount;
        std::ifstream file2(PATH2);

        for (double i = 1; i <= idx; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> timeon;

        qDebug()<<timeon;

        hhandler->vso_ontime(((timeon / (100*freq)) / resolution));
        hhandler->vso_period(((1 / freq) / resolution));
        int avg1=vac->stabilize();
        ui->label_2->setText(QString::number(avg1));

        file.close();
        file2.close();

          if(vip==1){hhandler->vit_off();}



          if(vip==0){hhandler->vit_off();}
          }
          else {
              if(flag2==1)
              {
                  //swap
               ui->label_36->setText("2");

               hhandler->vso_off();
               int avg1=vac->stabilize();
               ui->label_2->setText(QString::number(avg1));

               if(vip==1 && vitp==1){hhandler->vit_on(1000/(vit_value/60));ui->label_48->setText("0");}
               if(vip==1 && vitp==0)
               {
                   linearcall();
               }
               if(vip==0) {hhandler->vit_off();ui->label_48->setText("0");}

              }
          }

      }
      //vitrectomy
      if((avg > (fp1+fp2+fp0)&& avg <= (fp1+fp2+fp3+fp0))&&fp2!=0&&fp3!=0)
      {
       ui->label_36->setText("3");

       float freq = 12000;
       float timeon;

       std::string col1, col2;
       std::ifstream file(PATH2);
         int lineCount=0;
       while(file >> col1 >> col2)
       {
           if(std::stoi(col2) <= ui->label_5->text().toInt())
           {
               lineCount++;
           }
           else
           {
               lineCount = lineCount;
           }
       }


       std::ifstream file2(PATH2);
       std::string line;
       for (int i = 1; i <= lineCount; i++) {
           std::getline(file2, line);
       }


       std::istringstream iss(line);
       std::string column1, column2;
       iss >> column1 >> column2;

       std::stringstream ss(column1);
       ss >> timeon;

       qDebug()<<timeon;

       hhandler->vso_ontime(((timeon / (100*freq)) / resolution));
       hhandler->vso_period(((1 / freq) / resolution));
       int avg1=vac->stabilize();
       ui->label_2->setText(QString::number(avg1));

       file.close();
        file2.close();


       if(vip==1 && vitp==1){hhandler->vit_on(1000/(vit_value/60));ui->label_48->setText("0");}
       else if(vip==1 && vitp==0)
       {
           hhandler->vit_on(1000/(vit_value/60));
           ui->label_48->setText(QString::number(vit_value));

       }
       if(vip==0) {hhandler->vit_off();ui->label_48->setText("0");}

     }
  }
  if(vp==1)
  {//non-linear


    if(avg >= 0 && avg <= fp0)
    {
        ui->dial->setValue(0);
        ui->label_36->setText("0");
        if(vip==1){hhandler->vit_off();}
        if(vip==0){hhandler->vit_off();}
        hhandler->vso_off();
        int avg1=vac->stabilize();
        ui->label_2->setText(QString::number(avg1));

    }
    if((avg > fp0&& avg <= (fp1+fp0)))
    {
        ui->dial->setValue((fp1+fp0));
        ui->label_36->setText("1");
        if(vip==1){hhandler->vit_off();}
       if(vip==0){hhandler->vit_off();}

       hhandler->vso_off();
       int avg1=vac->stabilize();
       ui->label_2->setText(QString::number(avg1));

    }
    if((avg > (fp1+fp0) && avg <= (fp1+fp2+fp0))&&fp2!=0)
    {
        if(flag2==0)
        {
            //vaccum
            //normal
        ui->dial->setValue(fp1+fp2+fp0);
        ui->label_36->setText("2");

        if(vip==1){hhandler->vit_off();}
        if(vip==0){hhandler->vit_off();}

        float freq = 12000;
        float timeon;

        std::string col1, col2;
        std::ifstream file(PATH2);
          int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col2) <= ui->label_5->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::ifstream file2(PATH2);
        std::string line;
        for (int i = 1; i <= lineCount; i++) {
            std::getline(file2, line);
        }

        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> timeon;

        qDebug()<<timeon;

        hhandler->vso_ontime(((timeon / (100*freq)) / resolution));
        hhandler->vso_period(((1 / freq) / resolution));
        int avg1=vac->stabilize();
        ui->label_2->setText(QString::number(avg1));

        file.close();
         file2.close();
    }
}
    else {
        if(flag2==1)
        {
            //swap
            ui->dial->setValue(fp1+fp2+fp0);
            ui->label_36->setText("2");

           if(vip==1 && vitp==1){hhandler->vit_on(1000/(vit_value/60));ui->label_48->setText("0");}
           if(vip==1 && vitp==0)
           {
               linearcall();
           }
           if(vip==0){hhandler->vit_off();ui->label_48->setText("0");}

           hhandler->vso_off();
           int avg1=vac->stabilize();
           ui->label_2->setText(QString::number(avg1));
        }
    }

    //vitrectomy
    if((avg > (fp1+fp2+fp0)&& avg <= (fp1+fp2+fp3)+fp0)&&fp2!=0&&fp3!=0)
    {
         ui->dial->setValue(fp1+fp2+fp3+fp0);
         ui->label_36->setText("3");

        if(vip==1 && vitp==1){hhandler->vit_on(1000/(vit_value/60));ui->label_48->setText("0");}
        if(vip==1 && vitp==0)
        {
            hhandler->vit_on(1000/(vit_value/60));
            ui->label_48->setText(QString::number(vit_value));

        }
        if(vip==0){hhandler->vit_off();ui->label_48->setText("0");}


        float freq = 12000;
        float timeon;

        std::string col1, col2;
        std::ifstream file(PATH2);
          int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col2) <= ui->label_5->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::ifstream file2(PATH2);
        std::string line;
        for (int i = 1; i <= lineCount; i++) {
            std::getline(file2, line);
        }

        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> timeon;

        qDebug()<<timeon;

        hhandler->vso_ontime(((timeon / (100*freq)) / resolution));
        hhandler->vso_period(((1 / freq) / resolution));
        int avg1=vac->stabilize();
        ui->label_2->setText(QString::number(avg1));

        file.close();
        file2.close();

    }
  }
}

// inc / dec values in label
void MainWindow::increaseVaccumValue()
{
    int currentValue = ui->label_5->text().toInt();
    int newValue = currentValue + 5;
    ui->label_5->setText(QString::number(newValue));
}

void MainWindow::decreaseVaccumValue()
{
    int currentValue = ui->label_5->text().toInt();
    int newValue = currentValue - 5;
    ui->label_5->setText(QString::number(newValue));
}

void MainWindow::increaseVitrectomyValue()
{

    ui->label_4->setText(QString::number(vit_value));
    vit_value = vit_value + 60;
    if(vit_value>8000)
    {
        vit_value=8000;
    }
    ui->label_4->setText(QString::number(vit_value));
}

void MainWindow::decreaseVitrectomyValue()
{
    ui->label_4->setText(QString::number(vit_value));
    vit_value = vit_value - 60;
    if(vit_value<60)
    {
        vit_value=60;
    }
    ui->label_4->setText(QString::number(vit_value));
}

void MainWindow::increaseDiathermyValue()
{
    int currentValue = ui->label_6->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    ui->label_6->setText(QString::number(newValue));
}

void MainWindow::decreaseDiathermyValue()
{
    int currentValue = ui->label_6->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    ui->label_6->setText(QString::number(newValue));
}

void MainWindow::increaseAirInjectorValue()
{
    int currentValue = ui->label_3->text().toInt();
    int newValue = currentValue + 1;
    if(newValue>100)
    {
        newValue=100;
    }
    ui->label_3->setText(QString::number(newValue));
    ui->progressBar->setValue(newValue);
}

void MainWindow::decreaseAirInjectorValue()
{
    int currentValue = ui->label_3->text().toInt();
    int newValue = currentValue - 1;
    if(newValue<0)
    {
        newValue=0;
    }
    ui->label_3->setText(QString::number(newValue));
    ui->progressBar->setValue(newValue);
}

void MainWindow::increaseledvalue()
{
    int currentValue = ui->label_9->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    double choice = newValue;
    led1->processUserInput(round(30-(choice*27/100)));
    ui->label_9->setText(QString::number(newValue));

}

void MainWindow::decreaseledvalue()
{
    int currentValue = ui->label_9->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    double choice = newValue;
    led1->processUserInput(round(30-(choice*27/100)));
    ui->label_9->setText(QString::number(newValue));
}

void MainWindow::increaseledvalue2()
{
    int currentValue = ui->label_37->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    double choice = newValue;
    led2->processUserInput(round(30-(choice*27/100)));
    ui->label_37->setText(QString::number(newValue));
}

void MainWindow::decreaseledvalue2()
{
    int currentValue = ui->label_37->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    double choice = newValue;
    led2->processUserInput(round(30-(choice*27/100)));
    ui->label_37->setText(QString::number(newValue));
}

void MainWindow::increasesiliconoil()
{
    int currentValue = ui->label_8->text().toInt();
    int newValue = currentValue + 5;
    ui->label_8->setText(QString::number(newValue));
}

void MainWindow::decreasesiliconoil()
{
    int currentValue = ui->label_8->text().toInt();
    int newValue = currentValue - 5;
    ui->label_8->setText(QString::number(newValue));
}

void MainWindow::receiveString(const QString& str)
{
    ui->label_11->setText(str);
}

void MainWindow::led1val(QString str)
{
    ui->label_9->setText(str);
    led1->processUserInput(round(30-(ui->label_9->text().toInt()*27/100)));
}

void MainWindow::led2val(QString str)
{
    ui->label_37->setText(str);
    led2->processUserInput(round(30-(ui->label_37->text().toInt()*27/100)));
}

void MainWindow::on_pushButton_clicked()
{

   QString surgeon;
   surgeon=ui->label_11->text();

}

// code for continuous press

//inc vaccum
void MainWindow::on_pushButton_8_pressed()
{

    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseVaccumValue);

}

void MainWindow::on_pushButton_8_released()
{
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseVaccumValue);

}

//dec vaccum
void MainWindow::on_pushButton_12_pressed()
{
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseVaccumValue);
}


void MainWindow::on_pushButton_12_released()
{
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseVaccumValue);
}

//inc vit
void MainWindow::on_pushButton_11_pressed()
{if(vip==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseVitrectomyValue);
}
}

void MainWindow::on_pushButton_11_released()
{if(vip==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseVitrectomyValue);
}
}

//dec vit
void MainWindow::on_pushButton_15_pressed()
{
    if(vip==1)
        {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseVitrectomyValue);
}}

void MainWindow::on_pushButton_15_released()
{if(vip==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseVitrectomyValue);
}
}

// inc sil
void MainWindow::on_pushButton_19_pressed()
{if(sp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increasesiliconoil);
}}

void MainWindow::on_pushButton_19_released()
{if(sp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increasesiliconoil);
}}

//dec sil
void MainWindow::on_pushButton_18_pressed()
{if(sp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreasesiliconoil);
}}

void MainWindow::on_pushButton_18_released()
{if(sp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreasesiliconoil);
}}

//inc led1
void MainWindow::on_pushButton_17_pressed()
{if(lp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseledvalue);
}
}

void MainWindow::on_pushButton_17_released()
{if(lp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseledvalue);
}}

//dec led1
void MainWindow::on_pushButton_16_pressed()
{if(lp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseledvalue);
}}
void MainWindow::on_pushButton_16_released()
{if(lp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseledvalue);
}}
//inc led2
void MainWindow::on_pushButton_21_pressed()
{
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseledvalue2);
}

void MainWindow::on_pushButton_21_released()
{
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseledvalue2);
}
//dec led2
void MainWindow::on_pushButton_22_pressed()
{
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseledvalue2);
}

void MainWindow::on_pushButton_22_released()
{
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseledvalue2);
}


//inc air
void MainWindow::on_pushButton_9_pressed()
{if(ap==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseAirInjectorValue);
}
}
void MainWindow::on_pushButton_9_released()
{if(ap==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseAirInjectorValue);
}}
//dec air
void MainWindow::on_pushButton_13_pressed()
{if(ap==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseAirInjectorValue);
}}

void MainWindow::on_pushButton_13_released()
{if(ap==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseAirInjectorValue);
}}
//inc dia
void MainWindow::on_pushButton_10_pressed()
{if(dp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::increaseDiathermyValue);
}}

void MainWindow::on_pushButton_10_released()
{if(dp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::increaseDiathermyValue);
}}
//dec dia

void MainWindow::on_pushButton_14_pressed()
{if(dp==1)
    {
    time.start(300);
     connect(&time, &QTimer::timeout, this, &MainWindow::decreaseDiathermyValue);
}}

void MainWindow::on_pushButton_14_released()
{if(dp==1)
    {
    time.stop();
     disconnect(&time, &QTimer::timeout, this, &MainWindow::decreaseDiathermyValue);
}
}


void MainWindow::on_pushButton_24_clicked()
{

    if(vitp==0)
    {

       ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");
       vitp=1;



    }
    else
    {

        ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");
        vitp=0;


    }
}

// code for date and time
void MainWindow::updatetimedate()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateString = currentDateTime.toString("yyyy-MM-dd");

    QString timeString = currentDateTime.toString("hh:mm:ss");

    ui->label_46->setText(dateString);
     ui->label_47->setText(timeString);
}

//code to load combobox from db
void MainWindow::comboboxload()
{
    QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName(PATH);

    if (!mydb1.open()) {
        qDebug() << "Error opening database:"  ;
        return;
    }

    QSqlQuery query;
    if (!query.exec("SELECT surgeon FROM maindb")) {
        qDebug() << "Error executing query:" ;
        mydb1.close();
        return;
    }

    ui->comboBox_2->clear(); // Clear existing items before loading new ones


    while (query.next()) {
        QString itemName = query.value(0).toString();


        ui->comboBox_2->addItem(itemName);


   }
    mydb1.close();
}


void MainWindow::timerCompleted()
{
    ui->label_22->lower();
    ui->label_12->lower();
    ui->comboBox_2->move(30,34);
    ui->pushButton_25->lower();

}

//combo box code
void MainWindow::onComboBoxClicked()
{timerforondscreen->stop();
if((ui->comboBox_2->currentIndex())>=1 && (ui->comboBox_2->currentIndex())<=19)
{

        surgeonid=ui->comboBox_2->currentText();
        surgeonind=ui->comboBox_2->currentIndex();
        qDebug() << surgeonind;




        QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
        mydb1.setDatabaseName(PATH);
        mydb1.open();
        QSqlQuery query;



        query.prepare("UPDATE maindb SET lastselected = :surgeonind");
        query.bindValue(":surgeonind", surgeonind);
        if (!query.exec()) {
            qDebug() << "Error updating lastselected column:";
        }

       query.exec("select * from maindb where surgeon='"+surgeonid+"'");
       if(query.next()){
           QString itemname1;
           QString itemname34;
           QString itemname35;
           QString itemname36;
           QString itemname44;
           QString itemname45;
           QString itemname46;
           QString itemname47;


           itemname1 = query.value(0).toString();
             ui->label_6->setText(itemname1);
           itemname34 = query.value(33).toString();
           ui->label_4->setText(itemname34);

           itemname35 = query.value(34).toString();
           if(itemname35=="Linear")
           {
                ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");

           }
           else
           {

               ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");

           }
                itemname36 = query.value(35).toString();
                ui->label_3->setText(itemname36);
                itemname44= query.value(43).toString();
               fp0=itemname44.toDouble()*40.95;
                itemname45 = query.value(44).toString();
               fp1=itemname45.toDouble()*40.95;
                itemname46 = query.value(45).toString();
               fp2=itemname46.toDouble()*40.95;
                itemname47 = query.value(46).toString();
               fp3=itemname47.toDouble()*40.95;
               qDebug()<<itemname44;
               qDebug()<<itemname45;
               qDebug()<<itemname46;
               qDebug()<<itemname47;
           }

     qDebug()<<fp0;
     qDebug()<<fp1;
     qDebug()<<fp2;
     qDebug()<<fp3;
    mydb1.close();

}

}

void MainWindow::on_pushButton_25_clicked()
{
        ui->label_22->lower();
        ui->label_12->lower();
        ui->comboBox_2->move(30,34);
        ui->pushButton_25->lower();
}

void MainWindow::on_pushButton_26_clicked()
{
    QString swap = ui->pushButton_26->text();

    if(swap.compare("SWAP OFF") == 0)
    {
        ui->pushButton_26->setText("SWAP ON");
        flag2=1;
    }
    else if(swap.compare("SWAP ON") == 0)
    {
        ui->pushButton_26->setText("SWAP OFF");
        flag2=0;
    }
}

void MainWindow::linearcall()
{
    int avg = fp->convert(CHANNEL_0);

    if(avg<=(fp0+fp1))
    {
        ui->label_48->setText("0");
    }

    int val = ((avg-fp0-fp1)/fp2)*vit_value;
    int q = val/60;
    int val2=q*60;
    if(val2>=60)
    {
        if(avg>=4000)
        {
            hhandler->vit_on(1000/(vit_value/60));
            ui->label_48->setText(QString::number(vit_value));
        }
        else
        {
            hhandler->vit_on(1000/(val2/60));
            ui->label_48->setText(QString::number(val2));
       }
    }
    else
    {
        hhandler->vit_off();
    }

}

void MainWindow::diathermy()
{
    hhandler->dia_on();
    hhandler->dia_count(ui->label_6->text().toInt()*256/100);
}

void MainWindow::airinjector()
{
    if(ui->label_3->text().toInt()==0)
    {
        airinjector2();
    }
    else
    {
        aiflag=1;
        hhandler->ai_on();
        hhandler->ai_preset_count(ui->label_3->text().toInt()*256/100);
        //hhandler->ai_actual_count(100);
        int value = (int)(vac->convert(CHANNEL_2)*0.17);
        ui->label_10->setText(QString::number(value));
        hhandler->ai_actual_count(value);
    }
}

void MainWindow::airinjector2()
{
    aiflag=0;
    hhandler->ai_off();
    hhandler->ai_preset_count(0);
    ui->label_10->setText(QString::number(0));
    hhandler->ai_actual_count(0);

}

void MainWindow::label48()
{
    int avg = fp->convert(CHANNEL_0);

    if(avg<=(fp0+fp1))
    {
        ui->label_48->setText("0");
    }
}
