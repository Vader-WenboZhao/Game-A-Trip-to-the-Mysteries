#ifndef QFAIRY_H
#define QFAIRY_H

#include "qgameelement.h"
#include <qmath.h>
#include <QList>

class QFairy : public QGameElement
{
    Q_OBJECT
private:
    bool isInvcb;
    bool hasBuff;
    int curFrame;
    int elapsedFrame;
    qreal vy;
    QList<QGameElement*> *elementList;
public:
    explicit QFairy(QList<QGameElement*>*,QObject *parent = 0);
    void draw(QPainter *);
    void logic();
    void fairyUp();
    void setVy(qreal);
    void setBuff(bool);
    void setInvcb(bool);
signals:
    void addMyIce();
    void destroyAll();
    void addmanyscore();
    void fairyDead();
    void fairyStrong();
    void buffDestroyDead();
    void buffInvcbDead();
    void buffAddScoreDead();
    void buffIceDead();
    void fairyfly();
};

#endif // QFAIRY_H
