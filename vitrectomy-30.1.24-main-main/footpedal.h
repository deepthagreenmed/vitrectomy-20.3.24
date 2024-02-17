#ifndef FOOTPEDAL_H
#define FOOTPEDAL_H

#include <QObject>
#include <QTimer>

#include <stdint.h>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

class footpedal : public QObject
{
    Q_OBJECT
public:
    explicit footpedal(QObject *parent = nullptr);
    void init();
    int convert(uint8_t channel);
    int stabilize();


private:
    int spi_fd;
    QTimer *timer;

};

#endif // FOOTPEDAL_H
