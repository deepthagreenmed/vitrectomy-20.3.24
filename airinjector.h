#ifndef AIRINJECTOR_H
#define AIRINJECTOR_H

#include "vaccum.h"
#include "hwhandler.h"

#include <QObject>

#include <iostream>

class airinjector
{
public:
    airinjector();

signals:
    void aisignal(int a);

public slots:
    void aivalue(int p);

private:
    hwHandler *hhandler;
    Vaccum *vac;
};

#endif // AIRINJECTOR_H
