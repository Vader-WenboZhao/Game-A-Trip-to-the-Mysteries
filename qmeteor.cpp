#include "qmeteor.h"
#include <QTime>

int QMeteor::lastRandom=0;

QMeteor::QMeteor(QObject *parent) :
    QGameElement(parent)
{
    meteorType=0;
    emited=false;
    IsBuff=0;
    IsFairy=0;
}

void QMeteor::draw(QPainter *painter)//绘制流星
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[0]);
}

void QMeteor::logic()
{
    if (!enabled)//如果流星无效
        return;
    bindRect.translate(-20.0,0.0);//流星移动的速率,左移为负，上下不移动所以为0
    if (bindRect.x()<200)//流星的横坐标小于200，即仙女飞过了流星
        if (!emited)//仙女刚进入流星的横坐标区域
        {
            emit scoreAdd();//加分
            emited=true;//值变为1
        }

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    if (bindRect.x()<-70)//流星移动到了-70之后
    {
        bindRect.translate(2400.0,
                           randomY[lastRandom=qrand()%80]-bindRect.y());
                            //在x==2400处产生一个随机的新流星
        emited=false;//值变为0，迎接新流星
    }
}
