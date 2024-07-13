/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_settingswindow;
    QLabel *label_vacpreset;
    QLabel *label_vacactual;
    QLabel *label_aipreset;
    QLabel *label_vitpreset;
    QLabel *label_dia;
    QPushButton *pushButton_siloilonoff;
    QLabel *label_siloil;
    QLabel *label_led1;
    QPushButton *pushButton_aidec;
    QPushButton *pushButton_diadec;
    QPushButton *pushButton_vitdec;
    QPushButton *pushButton_led1dec;
    QPushButton *pushButton_aiinc;
    QPushButton *pushButton_diainc;
    QPushButton *pushButton_vitinc;
    QPushButton *pushButton_led1inc;
    QPushButton *pushButton_siloilinc;
    QPushButton *pushButton_led1onoff;
    QPushButton *pushButton_vitonoff;
    QPushButton *pushButton_diaonoff;
    QPushButton *pushButton_vaclinearnonlinear;
    QLabel *label_aiactual;
    QLabel *label_surgeonname;
    QPushButton *pushButton_siloildec;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *pushButton_endcase;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_28;
    QLabel *label_dialvalue;
    QDial *dial;
    QLabel *label_38;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_19;
    QPushButton *pushButton_aionoff;
    QLabel *label_led2;
    QPushButton *pushButton_led2inc;
    QPushButton *pushButton_led2dec;
    QPushButton *pushButton_led2onoff;
    QLabel *label_42;
    QLabel *label_41;
    QPushButton *pushButton_vitlinearnonlinear;
    QLabel *label_44;
    QLabel *label_7;
    QLabel *label_40;
    QProgressBar *progressBar;
    QLabel *label_testtube;
    QLabel *label_15;
    QLabel *label_43;
    QLabel *label_date;
    QLabel *label_time;
    QComboBox *comboBox_surgeonname;
    QLabel *label_12;
    QLabel *label_22;
    QPushButton *pushButton_start;
    QLabel *label_39;
    QPushButton *pushButton_swap;
    QLabel *label_vitactual;
    QPushButton *pushButton_vacinc;
    QPushButton *pushButton_vacdec;
    QPushButton *pushButton_drain;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_settingswindow = new QPushButton(centralwidget);
        pushButton_settingswindow->setObjectName(QString::fromUtf8("pushButton_settingswindow"));
        pushButton_settingswindow->setGeometry(QRect(1810, 24, 91, 91));
        pushButton_settingswindow->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"background-image: url(:/new/prefix1/Settimg 3.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"\n"
"\n"
""));
        label_vacpreset = new QLabel(centralwidget);
        label_vacpreset->setObjectName(QString::fromUtf8("label_vacpreset"));
        label_vacpreset->setGeometry(QRect(180, 240, 301, 141));
        label_vacpreset->setStyleSheet(QString::fromUtf8("font: 65pt \"Ubuntu\";\n"
"image: url(:/new/prefix1/img/textbox2.png);\n"
""));
        label_vacpreset->setAlignment(Qt::AlignCenter);
        label_vacactual = new QLabel(centralwidget);
        label_vacactual->setObjectName(QString::fromUtf8("label_vacactual"));
        label_vacactual->setGeometry(QRect(180, 400, 291, 141));
        label_vacactual->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_vacactual->setAlignment(Qt::AlignCenter);
        label_aipreset = new QLabel(centralwidget);
        label_aipreset->setObjectName(QString::fromUtf8("label_aipreset"));
        label_aipreset->setGeometry(QRect(1470, 240, 281, 131));
        label_aipreset->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_aipreset->setAlignment(Qt::AlignCenter);
        label_vitpreset = new QLabel(centralwidget);
        label_vitpreset->setObjectName(QString::fromUtf8("label_vitpreset"));
        label_vitpreset->setGeometry(QRect(110, 770, 311, 141));
        label_vitpreset->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_vitpreset->setAlignment(Qt::AlignCenter);
        label_dia = new QLabel(centralwidget);
        label_dia->setObjectName(QString::fromUtf8("label_dia"));
        label_dia->setGeometry(QRect(1520, 820, 281, 141));
        label_dia->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_dia->setAlignment(Qt::AlignCenter);
        pushButton_siloilonoff = new QPushButton(centralwidget);
        pushButton_siloilonoff->setObjectName(QString::fromUtf8("pushButton_siloilonoff"));
        pushButton_siloilonoff->setGeometry(QRect(930, 160, 101, 51));
        pushButton_siloilonoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_siloil = new QLabel(centralwidget);
        label_siloil->setObjectName(QString::fromUtf8("label_siloil"));
        label_siloil->setGeometry(QRect(830, 330, 291, 131));
        label_siloil->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_siloil->setAlignment(Qt::AlignCenter);
        label_led1 = new QLabel(centralwidget);
        label_led1->setObjectName(QString::fromUtf8("label_led1"));
        label_led1->setGeometry(QRect(590, 710, 201, 91));
        label_led1->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox1.png);\n"
"font: 45pt \"Ubuntu\";"));
        label_led1->setAlignment(Qt::AlignCenter);
        pushButton_aidec = new QPushButton(centralwidget);
        pushButton_aidec->setObjectName(QString::fromUtf8("pushButton_aidec"));
        pushButton_aidec->setGeometry(QRect(1760, 250, 81, 91));
        pushButton_aidec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/img/down1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_diadec = new QPushButton(centralwidget);
        pushButton_diadec->setObjectName(QString::fromUtf8("pushButton_diadec"));
        pushButton_diadec->setGeometry(QRect(1810, 840, 81, 91));
        pushButton_diadec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/img/down1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_vitdec = new QPushButton(centralwidget);
        pushButton_vitdec->setObjectName(QString::fromUtf8("pushButton_vitdec"));
        pushButton_vitdec->setGeometry(QRect(410, 800, 81, 91));
        pushButton_vitdec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/img/down1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_led1dec = new QPushButton(centralwidget);
        pushButton_led1dec->setObjectName(QString::fromUtf8("pushButton_led1dec"));
        pushButton_led1dec->setGeometry(QRect(800, 720, 51, 61));
        pushButton_led1dec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_aiinc = new QPushButton(centralwidget);
        pushButton_aiinc->setObjectName(QString::fromUtf8("pushButton_aiinc"));
        pushButton_aiinc->setGeometry(QRect(1380, 250, 81, 91));
        pushButton_aiinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/img/up1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_diainc = new QPushButton(centralwidget);
        pushButton_diainc->setObjectName(QString::fromUtf8("pushButton_diainc"));
        pushButton_diainc->setGeometry(QRect(1430, 840, 81, 91));
        pushButton_diainc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/img/up1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_vitinc = new QPushButton(centralwidget);
        pushButton_vitinc->setObjectName(QString::fromUtf8("pushButton_vitinc"));
        pushButton_vitinc->setGeometry(QRect(30, 800, 81, 91));
        pushButton_vitinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/img/up1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_led1inc = new QPushButton(centralwidget);
        pushButton_led1inc->setObjectName(QString::fromUtf8("pushButton_led1inc"));
        pushButton_led1inc->setGeometry(QRect(530, 720, 51, 61));
        pushButton_led1inc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_siloilinc = new QPushButton(centralwidget);
        pushButton_siloilinc->setObjectName(QString::fromUtf8("pushButton_siloilinc"));
        pushButton_siloilinc->setGeometry(QRect(740, 350, 81, 91));
        pushButton_siloilinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/img/up1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_led1onoff = new QPushButton(centralwidget);
        pushButton_led1onoff->setObjectName(QString::fromUtf8("pushButton_led1onoff"));
        pushButton_led1onoff->setGeometry(QRect(800, 640, 101, 51));
        pushButton_led1onoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        pushButton_vitonoff = new QPushButton(centralwidget);
        pushButton_vitonoff->setObjectName(QString::fromUtf8("pushButton_vitonoff"));
        pushButton_vitonoff->setGeometry(QRect(380, 640, 101, 51));
        pushButton_vitonoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        pushButton_diaonoff = new QPushButton(centralwidget);
        pushButton_diaonoff->setObjectName(QString::fromUtf8("pushButton_diaonoff"));
        pushButton_diaonoff->setGeometry(QRect(1440, 620, 101, 51));
        pushButton_diaonoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        pushButton_vaclinearnonlinear = new QPushButton(centralwidget);
        pushButton_vaclinearnonlinear->setObjectName(QString::fromUtf8("pushButton_vaclinearnonlinear"));
        pushButton_vaclinearnonlinear->setGeometry(QRect(530, 160, 101, 51));
        pushButton_vaclinearnonlinear->setLayoutDirection(Qt::LeftToRight);
        pushButton_vaclinearnonlinear->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);\n"
""));
        label_aiactual = new QLabel(centralwidget);
        label_aiactual->setObjectName(QString::fromUtf8("label_aiactual"));
        label_aiactual->setGeometry(QRect(1470, 390, 281, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(65);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_aiactual->setFont(font);
        label_aiactual->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_aiactual->setAlignment(Qt::AlignCenter);
        label_surgeonname = new QLabel(centralwidget);
        label_surgeonname->setObjectName(QString::fromUtf8("label_surgeonname"));
        label_surgeonname->setGeometry(QRect(20, 28, 781, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(1);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_surgeonname->setFont(font1);
        label_surgeonname->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/docidbox.png);\n"
"font: 1pt \"Ubuntu\";"));
        label_surgeonname->setAlignment(Qt::AlignCenter);
        pushButton_siloildec = new QPushButton(centralwidget);
        pushButton_siloildec->setObjectName(QString::fromUtf8("pushButton_siloildec"));
        pushButton_siloildec->setGeometry(QRect(1120, 350, 81, 91));
        pushButton_siloildec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/img/down1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 140, 641, 451));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1270, 140, 641, 451));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1420, 600, 491, 471));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 10, 1901, 121));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 0, 1920, 1080));
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgba(68, 44, 44, 198);"));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(210, 160, 221, 61));
        label_21->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(1440, 160, 421, 61));
        label_23->setStyleSheet(QString::fromUtf8("font: 40pt ;\n"
"color: rgb(0, 0, 0);"));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 700, 351, 71));
        label_24->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(1510, 730, 321, 51));
        label_25->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(810, 260, 411, 51));
        label_26->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(620, 630, 171, 61));
        label_27->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        pushButton_endcase = new QPushButton(centralwidget);
        pushButton_endcase->setObjectName(QString::fromUtf8("pushButton_endcase"));
        pushButton_endcase->setGeometry(QRect(1620, 20, 171, 101));
        pushButton_endcase->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(37, 173, 232);border-radius: 20px;\n"
"font: 20pt \"Ubuntu\";\n"
"}\n"
"\n"
"QPushButton::hover{background-color: #007dff;\n"
"border-radius: 20px;\n"
"font: 20pt \"Ubuntu\";\n"
"color:white;;}"));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(1300, 160, 51, 51));
        label_29->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(800, 640, 51, 51));
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(930, 160, 51, 51));
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(1440, 620, 51, 51));
        label_32->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_33 = new QLabel(centralwidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(380, 640, 51, 51));
        label_33->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(530, 150, 101, 71));
        label_28->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/linbg3.png);"));
        label_dialvalue = new QLabel(centralwidget);
        label_dialvalue->setObjectName(QString::fromUtf8("label_dialvalue"));
        label_dialvalue->setEnabled(false);
        label_dialvalue->setGeometry(QRect(955, 872, 61, 71));
        label_dialvalue->setStyleSheet(QString::fromUtf8("font: 60pt \"Ubuntu\";\n"
"color: rgb(165, 29, 45);"));
        label_dialvalue->setAlignment(Qt::AlignCenter);
        label_dialvalue->setWordWrap(false);
        dial = new QDial(centralwidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setEnabled(false);
        dial->setGeometry(QRect(840, 770, 291, 281));
        dial->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dial->setSliderPosition(0);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchTarget(0.000000000000000);
        dial->setNotchesVisible(false);
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(10, 600, 491, 471));
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(510, 600, 901, 471));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);\n"
""));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(820, 750, 331, 311));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/dialscale1.png);"));
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(870, 1030, 101, 31));
        label_34->setStyleSheet(QString::fromUtf8("font: 17pt \"Ubuntu\";"));
        label_34->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(centralwidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(990, 1030, 101, 31));
        label_35->setStyleSheet(QString::fromUtf8("font: 17pt \"Ubuntu\";"));
        label_35->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(660, 140, 601, 451));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);"));
        pushButton_aionoff = new QPushButton(centralwidget);
        pushButton_aionoff->setObjectName(QString::fromUtf8("pushButton_aionoff"));
        pushButton_aionoff->setGeometry(QRect(1300, 160, 101, 51));
        pushButton_aionoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_led2 = new QLabel(centralwidget);
        label_led2->setObjectName(QString::fromUtf8("label_led2"));
        label_led2->setGeometry(QRect(1160, 710, 191, 81));
        label_led2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox1.png);\n"
"font: 45pt \"Ubuntu\";"));
        label_led2->setAlignment(Qt::AlignCenter);
        pushButton_led2inc = new QPushButton(centralwidget);
        pushButton_led2inc->setObjectName(QString::fromUtf8("pushButton_led2inc"));
        pushButton_led2inc->setGeometry(QRect(1100, 720, 51, 61));
        pushButton_led2inc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/upnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_led2dec = new QPushButton(centralwidget);
        pushButton_led2dec->setObjectName(QString::fromUtf8("pushButton_led2dec"));
        pushButton_led2dec->setGeometry(QRect(1350, 720, 51, 61));
        pushButton_led2dec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/downnew1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_led2onoff = new QPushButton(centralwidget);
        pushButton_led2onoff->setObjectName(QString::fromUtf8("pushButton_led2onoff"));
        pushButton_led2onoff->setGeometry(QRect(1060, 640, 101, 51));
        pushButton_led2onoff->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_42 = new QLabel(centralwidget);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(1060, 640, 51, 51));
        label_42->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/fpled.png);\n"
""));
        label_41 = new QLabel(centralwidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(1190, 630, 191, 61));
        label_41->setStyleSheet(QString::fromUtf8("font: 40pt \"Ubuntu\";"));
        pushButton_vitlinearnonlinear = new QPushButton(centralwidget);
        pushButton_vitlinearnonlinear->setObjectName(QString::fromUtf8("pushButton_vitlinearnonlinear"));
        pushButton_vitlinearnonlinear->setGeometry(QRect(20, 640, 101, 51));
        pushButton_vitlinearnonlinear->setLayoutDirection(Qt::LeftToRight);
        pushButton_vitlinearnonlinear->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);\n"
""));
        label_44 = new QLabel(centralwidget);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(20, 630, 101, 71));
        label_44->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/linvit1.png);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(820, 740, 331, 321));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/Ellipse 201.png);"));
        label_40 = new QLabel(centralwidget);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(930, 1008, 111, 17));
        label_40->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 184, 222);\n"
""));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(1300, 280, 41, 171));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0.498, y1:0.983, x2:0.473, y2:1, stop:0.432836 rgba(38, 162, 105, 255));\n"
"	\n"
"\n"
"border-radius:20px;\n"
"	\n"
"}\n"
"\n"
"QProgressBar {\n"
"background-color: rgba(191, 64, 64, 0);\n"
"}\n"
""));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        label_testtube = new QLabel(centralwidget);
        label_testtube->setObjectName(QString::fromUtf8("label_testtube"));
        label_testtube->setGeometry(QRect(1288, 277, 71, 181));
        label_testtube->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/airscale2.png);"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(870, 40, 71, 61));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/dateimg1.png);"));
        label_43 = new QLabel(centralwidget);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(1250, 39, 67, 61));
        label_43->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/timeimg2.png);"));
        label_date = new QLabel(centralwidget);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(970, 40, 261, 61));
        label_date->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";"));
        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(1340, 40, 181, 61));
        label_time->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";"));
        comboBox_surgeonname = new QComboBox(centralwidget);
        comboBox_surgeonname->setObjectName(QString::fromUtf8("comboBox_surgeonname"));
        comboBox_surgeonname->setGeometry(QRect(680, 620, 751, 61));
        comboBox_surgeonname->setStyleSheet(QString::fromUtf8("QComboBox{font: 35pt \"Ubuntu\";background-color: rgb(255, 255, 255);}\n"
"\n"
"\n"
"QComboBox::item:selected {\n"
"                            \n"
"	background-color: rgb(26, 95, 180);\n"
"        color: rgb(255, 255, 255);                    }\n"
""));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 1920, 1080));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/logo3.png);"));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(540, 600, 91, 101));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newdoc 1.png);"));
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(870, 730, 181, 81));
        pushButton_start->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: rgb(36, 11, 78);\n"
"font: 28pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
""));
        label_39 = new QLabel(centralwidget);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(0, 0, 1920, 1080));
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));
        pushButton_swap = new QPushButton(centralwidget);
        pushButton_swap->setObjectName(QString::fromUtf8("pushButton_swap"));
        pushButton_swap->setGeometry(QRect(1200, 830, 101, 51));
        pushButton_swap->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_vitactual = new QLabel(centralwidget);
        label_vitactual->setObjectName(QString::fromUtf8("label_vitactual"));
        label_vitactual->setGeometry(QRect(110, 910, 311, 141));
        label_vitactual->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/textbox2.png);\n"
"font: 65pt \"Ubuntu\";"));
        label_vitactual->setAlignment(Qt::AlignCenter);
        pushButton_vacinc = new QPushButton(centralwidget);
        pushButton_vacinc->setObjectName(QString::fromUtf8("pushButton_vacinc"));
        pushButton_vacinc->setGeometry(QRect(90, 260, 81, 91));
        pushButton_vacinc->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-image: url(:/new/prefix1/img/up1.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_vacdec = new QPushButton(centralwidget);
        pushButton_vacdec->setObjectName(QString::fromUtf8("pushButton_vacdec"));
        pushButton_vacdec->setGeometry(QRect(490, 260, 81, 91));
        pushButton_vacdec->setStyleSheet(QString::fromUtf8("QPushButton{background-image: url(:/new/prefix1/img/down1.png);\n"
"background-color: rgba(242, 179, 179, 0);}\n"
"\n"
"\n"
"QPushButton::hover{background-color: #0085ff;\n"
"border-radius: 20px;\n"
"color:white;;}"));
        pushButton_drain = new QPushButton(centralwidget);
        pushButton_drain->setObjectName(QString::fromUtf8("pushButton_drain"));
        pushButton_drain->setGeometry(QRect(1200, 930, 101, 51));
        pushButton_drain->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/backbg3.png);\n"
"color: rgb(255, 120, 0);\n"
"background-color: rgba(191, 64, 64, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        label_39->raise();
        label_20->raise();
        label_16->raise();
        label_14->raise();
        label_13->raise();
        label->raise();
        pushButton_settingswindow->raise();
        label_vacpreset->raise();
        label_vacactual->raise();
        label_dia->raise();
        pushButton_diadec->raise();
        pushButton_diainc->raise();
        label_21->raise();
        label_25->raise();
        pushButton_endcase->raise();
        label_32->raise();
        pushButton_diaonoff->raise();
        label_28->raise();
        pushButton_vaclinearnonlinear->raise();
        label_surgeonname->raise();
        label_38->raise();
        label_23->raise();
        pushButton_aiinc->raise();
        label_aipreset->raise();
        label_aiactual->raise();
        pushButton_aidec->raise();
        label_29->raise();
        label_17->raise();
        pushButton_aionoff->raise();
        label_led2->raise();
        label_41->raise();
        pushButton_led2dec->raise();
        label_44->raise();
        label_7->raise();
        label_18->raise();
        dial->raise();
        label_dialvalue->raise();
        label_40->raise();
        label_34->raise();
        label_35->raise();
        pushButton_led1inc->raise();
        label_27->raise();
        label_led1->raise();
        label_30->raise();
        pushButton_led1onoff->raise();
        label_42->raise();
        pushButton_led1dec->raise();
        pushButton_led2inc->raise();
        pushButton_vitinc->raise();
        pushButton_vitlinearnonlinear->raise();
        label_vitpreset->raise();
        label_24->raise();
        pushButton_vitdec->raise();
        label_33->raise();
        label_19->raise();
        label_siloil->raise();
        label_26->raise();
        pushButton_siloilinc->raise();
        label_31->raise();
        pushButton_siloildec->raise();
        progressBar->raise();
        label_testtube->raise();
        pushButton_vitonoff->raise();
        pushButton_siloilonoff->raise();
        pushButton_led2onoff->raise();
        label_15->raise();
        label_43->raise();
        label_date->raise();
        label_time->raise();
        pushButton_swap->raise();
        label_vitactual->raise();
        pushButton_vacinc->raise();
        pushButton_vacdec->raise();
        pushButton_drain->raise();
        label_12->raise();
        label_22->raise();
        comboBox_surgeonname->raise();
        pushButton_start->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_settingswindow->setText(QString());
        label_vacpreset->setText(QCoreApplication::translate("MainWindow", "250", nullptr));
        label_vacactual->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_aipreset->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        label_vitpreset->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        label_dia->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        pushButton_siloilonoff->setText(QString());
        label_siloil->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_led1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_aidec->setText(QString());
        pushButton_diadec->setText(QString());
        pushButton_vitdec->setText(QString());
        pushButton_led1dec->setText(QString());
        pushButton_aiinc->setText(QString());
        pushButton_diainc->setText(QString());
        pushButton_vitinc->setText(QString());
        pushButton_led1inc->setText(QString());
        pushButton_siloilinc->setText(QString());
        pushButton_led1onoff->setText(QString());
        pushButton_vitonoff->setText(QString());
        pushButton_diaonoff->setText(QString());
        pushButton_vaclinearnonlinear->setText(QString());
        label_aiactual->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_surgeonname->setText(QString());
        pushButton_siloildec->setText(QString());
        label->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_16->setText(QString());
        label_20->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "VACCUM", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "AIR INJECTOR", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "VITRECTOMY", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "DIATHERMY", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "SILICON OIL", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "LED-1", nullptr));
        pushButton_endcase->setText(QCoreApplication::translate("MainWindow", "END CASE", nullptr));
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        label_28->setText(QString());
        label_dialvalue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_38->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_34->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_19->setText(QString());
        pushButton_aionoff->setText(QString());
        label_led2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_led2inc->setText(QString());
        pushButton_led2dec->setText(QString());
        pushButton_led2onoff->setText(QString());
        label_42->setText(QString());
        label_41->setText(QCoreApplication::translate("MainWindow", "LED-2", nullptr));
        pushButton_vitlinearnonlinear->setText(QString());
        label_44->setText(QString());
        label_7->setText(QString());
        label_40->setText(QString());
        label_testtube->setText(QString());
        label_15->setText(QString());
        label_43->setText(QString());
        label_date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QString());
        label_22->setText(QString());
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        label_39->setText(QString());
        pushButton_swap->setText(QCoreApplication::translate("MainWindow", "SWAP OFF", nullptr));
        label_vitactual->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_vacinc->setText(QString());
        pushButton_vacdec->setText(QString());
        pushButton_drain->setText(QCoreApplication::translate("MainWindow", "DRAIN OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
