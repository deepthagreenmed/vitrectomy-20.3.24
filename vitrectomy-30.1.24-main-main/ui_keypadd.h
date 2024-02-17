/********************************************************************************
** Form generated from reading UI file 'keypadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPADD_H
#define UI_KEYPADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keypad
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QWidget *keypad)
    {
        if (keypad->objectName().isEmpty())
            keypad->setObjectName(QString::fromUtf8("keypad"));
        keypad->resize(1280, 720);
        groupBox = new QGroupBox(keypad);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 0, 351, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 273, 165));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 1, 1, 1, 1);


        retranslateUi(keypad);

        QMetaObject::connectSlotsByName(keypad);
    } // setupUi

    void retranslateUi(QWidget *keypad)
    {
        keypad->setWindowTitle(QCoreApplication::translate("keypad", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("keypad", "GroupBox", nullptr));
        pushButton_8->setText(QCoreApplication::translate("keypad", "8", nullptr));
        pushButton_6->setText(QCoreApplication::translate("keypad", "6", nullptr));
        pushButton->setText(QCoreApplication::translate("keypad", "1", nullptr));
        pushButton_7->setText(QCoreApplication::translate("keypad", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("keypad", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("keypad", "5", nullptr));
        pushButton_3->setText(QCoreApplication::translate("keypad", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("keypad", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("keypad", "4", nullptr));
        pushButton_10->setText(QCoreApplication::translate("keypad", "0", nullptr));
        pushButton_11->setText(QCoreApplication::translate("keypad", "Backspace", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keypad: public Ui_keypad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPADD_H
