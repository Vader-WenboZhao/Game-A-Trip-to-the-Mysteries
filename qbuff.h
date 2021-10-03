#ifndef QBUFF_H
#define QBUFF_H

#include "qgameelement.h"


class QBuff: public QGameElement
{
    Q_OBJECT
private:
    static int lastRandom;
    int BuffType;
    bool emited;
    const qreal randomY[160]={450,230,360,330,280,250,260,440,
                              160,300,310,320,340,370,380,390,
                              400,170,180,220,140,150,100,270,
                              470,480,210,350,130,110,190,460,
                              240,420,430,120,200,410,450,230,
                              360,330,280,250,260,440,160,300,
                              310,320,340,370,380,390,400,170,
                              180,220,140,150,100,270,470,480,
                              210,350,130,110,190,460,240,420,
                              430,120,200,410,290,490,290,490,
                              560,450,230,360,330,280,250,260,
                              440,160,300,310,320,340,370,380,
                              390,400,170,180,220,140,150,100,
                              270,470,480,210,350,130,110,190,
                              460,240,420,430,120,200,410,290,
                              490,625,610,620,770,540,565,710,
                              720,730,655,535,545,780,790,800,
                              655,530,650,660,675,670,740,750,
                              695,680,690,500,570,580,590,600,
                              760,510,520,550,700,630,640,655};
public:
    static double vx_buff;
    int birthPlace;
    explicit QBuff(QObject *parent = 0);
    void draw(QPainter *);
    void logic();
    void setBuffType(int _type){BuffType=_type;}
signals:
    buffDead();
};


#endif // QBUFF_H