#include "CanTiming.h"

CanTiming::CanTiming(unsigned id, unsigned bitrate, uint32_t bitrate_fd, float samplePoint)
  : _id(id),
    _bitrate(bitrate),
    _bitrate_fd(bitrate_fd),
    _samplePoint(samplePoint)
{
}

unsigned CanTiming::getId()
{
    return _id;
}

unsigned CanTiming::getBitrate()
{
    return _bitrate;
}

unsigned CanTiming::getBitrateFD()
{
    return _bitrate_fd;
}

bool CanTiming::isCanFD()
{
    return _bitrate_fd != 0;
}

float CanTiming::getSamplePoint()
{
    return _samplePoint;
}

QString CanTiming::getTitle()
{
    QString format = isCanFD() ? "%1/%3(FD) kBit/s, sample point %2%" : "%1 kBit/s, sample point %2";
    return format.arg(
        QString::number(getBitrate()/1000, 'f', 2),
        QString::number(getSamplePoint()*100, 'f', 1),
        QString::number(getBitrateFD()/1000, 'f', 2)
    );
}