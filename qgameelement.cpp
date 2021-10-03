#include "qgameelement.h"

QGameElement::QGameElement(QObject *parent) :
    QObject(parent)
{
    frameCount=0;//帧编号
    enabled=true;//状态为可用
}

void QGameElement::addFrame(QPixmap pixmap)//添加帧
{
    if (pixmap.isNull())//帧无效
        return;
    pixmapList.append(pixmap);//帧列表加上这个元素
    frameCount++;//帧总数+1
}

void QGameElement::clearAllFrame()//清除所有帧
{
    pixmapList.clear();//帧列表清空
    frameCount=0;//帧总数清零
}

QRectF& QGameElement::getBindRect()//获取矩形
{
    return bindRect;
}

void QGameElement::setRect(qreal x, qreal y, qreal w, qreal h)//放置矩形
{
    bindRect.setRect(x,y,w,h);
}

void QGameElement::setRect(QRectF rect)//重载放置矩形
{
    bindRect=rect;
}

void QGameElement::setEnabled(bool _enabled)//修改状态
{
    enabled=_enabled;
}

