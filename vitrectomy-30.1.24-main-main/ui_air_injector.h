/********************************************************************************
** Form generated from reading UI file 'air_injector.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIR_INJECTOR_H
#define UI_AIR_INJECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_air_injector
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *air_injector)
    {
        if (air_injector->objectName().isEmpty())
            air_injector->setObjectName(QStringLiteral("air_injector"));
        air_injector->resize(664, 453);
        air_injector->setMaximumSize(QSize(800, 600));
        air_injector->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pxfuel 1.png);"));
        pushButton = new QPushButton(air_injector);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 380, 51, 51));
        pushButton->setMaximumSize(QSize(800, 600));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/back3.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_4 = new QPushButton(air_injector);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 10, 191, 61));
        pushButton_4->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/newwbutton1 1.png);\n"
"image: url(:/new/prefix1/NEWWWAIR INJECTOR.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        label_5 = new QLabel(air_injector);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 100, 181, 91));
        label_5->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));
        label_6 = new QLabel(air_injector);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 220, 181, 91));
        label_6->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));
        pushButton_5 = new QPushButton(air_injector);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 100, 91, 91));
        pushButton_5->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/+.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_6 = new QPushButton(air_injector);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(440, 100, 91, 91));
        pushButton_6->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/-new.png);\n"
"background-color: rgba(242, 179, 179, 0);"));

        retranslateUi(air_injector);

        QMetaObject::connectSlotsByName(air_injector);
    } // setupUi

    void retranslateUi(QDialog *air_injector)
    {
        air_injector->setWindowTitle(QApplication::translate("air_injector", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_4->setText(QString());
        label_5->setText(QApplication::translate("air_injector", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("air_injector", "TextLabel", nullptr));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class air_injector: public Ui_air_injector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIR_INJECTOR_H
