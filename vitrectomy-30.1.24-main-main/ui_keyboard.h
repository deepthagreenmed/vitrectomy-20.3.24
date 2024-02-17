/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyboard
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_19;
    QPushButton *pushButton_16;
    QPushButton *pushButton_20;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;

    void setupUi(QDialog *keyboard)
    {
        if (keyboard->objectName().isEmpty())
            keyboard->setObjectName(QStringLiteral("keyboard"));
        keyboard->resize(707, 496);
        buttonBox = new QDialogButtonBox(keyboard);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(310, 270, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(keyboard);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 110, 641, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_2->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(layoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        horizontalLayout_2->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(layoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        horizontalLayout_2->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(layoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        horizontalLayout_2->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(layoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        horizontalLayout_2->addWidget(pushButton_15);

        pushButton_19 = new QPushButton(layoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        horizontalLayout_2->addWidget(pushButton_19);

        pushButton_16 = new QPushButton(layoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        horizontalLayout_2->addWidget(pushButton_16);

        pushButton_20 = new QPushButton(layoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        horizontalLayout_2->addWidget(pushButton_20);

        pushButton_17 = new QPushButton(layoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        horizontalLayout_2->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(layoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        horizontalLayout_2->addWidget(pushButton_18);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_21 = new QPushButton(layoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        horizontalLayout_3->addWidget(pushButton_21);

        pushButton_22 = new QPushButton(layoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        horizontalLayout_3->addWidget(pushButton_22);

        pushButton_23 = new QPushButton(layoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        horizontalLayout_3->addWidget(pushButton_23);

        pushButton_24 = new QPushButton(layoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        horizontalLayout_3->addWidget(pushButton_24);

        pushButton_25 = new QPushButton(layoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        horizontalLayout_3->addWidget(pushButton_25);

        pushButton_26 = new QPushButton(layoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));

        horizontalLayout_3->addWidget(pushButton_26);

        pushButton_27 = new QPushButton(layoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));

        horizontalLayout_3->addWidget(pushButton_27);

        pushButton_28 = new QPushButton(layoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));

        horizontalLayout_3->addWidget(pushButton_28);

        pushButton_29 = new QPushButton(layoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));

        horizontalLayout_3->addWidget(pushButton_29);

        pushButton_30 = new QPushButton(layoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));

        horizontalLayout_3->addWidget(pushButton_30);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_31 = new QPushButton(keyboard);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setGeometry(QRect(230, 240, 291, 25));
        pushButton_32 = new QPushButton(keyboard);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        pushButton_32->setGeometry(QRect(530, 240, 89, 25));

        retranslateUi(keyboard);
        QObject::connect(buttonBox, SIGNAL(accepted()), keyboard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), keyboard, SLOT(reject()));

        QMetaObject::connectSlotsByName(keyboard);
    } // setupUi

    void retranslateUi(QDialog *keyboard)
    {
        keyboard->setWindowTitle(QApplication::translate("keyboard", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("keyboard", "Q", nullptr));
        pushButton_2->setText(QApplication::translate("keyboard", "W", nullptr));
        pushButton_4->setText(QApplication::translate("keyboard", "E", nullptr));
        pushButton_3->setText(QApplication::translate("keyboard", "R", nullptr));
        pushButton_5->setText(QApplication::translate("keyboard", "T", nullptr));
        pushButton_6->setText(QApplication::translate("keyboard", "Y", nullptr));
        pushButton_7->setText(QApplication::translate("keyboard", "U", nullptr));
        pushButton_8->setText(QApplication::translate("keyboard", "I", nullptr));
        pushButton_9->setText(QApplication::translate("keyboard", "O", nullptr));
        pushButton_10->setText(QApplication::translate("keyboard", "P", nullptr));
        pushButton_11->setText(QApplication::translate("keyboard", "A", nullptr));
        pushButton_12->setText(QApplication::translate("keyboard", "S", nullptr));
        pushButton_13->setText(QApplication::translate("keyboard", "D", nullptr));
        pushButton_14->setText(QApplication::translate("keyboard", "F", nullptr));
        pushButton_15->setText(QApplication::translate("keyboard", "G", nullptr));
        pushButton_19->setText(QApplication::translate("keyboard", "H", nullptr));
        pushButton_16->setText(QApplication::translate("keyboard", "J", nullptr));
        pushButton_20->setText(QApplication::translate("keyboard", "K", nullptr));
        pushButton_17->setText(QApplication::translate("keyboard", "L", nullptr));
        pushButton_18->setText(QApplication::translate("keyboard", "<-", nullptr));
        pushButton_21->setText(QApplication::translate("keyboard", "Z", nullptr));
        pushButton_22->setText(QApplication::translate("keyboard", "X", nullptr));
        pushButton_23->setText(QApplication::translate("keyboard", "C", nullptr));
        pushButton_24->setText(QApplication::translate("keyboard", "V", nullptr));
        pushButton_25->setText(QApplication::translate("keyboard", "B", nullptr));
        pushButton_26->setText(QApplication::translate("keyboard", "N", nullptr));
        pushButton_27->setText(QApplication::translate("keyboard", "M", nullptr));
        pushButton_28->setText(QApplication::translate("keyboard", ",", nullptr));
        pushButton_29->setText(QApplication::translate("keyboard", ".", nullptr));
        pushButton_30->setText(QApplication::translate("keyboard", "/", nullptr));
        pushButton_31->setText(QApplication::translate("keyboard", " SPACE", nullptr));
        pushButton_32->setText(QApplication::translate("keyboard", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keyboard: public Ui_keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
