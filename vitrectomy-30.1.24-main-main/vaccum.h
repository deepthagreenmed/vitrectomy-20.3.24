#ifndef VACCUM_H
#define VACCUM_H

#include "hwhandler.h"

#include <QObject>
#include <QTimer>
#include <QLabel>

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <vector>
#include <iostream>


class vaccum : public QObject
{
    Q_OBJECT
public:
    vaccum();
    ~vaccum();
    int convert(uint8_t channel);
    void initSPI();
    float val;
    float stabilizeoff();
    float stabilizeon();

private:
    QTimer *timer;
    int spi_fd;
    hwHandler h;

};

#endif // VACCUM_H
