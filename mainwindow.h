#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QLCDNumber>
#include <QPushButton>
#include <QMediaPlayer>
#include "qfairy.h"
#include "qguide.h"
#include "qground.h"
#include "qstone.h"
#include "qgameboard.h"
#include "qbuffinvcb.h"
#include "qbuffaddscore.h"
#include "qbuffIce.h"
#include "qbuffdestroy.h"
#include "qmeteor.h"
#include "qintroduction.h"
#define GAME_PLAYING 1
#define GAME_PAUSED 2
#define GAME_PAUSEDTRUE 3
#define GAME_OVER 4

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QIntroduction *intr;//说明
    QFairy *fairy;//仙女
    QGuide *guide;//引导界面
    QGround *ground;//地面
    QStone *stone[14];//管道
    QMeteor *meteor;//流星

    QBuffIce *buffice;//冰冻buff果实
    QBuffDestroy *buffdestroy;//毁灭buff果实
    QBuffInvcb *buffinvcb;//无敌buff果实
    QBuffAddScore *buffaddscore;//加分buff果实

    QGameBoard *gameover;//游戏结束板
    QGameBoard *scoreBoard;//分数板
    QGameBoard *rankBoard;//排名板
    QList<QGameElement*> Elementlist;//游戏元素列表(链表类型)
    QTimer timer;//总计时器

    QTimer timerBuffIce;//用于冰冻果实持续时间的计时器
    QTimer timerBuffIceBack;//冰冻果实再次出现的计时器
    QTimer timerBuffDestroy;//用于毁灭果实持续时间的计时器
    QTimer timerBuffDestroyBack;//毁灭果实再次出现的计时器
    QTimer timerBuffInvcb;//用于无敌buff持续时间的计时器
    QTimer timerBuffInvcbBack;//无敌果实再次出现的计时器
    QTimer timerBuffAddScore;//用于加分buff持续时间的计时器
    QTimer timerBuffAddScoreBack;//加分果实再次出现的计时器

    QLCDNumber *lcdScore;//显示分数
    QPushButton *btnPlay;//开始按钮
    QPushButton *btnQuit;//退出按钮
    QPushButton *btnReplay;//重新开始按钮
    QPushButton *btnRank;//排名按钮
    QPixmap pixmapBkgnd;//游戏背景
    int score;//游戏分数
    int scorerank[4]={0};//分数纪录
    int bestscore;//最高分数

    uint gameStatus;//游戏状态

    QMediaPlayer *flyMusic;//飞行音效
    QMediaPlayer *dieMusic;//死亡音效
    QMediaPlayer *BuffInvcbMusic;//无敌音效
    QMediaPlayer *BuffAddScoreMusic;//加分音效
    QMediaPlayer *bgmMusic;//背景音乐
    QMediaPlayer *gameoverMusic;//游戏结束音效

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void sleepNoBlock(int);
    void sleepBlock(int);
    void createMusic();
    void pausegame();
public slots:
    void changeStyle1();//4种buff特效
    void changeStyle2();
    void changeStyle3();
    void changeStyle4();

    void buffIceBack();//冰冻buff果实回归
    void buffIceTimeIsOut();//时间到
    void deleteBuffIce();//消除Buff

    void buffDestroyBack();//毁灭buff果实回归
    void buffDestroyTimeIsOut();//时间到
    void deleteBuffDestroy();//消除Buff

    void buffInvcbBack();//无敌buff果实回归
    void buffInvcbTimeIsOut();//时间到
    void deleteBuffInvcb();//消除Buff

    void buffAddScoreBack();//加分buff果实回归
    void buffAddScoreTimeIsOut();//时间到
    void deleteBuffAddScore();//消除Buff

    void addIce();//仙女冰冻
    void deleteAllStones();//消除所有障碍物
    void gameScoreAddMany();//加许多分
    void gameOver();//游戏结束
    void gameScoreAdd();//游戏加分
    void makeFairyStrong();//使仙女无敌
    void board1Stop();//板子1停止
    void board2Stop();//板子2停止
    void play();//游戏开始
    void quit();//退出
    void replay();//重新开始
    void rank();//排名
    void flymusic();//飞舞的音乐
signals:
    void Gameover();//游戏结束
};

#endif // MAINWINDOW_H
