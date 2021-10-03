#ifndef QBUFFICE_H
#define QBUFFICE_H

#include "qgameelement.h"
#include "qbuff.h"


class QBuffIce: public QBuff
{
    Q_OBJECT
public:
    explicit QBuffIce(QObject *parent = 0);
};


#endif // QBUFFICE_H
