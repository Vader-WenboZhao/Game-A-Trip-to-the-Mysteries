#ifndef QBUFFINVCB_H
#define QBUFFINVCB_H

#include "qgameelement.h"
#include "qbuff.h"


class QBuffInvcb: public QBuff
{
    Q_OBJECT
public:
    explicit QBuffInvcb(QObject *parent = 0);
};

#endif // QBUFFINVCB_H
