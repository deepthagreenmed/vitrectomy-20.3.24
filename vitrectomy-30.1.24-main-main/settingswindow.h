#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "footpedal.h"
#include "keypad.h"
#include "textkeypad.h"

#include <QSqlDatabase>
#include <QDialog>
#include <QMainWindow>
#include <QMouseEvent>

#define PATH "/home/main.db"

namespace Ui {
class settingswindow;
}

class settingswindow : public QDialog
{
    Q_OBJECT

public:
    explicit settingswindow(QWidget *parent = nullptr);
    ~settingswindow();
     QString surgeonid,le1,le2,le3;
     QString docnameold;
     int currentindex=0;
    bool eventFilter(QObject* object, QEvent* event);
    void populatetype();


signals:
    void stringPassed(const QString& str);
    void stringPassed0(const QString& str);
    void stringPassed1(const QString& str);
    void stringPassed2(const QString& str);
    void stringPassed3(const QString& str);
    void led1str(QString str);
    void led2str(QString str);

public slots:

    void on_clicked(const QString& digit);

     void on_clickedbackspace();

     void on_clickedenter();

     void zeroinc();

     void zerodec();

     void oneinc();

     void onedec();

     void twoinc();

     void twodec();

     void threeinc();

     void threedec();

     void on_clickedtext(const QString& digit);

     void on_clickedbackspacetext();

     void on_clickedspace();

     void on_clickedentertext();

    //diapm
    void on_pushButton_4_clicked();

    //pe
    void on_pushButton_5_clicked();

    //led
    void on_pushButton_8_clicked();

    //pc
    void on_pushButton_9_clicked();

    //ps
    void on_pushButton_10_clicked();

    //vv
    void on_pushButton_6_clicked();

    //vc
    void on_pushButton_7_clicked();

    //home screen
    void on_pushButton_12_clicked();

    //dimensions
    void on_pushButton_15_clicked();

    //dimensions with surgeon
    void on_pushButton_23_clicked();


private slots:
    void on_listWidget_currentTextChanged(const QString &currentText);

    //footpedal settings
    void on_pushButton_13_clicked();

    //tab0
    void on_pushButton_2_clicked();

    //tab1
    void on_pushButton_clicked();

    //tab2
    void on_pushButton_3_clicked();

    //tab3
    void on_pushButton_8vit_clicked();

    //tab4
    void on_pushButton_5fp_clicked();

    //tab5
    void on_pushButton_fps_clicked();





private:
    Ui::settingswindow *ui;
    bool flag = false;
      footpedal *fp;
      QSqlDatabase mydb;
      QSqlDatabase db1;
      keypad *key;
      textkeypad *text;
      int led1value;
      int led2value;




};

#endif // SETTINGSWINDOW_H
