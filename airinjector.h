#ifndef AIRINJECTOR_H
#define AIRINJECTOR_H
#include "vaccum.h"
#include "hwhandler.h"
#include <QObject>

class airinjector
{
public:
    airinjector();

public slots:
    void aivalue(int p);

private:
    hwHandler *hhandler;
    Vaccum *vac;
};

#endif // AIRINJECTOR_H
