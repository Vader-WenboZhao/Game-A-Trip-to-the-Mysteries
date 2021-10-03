#ifndef SECIALEFFICIENCY_H
#define SECIALEFFICIENCY_H

#include "qgameelement.h"
#include <qmath.h>
#include <QList>

class SecialEfficiency
{
    Q_OBJECT
private:
    int curFrame;
    int elapsedFrame;
    qreal vy;
    QList<QGameElement*> *elementList;
public:
    explicit SecialEfficiency(QList<QGameElement*>*,QObject *parent = 0);
    void draw(QPainter *);
    void logic();
    void birdUp();
    void setVy(qreal);
    void setInvcb(bool);
signals:
    void birdDead();
    void birdStrong();
    void buffInvcbDead();
public slots:
};

#endif // SECIALEFFICIENCY_H
