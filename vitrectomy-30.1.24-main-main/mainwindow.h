#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>

#include "vaccum.h"
#include "keypad.h"
#include "settingswindow.h"
#include "footpedal.h"
#include "hwhandler.h"
#include "led.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

#include <QSqlDatabase>
#include <QTimer>
#include <QMouseEvent>
#include <QPropertyAnimation>

#define PATH "/home/main.db"
#define PATH2 "/home/vsodata9new.txt"

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
    void linearcall();
    LED *led1;
    LED *led2;
    bool eventFilter(QObject* object, QEvent* event);
    void updateLabelValue(QLabel* label, int value, int maxValue);
public slots:
    void receiveString(const QString& str);
    void led1val(QString str);
    void led2val(QString str);
    void aibackground();
    void on_clicked(const QString& digit);

     void on_clickedbackspace();

     void on_clickedenter();



private slots:

     void transitionToNewScreen();

        void label48();

         void updateLabel();

        void diathermy();

        void airinjector();

        void airinjector2();

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
        void on_pushButton_6_clicked();

        //silicon oil
        void on_pushButton_2_clicked();

        //vaccum linear/nonlinear
        void on_pushButton_20_clicked();

        //led1
        void on_pushButton_3_clicked();

        //diathermy
        void on_pushButton_5_clicked();

        //air injector
        void on_pushButton_7_clicked();

        //vitrectomy
        void on_pushButton_4_clicked();

        //surgeon
        void on_pushButton_clicked();

        //continous press
        //vaccum
        void on_pushButton_8_pressed();

        void on_pushButton_8_released();

        void on_pushButton_12_pressed();

        void on_pushButton_12_released();

        //vitrectomy
        void on_pushButton_11_pressed();

        void on_pushButton_11_released();

        void on_pushButton_15_pressed();

        void on_pushButton_15_released();

        //silicon oil
        void on_pushButton_19_pressed();

        void on_pushButton_19_released();

        void on_pushButton_18_pressed();

        void on_pushButton_18_released();

        //led1
        void on_pushButton_17_pressed();

        void on_pushButton_17_released();

        void on_pushButton_16_pressed();

        void on_pushButton_16_released();

        //air injector
        void on_pushButton_9_pressed();

        void on_pushButton_9_released();

        void on_pushButton_13_pressed();

        void on_pushButton_13_released();

        //diathermy
        void on_pushButton_10_pressed();

        void on_pushButton_10_released();

        void on_pushButton_14_pressed();

        void on_pushButton_14_released();

        //led2
        void on_pushButton_21_pressed();

        void on_pushButton_21_released();

        void on_pushButton_22_pressed();

        void on_pushButton_22_released();

        //vitrectomy linear/nonlinear
        void on_pushButton_24_clicked();

        //led2
        void on_pushButton_23_clicked();

        void comboboxload();

        void onComboBoxClicked();

        void timerCompleted();

        //start screen
        void on_pushButton_25_clicked();

        //swap on/off
        void on_pushButton_26_clicked();

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
    int avg=0;
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
    QTimer timedia;
    QTimer timeai;
    QTimer timer48;
    QTimer timeai2;
    QTimer timeai3;
    int aiflag=0;
    keypad *key;


};
#endif // MAINWINDOW_H
