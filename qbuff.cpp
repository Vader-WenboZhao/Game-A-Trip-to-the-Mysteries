#include "qbuff.h"
#include "qstone.h"
int QBuff::lastRandom=0;
double QBuff::vx_buff=-6;
QBuff::QBuff(QObject *parent) :
    QGameElement(parent)
{
    BuffType=0;
    emited=false;
    IsBuff=1;
    IsFairy=0;
    birthPlace = 1920;
}

void QBuff::draw(QPainter *painter)//绘制果实
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[0]);
}

void QBuff::logic()
{
    if (!enabled)//如果果实无效
        return;
    QBuff::vx_buff=QStone::vx;
    bindRect.translate(QBuff::vx_buff,0.0);//果实移动的速率,左移为负，上下不移动所以为0

    if (bindRect.x()<70)//果实的横坐标小于70，即仙女飞过了果实
        if (!emited)//仙女刚进入果实的横坐标区域
        {
            emited=true;//值变为1
        }
    if (bindRect.x()<-70)//果实移动到了-70之后
    {
        bindRect.translate(birthPlace,
                           randomY[lastRandom=qrand()%160]-bindRect.y());
                            //在x==birthplace处产生一个随机的新果实
        emited=false;//值变为0，迎接新加分果实
    }
}
