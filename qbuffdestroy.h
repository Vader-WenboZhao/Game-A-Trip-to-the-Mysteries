#ifndef QBUFFDESTROY_H
#define QBUFFDESTROY_H

#include "qgameelement.h"
#include "qbuff.h"


class QBuffDestroy: public QBuff
{
    Q_OBJECT
public:
    explicit QBuffDestroy(QObject *parent = 0);
};

#endif // QBUFFDESTROY_H
