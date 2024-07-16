#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <vector>
#include <iostream>

#include <QObject>
#include <QDebug>

class pressuresensor : public QObject
{
    Q_OBJECT
public:
    explicit pressuresensor(QObject *parent = nullptr);
    ~pressuresensor();
    void init();
    float convert();

signals:
private:
    int spi_fd;

};

#endif // PRESSURESENSOR_H
