#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vaccum.h"
#include "keypad.h"
#include "settingswindow.h"
#include "footpedal.h"
#include "hwhandler.h"
#include "led.h"
#include "ltc2614.h"
#include "sensor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <unistd.h>
#include <chrono>
#include <thread>

#include <QLabel>
#include <QSqlDatabase>
#include <QTimer>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QString>
#include <QProcess>
#include <QComboBox>

#define PATH "/home/vitrectomy.db"
//#define PATH2 "/home/vsodata10.txt"
#define PATH3 "/home/midlabs.txt"
#define PATH4 "/home/alcon.txt"
//#define PATH5 "/home/dorc.txt"
#define PATH6 "/home/data_casete3.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void connections();
   QString surgeonid;
   int surgeonind;
    int vit_value=60; //period
    float resolution = 0.000000005; //5ns
    float freq=12000;   //12kHz
    void linearcall2();
    void linearcall3();
    void nonlinearcall2();
    void nonlinearcall3();
    LED *led1;
    LED *led2;
    bool eventFilter(QObject* object, QEvent* event);
    void updateLabelValue(QLabel* label, int dig, int value, int maxValue);
    void switchled(LED *led, int choice);
    void footpedalbeep();
    int beep_0to1=0;
    int beep_1to2=0;
    int beep_2to3=0;
    QString madtype;
    QString surgeon;
    void exportGPIO(int pin);
    void setGPIODirection(int pin, const std::string& direction);
    void writeGPIO(int pin, int value);
    void loadPresets();





signals:

public slots:
    void updateText(const QString &text);
    void setFPValues();
    void receiveString(const QString& str);
    void receiveString0(QString val);
    void receiveString1(QString val);
    void receiveString2(QString val);
    void receiveString3(QString val);
    void led1val(QString str);
    void led2val(QString str);
    void vacval(QString str);
    void vaclnl(QString str);
    void vitval(QString str);
    void vitlnl(QString str);
    void typevit(QString str);
    void diaval(QString val);
    void on_clicked(const QString& digit);
     void on_clickedenter();
     void on_clickedbackspace();
     void vitvalset();




private slots:
     void configOnOff();
     void siloil();
     void led1_setvalue(int pin, int value);
     void led2_setvalue(int pin, int value);
     void vit_setvalue(int pin, int value);
     void dia_setvalue(int pin, int value);
     void siloil_setvalue(int pin, int value);
    void dacvalue();
    void pressureval();
    void transitionToNewScreen();
    void setZero();
     void updateLabel();
     void updateLabel2();
    void diathermy();
    void airinjectoroff();
     void updatetimedate();
    void increaseVaccumValue();
    void decreaseVaccumValue();
    void increaseVitrectomyValue();
    void decreaseVitrectomyValue();
    void increaseDiathermyValue();
    void decreaseDiathermyValue();
    void increaseAirInjectorValue();
    void decreaseAirInjectorValue();
    void increaseledvalue();
    void decreaseledvalue();
    void increaseled2value();
    void decreaseled2value();
    void increasesiliconoilvalue();
    void decreasesiliconoilvalue();
    //settings window
    void showsettingswindow();
    //silicon oil
    void siloil_onoff();
    //vaccum linear/nonlinear
    void vac_linear_nonlinear();
    //led1
    void led1_onoff();
    //diathermy
    void dia_onoff();
    //air injector
    void ai_onoff();
    //vitrectomy
    void vit_onoff();
//    void vit_onoff2();
    //surgeon
    void setsurgeon();
    //vitrectomy linear/nonlinear
    void vit_linear_nonlinear();
    //led2
    void led2_onoff();
    void comboboxload();
    void onComboBoxClicked();
    void timerCompleted();
    //setup screen
    void showsetupscreen();
    //drain on/off
    void drain_onoff();

private:
    Ui::MainWindow *ui;
    settingswindow *win2;
    QSqlDatabase mydb1;
    QSqlDatabase mydb2;
    QTimer time;
    QTimer *timerforondscreen ;
    int frequency;
    float dutycycle;
    int vp;
    int ap;
    int vip;
    int vitp;
    int dp;
    int lp;
    int lp2;
    int sp;
    int p=0;
    int avgfp=0;
    double fp0=2*40.95;
    double fp1=8*40.95;
    double fp2=45*40.95;
    double fp3=45*40.95;
    hwHandler *hhandler;
    footpedal *fp;
    Vaccum *vac;
    int vacc=1;
    double idx;
     bool flag = false;
    int flag2=0;
    int flag3=0;
    QTimer timedia;
    QTimer timeai;
    QTimer timerzero;
    keypad *key;
    ltc2614 *l;
    sensor *pres;
    int vacpresetval;
    QTimer timesiloil;
    QTimer *clicktimer;
    QTimer *timercb;
    int counter1=0;
    int counter2=0;
    int counter3=0;
    int counter4=0;
    int counter5=0;


};
#endif // MAINWINDOW_H


