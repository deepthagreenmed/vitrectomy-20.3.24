#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "footpedal.h"
#include "keypad.h"
#include "textkeypad.h"

#include <QSqlDatabase>
#include <QDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include <QLineEdit>
#include <QListWidget>

#define PATH "/home/vitrectomy.db"

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
    void updateLineEditValue(QLineEdit* label, int dig, int value, int maxValue);
    int flag2=0;
    int lp=0;
    int lp2=0;
    int vip=0;
    int dp=0;
    int sp=0;


signals:
    void stringPassed(const QString& str);
    void stringPassed0(const QString& str);
    void stringPassed1(const QString& str);
    void stringPassed2(const QString& str);
    void stringPassed3(const QString& str);
    void led1str(QString str);
    void led2str(QString str);
    void vacstr(QString str);
    void vacmode(QString str);
    void vitstr(QString str);
    void vitmode(QString str);
    void vittype(QString str);
    void diastr(QString str);
    void textSelected(const QString &text);
    void led1_pedal(int pin, int value);
    void led2_pedal(int pin, int value);
    void vit_pedal(int pin, int value);
    void dia_pedal(int pin, int value);
    void siloil_pedal(int pin, int value);


public slots:
    void fpsettings();
    void updateSurgeon();
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
     //dia
    void on_dia_clicked();
    //led
    void on_led_clicked();
    //vac
    void on_ia_clicked();
    //vit
    void on_vit_clicked();
    //home screen
    void show_surgery_screen();
    //save for all surgeons
    void on_saveforall_clicked();
    //save for current surgeon
    void on_save_clicked();
    void on_fp_settings_clicked();


private slots:
    //swap on/off
    void swap_onoff();
    void onCutterTypeChanged(int index);
    void loadDatabaseFromList(const QString &currentText);
    //footpedal settings

    //tabs
    void on_tab_dia_clicked();
    void on_tab_led_clicked();
    void on_tab_ia_clicked();
    void on_tab_vit_clicked();
    void on_tab_fp_clicked();
    void on_tab_fppreset_clicked();

    void comboBoxTL(int index);
    void comboBoxBR(int index);
    void comboBoxBL(int index);
    void comboBoxTR(int index);


private:
    Ui::settingswindow *ui;
    QString tl1;
    QString tr1;
    QString bl1;
    QString br1;
    bool flag = false;
      footpedal *fp;
      QSqlDatabase mydb;
      QSqlDatabase db1;
      keypad *key;
      textkeypad *text;
      int led1value;
      int led2value;
      int tlpedal=0;
      int blpedal=0;
      int trpedal=0;
      int brpedal=0;
      QTimer* clicktimer;





};

#endif // SETTINGSWINDOW_H
