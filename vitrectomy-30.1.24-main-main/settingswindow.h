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

    // void on_clickedbackspace();

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
    void on_diapm_clicked();

    //pe
    void on_pe_clicked();

    //led
    void on_led_clicked();

    //pc
    void on_pc_clicked();

    //ps
    void on_ps_clicked();

    //vv
    void on_vv_clicked();

    //vc
    void on_vc_clicked();

    //home screen
    void show_surgery_screen();

    //dimensions
    void on_dimensions_clicked();

    //dimensions with surgeon
    void on_dimensions_with_surgeon_clicked();


private slots:
    void loadDatabaseFromList(const QString &currentText);

    //footpedal settings
    void on_fp_settings_clicked();

    //tabs
    void on_tab_dia_clicked();

    void on_tab_led_clicked();

    void on_tab_ia_clicked();

    void on_tab_vit_clicked();

    void on_tab_fp_clicked();

    void on_tab_fppreset_clicked();


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
