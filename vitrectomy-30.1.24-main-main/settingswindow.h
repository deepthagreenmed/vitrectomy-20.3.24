#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include<QSqlDatabase>
#include <QDialog>
#include <QMainWindow>
#include"footpedal.h"
#include "keypad.h"
#include <QMouseEvent>
#include"textkeypad.h"

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



//protected:
//     void mousePressEvent(QMouseEvent *event) override
//     {
//         if(event->button() == Qt::LeftButton)
//         {
//             key->resize(400,300);
//             key->show();
//         }
//         if(event->button() == Qt::RightButton)
//         {
//             key->hide();
//         }

//     }


signals:
    void stringPassed(const QString& str);
    void stringPassed0(const QString& str);
    void stringPassed1(const QString& str);
    void stringPassed2(const QString& str);
    void stringPassed3(const QString& str);


public slots:

    void keypadshow(int oldPos, int newPos);

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



  //  void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



    void on_pushButton_12_clicked();

    void on_pushButton_clicked();


    void on_pushButton_15_clicked();

    void on_pushButton_23_clicked();

    //void on_comboBox_currentTextChanged(const QString &arg1);

  //  void on_comboBox_currentIndexChanged(const QString &arg1);

   // void on_coformmboBox_currentIndexChanged(int index);

private slots:
    void on_listWidget_currentTextChanged(const QString &currentText);

//    void on_horizontalSlider_valueChanged(int value);


//    void on_horizontalSlider_3_valueChanged(int value);

//    void on_horizontalSlider_4_valueChanged(int value);



    void on_pushButton_13_clicked();

//    void on_horizontalSlider_sliderReleased();

//    void on_horizontalSlider_3_sliderReleased();

//    void on_horizontalSlider_4_sliderReleased();




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8vit_clicked();

    void on_pushButton_5fp_clicked();

    void on_pushButton_fps_clicked();





private:
    Ui::settingswindow *ui;
    bool flag = false;
      footpedal *fp;
      QSqlDatabase mydb;
      QSqlDatabase db1;
      keypad *key;
      textkeypad *text;




};

#endif // SETTINGSWINDOW_H
