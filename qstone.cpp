#include "qstone.h"

int QStone::lastRandom=0;
double QStone::vx=-6;
QStone::QStone(QObject *parent) :
    QGameElement(parent)
{
    stoneType=0;
    emited=false;
    IsBuff=0;
    IsFairy=0;
}

void QStone::draw(QPainter *painter)//绘制障碍物
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[0]);
}

void QStone::logic()
{
    if (!enabled)//如果障碍物无效
        return;
    if(QStone::vx>=-13)
        QStone::vx-=0.00005;
    bindRect.translate(QStone::vx,0.0);//障碍物移动的速率,左移为负，上下不移动所以为0
    if (bindRect.x()<400)//障碍物的横坐标小于400，即仙女飞过了障碍物
        if (!emited)//仙女刚进入障碍物的横坐标区域
        {
            emit scoreAdd();//加分
            emited=true;//值变为1
        }
    if (bindRect.x()<-70)//障碍物移动到了-70之后
    {
        bindRect.translate(1920.0,
                           randomY[lastRandom=qrand()%80]-bindRect.y());
                            //在x==1920处产生一个随机的新障碍物
        emited=false;//值变为0，迎接新障碍物
    }
}
