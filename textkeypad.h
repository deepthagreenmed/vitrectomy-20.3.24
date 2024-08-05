#ifndef TEXTKEYPAD_H
#define TEXTKEYPAD_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class textkeypad;
}

class textkeypad : public QDialog
{
    Q_OBJECT

public:
    explicit textkeypad(QWidget *parent = nullptr);
    ~textkeypad() ;
    QString digit;


signals:
   void textsignal(const QString& digit);
   void backsignal();
   void spacesignal();
   void entersignal();

private slots:
    void entertext();
    void enterback();
    void enterspace();
    void enterenter();

private:
    Ui::textkeypad *ui;
    QTimer *clicktimer;
};

#endif // TEXTKEYPAD_H
