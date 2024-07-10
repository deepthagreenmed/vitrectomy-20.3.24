/********************************************************************************
** Form generated from reading UI file 'vaccum.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACCUM_H
#define UI_VACCUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_vaccum
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *vaccum)
    {
        if (vaccum->objectName().isEmpty())
            vaccum->setObjectName(QStringLiteral("vaccum"));
        vaccum->resize(779, 428);
        vaccum->setMaximumSize(QSize(800, 600));
        vaccum->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pxfuel 1.png);"));
        pushButton_3 = new QPushButton(vaccum);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 370, 51, 51));
        pushButton_3->setMaximumSize(QSize(800, 600));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/back3.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_4 = new QPushButton(vaccum);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 90, 91, 91));
        pushButton_4->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/+.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_5 = new QPushButton(vaccum);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(510, 80, 91, 91));
        pushButton_5->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/-new.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        label_3 = new QLabel(vaccum);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 70, 181, 91));
        label_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));
        pushButton = new QPushButton(vaccum);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 0, 191, 61));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/newwbutton1 1.png);\n"
"image: url(:/new/prefix1/NEWWWVACCUM.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_8 = new QPushButton(vaccum);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(300, 250, 191, 61));
        pushButton_8->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/newwbutton1 1.png);\n"
"image: url(:/new/prefix1/newvit.png);\n"
"background-color: rgba(242, 179, 179, 0);\n"
""));
        pushButton_9 = new QPushButton(vaccum);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(200, 330, 91, 91));
        pushButton_9->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/+.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        pushButton_7 = new QPushButton(vaccum);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(510, 330, 91, 91));
        pushButton_7->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/-new.png);\n"
"background-color: rgba(242, 179, 179, 0);"));
        label_4 = new QLabel(vaccum);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 160, 181, 91));
        label_4->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));
        label_5 = new QLabel(vaccum);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 320, 181, 91));
        label_5->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-image: url(:/new/prefix1/Rectangle 15.png);\n"
"font: 24pt \"Ubuntu\";"));

        retranslateUi(vaccum);

        QMetaObject::connectSlotsByName(vaccum);
    } // setupUi

    void retranslateUi(QDialog *vaccum)
    {
        vaccum->setWindowTitle(QApplication::translate("vaccum", "Dialog", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_3->setText(QApplication::translate("vaccum", "TextLabel", nullptr));
        pushButton->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        label_4->setText(QApplication::translate("vaccum", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("vaccum", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vaccum: public Ui_vaccum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACCUM_H
