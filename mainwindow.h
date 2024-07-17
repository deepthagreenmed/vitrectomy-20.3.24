#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vaccum.h"
#include "keypad.h"
#include "settingswindow.h"
#include "footpedal.h"
#include "hwhandler.h"
#include "led.h"
#include "ltc2614.h"
#include "pressuresensor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

#include <QLabel>
#include <QSqlDatabase>
#include <QTimer>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QString>
#include <QProcess>

#define PATH "/home/vitrectomy.db"
//#define PATH2 "/home/vsodata10.txt"
#define PATH3 "/home/midlabs.txt"
#define PATH4 "/home/aktive.txt"
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

    void linearcall23();
    void linearcall3();
    void nonlinearcall23();
    void nonlinearcall3();


    LED *led1;
    LED *led2;
    bool eventFilter(QObject* object, QEvent* event);
    void updateLabelValue(QLabel* label, int dig, int value, int maxValue);
    //void zeropreset(QLabel *label, int dig, int prevValue);
    void switchled(LED *led, int choice);
    void footpedalbeep();
    int beep_0to1=0;
    int beep_1to2=0;
    int beep_2to3=0;
    QString madtype;
    QString surgeon;


signals:
    void airinjectoronFinished();


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

    void aibackground();

    void on_clicked(const QString& digit);

     void on_clickedenter();

     void on_clickedbackspace();

     void airinjectoron();

     void vitvalset();




private slots:

        void vacpreset(const QString &text);

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

        void increaseledvalue2();

        void decreaseledvalue2();

        void increasesiliconoil();

        void decreasesiliconoil();

        //settings window
        void showsettingswindow();

        //silicon oil
        void sil_oil_onoff();

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

        //surgeon
        void setsurgeon();

        //continous press
        //vaccum
        void on_increase_vac_pressed();

        void on_increase_vac_released();

        void on_decrease_vac_pressed();

        void on_decrease_vac_released();

        //vitrectomy
        void on_increase_vit_pressed();

        void on_increase_vit_released();

        void on_decrease_vit_pressed();

        void on_decrease_vit_released();

        //silicon oil
        void on_increase_sil_oil_pressed();

        void on_increase_sil_oil_released();

        void on_decrease_sil_oil_pressed();

        void on_decrease_sil_oil_released();

        //led1
        void on_increase_led1_pressed();

        void on_increase_led1_released();

        void on_decrease_led1_pressed();

        void on_decrease_led1_released();

        //air injector
        void on_increase_ai_pressed();

        void on_increase_ai_released();

        void on_decrease_ai_pressed();

        void on_decrease_ai_released();

        //diathermy
        void on_increase_dia_pressed();

        void on_increase_dia_released();

        void on_decrease_dia_pressed();

        void on_decrease_dia_released();

        //led2
        void on_increase_led2_pressed();

        void on_increase_led2_released();

        void on_decrease_led2_pressed();

        void on_decrease_led2_released();

        //vitrectomy linear/nonlinear
        void vit_linear_nonlinear();

        //led2
        void led2_onoff();

        void comboboxload();

        void onComboBoxClicked();

        void timerCompleted();

        //setup screen
        void showsetupscreen();

        //swap on/off
        void swap_onoff();

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
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QPropertyAnimation *animation4;
    QPropertyAnimation *animation5;
    int vp=0;
    int ap=0;
    int vip=0;
    int vitp=1;
    int dp=0;
    int lp=0;
    int lp2=0;
    int sp=0;
    int p=0;
    int avgfp=0;
    double fp0;
    double fp1;
    double fp2;
    double fp3;
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
    QTimer timeai2;
    QTimer timeai3;
    bool aiflag=0;
    keypad *key;
//    QMessageBox *msg;
//    QTimer *timermsg;
    ltc2614 *l;
    pressuresensor *pressure;
    int vacprevval;

};
#endif // MAINWINDOW_H
