/********************************************************************************
** Form generated from reading UI file 'diathermy.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIATHERMY_H
#define UI_DIATHERMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_diathermy
{
public:
    QPushButton *pushButton;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *diathermy)
    {
        if (diathermy->objectName().isEmpty())
            diathermy->setObjectName(QStringLiteral("diathermy"));
        diathermy->resize(728, 436);
        diathermy->setMaximumSize(QSize(800, 600));
        diathermy->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pxfuel 1.png);"));
        pushButton = new QPushButton(diathermy);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 290, 51, 51));
        pushButton->setMaximumSize(QSize(800, 600));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/back3.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        label_5 = new QLabel(diathermy);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 50, 181, 91));
        label_5->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));
        pushButton_5 = new QPushButton(diathermy);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 50, 91, 91));
        pushButton_5->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/-new.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_6 = new QPushButton(diathermy);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(150, 50, 91, 91));
        pushButton_6->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/+.png);\n"
"background-color: rgba(242, 179, 179, 0);"));

        retranslateUi(diathermy);

        QMetaObject::connectSlotsByName(diathermy);
    } // setupUi

    void retranslateUi(QDialog *diathermy)
    {
        diathermy->setWindowTitle(QApplication::translate("diathermy", "Dialog", nullptr));
        pushButton->setText(QString());
        label_5->setText(QApplication::translate("diathermy", "TextLabel", nullptr));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class diathermy: public Ui_diathermy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIATHERMY_H
