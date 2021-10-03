#include "qintroduction.h"

QIntroduction::QIntroduction(QObject *parent) :
    QGameElement(parent)
{
    IsBuff=1;
    buffType=100;
}

void QIntroduction::draw(QPainter *painter)//绘制说明
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[0]);
}

void QIntroduction::logic()
{
    if (!enabled)//如果说明无效
        return;
    bindRect.translate(-12,0.0);
}
