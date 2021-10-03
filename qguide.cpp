#include "qguide.h"

QGuide::QGuide(QObject *parent) :
    QGameElement(parent)
{
    curFrame=0;//仙女换帧频率为0
    elapsedFrame=0;//界面换帧频率为0
    IsBuff=0;
    IsFairy=0;
}

void QGuide::draw(QPainter *painter)//初始界面绘制
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[curFrame]);
}

void QGuide::logic()
{
    if (!enabled)//如果界面无效
        return;
    elapsedFrame++;//界面换1帧
    if (elapsedFrame%3==0)//界面每换3帧
        curFrame++;//仙女换1帧
    if (curFrame==frameCount)//换到最后一帧
    {
        curFrame=0;//从第一帧开始
        elapsedFrame=0;
    }
}
