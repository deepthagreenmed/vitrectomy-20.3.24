/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingswindow
{
public:
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QPushButton *pushButton_save;
    QLineEdit *lineEdit_powmax;
    QLabel *label_9;
    QLabel *label_15;
    QLabel *label_25;
    QWidget *tab_6;
    QLabel *label_45;
    QLineEdit *lineEdit_led2;
    QLineEdit *lineEdit_led1;
    QLabel *label_42;
    QLabel *label_44;
    QPushButton *pushButton_save_2;
    QWidget *tab_8;
    QPushButton *pushButton_save_3;
    QLabel *label_30;
    QLineEdit *lineEdit_vac;
    QLabel *label_26;
    QLabel *label_14;
    QLabel *label_33;
    QComboBox *comboBox_mode;
    QWidget *tab_7;
    QLabel *label_24;
    QPushButton *pushButton_save_4;
    QLineEdit *lineEdit_cutrate;
    QLabel *label_13;
    QLabel *label_28;
    QLabel *label_34;
    QLabel *label_43;
    QLineEdit *lineEdit_maxcutrate;
    QLabel *label_46;
    QComboBox *comboBox_cuttermode;
    QComboBox *comboBox_cuttertype;
    QWidget *tab_9;
    QPushButton *pushButton_saveforall;
    QPushButton *pushButton_save_5;
    QLabel *label_11;
    QLabel *label_20;
    QLabel *label_35;
    QComboBox *comboBox_tr;
    QComboBox *comboBox_bl;
    QComboBox *comboBox_br;
    QComboBox *comboBox_tl;
    QWidget *tab_10;
    QPushButton *pushButton_oneinc;
    QPushButton *pushButton_onedec;
    QPushButton *pushButton_twoinc;
    QPushButton *pushButton_twodec;
    QPushButton *pushButton_threeinc;
    QPushButton *pushButton_threedec;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_save_6;
    QLineEdit *lineEdit_one;
    QLineEdit *lineEdit_two;
    QLineEdit *lineEdit_three;
    QLabel *label_8;
    QProgressBar *progressBar_one;
    QProgressBar *progressBar_two;
    QProgressBar *progressBar_three;
    QProgressBar *progressBar_zero;
    QPushButton *pushButton_zerodec;
    QPushButton *pushButton_zeroinc;
    QLineEdit *lineEdit_zero;
    QLabel *label_3;
    QLabel *label_105;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_106;
    QLabel *label_107;
    QLabel *label_108;
    QLabel *label_110;
    QLabel *label_16;
    QLabel *label_36;
    QLabel *label_27;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_37;
    QPushButton *pushButton_swap;
    QLabel *label_19;
    QLabel *label_17;
    QListWidget *listWidget;
    QPushButton *pushButton_goback;
    QLabel *label_12;
    QLabel *label_23;
    QLabel *label_title;
    QLabel *label_29;
    QLabel *label_31;
    QLabel *label_32;
    QLineEdit *lineEdit_5;
    QLabel *vit;
    QPushButton *pushButton_dia;
    QPushButton *pushButton_fp;
    QPushButton *pushButton_fps;
    QPushButton *pushButton_vit;
    QPushButton *pushButton_ia;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_41;
    QPushButton *pushButton_led;

    void setupUi(QDialog *settingswindow)
    {
        if (settingswindow->objectName().isEmpty())
            settingswindow->setObjectName(QString::fromUtf8("settingswindow"));
        settingswindow->resize(1920, 1080);
        settingswindow->setMaximumSize(QSize(1920, 1080));
        settingswindow->setStyleSheet(QString::fromUtf8(""));
        tabWidget_2 = new QTabWidget(settingswindow);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(390, -10, 1121, 1071));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(1);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tabWidget_2->setFont(font);
        tabWidget_2->setLayoutDirection(Qt::LeftToRight);
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);\n"
"QTabWidget{font: 0.5pt \"Ubuntu\";}\n"
"QTabWidget::tab-bar { alignment: center; }\n"
""));
        tabWidget_2->setTabPosition(QTabWidget::South);
        tabWidget_2->setTabShape(QTabWidget::Rounded);
        tabWidget_2->setIconSize(QSize(100, 100));
        tabWidget_2->setElideMode(Qt::ElideNone);
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tabWidget_2->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        pushButton_save = new QPushButton(tab_5);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(760, 920, 321, 91));
        pushButton_save->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_powmax = new QLineEdit(tab_5);
        lineEdit_powmax->setObjectName(QString::fromUtf8("lineEdit_powmax"));
        lineEdit_powmax->setGeometry(QRect(750, 190, 301, 81));
        lineEdit_powmax->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_powmax->setAlignment(Qt::AlignCenter);
        lineEdit_powmax->setReadOnly(false);
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(290, 190, 461, 81));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, -20, 1307, 1088));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_25 = new QLabel(tab_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(6, 96, 1111, 951));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        tabWidget_2->addTab(tab_5, QString());
        label_15->raise();
        label_25->raise();
        label_9->raise();
        lineEdit_powmax->raise();
        pushButton_save->raise();
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tab_6->setEnabled(true);
        label_45 = new QLabel(tab_6);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(-30, 80, 1151, 1191));
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        lineEdit_led2 = new QLineEdit(tab_6);
        lineEdit_led2->setObjectName(QString::fromUtf8("lineEdit_led2"));
        lineEdit_led2->setGeometry(QRect(750, 290, 281, 81));
        lineEdit_led2->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_led2->setAlignment(Qt::AlignCenter);
        lineEdit_led1 = new QLineEdit(tab_6);
        lineEdit_led1->setObjectName(QString::fromUtf8("lineEdit_led1"));
        lineEdit_led1->setGeometry(QRect(750, 140, 281, 81));
        lineEdit_led1->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_led1->setAlignment(Qt::AlignCenter);
        label_42 = new QLabel(tab_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(410, 140, 261, 91));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_44 = new QLabel(tab_6);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(410, 290, 261, 91));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        pushButton_save_2 = new QPushButton(tab_6);
        pushButton_save_2->setObjectName(QString::fromUtf8("pushButton_save_2"));
        pushButton_save_2->setGeometry(QRect(730, 910, 331, 101));
        pushButton_save_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        tabWidget_2->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        pushButton_save_3 = new QPushButton(tab_8);
        pushButton_save_3->setObjectName(QString::fromUtf8("pushButton_save_3"));
        pushButton_save_3->setGeometry(QRect(760, 920, 331, 101));
        pushButton_save_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        label_30 = new QLabel(tab_8);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(140, 180, 471, 91));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        lineEdit_vac = new QLineEdit(tab_8);
        lineEdit_vac->setObjectName(QString::fromUtf8("lineEdit_vac"));
        lineEdit_vac->setGeometry(QRect(630, 190, 311, 81));
        lineEdit_vac->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_vac->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(tab_8);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(140, 310, 301, 81));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_26->setFrameShape(QFrame::NoFrame);
        label_14 = new QLabel(tab_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, -20, 1305, 1091));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_33 = new QLabel(tab_8);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(-4, 96, 1121, 951));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        comboBox_mode = new QComboBox(tab_8);
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->setObjectName(QString::fromUtf8("comboBox_mode"));
        comboBox_mode->setGeometry(QRect(630, 320, 401, 81));
        comboBox_mode->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        tabWidget_2->addTab(tab_8, QString());
        label_14->raise();
        label_33->raise();
        label_30->raise();
        label_26->raise();
        lineEdit_vac->raise();
        pushButton_save_3->raise();
        comboBox_mode->raise();
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        label_24 = new QLabel(tab_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(210, 170, 521, 91));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        pushButton_save_4 = new QPushButton(tab_7);
        pushButton_save_4->setObjectName(QString::fromUtf8("pushButton_save_4"));
        pushButton_save_4->setGeometry(QRect(760, 920, 311, 91));
        pushButton_save_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_cutrate = new QLineEdit(tab_7);
        lineEdit_cutrate->setObjectName(QString::fromUtf8("lineEdit_cutrate"));
        lineEdit_cutrate->setGeometry(QRect(750, 180, 281, 81));
        lineEdit_cutrate->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_cutrate->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(tab_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, -20, 1311, 1091));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_28 = new QLabel(tab_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(340, 310, 271, 81));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_28->setFrameShape(QFrame::NoFrame);
        label_34 = new QLabel(tab_7);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(-20, 96, 1121, 951));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        label_43 = new QLabel(tab_7);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(220, 440, 511, 81));
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        lineEdit_maxcutrate = new QLineEdit(tab_7);
        lineEdit_maxcutrate->setObjectName(QString::fromUtf8("lineEdit_maxcutrate"));
        lineEdit_maxcutrate->setGeometry(QRect(750, 560, 281, 81));
        lineEdit_maxcutrate->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);border-radius: 20px;"));
        lineEdit_maxcutrate->setAlignment(Qt::AlignCenter);
        label_46 = new QLabel(tab_7);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(210, 560, 501, 81));
        label_46->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 35pt \"Ubuntu\";\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_46->setFrameShape(QFrame::NoFrame);
        comboBox_cuttermode = new QComboBox(tab_7);
        comboBox_cuttermode->addItem(QString());
        comboBox_cuttermode->addItem(QString());
        comboBox_cuttermode->setObjectName(QString::fromUtf8("comboBox_cuttermode"));
        comboBox_cuttermode->setGeometry(QRect(630, 310, 401, 81));
        comboBox_cuttermode->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        comboBox_cuttertype = new QComboBox(tab_7);
        comboBox_cuttertype->addItem(QString());
        comboBox_cuttertype->addItem(QString());
        comboBox_cuttertype->addItem(QString());
        comboBox_cuttertype->setObjectName(QString::fromUtf8("comboBox_cuttertype"));
        comboBox_cuttertype->setGeometry(QRect(630, 450, 401, 81));
        comboBox_cuttertype->setStyleSheet(QString::fromUtf8("font: 45pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        tabWidget_2->addTab(tab_7, QString());
        label_13->raise();
        label_34->raise();
        label_24->raise();
        label_28->raise();
        pushButton_save_4->raise();
        lineEdit_cutrate->raise();
        label_43->raise();
        lineEdit_maxcutrate->raise();
        label_46->raise();
        comboBox_cuttermode->raise();
        comboBox_cuttertype->raise();
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        pushButton_saveforall = new QPushButton(tab_9);
        pushButton_saveforall->setObjectName(QString::fromUtf8("pushButton_saveforall"));
        pushButton_saveforall->setGeometry(QRect(780, 890, 321, 111));
        pushButton_saveforall->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/saveforall1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        pushButton_save_5 = new QPushButton(tab_9);
        pushButton_save_5->setObjectName(QString::fromUtf8("pushButton_save_5"));
        pushButton_save_5->setGeometry(QRect(760, 750, 351, 121));
        pushButton_save_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, -20, 1301, 1098));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_20 = new QLabel(tab_9);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(250, 130, 571, 611));
        label_20->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpbg1.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_35 = new QLabel(tab_9);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(0, 90, 1121, 951));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        comboBox_tr = new QComboBox(tab_9);
        comboBox_tr->addItem(QString());
        comboBox_tr->addItem(QString());
        comboBox_tr->addItem(QString());
        comboBox_tr->addItem(QString());
        comboBox_tr->addItem(QString());
        comboBox_tr->setObjectName(QString::fromUtf8("comboBox_tr"));
        comboBox_tr->setGeometry(QRect(10, 290, 291, 61));
        comboBox_tr->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        comboBox_bl = new QComboBox(tab_9);
        comboBox_bl->addItem(QString());
        comboBox_bl->addItem(QString());
        comboBox_bl->addItem(QString());
        comboBox_bl->addItem(QString());
        comboBox_bl->addItem(QString());
        comboBox_bl->setObjectName(QString::fromUtf8("comboBox_bl"));
        comboBox_bl->setGeometry(QRect(10, 440, 291, 61));
        comboBox_bl->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        comboBox_br = new QComboBox(tab_9);
        comboBox_br->addItem(QString());
        comboBox_br->addItem(QString());
        comboBox_br->addItem(QString());
        comboBox_br->addItem(QString());
        comboBox_br->addItem(QString());
        comboBox_br->setObjectName(QString::fromUtf8("comboBox_br"));
        comboBox_br->setGeometry(QRect(770, 290, 291, 61));
        comboBox_br->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        comboBox_tl = new QComboBox(tab_9);
        comboBox_tl->addItem(QString());
        comboBox_tl->addItem(QString());
        comboBox_tl->addItem(QString());
        comboBox_tl->addItem(QString());
        comboBox_tl->addItem(QString());
        comboBox_tl->setObjectName(QString::fromUtf8("comboBox_tl"));
        comboBox_tl->setGeometry(QRect(770, 450, 291, 61));
        comboBox_tl->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255,255,255);\n"
"border-radius:20px;\n"
"font-weight: bold;"));
        tabWidget_2->addTab(tab_9, QString());
        label_11->raise();
        label_35->raise();
        pushButton_saveforall->raise();
        pushButton_save_5->raise();
        label_20->raise();
        comboBox_tr->raise();
        comboBox_bl->raise();
        comboBox_br->raise();
        comboBox_tl->raise();
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        pushButton_oneinc = new QPushButton(tab_10);
        pushButton_oneinc->setObjectName(QString::fromUtf8("pushButton_oneinc"));
        pushButton_oneinc->setGeometry(QRect(80, 310, 51, 61));
        pushButton_oneinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_onedec = new QPushButton(tab_10);
        pushButton_onedec->setObjectName(QString::fromUtf8("pushButton_onedec"));
        pushButton_onedec->setGeometry(QRect(290, 310, 51, 61));
        pushButton_onedec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_twoinc = new QPushButton(tab_10);
        pushButton_twoinc->setObjectName(QString::fromUtf8("pushButton_twoinc"));
        pushButton_twoinc->setGeometry(QRect(80, 480, 51, 61));
        pushButton_twoinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_twodec = new QPushButton(tab_10);
        pushButton_twodec->setObjectName(QString::fromUtf8("pushButton_twodec"));
        pushButton_twodec->setGeometry(QRect(290, 480, 51, 61));
        pushButton_twodec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_threeinc = new QPushButton(tab_10);
        pushButton_threeinc->setObjectName(QString::fromUtf8("pushButton_threeinc"));
        pushButton_threeinc->setGeometry(QRect(80, 650, 51, 61));
        pushButton_threeinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_threedec = new QPushButton(tab_10);
        pushButton_threedec->setObjectName(QString::fromUtf8("pushButton_threedec"));
        pushButton_threedec->setGeometry(QRect(290, 650, 51, 61));
        pushButton_threedec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        label_4 = new QLabel(tab_10);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 770, 601, 81));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;font: 30pt \"Ubuntu\";"));
        label_6 = new QLabel(tab_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(430, 770, 51, 91));
        label_6->setStyleSheet(QString::fromUtf8("background-color:transparent;image: url(:/new/prefix1/img/icon1.png);"));
        pushButton_save_6 = new QPushButton(tab_10);
        pushButton_save_6->setObjectName(QString::fromUtf8("pushButton_save_6"));
        pushButton_save_6->setGeometry(QRect(720, 910, 371, 121));
        pushButton_save_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/save-button 1.png);\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_one = new QLineEdit(tab_10);
        lineEdit_one->setObjectName(QString::fromUtf8("lineEdit_one"));
        lineEdit_one->setGeometry(QRect(150, 320, 113, 41));
        lineEdit_one->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_one->setAlignment(Qt::AlignCenter);
        lineEdit_two = new QLineEdit(tab_10);
        lineEdit_two->setObjectName(QString::fromUtf8("lineEdit_two"));
        lineEdit_two->setGeometry(QRect(140, 480, 113, 61));
        lineEdit_two->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_two->setAlignment(Qt::AlignCenter);
        lineEdit_three = new QLineEdit(tab_10);
        lineEdit_three->setObjectName(QString::fromUtf8("lineEdit_three"));
        lineEdit_three->setGeometry(QRect(150, 660, 113, 51));
        lineEdit_three->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_three->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(tab_10);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 930, 351, 81));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;font: 35pt \"Ubuntu\";"));
        progressBar_one = new QProgressBar(tab_10);
        progressBar_one->setObjectName(QString::fromUtf8("progressBar_one"));
        progressBar_one->setGeometry(QRect(400, 310, 681, 71));
        progressBar_one->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	\n"
"	\n"
"	background-color: rgb(179, 0, 0);\n"
"\n"
"border-radius: 20px;\n"
"	\n"
"}\n"
"\n"
"QProgressBar {\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);}\n"
"\n"
""));
        progressBar_one->setValue(18);
        progressBar_one->setTextVisible(false);
        progressBar_one->setTextDirection(QProgressBar::TopToBottom);
        progressBar_two = new QProgressBar(tab_10);
        progressBar_two->setObjectName(QString::fromUtf8("progressBar_two"));
        progressBar_two->setGeometry(QRect(400, 470, 681, 71));
        progressBar_two->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	\n"
"	\n"
"	background-color: rgb(179, 0, 0);\n"
"\n"
"border-radius: 20px;\n"
"	\n"
"}\n"
"\n"
"QProgressBar {\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);}\n"
"\n"
""));
        progressBar_two->setValue(24);
        progressBar_two->setTextVisible(false);
        progressBar_two->setInvertedAppearance(false);
        progressBar_three = new QProgressBar(tab_10);
        progressBar_three->setObjectName(QString::fromUtf8("progressBar_three"));
        progressBar_three->setGeometry(QRect(400, 640, 681, 71));
        progressBar_three->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	\n"
"	\n"
"	background-color: rgb(179, 0, 0);\n"
"\n"
"border-radius: 20px;\n"
"	\n"
"}\n"
"\n"
"QProgressBar {\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);}\n"
"\n"
""));
        progressBar_three->setValue(24);
        progressBar_three->setTextVisible(false);
        progressBar_zero = new QProgressBar(tab_10);
        progressBar_zero->setObjectName(QString::fromUtf8("progressBar_zero"));
        progressBar_zero->setGeometry(QRect(400, 150, 681, 71));
        progressBar_zero->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	\n"
"	\n"
"	background-color: rgb(179, 0, 0);\n"
"\n"
"border-radius: 20px;\n"
"	\n"
"}\n"
"\n"
"QProgressBar {\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);}\n"
"\n"
""));
        progressBar_zero->setValue(18);
        progressBar_zero->setTextVisible(false);
        progressBar_zero->setTextDirection(QProgressBar::TopToBottom);
        pushButton_zerodec = new QPushButton(tab_10);
        pushButton_zerodec->setObjectName(QString::fromUtf8("pushButton_zerodec"));
        pushButton_zerodec->setGeometry(QRect(290, 150, 51, 61));
        pushButton_zerodec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_zeroinc = new QPushButton(tab_10);
        pushButton_zeroinc->setObjectName(QString::fromUtf8("pushButton_zeroinc"));
        pushButton_zeroinc->setGeometry(QRect(70, 150, 51, 61));
        pushButton_zeroinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        lineEdit_zero = new QLineEdit(tab_10);
        lineEdit_zero->setObjectName(QString::fromUtf8("lineEdit_zero"));
        lineEdit_zero->setGeometry(QRect(140, 157, 131, 51));
        lineEdit_zero->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        lineEdit_zero->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 150, 141, 71));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;image: url(:/new/prefix1/img/textbox1.png);"));
        label_105 = new QLabel(tab_10);
        label_105->setObjectName(QString::fromUtf8("label_105"));
        label_105->setGeometry(QRect(230, 470, 41, 81));
        label_105->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        label_105->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(tab_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 310, 141, 71));
        label_5->setStyleSheet(QString::fromUtf8("background-color:transparent;image: url(:/new/prefix1/img/textbox1.png);"));
        label_7 = new QLabel(tab_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(140, 480, 141, 71));
        label_7->setStyleSheet(QString::fromUtf8("background-color:transparent;image: url(:/new/prefix1/img/textbox1.png);"));
        label_10 = new QLabel(tab_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(140, 650, 141, 71));
        label_10->setStyleSheet(QString::fromUtf8("background-color:transparent;image: url(:/new/prefix1/img/textbox1.png);"));
        label_106 = new QLabel(tab_10);
        label_106->setObjectName(QString::fromUtf8("label_106"));
        label_106->setGeometry(QRect(240, 640, 41, 81));
        label_106->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        label_106->setAlignment(Qt::AlignCenter);
        label_107 = new QLabel(tab_10);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        label_107->setGeometry(QRect(230, 300, 41, 81));
        label_107->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        label_107->setAlignment(Qt::AlignCenter);
        label_108 = new QLabel(tab_10);
        label_108->setObjectName(QString::fromUtf8("label_108"));
        label_108->setGeometry(QRect(230, 150, 41, 71));
        label_108->setStyleSheet(QString::fromUtf8("font: 35pt \"Ubuntu\";\n"
"\n"
"background-color: transparent;\n"
"border:none;"));
        label_108->setAlignment(Qt::AlignCenter);
        label_110 = new QLabel(tab_10);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(510, 930, 131, 91));
        label_110->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 35pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border:none;"));
        label_110->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(tab_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 0, 1121, 1051));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_36 = new QLabel(tab_10);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(-20, 110, 1121, 951));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 30pt \"Ubuntu\";border-radius: 20px;\n"
"background-color: rgb(53, 63, 99);"));
        label_27 = new QLabel(tab_10);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(350, 350, 691, 621));
        label_27->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/diaselected2.png);"));
        label_38 = new QLabel(tab_10);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(0, 310, 67, 61));
        QFont font1;
        font1.setPointSize(50);
        label_38->setFont(font1);
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        label_38->setAlignment(Qt::AlignCenter);
        label_39 = new QLabel(tab_10);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 480, 67, 61));
        label_39->setFont(font1);
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        label_39->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(tab_10);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 650, 67, 61));
        label_40->setFont(font1);
        label_40->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        label_40->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(tab_10);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(4, 150, 67, 61));
        label_37->setFont(font1);
        label_37->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        label_37->setAlignment(Qt::AlignCenter);
        pushButton_swap = new QPushButton(tab_10);
        pushButton_swap->setObjectName(QString::fromUtf8("pushButton_swap"));
        pushButton_swap->setGeometry(QRect(90, 770, 231, 91));
        pushButton_swap->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"font-weight: bold;\n"
"font-size: 20px;"));
        tabWidget_2->addTab(tab_10, QString());
        label_27->raise();
        label_16->raise();
        label_36->raise();
        pushButton_save_6->raise();
        label_4->raise();
        label_8->raise();
        progressBar_two->raise();
        progressBar_three->raise();
        progressBar_one->raise();
        progressBar_zero->raise();
        pushButton_zerodec->raise();
        pushButton_onedec->raise();
        pushButton_twodec->raise();
        pushButton_threedec->raise();
        pushButton_threeinc->raise();
        pushButton_twoinc->raise();
        pushButton_zeroinc->raise();
        pushButton_oneinc->raise();
        label_10->raise();
        label_106->raise();
        label_110->raise();
        label_3->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        lineEdit_one->raise();
        lineEdit_zero->raise();
        lineEdit_two->raise();
        lineEdit_three->raise();
        label_105->raise();
        label_107->raise();
        label_108->raise();
        label_38->raise();
        label_39->raise();
        label_40->raise();
        label_37->raise();
        pushButton_swap->raise();
        label_19 = new QLabel(settingswindow);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, -20, 1920, 1080));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_17 = new QLabel(settingswindow);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1510, 12, 401, 91));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);border-radius: 20px;"));
        listWidget = new QListWidget(settingswindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(1510, 107, 401, 861));
        QFont font2;
        font2.setPointSize(40);
        listWidget->setFont(font2);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background-color: rgb(53, 63, 99);border-radius: 20px;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(6);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        pushButton_goback = new QPushButton(settingswindow);
        pushButton_goback->setObjectName(QString::fromUtf8("pushButton_goback"));
        pushButton_goback->setGeometry(QRect(1635, 978, 141, 71));
        pushButton_goback->setMaximumSize(QSize(800, 600));
        pushButton_goback->setAutoFillBackground(false);
        pushButton_goback->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/back1.png);\n"
"background-color: transparent;\n"
"color: rgba(68, 44, 44, 198);border:none;"));
        label_12 = new QLabel(settingswindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 1060, 1921, 20));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_23 = new QLabel(settingswindow);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(-30, 192, 371, 891));
        label_23->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/ring6.png);"));
        label_title = new QLabel(settingswindow);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(10, 120, 351, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Waree"));
        font3.setPointSize(30);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(12);
        font3.setStrikeOut(false);
        label_title->setFont(font3);
        label_title->setLayoutDirection(Qt::LeftToRight);
        label_title->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 20px;\n"
"font: 100 30pt;\n"
""));
        label_title->setTextFormat(Qt::AutoText);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setMargin(8);
        label_29 = new QLabel(settingswindow);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(1498, 0, 6, 1061));
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_31 = new QLabel(settingswindow);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(0, 0, 1921, 12));
        label_31->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        label_32 = new QLabel(settingswindow);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(380, 10, 9, 1051));
        label_32->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 165, 178);"));
        lineEdit_5 = new QLineEdit(settingswindow);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(12, 14, 1486, 91));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;font: 45pt \"Ubuntu\";"));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        vit = new QLabel(settingswindow);
        vit->setObjectName(QString::fromUtf8("vit"));
        vit->setGeometry(QRect(130, 540, 181, 161));
        vit->setStyleSheet(QString::fromUtf8(""));
        pushButton_dia = new QPushButton(settingswindow);
        pushButton_dia->setObjectName(QString::fromUtf8("pushButton_dia"));
        pushButton_dia->setGeometry(QRect(0, 370, 121, 111));
        pushButton_dia->setLayoutDirection(Qt::LeftToRight);
        pushButton_dia->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_fp = new QPushButton(settingswindow);
        pushButton_fp->setObjectName(QString::fromUtf8("pushButton_fp"));
        pushButton_fp->setGeometry(QRect(0, 630, 131, 151));
        pushButton_fp->setStyleSheet(QString::fromUtf8("background-color: rgba(130, 52, 52, 0);border:none;"));
        pushButton_fps = new QPushButton(settingswindow);
        pushButton_fps->setObjectName(QString::fromUtf8("pushButton_fps"));
        pushButton_fps->setGeometry(QRect(0, 790, 161, 141));
        pushButton_fps->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_vit = new QPushButton(settingswindow);
        pushButton_vit->setObjectName(QString::fromUtf8("pushButton_vit"));
        pushButton_vit->setGeometry(QRect(0, 550, 131, 91));
        pushButton_vit->setStyleSheet(QString::fromUtf8("background-color: rgba(130, 52, 52, 0);\n"
"border:none;"));
        pushButton_ia = new QPushButton(settingswindow);
        pushButton_ia->setObjectName(QString::fromUtf8("pushButton_ia"));
        pushButton_ia->setGeometry(QRect(0, 450, 121, 91));
        pushButton_ia->setStyleSheet(QString::fromUtf8("background-color: rgba(130, 52, 52, 0);border:none;"));
        label = new QLabel(settingswindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-30, 110, 391, 951));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;\n"
"font: 100 30pt;\n"
""));
        label_2 = new QLabel(settingswindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(366, 109, 36, 951));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);border-radius: 20px;"));
        label_18 = new QLabel(settingswindow);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(1510, 970, 400, 87));
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 63, 99);border-radius: 20px;"));
        label_22 = new QLabel(settingswindow);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(1670, 10, 81, 91));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/doc 1.png);\n"
"background-color: transparent;\n"
"color: rgba(68, 44, 44, 198);border:none;"));
        label_41 = new QLabel(settingswindow);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(-40, 300, 151, 81));
        label_41->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/ledsw.png);"));
        pushButton_led = new QPushButton(settingswindow);
        pushButton_led->setObjectName(QString::fromUtf8("pushButton_led"));
        pushButton_led->setGeometry(QRect(-20, 300, 131, 81));
        pushButton_led->setStyleSheet(QString::fromUtf8("background-color: rgba(130, 52, 52, 0);border:none;"));
        label_19->raise();
        label_32->raise();
        label->raise();
        label_17->raise();
        tabWidget_2->raise();
        listWidget->raise();
        label_12->raise();
        label_23->raise();
        label_31->raise();
        vit->raise();
        pushButton_dia->raise();
        pushButton_fp->raise();
        pushButton_fps->raise();
        pushButton_vit->raise();
        pushButton_ia->raise();
        label_29->raise();
        label_title->raise();
        lineEdit_5->raise();
        label_2->raise();
        label_18->raise();
        pushButton_goback->raise();
        label_22->raise();
        label_41->raise();
        pushButton_led->raise();

        retranslateUi(settingswindow);

        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(settingswindow);
    } // setupUi

    void retranslateUi(QDialog *settingswindow)
    {
        settingswindow->setWindowTitle(QCoreApplication::translate("settingswindow", "Dialog", nullptr));
        pushButton_save->setText(QString());
        lineEdit_powmax->setText(QString());
        label_9->setText(QCoreApplication::translate("settingswindow", " Power Maximum", nullptr));
        label_15->setText(QString());
        label_25->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("settingswindow", "DIA", nullptr));
        label_45->setText(QString());
        lineEdit_led2->setText(QString());
        lineEdit_led1->setText(QString());
        label_42->setText(QCoreApplication::translate("settingswindow", "LED1", nullptr));
        label_44->setText(QCoreApplication::translate("settingswindow", "LED2", nullptr));
        pushButton_save_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("settingswindow", "Phaco", nullptr));
        pushButton_save_3->setText(QString());
        label_30->setText(QCoreApplication::translate("settingswindow", " Vaccum(mm/hg)", nullptr));
        label_26->setText(QCoreApplication::translate("settingswindow", "  Mode", nullptr));
        label_14->setText(QString());
        label_33->setText(QString());
        comboBox_mode->setItemText(0, QCoreApplication::translate("settingswindow", "Linear", nullptr));
        comboBox_mode->setItemText(1, QCoreApplication::translate("settingswindow", "NON-Linear", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("settingswindow", "I/A", nullptr));
        label_24->setText(QCoreApplication::translate("settingswindow", " Cutrate(cuts/min)", nullptr));
        pushButton_save_4->setText(QString());
        lineEdit_cutrate->setText(QString());
        label_13->setText(QString());
        label_28->setText(QCoreApplication::translate("settingswindow", "  Mode", nullptr));
        label_34->setText(QString());
        label_43->setText(QCoreApplication::translate("settingswindow", "Cutter Type", nullptr));
        lineEdit_maxcutrate->setText(QString());
        label_46->setText(QCoreApplication::translate("settingswindow", "Max Cutrate", nullptr));
        comboBox_cuttermode->setItemText(0, QCoreApplication::translate("settingswindow", "Linear", nullptr));
        comboBox_cuttermode->setItemText(1, QCoreApplication::translate("settingswindow", "NON-Linear", nullptr));

        comboBox_cuttertype->setItemText(0, QCoreApplication::translate("settingswindow", "Midlabs", nullptr));
        comboBox_cuttertype->setItemText(1, QCoreApplication::translate("settingswindow", "Alcon", nullptr));
        comboBox_cuttertype->setItemText(2, QCoreApplication::translate("settingswindow", "Dorc", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("settingswindow", "VIT", nullptr));
        pushButton_saveforall->setText(QString());
        pushButton_save_5->setText(QString());
        label_11->setText(QString());
        label_20->setText(QString());
        label_35->setText(QString());
        comboBox_tr->setItemText(0, QCoreApplication::translate("settingswindow", "LED1 On/Off", nullptr));
        comboBox_tr->setItemText(1, QCoreApplication::translate("settingswindow", "LED2 On/Off", nullptr));
        comboBox_tr->setItemText(2, QCoreApplication::translate("settingswindow", "Vitrectomy On/Off", nullptr));
        comboBox_tr->setItemText(3, QCoreApplication::translate("settingswindow", "Diathermy On/Off", nullptr));
        comboBox_tr->setItemText(4, QCoreApplication::translate("settingswindow", "Silicon Oil On/Off", nullptr));

        comboBox_bl->setItemText(0, QCoreApplication::translate("settingswindow", "LED1 On/Off", nullptr));
        comboBox_bl->setItemText(1, QCoreApplication::translate("settingswindow", "LED2 On/Off", nullptr));
        comboBox_bl->setItemText(2, QCoreApplication::translate("settingswindow", "Vitrectomy On/Off", nullptr));
        comboBox_bl->setItemText(3, QCoreApplication::translate("settingswindow", "Diathermy On/Off", nullptr));
        comboBox_bl->setItemText(4, QCoreApplication::translate("settingswindow", "Silicon Oil On/Off", nullptr));

        comboBox_br->setItemText(0, QCoreApplication::translate("settingswindow", "LED1 On/Off", nullptr));
        comboBox_br->setItemText(1, QCoreApplication::translate("settingswindow", "LED2 On/Off", nullptr));
        comboBox_br->setItemText(2, QCoreApplication::translate("settingswindow", "Vitrectomy On/Off", nullptr));
        comboBox_br->setItemText(3, QCoreApplication::translate("settingswindow", "Diathermy On/Off", nullptr));
        comboBox_br->setItemText(4, QCoreApplication::translate("settingswindow", "Silicon Oil On/Off", nullptr));

        comboBox_tl->setItemText(0, QCoreApplication::translate("settingswindow", "LED1 On/Off", nullptr));
        comboBox_tl->setItemText(1, QCoreApplication::translate("settingswindow", "LED2 On/Off", nullptr));
        comboBox_tl->setItemText(2, QCoreApplication::translate("settingswindow", "Vitrectomy On/Off", nullptr));
        comboBox_tl->setItemText(3, QCoreApplication::translate("settingswindow", "Diathermy On/Off", nullptr));
        comboBox_tl->setItemText(4, QCoreApplication::translate("settingswindow", "Silicon Oil On/Off", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QCoreApplication::translate("settingswindow", "Foot Pedal", nullptr));
        pushButton_oneinc->setText(QString());
        pushButton_onedec->setText(QString());
        pushButton_twoinc->setText(QString());
        pushButton_twodec->setText(QString());
        pushButton_threeinc->setText(QString());
        pushButton_threedec->setText(QString());
        label_4->setText(QCoreApplication::translate("settingswindow", "     Total must be 100%", nullptr));
        label_6->setText(QString());
        pushButton_save_6->setText(QString());
        lineEdit_one->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        lineEdit_two->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        lineEdit_three->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("settingswindow", " Total is :", nullptr));
        pushButton_zerodec->setText(QString());
        pushButton_zeroinc->setText(QString());
        lineEdit_zero->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        label_3->setText(QString());
        label_105->setText(QCoreApplication::translate("settingswindow", "%", nullptr));
        label_5->setText(QString());
        label_7->setText(QString());
        label_10->setText(QString());
        label_106->setText(QCoreApplication::translate("settingswindow", "%", nullptr));
        label_107->setText(QCoreApplication::translate("settingswindow", "%", nullptr));
        label_108->setText(QCoreApplication::translate("settingswindow", "%", nullptr));
        label_110->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        label_16->setText(QString());
        label_36->setText(QString());
        label_27->setText(QString());
        label_38->setText(QCoreApplication::translate("settingswindow", "1", nullptr));
        label_39->setText(QCoreApplication::translate("settingswindow", "2", nullptr));
        label_40->setText(QCoreApplication::translate("settingswindow", "3", nullptr));
        label_37->setText(QCoreApplication::translate("settingswindow", "0", nullptr));
        pushButton_swap->setText(QCoreApplication::translate("settingswindow", "SWAP OFF", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("settingswindow", "Foot Pedal Preset", nullptr));
        label_19->setText(QString());
        label_17->setText(QString());
        pushButton_goback->setText(QString());
        label_12->setText(QString());
        label_23->setText(QString());
        label_title->setText(QCoreApplication::translate("settingswindow", "Diathermy", nullptr));
        label_29->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        lineEdit_5->setText(QString());
        vit->setText(QString());
        pushButton_dia->setText(QString());
        pushButton_fp->setText(QString());
        pushButton_fps->setText(QString());
        pushButton_vit->setText(QString());
        pushButton_ia->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_18->setText(QString());
        label_22->setText(QString());
        label_41->setText(QString());
        pushButton_led->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settingswindow: public Ui_settingswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
