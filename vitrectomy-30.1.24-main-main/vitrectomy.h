#ifndef VITRECTOMY_H
#define VITRECTOMY_H

#include <QDialog>

namespace Ui {
class vitrectomy;
}

class vitrectomy : public QDialog
{
    Q_OBJECT

public:
    explicit vitrectomy(QWidget *parent = nullptr);
    ~vitrectomy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitrectomy *ui;
};

#endif // VITRECTOMY_H
