#ifndef QBUFFADDSCORE_H
#define QBUFFADDSCORE_H

#include "qgameelement.h"
#include "qbuff.h"


class QBuffAddScore: public QBuff
{
    Q_OBJECT
public:
    explicit QBuffAddScore(QObject *parent = 0);
};

#endif // QBUFFADDSCORE_H
