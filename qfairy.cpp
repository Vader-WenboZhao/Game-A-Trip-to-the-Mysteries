#include "qfairy.h"

QFairy::QFairy(QList<QGameElement *>* lpList, QObject *parent) :
    QGameElement(parent)
{
    elementList=lpList;
    curFrame=0;
    elapsedFrame=0;
    hasBuff=0;
    IsBuff=0;
    IsFairy=1;
    isInvcb=0;
    vy=2.0;//刚开局仙女初始的下落速度为2
}

void QFairy::setVy(qreal _vy)//仙女自然下落
{
    vy=_vy;
}

void QFairy::fairyUp()//点击后仙女上升
{
    vy=-7.0;//点击后仙女上升的速度(向下为正)
   emit fairyfly();//发出仙女上升的信号
}

void QFairy::draw(QPainter *painter)//仙女显示在界面上
{
    painter->drawPixmap(bindRect.topLeft(),pixmapList[curFrame]);
}

void QFairy::setBuff(bool x)//设置buff状态
{
    hasBuff=(x? 1:0);
}

void QFairy::setInvcb(bool x)//设置无敌状态
{
    isInvcb=(x? 1:0);
}

void QFairy::logic()
{
    if (!enabled) //如果仙女不可用
        return;
    bindRect.translate(0.0,vy);//仙女的前进速度和下落速度,仙女不前进所以第一个参数为0
    vy+=0.5;//仙女下落的重力加速度为0.5，即仙女每换一帧下降速度vy+0.5
    if (bindRect.y()<0.0)//仙女撞天
        emit fairyDead();//仙女死
    if (bindRect.y()>890.0)//仙女撞地
        emit fairyDead();//仙女死

    if(hasBuff==0)
    {
        for (QGameElement *e:*elementList)
            if (e!=this && e->IsBuff==0)
            {
                if (bindRect.intersects(e->getBindRect()))//仙女撞上东西(障碍物)
                    emit fairyDead();//仙女死
            }
            else if(e!=this && e->IsBuff==1)
            {
                if(e->buffType==1)
                {
                    if (bindRect.intersects(e->getBindRect()))//仙女撞上无敌Buff果实
                    {
                        emit fairyStrong();
                        emit buffInvcbDead();
                    }
                }
                else if(e->buffType==2)
                {
                    if (bindRect.intersects(e->getBindRect()))//仙女撞上加分Buff果实
                    {
                        emit addmanyscore();
                        emit buffAddScoreDead();
                    }
                }
                else if(e->buffType==3)
                {
                    if (bindRect.intersects(e->getBindRect()))//仙女撞上毁灭Buff果实
                    {
                        emit destroyAll();
                        emit buffDestroyDead();
                    }
                }
                else if(e->buffType==4)
                {
                    if (bindRect.intersects(e->getBindRect()))//仙女撞上冰冻Buff果实
                    {
                        emit addMyIce();
                        emit buffIceDead();
                    }
                }
            }
    }
    else if(hasBuff==1)
    {
        if(isInvcb==1)
            ;
        else
        {
            for (QGameElement *e:*elementList)
                if (e!=this && e->IsBuff==0)
                    if (bindRect.intersects(e->getBindRect()))//仙女撞上东西(障碍物)
                        emit fairyDead();//仙女死
        }
    }

    elapsedFrame++;//界面换1帧
    if (elapsedFrame%2==0)//界面帧数每增加2
        curFrame++;//仙女换1帧
    if (curFrame==frameCount)//所在帧数==元素拥有帧的总数,从0重新换帧
    {
        curFrame=0;//全部置零
        elapsedFrame=0;
    }
}
