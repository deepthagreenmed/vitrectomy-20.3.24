/********************************************************************************
** Form generated from reading UI file 'keypad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPAD_H
#define UI_KEYPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keypad
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label;

    void setupUi(QWidget *keypad)
    {
        if (keypad->objectName().isEmpty())
            keypad->setObjectName(QString::fromUtf8("keypad"));
        keypad->resize(491, 272);
        keypad->setStyleSheet(QString::fromUtf8("border-radius: 20px;"));
        pushButton_3 = new QPushButton(keypad);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 140, 80, 51));
        QFont font;
        font.setPointSize(20);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_2 = new QPushButton(keypad);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 140, 80, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_9 = new QPushButton(keypad);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(260, 10, 80, 51));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_6 = new QPushButton(keypad);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(260, 80, 81, 41));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_7 = new QPushButton(keypad);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 0, 81, 61));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_4 = new QPushButton(keypad);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 80, 80, 41));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_8 = new QPushButton(keypad);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 10, 80, 41));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_5 = new QPushButton(keypad);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 80, 80, 41));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton = new QPushButton(keypad);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 140, 80, 51));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_11 = new QPushButton(keypad);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(390, 70, 81, 91));
        pushButton_11->setFont(font);
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);\n"
"border:none;"));
        pushButton_10 = new QPushButton(keypad);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 210, 101, 51));
        pushButton_10->setFont(font);
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        pushButton_12 = new QPushButton(keypad);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(380, 170, 101, 91));
        QFont font1;
        font1.setPointSize(17);
        pushButton_12->setFont(font1);
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);\n"
"border:none;"));
        pushButton_13 = new QPushButton(keypad);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(380, 10, 91, 51));
        pushButton_13->setFont(font);
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgba(191, 64, 64, 0);\n"
"border:none;"));
        label = new QLabel(keypad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 491, 271));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/keypadbg3 1.png);"));
        label->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        pushButton_9->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_4->raise();
        pushButton_8->raise();
        pushButton_5->raise();
        pushButton->raise();
        pushButton_11->raise();
        pushButton_10->raise();
        pushButton_12->raise();
        pushButton_13->raise();

        retranslateUi(keypad);

        QMetaObject::connectSlotsByName(keypad);
    } // setupUi

    void retranslateUi(QWidget *keypad)
    {
        keypad->setWindowTitle(QCoreApplication::translate("keypad", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("keypad", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("keypad", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("keypad", "9", nullptr));
        pushButton_6->setText(QCoreApplication::translate("keypad", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("keypad", "7", nullptr));
        pushButton_4->setText(QCoreApplication::translate("keypad", "4", nullptr));
        pushButton_8->setText(QCoreApplication::translate("keypad", "8", nullptr));
        pushButton_5->setText(QCoreApplication::translate("keypad", "5", nullptr));
        pushButton->setText(QCoreApplication::translate("keypad", "1", nullptr));
        pushButton_11->setText(QCoreApplication::translate("keypad", "CLR", nullptr));
        pushButton_10->setText(QCoreApplication::translate("keypad", "0", nullptr));
        pushButton_12->setText(QCoreApplication::translate("keypad", "Enter", nullptr));
        pushButton_13->setText(QCoreApplication::translate("keypad", ".", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class keypad: public Ui_keypad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPAD_H
