/********************************************************************************
** Form generated from reading UI file 'footpedal.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOOTPEDAL_H
#define UI_FOOTPEDAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_footpedal
{
public:
    QPushButton *pushButton_3;

    void setupUi(QDialog *footpedal)
    {
        if (footpedal->objectName().isEmpty())
            footpedal->setObjectName(QStringLiteral("footpedal"));
        footpedal->resize(1280, 720);
        footpedal->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/SWIMG.png);"));
        pushButton_3 = new QPushButton(footpedal);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 590, 101, 101));
        pushButton_3->setMaximumSize(QSize(800, 600));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/backimg 1.png);\n"
"background-color: rgba(242, 179, 179, 0);"));

        retranslateUi(footpedal);

        QMetaObject::connectSlotsByName(footpedal);
    } // setupUi

    void retranslateUi(QDialog *footpedal)
    {
        footpedal->setWindowTitle(QApplication::translate("footpedal", "Dialog", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class footpedal: public Ui_footpedal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOOTPEDAL_H
