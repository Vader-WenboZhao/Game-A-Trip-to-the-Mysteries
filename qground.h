#ifndef QGROUND_H
#define QGROUND_H

#include <qgameelement.h>

class QGround : public QGameElement
{
    Q_OBJECT
private:
    int xFrame1;
    int xFrame2;
    const int xMax=1919;
    const int dX=-6;
    const int yMax=599;
public:
    explicit QGround(QObject *parent = 0);
    void draw(QPainter *);
    void logic();
};

#endif // QGROUND_H
