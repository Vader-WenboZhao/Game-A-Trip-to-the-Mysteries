#ifndef QINTRODUCTION_H
#define QINTRODUCTION_H


#include "qgameelement.h"

class QIntroduction : public QGameElement
{
    Q_OBJECT
public:
    explicit QIntroduction(QObject *parent = 0);
    void draw(QPainter *);
    void logic();
};

#endif // QINTRODUCTION_H
