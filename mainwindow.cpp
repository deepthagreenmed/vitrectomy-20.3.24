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
#include <QThread>

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clicktimer=new QTimer;

    connect(ui->pushButton_vacinc, &QPushButton::clicked, this, &MainWindow::increaseVaccumValue);
    connect(ui->pushButton_vacdec, &QPushButton::clicked, this, &MainWindow::decreaseVaccumValue);
    connect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
    connect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);
    connect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
    connect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);
    connect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
    connect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);
    connect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
    connect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);
    connect(ui->pushButton_aiinc, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
    connect(ui->pushButton_aidec, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);
    connect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
    connect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);


    connect(ui->pushButton_settingswindow, &QPushButton::clicked, this, &MainWindow::showsettingswindow);
    connect(ui->pushButton_siloilonoff, &QPushButton::clicked, this, &MainWindow::siloil_onoff);
    connect(ui->pushButton_led1onoff, &QPushButton::clicked, this, &MainWindow::led1_onoff);
    connect(ui->pushButton_diaonoff, &QPushButton::clicked, this, &MainWindow::dia_onoff);
    connect(ui->pushButton_aionoff, &QPushButton::clicked, this, &MainWindow::ai_onoff);
    connect(ui->pushButton_vitonoff, &QPushButton::clicked, this, &MainWindow::vit_onoff);
    connect(ui->pushButton_led2onoff, &QPushButton::clicked, this, &MainWindow::led2_onoff);
    connect(ui->pushButton_drain, &QPushButton::clicked, this, &MainWindow::drain_onoff);
    connect(ui->pushButton_endcase, &QPushButton::clicked, this, &MainWindow::setsurgeon);
    connect(ui->pushButton_vaclinearnonlinear, &QPushButton::clicked, this, &MainWindow::vac_linear_nonlinear);
    connect(ui->pushButton_vitlinearnonlinear, &QPushButton::clicked, this, &MainWindow::vit_linear_nonlinear);
    connect(ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::showsetupscreen);


    clicktimer->setInterval(200);
    clicktimer->setSingleShot(true);

    vacpresetval = ui->label_vacpreset->text().toInt();


    for(int gpioPin=960; gpioPin<965; gpioPin++)
    {
        exportGPIO(gpioPin);
        setGPIODirection(gpioPin, "in");
    }


    fp = new footpedal;
    hhandler = new hwHandler;
    vac = new Vaccum;
    l = new ltc2614;
    key = new keypad;


    QTimer *timerfp = new QTimer;
    connect(timerfp, &QTimer::timeout, this, &MainWindow::setFPValues);
    timerfp->start(1);


    connect(ui->comboBox_surgeonname, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxClicked);

     timerforondscreen = new QTimer;
     timerforondscreen->start(7000);
     connect(timerforondscreen, &QTimer::timeout, this, &MainWindow::timerCompleted);

    //code to load database
    QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName(PATH);

     mydb1.open();


    QSqlQuery query;
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
    while(query.next()){
        itemname48=query.value(0).toString();
        surgeonind=itemname48.toInt();
    }

    QString vacmode2, vitmode;

     query.exec("select * from maindb where surgeon='"+surgeon+"'");
     while(query.next()){

         vp=query.value(51).toInt();
         vip=query.value(52).toInt();
         vitp=query.value(53).toInt();
         lp=query.value(54).toInt();
         lp2=query.value(55).toInt();
         dp=query.value(56).toInt();
         ap=query.value(57).toInt();
         sp=query.value(58).toInt();

         loadPresets();

        itemname1 = query.value(0).toString();
          ui->label_dia->setText(itemname1);
          itemname34 = query.value(33).toString();
          ui->label_vitpreset->setText(itemname34);

          ui->label_led1->setText(query.value(49).toString());
          ui->label_led2->setText(query.value(50).toString());
          ui->label_vacpreset->setText(query.value(35).toString());
          vacmode2=query.value(36).toString();
          vitmode=query.value(34).toString();

          itemname35 = query.value(34).toString();

          if(vitp==0)
          {
                ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");
          }
          else
          {
               ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");
          }

          if(vp==0)
          {
               ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");

          }
          else
          {

              ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");

          }

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

     vaclnl(vacmode2);
     vitlnl(vitmode);

    mydb1.close();

    ui->comboBox_surgeonname->setCurrentIndex(surgeonind);

    win2=new settingswindow(this);

    QObject::connect(win2, &settingswindow::stringPassed, this, &MainWindow::receiveString);

    avgfp=fp->convert(CHANNEL_0);

    hhandler->speaker_off();

    hhandler->vit_off();

    timerzero.start(100);
    connect(&timerzero,&QTimer::timeout, this, &MainWindow::setZero);

    QTimer *timer = new QTimer(this);
    QTimer *timerfortd = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel2);
    connect(timerfortd, &QTimer::timeout, this, &MainWindow::updatetimedate);


    hhandler->ai_off();
    hhandler->ai_preset_count(0);
    hhandler->ai_actual_count(0);
    hhandler->write_motor(0x00,0x03,0);

    led1 = new LED(PORT1);
    led2 = new LED(PORT2);

    timerfortd->start(1000);
    timer->start(1);

    ui->dial->setStyleSheet("");
    ui->dial->setStyle(QStyleFactory::create("Fusion"));
    ui->dial->setStyleSheet("background-color: rgb(26, 95, 180);");
    ui->dial->setRange(0, 4096);

    ui->dial->setValue(avgfp);

    connect(win2, &settingswindow::led1str, this, &MainWindow::led1val);
    connect(win2, &settingswindow::led2str, this, &MainWindow::led2val);

    connect(win2, &settingswindow::vacstr, this, &MainWindow::vacval);
    connect(win2, &settingswindow::vacmode, this, &MainWindow::vaclnl);

    connect(win2, &settingswindow::vitstr, this, &MainWindow::vitval);
    connect(win2, &settingswindow::vitmode, this, &MainWindow::vitlnl);
    connect(win2, &settingswindow::vittype, this, &MainWindow::typevit);

    connect(win2, &settingswindow::diastr, this, &MainWindow::diaval);

    connect(key, &keypad::textsignal, this, &MainWindow::on_clicked);
    connect(key, &keypad::entersignal, this, &MainWindow::on_clickedenter);
    connect(key, &keypad::backsignal, this, &MainWindow::on_clickedbackspace);



    ui->label_vacpreset->installEventFilter(this);
    ui->label_vitpreset->installEventFilter(this);
    ui->label_siloil->installEventFilter(this);
    ui->label_aipreset->installEventFilter(this);
    ui->label_dia->installEventFilter(this);
    ui->label_led2->installEventFilter(this);
    ui->label_led1->installEventFilter(this);

    ui->label_vitpreset->clearFocus();
    ui->label_siloil->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_led1->clearFocus();


    QTimer *timermain = new QTimer(this);
    timermain->setSingleShot(true);
    timermain->start(3000); // 3 seconds
    connect(timermain, &QTimer::timeout, this, &MainWindow::transitionToNewScreen);

    QTimer *timervit = new QTimer;
    connect(timervit, &QTimer::timeout, this, &MainWindow::vitvalset);
    timervit->start(1);

    connect(win2, &settingswindow::textSelected, this, &MainWindow::updateText);

    pres=new sensor;

    QTimer *timerpres = new QTimer(this);
    connect(timerpres, &QTimer::timeout, this, &MainWindow::pressureval);
    timerpres->start(100); // milliseconds


    connect(win2, &settingswindow::led1_pedal, this, &MainWindow::led1_setvalue);
    connect(win2, &settingswindow::led2_pedal, this, &MainWindow::led2_setvalue);
    connect(win2, &settingswindow::vit_pedal, this, &MainWindow::vit_setvalue);
    connect(win2, &settingswindow::dia_pedal, this, &MainWindow::dia_setvalue);
    connect(win2, &settingswindow::siloil_pedal, this, &MainWindow::siloil_setvalue);


    hhandler->vso_off();

    connect(win2, &settingswindow::stringPassed0, this, &MainWindow::receiveString0);
    connect(win2, &settingswindow::stringPassed1, this, &MainWindow::receiveString1);
    connect(win2, &settingswindow::stringPassed2, this, &MainWindow::receiveString2);
    connect(win2, &settingswindow::stringPassed3, this, &MainWindow::receiveString3);

    QTimer *onofftimer=new QTimer;
    connect(onofftimer, &QTimer::timeout, this, &MainWindow::configOnOff);
    onofftimer->start(1000);

}


// Show setup screen after 3 seconds
void MainWindow::transitionToNewScreen() {
    ui->label_22->hide();
    ui->label_12->hide();
    ui->label_2->hide();
    ui->comboBox_surgeonname->move(30,34);
    ui->pushButton_start->hide();
}

// Set limits and input validation
void MainWindow::updateLabelValue(QLabel* label, int dig, int value, int maxValue)
{

    if (value > maxValue)
    {
        label->setText(QString::number(dig));
    }
    else
    {
        label->setText(QString::number(value));
    }

    if (label == ui->label_vacpreset)
    {
        if (dig == 0 && ui->label_vacpreset->text() == "0")
        {
            ui->label_vacpreset->setText(QString::number(vacpresetval));
            return;
        }
        else
        {
            vacpresetval = ui->label_vacpreset->text().toInt();
        }
    }
}

// keypad showing code
bool MainWindow::eventFilter(QObject* object, QEvent* event)
{


  if(object == ui->label_vacpreset && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(180,400);
        key->show();
        ui->label_vacpreset->setFocus();
        ui->label_vitpreset->clearFocus();
        ui->label_siloil->clearFocus();
        ui->label_aipreset->clearFocus();
        ui->label_dia->clearFocus();
        ui->label_led2->clearFocus();
        ui->label_led1->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {
    }
  }
  if(object == ui->label_vitpreset && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(110,500);
        key->show();
        ui->label_vitpreset->setFocus();
        ui->label_vacpreset->clearFocus();
        ui->label_siloil->clearFocus();
        ui->label_aipreset->clearFocus();
        ui->label_dia->clearFocus();
        ui->label_led2->clearFocus();
        ui->label_led1->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_siloil && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
    key->resize(491,271);
    key->move(850,450);
    key->show();
    ui->label_siloil->setFocus();
    ui->label_vitpreset->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_led1->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_aipreset && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->resize(491,271);
          key->move(1400,390);
          key->show();
          ui->label_aipreset->setFocus();
          ui->label_vitpreset->clearFocus();
          ui->label_siloil->clearFocus();
          ui->label_vacpreset->clearFocus();
          ui->label_dia->clearFocus();
          ui->label_led2->clearFocus();
          ui->label_led1->clearFocus();

      } else if ( k->button() == Qt::RightButton ) {

      }
    }
  if(object == ui->label_dia && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(1400,450);
        key->show();
        ui->label_dia->setFocus();
        ui->label_vitpreset->clearFocus();
        ui->label_siloil->clearFocus();
        ui->label_aipreset->clearFocus();
        ui->label_vacpreset->clearFocus();
        ui->label_led2->clearFocus();
        ui->label_led1->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_led2 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(1350,690);
        key->show();
        ui->label_led2->setFocus();
        ui->label_vitpreset->clearFocus();
        ui->label_siloil->clearFocus();
        ui->label_aipreset->clearFocus();
        ui->label_dia->clearFocus();
        ui->label_vacpreset->clearFocus();
        ui->label_led1->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  if(object == ui->label_led1 && event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *k = static_cast<QMouseEvent *> (event);
    if( k->button() == Qt::LeftButton ) {
        key->resize(491,271);
        key->move(40,690);
        key->show();
        ui->label_led1->setFocus();
        ui->label_vitpreset->clearFocus();
        ui->label_siloil->clearFocus();
        ui->label_aipreset->clearFocus();
        ui->label_dia->clearFocus();
        ui->label_led2->clearFocus();
        ui->label_vacpreset->clearFocus();

    } else if ( k->button() == Qt::RightButton ) {

    }
  }
  return false;
}

//settings focus and insert digit
void MainWindow::on_clicked(const QString& digit)
{

  if(ui->label_vacpreset->focusWidget()) {
      ui->label_vitpreset->clearFocus();
      ui->label_siloil->clearFocus();
      ui->label_aipreset->clearFocus();
      ui->label_dia->clearFocus();
      ui->label_led2->clearFocus();
      ui->label_led1->clearFocus();
      if(!flag)
      {
      ui->label_vacpreset->setFocus();
      int dig = digit.toInt();
      int value = (ui->label_vacpreset->text()+digit).toInt();
      updateLabelValue(ui->label_vacpreset, dig, value, 500);
   }
  }
  if(ui->label_vitpreset->focusWidget()) {
      ui->label_vacpreset->clearFocus();
      ui->label_siloil->clearFocus();
      ui->label_aipreset->clearFocus();
      ui->label_dia->clearFocus();
      ui->label_led2->clearFocus();
      ui->label_led1->clearFocus();
      if(!flag)
      {
      ui->label_vitpreset->setFocus();
      int dig = digit.toInt();
      int value = (ui->label_vitpreset->text()+digit).toInt();
      updateLabelValue(ui->label_vitpreset, dig, value, 9600);
   }
  }
if(ui->label_siloil->focusWidget()) {
    ui->label_vitpreset->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_led1->clearFocus();
    if(!flag)
    {
    ui->label_siloil->setFocus();
    int dig = digit.toInt();
    int value = (ui->label_siloil->text()+digit).toInt();
    updateLabelValue(ui->label_siloil, dig, value, 100);

 }
}
if(ui->label_aipreset->focusWidget()) {
    ui->label_vitpreset->clearFocus();
    ui->label_siloil->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_led1->clearFocus();
    if(!flag)
    {
    ui->label_aipreset->setFocus();
    int dig = digit.toInt();
    int value = (ui->label_aipreset->text()+digit).toInt();
    updateLabelValue(ui->label_aipreset, dig, value, 100);

 }
}
if(ui->label_dia->focusWidget()) {
    ui->label_vitpreset->clearFocus();
    ui->label_siloil->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_led1->clearFocus();
    if(!flag)
    {
    ui->label_dia->setFocus();
    int dig = digit.toInt();
    int value = (ui->label_dia->text()+digit).toInt();
    updateLabelValue(ui->label_dia, dig, value, 100);

 }
}
if(ui->label_led2->focusWidget()) {
    ui->label_vitpreset->clearFocus();
    ui->label_siloil->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_vacpreset->clearFocus();
    ui->label_led1->clearFocus();
    if(!flag)
    {
    ui->label_led2->setFocus();
    int dig = digit.toInt();
    int value = (ui->label_led2->text()+digit).toInt();
    updateLabelValue(ui->label_led2, dig, value, 100);

 }
}
if(ui->label_led1->focusWidget()) {
    ui->label_vitpreset->clearFocus();
    ui->label_siloil->clearFocus();
    ui->label_aipreset->clearFocus();
    ui->label_dia->clearFocus();
    ui->label_led2->clearFocus();
    ui->label_vacpreset->clearFocus();
    if(!flag)
    {
    ui->label_led1->setFocus();
    int dig = digit.toInt();
    int value = (ui->label_led1->text()+digit).toInt();
    updateLabelValue(ui->label_led1, dig, value, 100);

 }
}
}

// Hide keypad, switch between LED1 and LED2, fix increments
void MainWindow::on_clickedenter()
{
    key->hide();

    if(lp == 1)
    {
         switchled(led1, ui->label_led1->text().toInt());
    }
    if(lp2 == 1)
    {
        switchled(led2, ui->label_led2->text().toInt());
    }

    if(ui->label_aipreset->text().toInt() == 0)
    {
        airinjectoroff();
    }


    vit_value = static_cast<int>(std::round(vit_value/60))*60;
    ui->label_vitpreset->setText(QString::number(vit_value));
    ui->label_vacpreset->setText(QString::number(static_cast<int>(std::round(ui->label_vacpreset->text().toInt()/5))*5));
    ui->label_siloil->setText(QString::number(static_cast<int>(std::round(ui->label_siloil->text().toInt()/5))*5));
    ui->label_dia->setText(QString::number(static_cast<int>(std::round(ui->label_dia->text().toInt()/5))*5));
    ui->label_led1->setText(QString::number(static_cast<int>(std::round(ui->label_led1->text().toInt()/5))*5));
    ui->label_led2->setText(QString::number(static_cast<int>(std::round(ui->label_led2->text().toInt()/5))*5));
}


MainWindow::~MainWindow()
{
    delete ui;

}

//settings window showing
void MainWindow::showsettingswindow()
{
    vip=0;
    ui->label_38->setStyleSheet("");
    ui->label_24->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
    ui->pushButton_vitinc->lower();
    ui->pushButton_vitdec->lower();
    ui->label_vitpreset->lower();
    ui->label_vitactual->lower();
    ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_vitonoff->setText("OFF");
    hhandler->vit_off();
    disconnect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
    disconnect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);

    sp=0;
    ui->label_19->setStyleSheet("");
    ui->label_26->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
    ui->pushButton_siloildec->lower();
    ui->pushButton_siloilinc->lower();
    ui->label_siloil->lower();
    ui->pushButton_siloilonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_siloilonoff->setText("OFF");
    hhandler->siloil_off();
    hhandler->vso_off();
    disconnect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
    disconnect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);


    ap=0;
    ui->label_13->setStyleSheet("");
    ui->label_23->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
    ui->pushButton_aidec->lower();
    ui->pushButton_aiinc->lower();
    ui->label_aiactual->lower();
    ui->label_aipreset->lower();
    ui->pushButton_aionoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_aionoff->setText("OFF");
    hhandler->ai_off();
    airinjectoroff();
    disconnect(ui->pushButton_aiinc, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
    disconnect(ui->pushButton_aidec, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);

    dp=0;
    ui->label_14->setStyleSheet("");
    ui->label_25->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
    ui->pushButton_diainc->lower();
    ui->pushButton_diadec->lower();
    ui->label_dia->lower();
    ui->pushButton_diaonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_diaonoff->setText("OFF");
    hhandler->dia_off();
    timedia.stop();
    disconnect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);
    disconnect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
    disconnect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);

    lp=0;
    ui->label_27->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
    ui->pushButton_led1onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_led1onoff->setText("OFF");
    led1->processUserInput(2);
    disconnect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
    disconnect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);

    lp2=0;
    ui->label_41->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
    ui->pushButton_led2onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
    ui->pushButton_led2onoff->setText("OFF");
    led2->processUserInput(2);
    disconnect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
    disconnect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);

    win2->show();
}


// Turn silicon oil on or off
void MainWindow::siloil_onoff()
{
    if(!clicktimer->isActive()) {

    if(sp==0)
    {
        ui->label_19->setStyleSheet("background-color: rgb(116, 184, 222);");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_siloildec->raise();
        ui->pushButton_siloilinc->raise();
        ui->label_siloil->raise();

        ui->pushButton_siloilonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_siloilonoff->setText("ON");

        connect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
        connect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);

        timesiloil.start(100);
        connect(&timesiloil, &QTimer::timeout, this, &MainWindow::siloil);

        hhandler->buzz();

        sp=1;

        }
        else
        {
        ui->label_19->setStyleSheet("");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_siloildec->lower();
        ui->pushButton_siloilinc->lower();
        ui->label_siloil->lower();

        ui->pushButton_siloilonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_siloilonoff->setText("OFF");
        \
        disconnect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
        disconnect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);

        hhandler->vso_off();
        hhandler->siloil_off();

        timesiloil.stop();
        disconnect(&timesiloil, &QTimer::timeout, this, &MainWindow::siloil);
hhandler->buzz();
        sp=0;
        }
    clicktimer->start();
    }

}

// Turn vaccum linear or non-linear
void MainWindow::vac_linear_nonlinear()
{
    if(!clicktimer->isActive()) {
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
    clicktimer->start();
    }
}

// Turn LED1 on or off
void MainWindow::led1_onoff()
{
    if(!clicktimer->isActive()) {

        if(lp==0)
        {
            ui->label_27->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");

            ui->pushButton_led1onoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_led1onoff->setText("ON");

            if(ui->label_led1->text().toInt() != 0)
            {
                led1->processUserInput(1);
            }

            connect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
            connect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);

            hhandler->buzz();


    lp=1;

        }
        else
        {
            ui->label_27->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");

            ui->pushButton_led1onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_led1onoff->setText("OFF");
            led1->processUserInput(2);

            disconnect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
            disconnect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);
            hhandler->buzz();
           lp=0;
        }
        clicktimer->start();
    }

}

// Turn LED2 on or off
void MainWindow::led2_onoff()
{
    if(!clicktimer->isActive()) {

    if(lp2==0)
    {
        ui->label_41->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_led2onoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led2onoff->setText("ON");

        if(ui->label_led2->text().toInt() != 0)
        {
            led2->processUserInput(1);
        }

        connect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
        connect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);

        hhandler->buzz();


        lp2=1;

    }
    else
    {   ui->label_41->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_led2onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led2onoff->setText("OFF");

        led2->processUserInput(2);

        disconnect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
        disconnect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);
        hhandler->buzz();
       lp2=0;
    }
    clicktimer->start();
    }
}

// Turn diathermy on or off
void MainWindow::dia_onoff()
{
    if(!clicktimer->isActive()) {

        if(dp==0)
        {
            ui->label_14->setStyleSheet("background-color: rgb(116, 184, 222);");
            ui->label_25->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
            ui->pushButton_diainc->raise();
            ui->pushButton_diadec->raise();
            ui->label_dia->raise();
            ui->pushButton_diaonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_diaonoff->setText("ON");

            timedia.start(1000);
            connect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);


            connect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
            connect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);

            hhandler->buzz();

            dp=1;

        }
        else
        {
            ui->label_14->setStyleSheet("");
            ui->label_25->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
            ui->pushButton_diainc->lower();
            ui->pushButton_diadec->lower();
            ui->label_dia->lower();
            ui->pushButton_diaonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_diaonoff->setText("OFF");
            hhandler->dia_off();

            timedia.stop();
            disconnect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);

            disconnect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
            disconnect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);
            hhandler->buzz();
           dp=0;
        }
        clicktimer->start();
    }

}

// Turn air injector on or off
void MainWindow::ai_onoff()
{
    if(!clicktimer->isActive()) {

        if(ap==0)
        {
            ui->label_13->setStyleSheet("background-color: rgb(116, 184, 222);");
            ui->label_23->setStyleSheet("font: 40pt;color: rgb(0, 0, 0);");
            ui->pushButton_aidec->raise();
            ui->pushButton_aiinc->raise();
            ui->label_aipreset->raise();
            ui->label_aiactual->raise();

            ui->pushButton_aionoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_aionoff->setText("ON");

            //int flow=90+ (int)(preset* 1.5);
            int flow=130;
            hhandler->write_motor(0x01,0x03,flow);

            // Define the lambda function with arguments and return value
            auto myFunction = [this]() -> int {
                hhandler->ai_on();
                int preset = ui->label_aipreset->text().toInt();
                hhandler->ai_preset_count(preset);

                int actual;

                actual=0;
                for(int i=0; i<10; i++)
                {
                    actual += vac->convert(CHANNEL_2) * 0.1894;
                }
                actual = static_cast<int>(actual/10);

                hhandler->ai_actual_count(actual);

                return actual;
            };

        QObject::connect(&timeai, &QTimer::timeout, [this, myFunction]() {

            if(ui->label_aipreset->text().toInt() == 0)
            {
                airinjectoroff();
                return;
            }

            int actual = myFunction();
            ui->label_aiactual->setText(QString::number(actual));
        });
        timeai.start(10);

            connect(ui->pushButton_aiinc, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
            connect(ui->pushButton_aidec, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);

            hhandler->buzz();

            ap=1;

        }
        else if(ap==1)
        {
            ui->label_13->setStyleSheet("");
            ui->label_23->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
            ui->pushButton_aidec->lower();
            ui->pushButton_aiinc->lower();
            ui->label_aiactual->lower();
            ui->label_aipreset->lower();
            ui->pushButton_aionoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_aionoff->setText("OFF");

            hhandler->ai_off();
            airinjectoroff();

            disconnect(ui->pushButton_aiinc, &QPushButton::clicked, this, &MainWindow::increaseAirInjectorValue);
            disconnect(ui->pushButton_aidec, &QPushButton::clicked, this, &MainWindow::decreaseAirInjectorValue);
            hhandler->buzz();
            ap=0;
        }
    clicktimer->start();
}
}

// Turn vitrectomy on or off
void MainWindow::vit_onoff()
{
    if(!clicktimer->isActive()) {

        if(vip==0)
        {
            ui->label_38->setStyleSheet("background-color: rgb(116, 184, 222);");

            ui->label_24->setStyleSheet("font: 40pt ;color: rgb(0, 0, 0);");
            ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
            ui->pushButton_vitonoff->setText("ON");
            ui->pushButton_vitinc->raise();
            ui->pushButton_vitdec->raise();
            ui->label_vitpreset->raise();
            ui->label_vitactual->raise();

            vip=1;



            connect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
            connect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);

            hhandler->buzz();



        }

        else if(vip==1)
            {   ui->label_38->setStyleSheet("");
                ui->label_24->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
                ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
                ui->pushButton_vitonoff->setText("OFF");
                ui->pushButton_vitinc->lower();
                ui->pushButton_vitdec->lower();
                ui->label_vitpreset->lower();
                ui->label_vitactual->lower();
hhandler->buzz();
                vip=0;

               hhandler->vit_off();


            disconnect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
            disconnect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);



        }
        clicktimer->start();
    }

}

// Increase vaccum
void MainWindow::increaseVaccumValue()
{
    if(!clicktimer->isActive()) {

    int currentValue = ui->label_vacpreset->text().toInt();
    int newValue = currentValue + 5;
    if(newValue > 500)
    {
        newValue = 500;
    }
    ui->label_vacpreset->setText(QString::number(newValue));

    clicktimer->start();
    }
}

// Decrease vaccum
void MainWindow::decreaseVaccumValue()
{
    if(!clicktimer->isActive()) {

    int currentValue = ui->label_vacpreset->text().toInt();
    int newValue = currentValue - 5;
    if(newValue < 0)
    {
        newValue = 0;
    }
    ui->label_vacpreset->setText(QString::number(newValue));

    clicktimer->start();
    }

}

// Increase vitrectomy
void MainWindow::increaseVitrectomyValue()
{
     if(vip==1) {
 if(!clicktimer->isActive()) {

    ui->label_vitpreset->setText(QString::number(vit_value));
    vit_value = vit_value + 60;
    if(vit_value>9600)
    {
        vit_value=9600;
    }
    ui->label_vitpreset->setText(QString::number(vit_value));

    clicktimer->start();
 }}
}

// Decrease vitrectomy
void MainWindow::decreaseVitrectomyValue()
{
     if(vip==1) {
    if(!clicktimer->isActive()) {

    ui->label_vitpreset->setText(QString::number(vit_value));
    vit_value = vit_value - 60;
    if(vit_value<60)
    {
        vit_value=60;
    }
    ui->label_vitpreset->setText(QString::number(vit_value));

    clicktimer->start();
    }}
}

// Increase diathermy
void MainWindow::increaseDiathermyValue()
{
     if(dp==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_dia->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    ui->label_dia->setText(QString::number(newValue));

    clicktimer->start();
    }
     }
}

// Decrease diathermy
void MainWindow::decreaseDiathermyValue()
{
    if(dp==1) {
    if(!clicktimer->isActive()) {

    int currentValue = ui->label_dia->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    ui->label_dia->setText(QString::number(newValue));

    clicktimer->start();
    }
    }
}

// Increase air injector
void MainWindow::increaseAirInjectorValue()
{
    if(ap==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_aipreset->text().toInt();
    int newValue = currentValue + 1;
    if(newValue>100)
    {
        newValue=100;
    }
    ui->label_aipreset->setText(QString::number(newValue));

    int flow=130;
    hhandler->write_motor(0x01,0x03,flow);

    // Define the lambda function with arguments and return value
    auto myFunction = [this]() -> int {
        hhandler->ai_on();
        int preset = ui->label_aipreset->text().toInt();
        hhandler->ai_preset_count(preset);

        int actual;

        actual=0;
        for(int i=0; i<10; i++)
        {
            actual += vac->convert(CHANNEL_2) * 0.1894;
        }
        actual = static_cast<int>(actual/10);

        hhandler->ai_actual_count(actual);

        return actual;
    };

    QObject::connect(&timeai, &QTimer::timeout, [this, myFunction]() {

        if(ui->label_aipreset->text().toInt() == 0)
        {
            airinjectoroff();
            return;
        }

        int actual = myFunction();
        ui->label_aiactual->setText(QString::number(actual));
    });
    timeai.start(10);

    clicktimer->start();
    }
}
}

// Decrease air injector
void MainWindow::decreaseAirInjectorValue()
{
    if(ap==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_aipreset->text().toInt();
    int newValue = currentValue - 1;
    if(newValue<0)
    {
        newValue=0;
    }
    ui->label_aipreset->setText(QString::number(newValue));

    int flow=130;
    hhandler->write_motor(0x01,0x03,flow);

    // Define the lambda function with arguments and return value
    auto myFunction = [this]() -> int {
        hhandler->ai_on();
        int preset = ui->label_aipreset->text().toInt();
        hhandler->ai_preset_count(preset);

        int actual;

        actual=0;
        for(int i=0; i<10; i++)
        {
            actual += vac->convert(CHANNEL_2) * 0.1894;
        }
        actual = static_cast<int>(actual/10);

        hhandler->ai_actual_count(actual);

        return actual;
    };

    QObject::connect(&timeai, &QTimer::timeout, [this, myFunction]() {

        if(ui->label_aipreset->text().toInt() == 0)
        {
            airinjectoroff();
            return;
        }

        int actual = myFunction();
        ui->label_aiactual->setText(QString::number(actual));
    });
    timeai.start(10);

    clicktimer->start();
    }
}
}

// Increase LED1
void MainWindow::increaseledvalue()
{
    if(lp==1) {
    if(!clicktimer->isActive()) {

    int currentValue = ui->label_led1->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    double choice = newValue;
    switchled(led1, choice);
    ui->label_led1->setText(QString::number(newValue));

    clicktimer->start();
    }
    }

}

// Decrease LED1
void MainWindow::decreaseledvalue()
{
    if(lp==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_led1->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    double choice = newValue;
    switchled(led1, choice);
    ui->label_led1->setText(QString::number(newValue));

    clicktimer->start();
    }
    }
}

// Increase LED2
void MainWindow::increaseled2value()
{
    if(lp2==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_led2->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    double choice = newValue;
    switchled(led2, choice);
    ui->label_led2->setText(QString::number(newValue));

    clicktimer->start();
    }
    }
}

// Decrease LED2
void MainWindow::decreaseled2value()
{
     if(lp2==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_led2->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    double choice = newValue;
    switchled(led2, choice);
    ui->label_led2->setText(QString::number(newValue));

    clicktimer->start();
    }
     }
}

// Increase silicon oil
void MainWindow::increasesiliconoilvalue()
{

    if(sp==1) {
     if(!clicktimer->isActive()) {

    int currentValue = ui->label_siloil->text().toInt();
    int newValue = currentValue + 5;
    if(newValue>100)
    {
        newValue=100;
    }
    ui->label_siloil->setText(QString::number(newValue));

    clicktimer->start();
     }}
}

// Decrease silicon oil
void MainWindow::decreasesiliconoilvalue()
{
    if(sp==1) {
    if(!clicktimer->isActive()) {

    int currentValue = ui->label_siloil->text().toInt();
    int newValue = currentValue - 5;
    if(newValue<0)
    {
        newValue=0;
    }
    ui->label_siloil->setText(QString::number(newValue));

    clicktimer->start();
    }}
}

// Slot function to set name of surgeon
void MainWindow::receiveString(const QString& str)
{
    ui->comboBox_surgeonname->setCurrentText(str);
}

// Slot function to set value of LED1
void MainWindow::led1val(QString str)
{
    ui->label_led1->setText(str);
}

// Slot function to set value of LED2
void MainWindow::led2val(QString str)
{
    ui->label_led2->setText(str);
}

// Slot function to set value of vaccum preset
void MainWindow::vacval(QString str)
{
    ui->label_vacpreset->setText(str);
}


// Vaccum linear/non-linear
void MainWindow::vaclnl(QString str)
{
    if(str == "NON-Linear")
    {
        ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/nonbg1.png);");
        vp=1;
    }
    else if(str == "Linear")
    {
        ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/linbg3.png);");
        vp=0;
    }

}

// Slot function to set value of vitrectomy preset
void MainWindow::vitval(QString str)
{
    ui->label_vitpreset->setText(str);
}

// Vitrectomy linear/non-linear
void MainWindow::vitlnl(QString str)
{

    if(str == "NON-Linear")
    {
        ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");
        vitp=1;
    }
    else if(str == "Linear")
    {
        ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");
        vitp=0;
    }

}

void MainWindow::typevit(QString str)
{
    madtype = str;
}

// Slot function to set value of diathermy
void MainWindow::diaval(QString str)
{
    ui->label_dia->setText(str);
}

// Get name of surgeon
void MainWindow::setsurgeon()
{
   surgeon=ui->comboBox_surgeonname->currentText();
}

// code for continuous press


// Turn vitrectomy linear or non-linear
void MainWindow::vit_linear_nonlinear()
{
    if(!clicktimer->isActive()) {

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
    clicktimer->start();
    }
}

// code for date and time
void MainWindow::updatetimedate()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateString = currentDateTime.toString("yyyy-MM-dd");

    QString timeString = currentDateTime.toString("hh:mm:ss");

    ui->label_date->setText(dateString);
     ui->label_time->setText(timeString);
}

// Load combobox from database
void MainWindow::comboboxload()
{
    ui->comboBox_surgeonname->clear();

    // Adding surgeons to the combo box
    for (int i = 1; i <= 20; ++i) {
        ui->comboBox_surgeonname->addItem(QString("Surgeon %1").arg(i));
    }
}

// Change screens after 3 seconds
void MainWindow::timerCompleted()
{
    ui->label_22->lower();
    ui->label_12->lower();
    ui->label_2->lower();
    ui->comboBox_surgeonname->move(30,34);
    ui->pushButton_start->lower();

}

// Combo box
void MainWindow::onComboBoxClicked()
{
    timerforondscreen->stop();
if((ui->comboBox_surgeonname->currentIndex())>=0 && (ui->comboBox_surgeonname->currentIndex())<20)
{

        surgeonid=ui->comboBox_surgeonname->currentText();
        surgeonind=ui->comboBox_surgeonname->currentIndex();


        QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
        mydb1.setDatabaseName(PATH);
        mydb1.open();
        QSqlQuery query;



        query.prepare("UPDATE maindb SET lastselected = :surgeonind");
        query.bindValue(":surgeonind", surgeonind);
        if (!query.exec()) {
            qDebug() << "Error updating lastselected column:";
        }

        QString vacmode2, vitmode;

       query.exec("select * from maindb where surgeon='"+surgeonid+"'");
       while(query.next()){
           QString itemname1;
           QString itemname34;
           QString itemname35;
           QString itemname36;
           QString itemname44;
           QString itemname45;
           QString itemname46;
           QString itemname47;


           vp=query.value(51).toInt();
           vip=query.value(52).toInt();
           vitp=query.value(53).toInt();
           lp=query.value(54).toInt();
           lp2=query.value(55).toInt();
           dp=query.value(56).toInt();
           ap=query.value(57).toInt();
           sp=query.value(58).toInt();

           loadPresets();

           itemname1 = query.value(0).toString();
             ui->label_dia->setText(itemname1);
           itemname34 = query.value(33).toString();
           ui->label_vitpreset->setText(itemname34);

           ui->label_led1->setText(query.value(49).toString());
           ui->label_led2->setText(query.value(50).toString());
           ui->label_vacpreset->setText(query.value(35).toString());
           vacmode2=query.value(36).toString();
           vitmode=query.value(34).toString();

           madtype = query.value(48).toString();

           itemname35 = query.value(34).toString();

           if(vitp==0)
           {
                ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");

           }
           else
           {

               ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");

           }

           if(vp==0)
           {
                ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");

           }
           else
           {

               ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");

           }


                itemname44= query.value(43).toString();
               fp0=itemname44.toDouble()*40.95;
                itemname45 = query.value(44).toString();
               fp1=itemname45.toDouble()*40.95;
                itemname46 = query.value(45).toString();
               fp2=itemname46.toDouble()*40.95;
                itemname47 = query.value(46).toString();
               fp3=itemname47.toDouble()*40.95;
           }

       vaclnl(vacmode2);
       vitlnl(vitmode);

    mydb1.close();

}

}

// Show setup screen
void MainWindow::showsetupscreen()
{
        ui->label_22->lower();
        ui->label_12->lower();
        ui->label_2->lower();
        ui->comboBox_surgeonname->move(30,34);
        ui->pushButton_start->lower();
}

void MainWindow::nonlinearcall3()
{
    if(madtype=="Alcon") {
        int vvalue;
        double ot;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1+fp2))
        {
            hhandler->vit_off();
            ui->label_vitactual->setText("0");
        } else {

        std::string col1, col2;
        std::ifstream file(PATH4);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        std::ifstream file2(PATH4);
        for (double i = 1; i <= lineCount; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> vvalue;
        std::stringstream ss2(column2);
        ss2 >> ot;

        hhandler->vit_ontime(ot);
        hhandler->vit_on(1000/(vvalue/60), madtype);
        ui->label_vitactual->setText(QString::number(vvalue));
    }
    }
    else if(madtype=="Midlabs") {
        int vvalue;
        double ot;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1+fp2))
        {
            hhandler->vit_off();
            ui->label_vitactual->setText("0");
        } else {

        std::string col1, col2;
        std::ifstream file(PATH3);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        std::ifstream file2(PATH3);
        for (double i = 1; i <= lineCount; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> vvalue;
        std::stringstream ss2(column2);
        ss2 >> ot;

        hhandler->vit_ontime(ot);
        hhandler->vit_on(1000/(vvalue/60), madtype);
        ui->label_vitactual->setText(QString::number(vvalue));
    }
    }
}

void MainWindow::nonlinearcall2()
{
    if(madtype=="Alcon") {
        int vvalue;
        double ot;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1))
        {
            hhandler->vit_off();
            ui->label_vitactual->setText("0");
        }
        else {

        std::string col1, col2;
        std::ifstream file(PATH4);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        std::ifstream file2(PATH4);
        for (double i = 1; i <= lineCount; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> vvalue;
        std::stringstream ss2(column2);
        ss2 >> ot;

        hhandler->vit_ontime(ot);
        hhandler->vit_on(1000/(vvalue/60), madtype);
        ui->label_vitactual->setText(QString::number(vvalue));
        }
    }

    else if(madtype=="Midlabs") {
        int vvalue;
        double ot;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1))
        {
            ui->label_vitactual->setText("0");
            hhandler->vit_off();
        } else {

        std::string col1, col2;
        std::ifstream file(PATH3);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        std::ifstream file2(PATH3);
        for (double i = 1; i <= lineCount; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> vvalue;
        std::stringstream ss2(column2);
        ss2 >> ot;

        hhandler->vit_ontime(ot);
        hhandler->vit_on(1000/(vvalue/60), madtype);
        ui->label_vitactual->setText(QString::number(vvalue));
    }
    }

}


// Vitrectomy linear 2
void MainWindow::linearcall2()
{
    if(madtype=="Alcon") {
        int vvalue;
        double ot;
        int idx1;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1))
        {
            ui->label_vitactual->setText("0");
            hhandler->vit_off();
        }


        std::string col1, col2;
        std::ifstream file(PATH4);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        idx1 = ((avg-fp0-fp1)/fp2)*lineCount;
        std::ifstream file2(PATH4);

        if(idx1>=1) {
            for (double i = 1; i <= idx1; i++)
            {
                std::getline(file2, line);
            }


            std::istringstream iss(line);
            std::string column1, column2;
            iss >> column1 >> column2;

            std::stringstream ss(column1);
            ss >> vvalue;
            std::stringstream ss2(column2);
            ss2 >> ot;

            hhandler->vit_ontime(ot);
            hhandler->vit_on(1000/(vvalue/60), madtype);
            ui->label_vitactual->setText(QString::number(vvalue));
        }
    }

    else if(madtype=="Midlabs") {
        int vvalue;
        double ot;
        int idx1;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1))
        {
            ui->label_vitactual->setText("0");
            hhandler->vit_off();
        }

        std::string col1, col2;
        std::ifstream file(PATH3);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        idx1 = ((avg-fp0-fp1)/fp2)*lineCount;
        std::ifstream file2(PATH3);

        if(idx1>=1) {
            for (double i = 1; i <= idx1; i++)
            {
                std::getline(file2, line);
            }


            std::istringstream iss(line);
            std::string column1, column2;
            iss >> column1 >> column2;

            std::stringstream ss(column1);
            ss >> vvalue;
            std::stringstream ss2(column2);
            ss2 >> ot;

            hhandler->vit_ontime(ot);
            hhandler->vit_on(1000/(vvalue/60), madtype);
            ui->label_vitactual->setText(QString::number(vvalue));
        }
    }

}


// Vitrectomy linear (3)
void MainWindow::linearcall3()
{
    if(madtype=="Alcon") {
        int vvalue;
        double ot;
        int idx1;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1+fp2))
        {
            ui->label_vitactual->setText("0");
            hhandler->vit_off();
        }

        std::string col1, col2;
        std::ifstream file(PATH4);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        idx1 = ((avg-fp0-fp1-fp2)/fp3)*lineCount;
        std::ifstream file2(PATH4);

        if(idx1>=1) {
            for (double i = 1; i <= idx1; i++)
            {
                std::getline(file2, line);
            }


            std::istringstream iss(line);
            std::string column1, column2;
            iss >> column1 >> column2;

            std::stringstream ss(column1);
            ss >> vvalue;
            std::stringstream ss2(column2);
            ss2 >> ot;

            hhandler->vit_ontime(ot);
            hhandler->vit_on(1000/(vvalue/60), madtype);
            ui->label_vitactual->setText(QString::number(vvalue));
        }

    }
    else if(madtype=="Midlabs") {
        int vvalue;
        double ot;
        int idx1;

        int avg = fp->convert(CHANNEL_0);

        if(avg<=(fp0+fp1+fp2))
        {
            ui->label_vitactual->setText("0");
            hhandler->vit_off();
        }

        std::string col1, col2;
        std::ifstream file(PATH3);
        int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col1) <= ui->label_vitpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::string line;
        idx1 = ((avg-fp0-fp1-fp2)/fp3)*lineCount;
        std::ifstream file2(PATH3);

        if(idx1>=1) {
            for (double i = 1; i <= idx1; i++)
            {
                std::getline(file2, line);
            }


            std::istringstream iss(line);
            std::string column1, column2;
            iss >> column1 >> column2;

            std::stringstream ss(column1);
            ss >> vvalue;
            std::stringstream ss2(column2);
            ss2 >> ot;

            hhandler->vit_ontime(ot);
            hhandler->vit_on(1000/(vvalue/60), madtype);
            ui->label_vitactual->setText(QString::number(vvalue));
        }

    }

}


// Diathermy
void MainWindow::diathermy()
{
    hhandler->dia_on();
    hhandler->dia_count(ui->label_dia->text().toInt()*255/100);
}

// Air injector off
void MainWindow::airinjectoroff()
{
    hhandler->ai_off();
    hhandler->ai_preset_count(0);
    hhandler->write_motor(0x00, 0x03, 0);
    hhandler->ai_actual_count(0);
    ui->label_aiactual->setText("0");
}

// Footpedal reading is less than 2
void MainWindow::setZero()
{
    int avgzero = fp->convert(CHANNEL_0);

    if(avgzero<=(fp0+fp1))
    {
        ui->label_vitactual->setText("0");
    }
}

// LED1 and LED2
void MainWindow::switchled(LED *led, int choice)
{
    if(led == led1)
    {

        switch(choice)
        {
            case(100):
                led1->processUserInput(3);
                led1->processUserInput(1);
                break;
            case(95):
                led1->processUserInput(4);
                led1->processUserInput(1);
                break;
            case(90):
                led1->processUserInput(5);
                led1->processUserInput(1);
                break;
            case(85):
                led1->processUserInput(7);
                led1->processUserInput(1);
                break;
            case(80):
                led1->processUserInput(8);
                led1->processUserInput(1);
                break;
            case(75):
                led1->processUserInput(9);
                led1->processUserInput(1);
                break;
            case(70):
                led1->processUserInput(11);
                led1->processUserInput(1);
                break;
            case(65):
                led1->processUserInput(12);
                led1->processUserInput(1);
                break;
            case(60):
                led1->processUserInput(14);
                led1->processUserInput(1);
                break;
            case(55):
                led1->processUserInput(15);
                led1->processUserInput(1);
                break;
            case(50):
                led1->processUserInput(17);
                led1->processUserInput(1);
                break;
            case(45):
                led1->processUserInput(18);
                led1->processUserInput(1);
                break;
            case(40):
                led1->processUserInput(20);
                led1->processUserInput(1);
                break;
            case(35):
                led1->processUserInput(21);
                led1->processUserInput(1);
                break;
            case(30):
                led1->processUserInput(23);
                led1->processUserInput(1);
                break;
            case(25):
                led1->processUserInput(24);
                led1->processUserInput(1);
                break;
            case(20):
                led1->processUserInput(25);
                led1->processUserInput(1);
                break;
            case(15):
                led1->processUserInput(27);
                led1->processUserInput(1);
                break;
            case(10):
                led1->processUserInput(28);
                led1->processUserInput(1);
                break;
            case(5):
                led1->processUserInput(29);
                led1->processUserInput(1);
                break;
            case(0):
                led1->processUserInput(2);
                break;

        }
    }

    if(led == led2)
    {

        switch(choice)
        {
            case(100):
                led2->processUserInput(3);
                led2->processUserInput(1);
                break;
            case(95):
                led2->processUserInput(4);
                led2->processUserInput(1);
                break;
            case(90):
                led2->processUserInput(5);
                led2->processUserInput(1);
                break;
            case(85):
                led2->processUserInput(7);
                led2->processUserInput(1);
                break;
            case(80):
                led2->processUserInput(8);
                led2->processUserInput(1);
                break;
            case(75):
                led2->processUserInput(9);
                led2->processUserInput(1);
                break;
            case(70):
                led2->processUserInput(11);
                led2->processUserInput(1);
                break;
            case(65):
                led2->processUserInput(12);
                led2->processUserInput(1);
                break;
            case(60):
                led2->processUserInput(14);
                led2->processUserInput(1);
                break;
            case(55):
                led2->processUserInput(15);
                led2->processUserInput(1);
                break;
            case(50):
                led2->processUserInput(17);
                led2->processUserInput(1);
                break;
            case(45):
                led2->processUserInput(18);
                led2->processUserInput(1);
                break;
            case(40):
                led2->processUserInput(20);
                led2->processUserInput(1);
                break;
            case(35):
                led2->processUserInput(21);
                led2->processUserInput(1);
                break;
            case(30):
                led2->processUserInput(23);
                led2->processUserInput(1);
                break;
            case(25):
                led2->processUserInput(24);
                led2->processUserInput(1);
                break;
            case(20):
                led2->processUserInput(25);
                led2->processUserInput(1);
                break;
            case(15):
                led2->processUserInput(27);
                led2->processUserInput(1);
                break;
            case(10):
                led2->processUserInput(28);
                led2->processUserInput(1);
                break;
            case(5):
                led2->processUserInput(29);
                led2->processUserInput(1);
                break;
            case(0):
                led2->processUserInput(2);
                break;

        }
    }
}

// Footpedal beep
void MainWindow::footpedalbeep()
{
    QProcess p;
    QString path = "/usr/bin/beep";

    p.setProgram(path);
    p.start();
    p.waitForFinished();
}

// Interface with vaccum based on footpedal reading
void MainWindow::updateLabel()
{

    // FOOTPEDAL

// setting value for dial
    avgfp = fp->convert(CHANNEL_0);
    flag2=win2->flag2;


  if(vp==0)
  {//linear

      if(ui->label_dialvalue->text() == "0")
      {
          l->writeDAC(0);
          int avg1 = vac->convert(CHANNEL_1)*0.1894;
          ui->label_vacactual->setText(QString::number(avg1));
         if(vip==1){hhandler->vit_off();}
         if(vip==0){hhandler->vit_off();}

         beep_0to1=0;
         beep_1to2=0;
         beep_2to3=0;
         hhandler->speaker_off();


      }
      if(ui->label_dialvalue->text() == "1")
      {

          beep_0to1++;
          if(beep_0to1==1)
          {
               footpedalbeep();
          }
          else if(beep_1to2>1)
          {
              beep_1to2=0;

          }
          else if(beep_1to2>1 && beep_2to3>1)
          {
              beep_1to2=0;
              beep_2to3=0;
          }

        //irrigation/aspiration
          l->writeDAC(0);
          int avg1 = vac->convert(CHANNEL_1)*0.1894;
          ui->label_vacactual->setText(QString::number(avg1));
          if(vip==1){hhandler->vit_off();}
          if(vip==0){hhandler->vit_off();}
          hhandler->speaker_off();


      }
      //vaccum
      if(ui->label_dialvalue->text() == "2")
      {

          beep_1to2++;
          if(beep_1to2==1)
          {
               footpedalbeep();
          }
          else if(beep_2to3>1)
          {
              beep_2to3=0;
          }


          if(flag2==0)
          {
          int dacval;

          std::string col1, col2;
          std::ifstream file(PATH6);
            int lineCount=0;
          while(file >> col1 >> col2)
          {
              if(std::stoi(col2) <= ui->label_vacpreset->text().toInt())
              {
                  lineCount++;
              }
              else
              {
                  lineCount = lineCount;
              }
          }


        std::string line;
        idx = ((avgfp-fp0-fp1)/fp2)*lineCount;
        std::ifstream file2(PATH6);

        for (double i = 1; i <= idx; i++)
        {
            std::getline(file2, line);
        }


        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> dacval;

        l->writeDAC(dacval);
        int avg1 = vac->convert(CHANNEL_1)*0.1894;
        ui->label_vacactual->setText(QString::number(avg1));

        if(ui->label_vacactual->text().toInt()>ui->label_vacpreset->text().toInt())
        {
            if(ui->label_vacpreset->text().toInt()>390)
            {
                int dacval=ui->label_vacpreset->text().toInt()*static_cast<int>(16383/500);
                l->writeDAC(dacval);
                ui->label_vacactual->setText(ui->label_vacpreset->text());

            }
            else
            {
                ui->label_vacactual->setText(ui->label_vacpreset->text());
            }

        }




        file.close();
        file2.close();

          if(vip==1){hhandler->vit_off();}

          if(vip==0){hhandler->vit_off();}
          }
          else {
              if(flag2==1)
              {
                  //swap
               l->writeDAC(0);
               int avg1 = vac->convert(CHANNEL_1)*0.1894;
               ui->label_vacactual->setText(QString::number(avg1));

              }
          }


          if(vip==0) {hhandler->vit_off();ui->label_vitactual->setText("0");}

          if(ui->label_vacactual->text().toInt() <= ui->label_vacpreset->text().toInt() && ui->label_vacactual->text().toInt()>0) {
              hhandler->speaker_on(ui->label_vacactual->text().toInt(),1,0,0);
          }
          else
          {
              hhandler->speaker_off();
          }

      }
      //vitrectomy
      if(ui->label_dialvalue->text() == "3")
      {

          beep_2to3++;
          if(beep_2to3==1)
          {
               footpedalbeep();
          }

          int dacval;


          if(flag2==0)
          {
              std::string col1, col2;
              std::ifstream file(PATH6);
                int lineCount=0;
              while(file >> col1 >> col2)
              {
                  if(std::stoi(col2) <= ui->label_vacpreset->text().toInt())
                  {
                      lineCount++;
                  }
                  else
                  {
                      lineCount = lineCount;
                  }
              }

              std::ifstream file2(PATH6);
              std::string line;
              for (int i = 1; i <= lineCount; i++) {
                  std::getline(file2, line);
              }

              std::istringstream iss(line);
              std::string column1, column2;

              iss >> column1 >> column2;

              std::stringstream ss(column1);
              ss >> dacval;

              l->writeDAC(dacval);
              int avg1 = vac->convert(CHANNEL_1)*0.1894;
              ui->label_vacactual->setText(QString::number(avg1));

              if(ui->label_vacactual->text().toInt()>ui->label_vacpreset->text().toInt())
              {
                  if(ui->label_vacpreset->text().toInt()>390)
                  {
                      int dacval=ui->label_vacpreset->text().toInt()*static_cast<int>(16383/500);
                      l->writeDAC(dacval);
                      ui->label_vacactual->setText(ui->label_vacpreset->text());

                  }
                  else
                  {
                      ui->label_vacactual->setText(ui->label_vacpreset->text());
                  }

              }




        file.close();
         file2.close();

       }

       else if(flag2==1)
       {
              int dacval;

              std::string col1, col2;
              std::ifstream file(PATH6);
                int lineCount=0;
              while(file >> col1 >> col2)
              {
                  if(std::stoi(col2) <= ui->label_vacpreset->text().toInt())
                  {
                      lineCount++;
                  }
                  else
                  {
                      lineCount = lineCount;
                  }
              }


            std::string line;
            idx = ((avgfp-fp0-fp1-fp2)/fp3)*lineCount;
            std::ifstream file2(PATH6);

            for (double i = 1; i <= idx; i++)
            {
                std::getline(file2, line);
            }


            std::istringstream iss(line);
            std::string column1, column2;
            iss >> column1 >> column2;

            std::stringstream ss(column1);
            ss >> dacval;

            l->writeDAC(dacval);
            int avg1 = vac->convert(CHANNEL_1)*0.1894;
            ui->label_vacactual->setText(QString::number(avg1));

           if(ui->label_vacactual->text().toInt()>ui->label_vacpreset->text().toInt())
           {
               if(ui->label_vacpreset->text().toInt()>390)
               {
                   int dacval=ui->label_vacpreset->text().toInt()*static_cast<int>(16383/500);
                   l->writeDAC(dacval);
                   ui->label_vacactual->setText(ui->label_vacpreset->text());

               }
               else
               {
                   ui->label_vacactual->setText(ui->label_vacpreset->text());
               }

           }




           file.close();
            file2.close();

       }


       if(vip==0) {hhandler->vit_off();ui->label_vitactual->setText("0");}

       hhandler->speaker_on(75,0,0,1);

     }
  }

  if(vp==1)
  {//non-linear


    if(ui->label_dialvalue->text() == "0")
    {
        beep_0to1=0;
        beep_1to2=0;
        beep_2to3=0;

        if(vip==1){hhandler->vit_off();}
        if(vip==0){hhandler->vit_off();}
        l->writeDAC(0);
        int avg1 = vac->convert(CHANNEL_1)*0.1894;
        ui->label_vacactual->setText(QString::number(avg1));
        hhandler->speaker_off();
    }
    if(ui->label_dialvalue->text() == "1")
    {

        beep_0to1++;
        if(beep_0to1==1)
        {
             footpedalbeep();
        }
        else if(beep_1to2>1)
        {
            beep_1to2=0;

        }
        else if(beep_1to2>1 && beep_2to3>1)
        {
            beep_1to2=0;
            beep_2to3=0;
        }

        if(vip==1){hhandler->vit_off();}
        if(vip==0){hhandler->vit_off();}

       l->writeDAC(0);
       int avg1 = vac->convert(CHANNEL_1)*0.1894;
       ui->label_vacactual->setText(QString::number(avg1));
       hhandler->speaker_off();

    }
    if(ui->label_dialvalue->text() == "2")
    {

        beep_1to2++;
        if(beep_1to2==1)
        {
             footpedalbeep();
        }
        else if(beep_2to3>1)
        {
            beep_2to3=0;
        }



        if(flag2==0)
        {
            //vaccum
            //normal
        int dacval;

        std::string col1, col2;
        std::ifstream file(PATH6);
          int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col2) <= ui->label_vacpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::ifstream file2(PATH6);
        std::string line;
        for (int i = 1; i <= lineCount; i++) {
            std::getline(file2, line);
        }

        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> dacval;

        l->writeDAC(dacval);
        int avg1 = vac->convert(CHANNEL_1)*0.1894;
        ui->label_vacactual->setText(QString::number(avg1));

        if(ui->label_vacactual->text().toInt()>ui->label_vacpreset->text().toInt())
        {
            if(ui->label_vacpreset->text().toInt()>390)
            {
                int dacval=ui->label_vacpreset->text().toInt()*static_cast<int>(16383/500);
                l->writeDAC(dacval);
                ui->label_vacactual->setText(ui->label_vacpreset->text());

            }
            else
            {
                ui->label_vacactual->setText(ui->label_vacpreset->text());
            }

        }



        file.close();
         file2.close();
    }
    else {
        if(flag2==1)
        {
            //swap
            l->writeDAC(0);
            int avg1 = vac->convert(CHANNEL_1)*0.1894;
            ui->label_vacactual->setText(QString::number(avg1));
        }
    }

    if(ui->label_vacactual->text().toInt() <= ui->label_vacpreset->text().toInt() && ui->label_vacactual->text().toInt()>0) {
        hhandler->speaker_on(ui->label_vacactual->text().toInt(),1,0,0);
    }
    else
    {
        hhandler->speaker_off();
    }

    }

    //vitrectomy
    if(ui->label_dialvalue->text() == "3")
    {

        beep_2to3++;
        if(beep_2to3==1)
        {
             footpedalbeep();
        }

        int dacval;

        std::string col1, col2;
        std::ifstream file(PATH6);
          int lineCount=0;
        while(file >> col1 >> col2)
        {
            if(std::stoi(col2) <= ui->label_vacpreset->text().toInt())
            {
                lineCount++;
            }
            else
            {
                lineCount = lineCount;
            }
        }

        std::ifstream file2(PATH6);
        std::string line;
        for (int i = 1; i <= lineCount; i++) {
            std::getline(file2, line);
        }

        std::istringstream iss(line);
        std::string column1, column2;
        iss >> column1 >> column2;

        std::stringstream ss(column1);
        ss >> dacval;

        l->writeDAC(dacval);
        int avg1 = vac->convert(CHANNEL_1)*0.1894;
        ui->label_vacactual->setText(QString::number(avg1));

        if(ui->label_vacactual->text().toInt()>ui->label_vacpreset->text().toInt())
        {
            if(ui->label_vacpreset->text().toInt()>390)
            {
                int dacval=ui->label_vacpreset->text().toInt()*static_cast<int>(16383/500);
                l->writeDAC(dacval);
                ui->label_vacactual->setText(ui->label_vacpreset->text());

            }
            else
            {
                ui->label_vacactual->setText(ui->label_vacpreset->text());
            }

        }


        file.close();
        file2.close();

        hhandler->speaker_on(75,0,0,1);

    }
  }
}

// Set vit preset value
void MainWindow::vitvalset()
{
    vit_value = ui->label_vitpreset->text().toInt();
}

//Interface with vitrectomy based on footpedal reading
void MainWindow::updateLabel2()
{
    flag2=win2->flag2;

    if(vip==0)
    {
        hhandler->vit_off();
        ui->label_vitactual->setText("0");
    }
    else if(vip==1)
    {

        if(vitp==1)
        {
            if(flag2==0)
            {
               nonlinearcall3();
            }
            else if(flag2==1)
            {
               nonlinearcall2();
            }
        }
        else if(vitp==0)
        {
            if(flag2==0)
            {
                if(avgfp<4085)
                {
                    linearcall3();
                }
                else
                {
                    hhandler->vit_on(1000/(vit_value/60), madtype);
                    ui->label_vitactual->setText(QString::number(vit_value));
                }

            }
            else if(flag2==1)
            {
                if(avgfp<(fp0+fp1+fp2-11))
                {
                    linearcall2();
                }
                else
                {
                    hhandler->vit_on(1000/(vit_value/60), madtype);
                    ui->label_vitactual->setText(QString::number(vit_value));
                }
            }
        }
    }
}


// Turn drain on or off
void MainWindow::drain_onoff()
{
    if(!clicktimer->isActive()) {

    QString drain = ui->pushButton_drain->text();

    if(drain.compare("DRAIN OFF") == 0)
    {
        ui->pushButton_drain->setText("DRAIN ON");
        hhandler->safety_vent_on();
        flag3=1;
    }
    else if(drain.compare("DRAIN ON") == 0)
    {
        ui->pushButton_drain->setText("DRAIN OFF");
        hhandler->safety_vent_off();
        flag3=0;
    }

    clicktimer->start();
    }
}

//fp0
void MainWindow::receiveString0(QString val)
{
    fp0=val.toDouble()*40.95;
    //qDebug()<<fp0;
}

//fp1
void MainWindow::receiveString1(QString val)
{
    fp1=val.toDouble()*40.95;
    //qDebug()<<fp1;
}

//fp2
void MainWindow::receiveString2(QString val)
{
    fp2=val.toDouble()*40.95;
    //qDebug()<<fp2;
}

//fp3
void MainWindow::receiveString3(QString val)
{
    fp3=val.toDouble()*40.95;
    //qDebug()<<fp3;

}

//Backspace on keypad
void MainWindow::on_clickedbackspace()
{
    if(ui->label_vacpreset->focusWidget()) {
        QString data = ui->label_vacpreset->text();
        data.chop(1);
        ui->label_vacpreset->setText(data);
    }
    if(ui->label_vitpreset->focusWidget()) {
        QString data = ui->label_vitpreset->text();
        data.chop(1);
        ui->label_vitpreset->setText(data);
    }
  if(ui->label_siloil->focusWidget()) {
    QString data = ui->label_siloil->text();
    data.chop(1);
    ui->label_siloil->setText(data);
  }
  if(ui->label_aipreset->focusWidget()) {
      QString data = ui->label_aipreset->text();
      data.chop(1);
      ui->label_aipreset->setText(data);
  }
  if(ui->label_dia->focusWidget()) {
      QString data = ui->label_dia->text();
      data.chop(1);
      ui->label_dia->setText(data);
  }
  if(ui->label_led2->focusWidget()) {
      QString data = ui->label_led2->text();
      data.chop(1);
      ui->label_led2->setText(data);
  }
  if(ui->label_led1->focusWidget()) {
      QString data = ui->label_led1->text();
      data.chop(1);
      ui->label_led1->setText(data);
  }
}

// Linear/Non-linear footpedal
void MainWindow::setFPValues()
{
    flag2=win2->flag2;

    avgfp=fp->convert(CHANNEL_0);

    if(avgfp>=0 && avgfp<=fp0)
    {
        if(vitp==0)
        {
            ui->dial->setValue(avgfp);
        }
        if(vitp==1)
        {
            ui->dial->setValue(0);
        }
        ui->label_dialvalue->setText("0");
        hhandler->speaker_off();
    }
    if(avgfp>fp0 && avgfp<=(fp0+fp1))
    {
        if(vitp==0)
        {
            ui->dial->setValue(avgfp);
        }
        if(vitp==1)
        {
            ui->dial->setValue(fp0+fp1);
        }
        ui->label_dialvalue->setText("1");
        hhandler->speaker_off();
    }
    if(avgfp>(fp0+fp1) && avgfp<=(fp0+fp1+fp2))
    {
        if(vp==0 && flag2==0)
        {
            ui->dial->setValue(avgfp);
        }
        if(vp==1 && flag2==0)
        {
            ui->dial->setValue(fp0+fp1+fp2);
        }
        if(vitp==0 && flag2==1)
        {
            ui->dial->setValue(avgfp);
        }
        if(vitp==1 && flag2==1)
        {
            ui->dial->setValue(fp0+fp1+fp2);
        }
        ui->label_dialvalue->setText("2");

        if(ui->label_vacactual->text().toInt() <= ui->label_vacpreset->text().toInt() && ui->label_vacactual->text().toInt()>0) {
            hhandler->speaker_on(ui->label_vacactual->text().toInt(),1,0,0);
        }
        else
        {
            hhandler->speaker_off();
        }

    }
    if(avgfp>(fp0+fp1+fp2) && avgfp<=(fp0+fp1+fp2+fp3))
    {
        if(vitp==0 && flag2==0)
        {
            ui->dial->setValue(avgfp);
        }
        if(vitp==1 && flag2==0)
        {
            ui->dial->setValue(fp0+fp1+fp2+fp3);
        }
        if(vp==0 && flag2==1)
        {
            ui->dial->setValue(avgfp);
        }
        if(vp==1 && flag2==1)
        {
            ui->dial->setValue(fp0+fp1+fp2+fp3);
        }
        ui->label_dialvalue->setText("3");
        hhandler->speaker_on(75,0,0,1);
        //std::this_thread::sleep_for(std::chrono::seconds(3));
        //hhandler->speaker_off();
        //std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    //qDebug()<<avgfp;

}

// Transmit surgeon from settings window to main window
void MainWindow::updateText(const QString &text)
{
    ui->comboBox_surgeonname->setCurrentText(text);
}

void MainWindow::pressureval()
{
    float sample=pres->convert();
    //ui->label->setText(QString::number(sample));
    float psi = static_cast<float>(0.007*sample-5.22);
    //qDebug()<<"Pressure"<<psi;
    //float psi = ((((float)sample - MIN_COUNT) * (100 - 0)) / (MAX_COUNT - MIN_COUNT)) + 0;
    //ui->label_2->setText(QString::number(psi));
    //float bar = static_cast<float>(0.0689476*psi);
    //ui->label_3->setText(QString::number(bar));
}


void MainWindow::led1_setvalue(int pin, int value)
{
    lp=value;
    //lp=win2->lp;
    //writeGPIO(pin,lp);
    qDebug()<<"led1 pedal"<<lp;
    if(lp==0)
    {
        ui->label_27->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");

        ui->pushButton_led1onoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led1onoff->setText("ON");


        if(ui->label_led1->text().toInt() != 0)
        {
            led1->processUserInput(1);
        }

        connect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
        connect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);


        lp=1;

    }
    else
    {
        ui->label_27->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_led1onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led1onoff->setText("OFF");

        led1->processUserInput(2);

        disconnect(ui->pushButton_led1inc, &QPushButton::clicked, this, &MainWindow::increaseledvalue);
        disconnect(ui->pushButton_led1dec, &QPushButton::clicked, this, &MainWindow::decreaseledvalue);
       lp=0;
    }


}

void MainWindow::led2_setvalue(int pin, int value)
{
    lp2=value;
    //lp2=win2->lp2;
    //writeGPIO(pin,lp2);
    qDebug()<<"led2 pedal"<<lp2;
    if(lp2==0)
    {
        ui->label_41->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_led2onoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led2onoff->setText("ON");
        if(ui->label_led2->text().toInt() != 0)
        {
            led2->processUserInput(1);
        }

        connect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
        connect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);


        lp2=1;

    }
    else
    {   ui->label_41->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_led2onoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_led2onoff->setText("OFF");
        led2->processUserInput(2);

        disconnect(ui->pushButton_led2inc, &QPushButton::clicked, this, &MainWindow::increaseled2value);
        disconnect(ui->pushButton_led2dec, &QPushButton::clicked, this, &MainWindow::decreaseled2value);
       lp2=0;
    }

}

void MainWindow::vit_setvalue(int pin, int value)
{
    vip=value;
    //vip=win2->vip;
    //writeGPIO(pin,vip);
    qDebug()<<"vit pedal"<<vip;
    if(vip==0)
    {
        ui->label_38->setStyleSheet("background-color: rgb(116, 184, 222);");

        ui->label_24->setStyleSheet("font: 40pt ;color: rgb(0, 0, 0);");
        ui->pushButton_vitinc->raise();
        ui->pushButton_vitdec->raise();
        ui->label_vitpreset->raise();
        ui->label_vitactual->raise();

        ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_vitonoff->setText("ON");
        vip=1;



        connect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
        connect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);



    }

    else if(vip==1)
    {   ui->label_38->setStyleSheet("");
        ui->label_24->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
        ui->pushButton_vitinc->lower();
        ui->pushButton_vitdec->lower();
        ui->label_vitpreset->lower();
        ui->label_vitactual->lower();

        ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_vitonoff->setText("OFF");
        vip=0;

       hhandler->vit_off();


    disconnect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
    disconnect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);

    }
}

void MainWindow::dia_setvalue(int pin, int value)
{
    dp=value;
    //dp=win2->dp;
    //writeGPIO(pin,dp);
    qDebug()<<"dia pedal"<<dp;
    if(dp==0)
    {
        ui->label_14->setStyleSheet("background-color: rgb(116, 184, 222);");
        ui->label_25->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_diainc->raise();
        ui->pushButton_diadec->raise();
        ui->label_dia->raise();
        ui->pushButton_diaonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_diaonoff->setText("ON");
        timedia.start(1000);
        connect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);


        connect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
        connect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);
        dp=1;

    }
    else
    {
        ui->label_14->setStyleSheet("");
        ui->label_25->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_diainc->lower();
        ui->pushButton_diadec->lower();
        ui->label_dia->lower();
        ui->pushButton_diaonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_diaonoff->setText("OFF");
        hhandler->dia_off();

        timedia.stop();
        disconnect(&timedia, &QTimer::timeout, this, &MainWindow::diathermy);

        disconnect(ui->pushButton_diainc, &QPushButton::clicked, this, &MainWindow::increaseDiathermyValue);
        disconnect(ui->pushButton_diadec, &QPushButton::clicked, this, &MainWindow::decreaseDiathermyValue);
       dp=0;
    }

}

void MainWindow::siloil_setvalue(int pin, int value)
{
    sp=value;
    //sp=win2->sp;
    //writeGPIO(pin,sp);
    qDebug()<<"silicon oil pedal"<<sp;
    if(sp==0)
    {
        ui->label_19->setStyleSheet("background-color: rgb(116, 184, 222);");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(0,0,0);");
        ui->pushButton_siloildec->raise();
        ui->pushButton_siloilinc->raise();
        ui->label_siloil->raise();

        ui->pushButton_siloilonoff->setStyleSheet("image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_siloilonoff->setText("ON");

        connect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
        connect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);

        timesiloil.start(100);
        connect(&timesiloil, &QTimer::timeout, this, &MainWindow::siloil);

        sp=1;

    }
    else
    {
        ui->label_19->setStyleSheet("");
        ui->label_26->setStyleSheet("font: 40pt ;color: rgb(255,255,255);");
        ui->pushButton_siloildec->lower();
        ui->pushButton_siloilinc->lower();
        ui->label_siloil->lower();

        ui->pushButton_siloilonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_siloilonoff->setText("OFF");

        disconnect(ui->pushButton_siloilinc, &QPushButton::clicked, this, &MainWindow::increasesiliconoilvalue);
        disconnect(ui->pushButton_siloildec, &QPushButton::clicked, this, &MainWindow::decreasesiliconoilvalue);

        hhandler->vso_off();
        hhandler->siloil_off();

        timesiloil.stop();
        disconnect(&timesiloil, &QTimer::timeout, this, &MainWindow::siloil);

        sp=0;
    }

}

//Silicon oil
void MainWindow::siloil()
{
    if(sp==0)
    {
        hhandler->siloil_off();
        hhandler->vso_off();
    }
    else if(sp==1)
    {
        l->writeDAC(0);
        int avg1 = vac->convert(CHANNEL_1)*0.1894;
        ui->label_vacactual->setText(QString::number(avg1));

        ui->label_vitactual->setText("0");
        vip=0;
        ui->label_38->setStyleSheet("");
        ui->label_24->setStyleSheet("font: 40pt;color: rgb(255, 255, 255);");
        ui->pushButton_vitinc->lower();
        ui->pushButton_vitdec->lower();
        ui->label_vitpreset->lower();
        ui->label_vitactual->lower();
        ui->pushButton_vitonoff->setStyleSheet("image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;");
        ui->pushButton_vitonoff->setText("OFF");
        hhandler->vit_off();
        disconnect(ui->pushButton_vitinc, &QPushButton::clicked, this, &MainWindow::increaseVitrectomyValue);
        disconnect(ui->pushButton_vitdec, &QPushButton::clicked, this, &MainWindow::decreaseVitrectomyValue);


        if(ui->label_dialvalue->text() == "0" || ui->label_siloil->text().toInt()==0)
        {
            hhandler->siloil_off();
            hhandler->vso_off();
        }
        else
        {

            avgfp=fp->convert(CHANNEL_0);
            float value1 = ui->label_siloil->text().toInt();
            float value2 = (((avgfp-fp0)/(fp1+fp2+fp3))*(55*(value1/100)))+45;
//            qDebug()<<value2;
            hhandler->vso_ontime((value2/(100*freq))/resolution);
            hhandler->vso_period((1/freq)/resolution);
        }
    }
}

void MainWindow::exportGPIO(int pin) {
    std::ofstream exportFile("/sys/class/gpio/export");
    if (!exportFile.is_open()) {
        std::cerr << "Unable to export GPIO" << std::endl;
        return;
    }
    exportFile << pin;
    exportFile.close();
}

void MainWindow::setGPIODirection(int pin, const std::string& direction) {
    std::ofstream directionFile("/sys/class/gpio/gpio" + std::to_string(pin) + "/direction");
    if (!directionFile.is_open()) {
        std::cerr << "Unable to set GPIO direction" << std::endl;
        return;
    }
    directionFile << direction;
    directionFile.close();
}

void MainWindow::writeGPIO(int pin, int value) {
    std::ofstream valueFile("/sys/class/gpio/gpio" + std::to_string(pin) + "/value");
    if (!valueFile.is_open()) {
        std::cerr << "Unable to write to GPIO" << std::endl;
        return;
    }
    valueFile << value;
    valueFile.close();
}

void MainWindow::configOnOff()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);

    mydb.open();

    QSqlQuery query;
    QString vp1=QString::number(vp);
    QString vip1=QString::number(vip);
    QString vitp1=QString::number(vitp);
    QString lp1=QString::number(lp);
    QString lp21=QString::number(lp2);
    QString dp1=QString::number(dp);
    QString ap1=QString::number(ap);
    QString sp1=QString::number(sp);

    query.prepare("update maindb set vp1='"+vp1+"',vip1='"+vip1+"',vitp1='"+vitp1+"',lp1='"+lp1+"',lp21='"+lp21+"',dp1='"+dp1+"',ap1='"+ap1+"',sp1='"+sp1+"'where surgeon='"+surgeonid+"'");
    query.exec();

    query.bindValue(vp1,"vp1");
    query.bindValue(vip1,"vip1");
    query.bindValue(vitp1,"vitp1");
    query.bindValue(lp1,"lp1");
    query.bindValue(lp21,"lp21");
    query.bindValue(dp1,"dp1");
    query.bindValue(ap1,"ap1");
    query.bindValue(sp1,"sp1");

    qDebug()<<vip1<<lp1<<lp21<<dp1<<ap1<<sp1<<vp1<<vitp1;

    loadPresets();


    mydb.close();

}

void MainWindow::loadPresets()
{
    QString styleoff="image: url(:/new/prefix1/img/off.png);border:3px solid black;border-radius:40px;";
    QString styleon="image: url(:/new/prefix1/img/on.png);border:3px solid black;border-radius:40px;";

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH);
    mydb.open();
    QSqlQuery query;
    query.exec("select * from maindb where surgeon='"+surgeonid+"'");
    while(query.next()){
        vp=query.value(51).toInt();
        qDebug()<<"vac_mode"<<vp;
        vip=query.value(52).toInt();
        vitp=query.value(53).toInt();
        lp=query.value(54).toInt();
        lp2=query.value(55).toInt();
        dp=query.value(56).toInt();
        ap=query.value(57).toInt();
        sp=query.value(58).toInt();
    }

    mydb.close();

    if(vp==1)
    {
        ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/nonbg1.png);");
    }
    else if(vp==0)
    {
        ui->label_28->setStyleSheet("image: url(:/new/prefix1/img/linbg3.png);");
    }

    if(vitp==1)
    {
        ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/nlinvit2.png);");
    }
    else if(vitp==0)
    {
        ui->label_44->setStyleSheet("image: url(:/new/prefix1/img/linvit1.png);");
    }

    if(vip==0)
    {
        ui->pushButton_vitonoff->setStyleSheet(styleoff);
        ui->pushButton_vitonoff->setText("OFF");
    }
    if(vip==1)
    {
        ui->pushButton_vitonoff->setStyleSheet(styleon);
        ui->pushButton_vitonoff->setText("ON");
    }


    if(lp==0)
    {
        ui->pushButton_led1onoff->setStyleSheet(styleoff);
        ui->pushButton_led1onoff->setText("OFF");
    }
    if(lp==1)
    {
        ui->pushButton_led1onoff->setStyleSheet(styleon);
        ui->pushButton_led1onoff->setText("ON");
    }



    if(lp2==0)
    {
        ui->pushButton_led2onoff->setStyleSheet(styleoff);
        ui->pushButton_led2onoff->setText("OFF");
    }
    if(lp2==1)
    {
        ui->pushButton_led2onoff->setStyleSheet(styleon);
        ui->pushButton_led2onoff->setText("ON");
    }



    if(dp==0)
    {
        ui->pushButton_diaonoff->setStyleSheet(styleoff);
        ui->pushButton_diaonoff->setText("OFF");
    }
    if(dp==1)
    {
        ui->pushButton_diaonoff->setStyleSheet(styleon);
        ui->pushButton_diaonoff->setText("ON");
    }



    if(ap==0)
    {
        ui->pushButton_aionoff->setStyleSheet(styleoff);
        ui->pushButton_aionoff->setText("OFF");
    }
    if(ap==1)
    {
        ui->pushButton_aionoff->setStyleSheet(styleon);
        ui->pushButton_aionoff->setText("ON");
    }



    if(sp==0)
    {
        ui->pushButton_siloilonoff->setStyleSheet(styleoff);
        ui->pushButton_siloilonoff->setText("OFF");
    }
    if(sp==1)
    {
        ui->pushButton_siloilonoff->setStyleSheet(styleon);
        ui->pushButton_siloilonoff->setText("ON");
    }

    qDebug()<<vip<<lp<<lp2<<dp<<ap<<sp<<vp<<vitp;



}

void MainWindow::fpone()
{
    if(ui->label_dialvalue->text() == "1")
    {
        ui->label_vacactual->setText("0");
    }
}
