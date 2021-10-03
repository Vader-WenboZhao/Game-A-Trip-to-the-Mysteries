#include "qgameboard.h"

QGameBoard::QGameBoard(QObject *parent) :
    QGameElement(parent)
{
    IsBuff=0;
    IsFairy=0;
}

void QGameBoard::draw(QPainter *painter)//绘制界面Gameover
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[0]);
}

void QGameBoard::logic()
{
    if (!enabled)//Gameover无效
        return;
    bindRect.translate(0.0,dY);//Gameover移动，因为它是垂直移动的,所以为0，其移动速率为dY
    if (dY>0?bindRect.y()>destY:bindRect.y()<destY)//如果速度>0则当y坐标大于目的Y坐标时停止，
                                                   //如果速度<0则当y坐标小于目的Y坐标时停止
    {
        setEnabled(false);//状态置为不可用
        emit moveFinished();//发出移动结束的信号
    }
}
