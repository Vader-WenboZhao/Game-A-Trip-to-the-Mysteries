#include "mainwindow.h"
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    bestscore=0;
    this->createMusic();   //创建音乐
    bgmMusic->play();      //播放背景音乐
    score=0;               //分数
    gameStatus=GAME_OVER;  //游戏状态
    setFixedSize(1920,900); //界面大小

    pixmapBkgnd.load(":/Images/bg.png");//背景图片

    lcdScore=new QLCDNumber(3,this);//记分七段译码管(3位数)
    lcdScore->setGeometry(50,20,160,100);//(x,y,w,h)
    lcdScore->setLineWidth(0);//白框宽度
    lcdScore->setStyleSheet("QLCDNumber{color: white}");//七段译码管颜色
    lcdScore->setVisible(false);//七段译码管分数不可见

    btnQuit=new QPushButton(this);//退出键
    btnQuit->setGeometry(1680,40,200,70);//(x,y,w,h)
    btnQuit->setStyleSheet("QPushButton{border-image:url(:/Images/quit.png);}"
                           "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    btnQuit->setVisible(true);//quit键可见

    btnPlay=new QPushButton(this);//开始键
    btnPlay->setGeometry(1095,350,230,80);//(x,y,w,h)
    btnPlay->setStyleSheet("QPushButton{border-image:url(:/Images/play.png);}"
                                                           //开始键的图案
                        "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
                                                           //按下的特效
    btnPlay->setVisible(true);//play键可见

    btnReplay=new QPushButton(this);//重新开始键
    btnReplay->setGeometry(600,600,170,100);//(x,y,w,h)
    btnReplay->setStyleSheet("QPushButton{border-image:url(:/Images/replay.png);}"
                                                           //重新开始键的图案
                             "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
                                                           //按下的特效

    btnReplay->setVisible(false);//replay键不可见

    btnRank=new QPushButton(this);//排行榜键
    btnRank->setGeometry(1100,600,170,100);//(x,y,w,h)
    btnRank->setStyleSheet("QPushButton{border-image:url(:/Images/rank.png);}"//
                                                           //排行榜键的图案
                             "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
                                                           //按下的特效
    btnRank->setVisible(false);//排行榜键不可见

    fairy=new QFairy(&Elementlist);//构建仙女
    fairy->addFrame(QPixmap(":/Images/fairy1.png"));//仙女的三种形态(扇翅膀的特效)
    fairy->addFrame(QPixmap(":/Images/fairy2.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy3.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy4.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy5.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy6.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy7.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy8.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy9.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy10.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy11.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy12.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy13.png"));//同理

    guide=new QGuide;//开始界面
    guide->addFrame(QPixmap(":/Images/guid1.png"));//开始的三种形态
    guide->addFrame(QPixmap(":/Images/guid2.png"));//同理
    guide->addFrame(QPixmap(":/Images/guid3.png"));//同理
    guide->setRect(0.0,0.0,0.0,0.0);//界面的(x,y,w,h)

    intr=new QIntroduction;//构建说明
    intr->addFrame(QPixmap(":/Images/hahaha.png"));

    stone[0]=new QStone;//构建障碍物0
    stone[0]->addFrame(QPixmap(":/Images/stone.png"));
    stone[1]=new QStone;//构建障碍物1
    stone[1]->addFrame(QPixmap(":/Images/stone.png"));
    stone[1]->setStoneType(1);//设置障碍物类型

    stone[2]=new QStone;//构建障碍物2
    stone[2]->addFrame(QPixmap(":/Images/stone.png"));
    stone[3]=new QStone;//构建障碍物3
    stone[3]->addFrame(QPixmap(":/Images/stone.png"));
    stone[4]=new QStone;//构建障碍物4
    stone[4]->addFrame(QPixmap(":/Images/stone.png"));
    stone[4]->setStoneType(1);//设置障碍物类型

    stone[5]=new QStone;//构建障碍物5
    stone[5]->addFrame(QPixmap(":/Images/stone.png"));
    stone[6]=new QStone;//构建障碍物6
    stone[6]->addFrame(QPixmap(":/Images/stone.png"));
    stone[6]->setStoneType(1);//设置障碍物类型

    stone[7]=new QStone;//构建障碍物7
    stone[7]->addFrame(QPixmap(":/Images/stone.png"));
    stone[8]=new QStone;//构建障碍物8
    stone[8]->addFrame(QPixmap(":/Images/stone.png"));
    stone[9]=new QStone;//构建障碍物9
    stone[9]->addFrame(QPixmap(":/Images/stone.png"));
    stone[9]->setStoneType(1);//设置障碍物类型

    stone[10]=new QStone;//构建障碍物10
    stone[10]->addFrame(QPixmap(":/Images/stone.png"));
    stone[11]=new QStone;//构建障碍物11
    stone[11]->addFrame(QPixmap(":/Images/stone.png"));
    stone[12]=new QStone;//构建障碍物12
    stone[12]->addFrame(QPixmap(":/Images/stone.png"));
    stone[13]=new QStone;//构建障碍物13
    stone[13]->addFrame(QPixmap(":/Images/stone.png"));
    stone[13]->setStoneType(1);//设置障碍物类型

    meteor = new QMeteor;//构建流星
    meteor->addFrame(QPixmap(":/Images/meteor.png"));//流星特效
    meteor->setMeteorType(1);//设置流星类型

    buffice = new QBuffIce;//构建冰冻Buff果实
    buffice->addFrame(QPixmap(":/Images/buffice.png"));//冰冻buff果实的特效
    buffice->setBuffType(1);//设置冰冻buff果实类型

    buffinvcb = new QBuffInvcb;//构建无敌Buff果实
    buffinvcb->addFrame(QPixmap(":/Images/buffinvcb.png"));//无敌buff果实的特效
    buffinvcb->setBuffType(1);//设置无敌buff果实类型

    buffaddscore = new QBuffAddScore;//构建加分Buff果实
    buffaddscore->addFrame(QPixmap(":/Images/buffaddscore.png"));//加分buff果实的特效
    buffaddscore->setBuffType(1);//设置加分buff果实类型

    buffdestroy = new QBuffDestroy;//构建毁灭Buff果实
    buffdestroy->addFrame(QPixmap(":/Images/buffdestroy_big.png"));//毁灭buff果实的特效
    buffdestroy->setBuffType(1);//设置毁灭buff果实类型


    gameover=new QGameBoard;//游戏结束产生游戏结束的界面
    gameover->addFrame(QPixmap(":/Images/gameover.png"));//Gameover图片
    gameover->setDestAndDelta(90,6.0);//最终停下的高度和移动的速度

    scoreBoard=new QGameBoard;//积分面板
    scoreBoard->setDestAndDelta(350.0,-10.0);//最终停下的高度和移动的速度

    rankBoard= new QGameBoard;//排行榜面板
    rankBoard->setDestAndDelta(350.0,-10.0);//最终停下的高度和移动的速度

    Elementlist.append(guide);//元素列表添加guide界面

    connect(fairy,SIGNAL(fairyDead()),this,SLOT(gameOver()));
                                    //仙女发出死的信号,mianwindow接收并作出Gameover反应
    connect(stone[0],SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //障碍物0(0、1是一组)发出加分的信号,mainwindow接收并作出总分增加的反应
    connect(stone[2],SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //障碍物2(2、3、4是一组)发出加分的信号,mainwindow接收并作出总分增加的反应
    connect(stone[5],SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //障碍物5(5、6是一组)发出加分的信号,mainwindow接收并作出总分增加的反应
    connect(stone[7],SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //障碍物7(7、8、9是一组)发出加分的信号,mainwindow接收并作出总分增加的反应
    connect(stone[10],SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //障碍物10(10、11、12、13是一组)发出加分的信号,mainwindow接收并作出总分增加的反应
    connect(meteor,SIGNAL(scoreAdd()),this,SLOT(gameScoreAdd()));
                                    //流星发出加分的信号,mainwindow接收并作出总分增加的反应

    connect(fairy,SIGNAL(fairyStrong()),this,SLOT(makeFairyStrong()));
                                    //仙女发出无敌的信号,mainwondow接收并作出使仙女无敌的反应
    connect(fairy,SIGNAL(addmanyscore()),this,SLOT(gameScoreAddMany()));
                                    //仙女发出加分的信号,mainwondow接收并作出游戏加许多分的反应
    connect(fairy,SIGNAL(destroyAll()),this,SLOT(deleteAllStones()));
                                    //仙女发出毁灭一切的信号,mainwondow接收并作出消除所有障碍物的反应
    connect(fairy,SIGNAL(addMyIce()),this,SLOT(addIce()));
                                    //仙女发出冰冻的信号,mainwondow接收并作出冰冻的反应

    connect(fairy,SIGNAL(buffIceDead()),this,SLOT(deleteBuffIce()));
                                    //仙女发出冰冻buff消失的信号,mainwondow接收并作出使冰冻buff消失的反应
    connect(fairy,SIGNAL(buffInvcbDead()),this,SLOT(deleteBuffInvcb()));
                                    //仙女发出无敌buff消失的信号,mainwondow接收并作出使无敌buff消失的反应
    connect(fairy,SIGNAL(buffAddScoreDead()),this,SLOT(deleteBuffAddScore()));
                                    //仙女发出加分buff消失的信号,mainwondow接收并作出使加分buff消失的反应
    connect(fairy,SIGNAL(buffDestroyDead()),this,SLOT(deleteBuffDestroy()));
                                    //仙女发出毁灭buff消失的信号,mainwondow接收并作出使毁灭buff消失的反应

    connect(gameover,SIGNAL(moveFinished()),this,SLOT(board1Stop()));
                                    //Gameover发出移动结束的信号,mainwindow接收并作出使之停下的反应
    connect(scoreBoard,SIGNAL(moveFinished()),this,SLOT(board2Stop()));
                                    //得分板发出移动结束的信号,nainwindow接收并作出使之停下的反应
    connect(btnQuit,SIGNAL(clicked()),this,SLOT(quit()));
                                    //quit键发出被点击的信号,mainwindow接收受并作出退出游戏的反应
    connect(btnPlay,SIGNAL(clicked()),this,SLOT(play()));
                                    //play键发出被点击的信号,mainwindow接收受并作出开始游戏的反应
    connect(btnReplay,SIGNAL(clicked()),this,SLOT(replay()));
                                    //replay键发出被点击的信号,mainwindow接收受并作出重新开始游戏的反应
    connect(btnRank,SIGNAL(clicked()),this,SLOT(rank()));
                                    //Rank键发出被点击的信号,mainwindow接收并作出rank()的反应

    connect(&timerBuffIce, SIGNAL(timeout()), this, SLOT(buffIceTimeIsOut()));
                                    //timerBuffIce发出计时结束的信号,mainwindow接收并作出冰冻buff消失的反应
    connect(&timerBuffIceBack, SIGNAL(timeout()), this, SLOT(buffIceBack()));
                                    //timerBuffIceBack发出计时结束信号,mainwindow接收并使冰冻buff回归
    connect(&timerBuffInvcb, SIGNAL(timeout()), this, SLOT(buffInvcbTimeIsOut()));
                                    //timerBuffInvcb发出计时结束的信号,mainwindow接收并作出无敌buff消失的反应
    connect(&timerBuffInvcbBack, SIGNAL(timeout()), this, SLOT(buffInvcbBack()));
                                    //timerBuffInvcbBack发出计时结束信号,mainwindow接收并使无敌buff回归
    connect(&timerBuffAddScore, SIGNAL(timeout()), this, SLOT(buffAddScoreTimeIsOut()));
                                    //timerBuffAddScore发出计时结束的信号,mainwindow接收并作出加分buff消失的反应
    connect(&timerBuffAddScoreBack, SIGNAL(timeout()), this, SLOT(buffAddScoreBack()));
                                    //timerBuffAddScoreBack发出计时结束信号,mainwindow接收并使加分buff回归
    connect(&timerBuffDestroy, SIGNAL(timeout()), this, SLOT(buffDestroyTimeIsOut()));
                                    //timerBuffDestroy发出计时结束的信号,mainwindow接收并作出毁灭buff消失的反应
    connect(&timerBuffDestroyBack, SIGNAL(timeout()), this, SLOT(buffDestroyBack()));
                                    //timerBuffDestroyBack发出计时结束信号,mainwindow接收并使毁灭buff回归

    connect(fairy, SIGNAL(fairyfly()), this,SLOT(flymusic()));
                                    //仙女发出上升的信号,mainwindow接收并作出播放飞行音效的反应
    connect(fairy, SIGNAL(fairyDead()), dieMusic, SLOT(play()));
                                    //仙女发出死亡的信号,mainwindow接收并作出播放死亡音效的反应
    connect(fairy, SIGNAL(fairyStrong()), BuffInvcbMusic, SLOT(play()));
                                    //仙女发出无敌的信号,mainwindow接收并作出播放无敌音效的反应
    connect(fairy, SIGNAL(addmanyscore()), BuffAddScoreMusic, SLOT(play()));
                                    //仙女发出加分的信号,mainwindow接收并作出播放加分音效的反应
    connect(fairy, SIGNAL(destroyAll()), BuffAddScoreMusic, SLOT(play()));
                                    //仙女发出毁灭的信号,mainwindow接收并作出播放毁灭音效的反应
    connect(fairy, SIGNAL(addMyIce()), BuffAddScoreMusic, SLOT(play()));
                                    //仙女发出冰冻的信号,mainwindow接收并作出播放冰冻音效的反应
    connect(this, SIGNAL(Gameover()),gameoverMusic, SLOT(play()));
                                    //仙女发出游戏结束的信号,mainwindow接收并作出播放游戏结束音效的反应

    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));//刷帧速度
    timer.start(20);//刷帧速度开始是20ms每帧
}

//飞行音效
void MainWindow::flymusic()
{
    if(flyMusic->state()==1)//每次开始播放音效
       flyMusic->stop();//播放音效停止
    flyMusic->play();//开始播放新的音效
}

//音乐与暂停
void MainWindow::createMusic()//创建音乐
{
    flyMusic =new QMediaPlayer();
    flyMusic->setMedia(QUrl("qrc:/Sounds/swing.mp3"));
    flyMusic->setVolume(30);
    dieMusic =new QMediaPlayer();
    dieMusic->setMedia(QUrl("qrc:/Sounds/Die.wav"));
    dieMusic->setVolume(40);
    BuffAddScoreMusic=new QMediaPlayer();
    BuffAddScoreMusic->setMedia(QUrl("qrc:/Sounds/scoreup.wav"));
    BuffAddScoreMusic->setVolume(40);
    BuffInvcbMusic=new QMediaPlayer();
    BuffInvcbMusic->setMedia(QUrl("qrc:/Sounds/buff.wav"));
    BuffInvcbMusic->setVolume(40);
    bgmMusic=new QMediaPlayer();
    bgmMusic->setMedia(QUrl("qrc:/Sounds/bgm.wav"));
    bgmMusic->setVolume(40);
    gameoverMusic=new QMediaPlayer();
    gameoverMusic->setMedia(QUrl("qrc:/Sounds/GameOver.wav"));
    gameoverMusic->setVolume(40);
}

void MainWindow:: pausegame()//游戏暂停
{
    gameStatus=GAME_PAUSEDTRUE;//游戏状态变为暂停
    for (QGameElement *e:Elementlist)//对于元素列表中的每一个元素
        e->setEnabled(false);//状态改为不可用
}

//buff回归
void MainWindow::buffIceBack()//冰冻buff回归
{
    timerBuffIceBack.stop();//计时结束
    Elementlist.append(buffice);//冰冻buff回归
    buffice->setRect(3000.0,600,100.0,70);//回归的位置
}

void MainWindow::buffDestroyBack()//毁灭buff回归
{
        timerBuffDestroyBack.stop();//计时结束
        Elementlist.append(buffdestroy);//毁灭buff回归
        buffdestroy->setRect(3000.0,400,100.0,70);//回归的位置
}

void MainWindow::buffInvcbBack()//无敌buff回归
{
    timerBuffInvcbBack.stop();//计时结束
    Elementlist.append(buffinvcb);//无敌buff回归
    buffinvcb->setRect(3000.0,300,100.0,70);//回归的位置
}

void MainWindow::buffAddScoreBack()//加分buff回归
{
    timerBuffAddScoreBack.stop();//计时结束
    Elementlist.append(buffaddscore);//加分buff回归
    buffaddscore->setRect(3000.0,500,100.0,70);//回归的位置

}

//buff时间结束
void MainWindow::buffIceTimeIsOut()//冰冻buff时间结束
{
        timerBuffIce.stop();//计时结束
        fairy->setBuff(0);//Buff状态置为0
        timer.start(20);//恢复20ms每帧
        fairy->clearAllFrame();//清除所有特效帧
        fairy->addFrame(QPixmap(":/Images/fairy1.png"));//普通状态仙女
        fairy->addFrame(QPixmap(":/Images/fairy2.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy3.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy4.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy5.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy6.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy7.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy8.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy9.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy10.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy11.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy12.png"));//同理
        fairy->addFrame(QPixmap(":/Images/fairy13.png"));//同理
}

void MainWindow::buffDestroyTimeIsOut()//毁灭buff时间结束
{
    timerBuffDestroy.stop();//计时结束
    fairy->setBuff(0);//Buff状态置为0
    fairy->setInvcb(0);//无敌状态置为0
    fairy->clearAllFrame();//清除所有特效帧
    fairy->addFrame(QPixmap(":/Images/fairy1.png"));//普通状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy2.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy3.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy4.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy5.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy6.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy7.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy8.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy9.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy10.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy11.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy12.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy13.png"));//同理

    for(int x=0; x<14; x++)
    {
        stone[x]->clearAllFrame();//清除所有stone的帧
    }
    meteor->clearAllFrame();//清除流星的帧

    for(int x=0; x<14; x++)
    {
        stone[x]->addFrame(QPixmap(":/Images/stone.png"));//添加石头的帧
    }
    meteor->addFrame(QPixmap(":/Images/meteor.png"));//添加流行的帧

    stone[0]->setRect(1920.0,150,100.0,70.0);//障碍物0的出现初始位置xy和长宽
    stone[1]->setRect(1920.0,600,100.0,70.0);//障碍物1的出初始现位置xy和长宽

    stone[2]->setRect(2300.0,125,100.0,70.0);//障碍物2的出现初始位置xy和长宽
    stone[3]->setRect(2300.0,400,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[4]->setRect(2300.0,650,100.0,70.0);//障碍物3的出现初始位置xy和长宽

    stone[5]->setRect(2680.0,300,100.0,70.0);//障碍物4的出现初始位置xy和长宽
    stone[6]->setRect(2680.0,500,100.0,70.0);//障碍物5的出现初始位置xy和长宽

    stone[7]->setRect(3060.0,100,100.0,70.0);//障碍物6的出现初始位置xy和长宽
    stone[8]->setRect(3060.0,400,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[9]->setRect(3060.0,600,100.0,70.0);//障碍物6的出现初始位置xy和长宽

    stone[10]->setRect(3440.0,100,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[11]->setRect(3440.0,300,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[12]->setRect(3440.0,600,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[13]->setRect(3440.0,800,100.0,70.0);//障碍物7的出现初始位置xy和长宽

    meteor->setRect(2000,450,100,70);//流星出现的初始位置xy和长宽

}

void MainWindow::buffInvcbTimeIsOut()//无敌buff时间结束
{
    timerBuffInvcb.stop();//计时结束
    fairy->setBuff(0);//Buff状态置为0
    fairy->setInvcb(0);//无敌状态置为0
    fairy->clearAllFrame();//清除所有特效帧
    fairy->addFrame(QPixmap(":/Images/fairy1.png"));//普通状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy2.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy3.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy4.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy5.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy6.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy7.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy8.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy9.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy10.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy11.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy12.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy13.png"));//同理
}

void MainWindow::buffAddScoreTimeIsOut()//加分buff时间结束
{
    timerBuffAddScore.stop();//计时结束
    fairy->setBuff(0);//Buff状态置为0
    fairy->clearAllFrame();//清除所有特效帧
    fairy->addFrame(QPixmap(":/Images/fairy1.png"));//普通状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy2.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy3.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy4.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy5.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy6.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy7.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy8.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy9.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy10.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy11.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy12.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy13.png"));//同理
}

//buff特效
void MainWindow::changeStyle1()//无敌特效
{
    fairy->clearAllFrame();//清除所有普通帧
    fairy->addFrame(QPixmap(":/Images/fairy14.png"));//无敌状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy15.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy16.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy17.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy18.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy19.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy20.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy21.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy22.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy23.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy24.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy25.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy26.png"));//同理
}

void MainWindow::changeStyle2()//加分特效
{
    fairy->clearAllFrame();//清除普通状态
    fairy->addFrame(QPixmap(":/Images/fairy40.png"));//无敌状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy41.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy42.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy43.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy44.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy45.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy46.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy47.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy48.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy49.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy50.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy51.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy52.png"));//同理
}

void MainWindow::changeStyle3()//毁灭特效
{
    fairy->clearAllFrame();//清除普通状态
    fairy->addFrame(QPixmap(":/Images/fairy27.png"));//毁灭状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy28.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy29.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy30.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy31.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy32.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy33.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy34.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy35.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy36.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy37.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy38.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy39.png"));//同理
}

void MainWindow::changeStyle4()//冰冻特效
{
    fairy->clearAllFrame();//清除普通状态
    fairy->addFrame(QPixmap(":/Images/fairy53.png"));//冰冻状态仙女
    fairy->addFrame(QPixmap(":/Images/fairy54.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy55.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy56.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy57.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy58.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy59.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy60.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy61.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy62.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy63.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy64.png"));//同理
    fairy->addFrame(QPixmap(":/Images/fairy65.png"));//同理
}


MainWindow::~MainWindow()
{
}

void MainWindow::gameOver()//游戏结束
{
    int i,j,temp;
    FILE *f;
    f=fopen("a.txt","rt");
    for(i=0;i<4;i++){
     fscanf(f,"%d",&scorerank[i]);
    }
    fclose(f);
    emit Gameover();//发出gameover信号
    timer.start(20);//20s每帧
    gameStatus=GAME_PAUSED;//游戏状态变为暂停
    lcdScore->setVisible(false);//七段译码管分数变为不可见
    for (QGameElement* e:Elementlist)//对于元素列表中的每一个元素
        e->setEnabled(false);//状态改为不可用
    Elementlist.clear();//清除元素列表所有元素
    gameover->setRect(780,-50.0,256.0,57.0);//放置Gameover
    gameover->setEnabled(true);//Gameover状态为可用
    Elementlist.append(gameover);//元素列表添加Gameover

    //各种buff更换为透明图片
    buffaddscore->clearAllFrame();
    buffaddscore->addFrame(QPixmap(":/Images/ground.png"));
    buffdestroy->clearAllFrame();
    buffdestroy->addFrame(QPixmap(":/Images/ground.png"));
    buffice->clearAllFrame();
    buffice->addFrame(QPixmap(":/Images/ground.png"));
    buffinvcb->clearAllFrame();
    buffinvcb->addFrame(QPixmap(":/Images/ground.png"));

    f=fopen("a.txt","wt");

    scorerank[3]=score;//本局得分录入,比较并判断是否能排进前三名
    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            if(scorerank[i]<scorerank[j]){
                temp=scorerank[i];
                scorerank[i]=scorerank[j];
                scorerank[j]=temp;
            }
        }
    }
    for(i=0;i<4;i++)
    {

      fprintf(f,"%d ",scorerank[i]);

    }
    fclose(f);
    for(int x=0; x<3; x++)//判断最高分
    {
        if(scorerank[x]>bestscore)
        {
            bestscore=scorerank[x];
        }
    }
}

void MainWindow::gameScoreAdd()//加分
{
    score++;//分数+1
    lcdScore->display(QString("%1").arg(score,3,10,QChar('0')));
               //七段译码管示数+1，显示score，三位显示，十进制，0补充空位
}

//消除buff果实
void MainWindow::deleteBuffDestroy()//消除毁灭buff果实
{
    Elementlist.removeOne(buffdestroy);//从元素列表中消除
    timerBuffDestroyBack.start(60000);//60s之后再出现
}

void MainWindow::deleteBuffInvcb()//消除无敌buff果实
{
    Elementlist.removeOne(buffinvcb);//从元素列表中消除
    timerBuffInvcbBack.start(30000);//30s之后再出现
}

void MainWindow::deleteBuffAddScore()//消除加分buff果实
{
    Elementlist.removeOne(buffaddscore);//从元素列表中消除
    timerBuffAddScoreBack.start(10000);//10s之后再出现
}

void MainWindow::deleteBuffIce()//消除冰冻buff果实
{
    Elementlist.removeOne(buffice);//从元素列表中消除
    timerBuffIceBack.start(10000);//10s之后再出现
}

//buff产生的效果
void MainWindow::deleteAllStones()//消除所有障碍物
{
    fairy->setBuff(1);//buff状态置为1
    fairy->setInvcb(1);//无敌状态置为1
    changeStyle3();//改变形态3

    for(int x=0; x<14; x++)//所有stone清除帧
    {
        stone[x]->clearAllFrame();
    }
    meteor->clearAllFrame();//流星清除帧  

    stone[0]->addFrame(QPixmap(":/Images/explode1.png"));//所有stone添加帧
    stone[1]->addFrame(QPixmap(":/Images/explode2.png"));
    stone[2]->addFrame(QPixmap(":/Images/explode3.png"));
    stone[3]->addFrame(QPixmap(":/Images/explode4.png"));
    stone[4]->addFrame(QPixmap(":/Images/explode1.png"));
    stone[5]->addFrame(QPixmap(":/Images/explode2.png"));
    stone[6]->addFrame(QPixmap(":/Images/explode3.png"));
    stone[7]->addFrame(QPixmap(":/Images/explode4.png"));
    stone[8]->addFrame(QPixmap(":/Images/explode1.png"));
    stone[9]->addFrame(QPixmap(":/Images/explode2.png"));
    stone[10]->addFrame(QPixmap(":/Images/explode3.png"));
    stone[11]->addFrame(QPixmap(":/Images/explode4.png"));
    stone[12]->addFrame(QPixmap(":/Images/explode1.png"));
    stone[13]->addFrame(QPixmap(":/Images/explode2.png"));
    meteor->addFrame(QPixmap(":/Images/explode2.png"));

    for(int x=0; x<14; x++)//加14分
    {
        gameScoreAdd();
    }
    timerBuffDestroy.start(5000);//5s的毁灭buff
}

void MainWindow::makeFairyStrong()//仙女无敌
{
    fairy->setBuff(1);//仙女的Buff状态置为1
    fairy->setInvcb(1);//无敌状态置为1
    changeStyle1();//改变形态1
    timerBuffInvcb.start(10000);//10s的无敌buff
}

void MainWindow::gameScoreAddMany()//加许多分
{
    fairy->setBuff(1);//仙女的Buff状态置为1
    changeStyle2();//改变形态2
    for(int x=0; x<10; x++)//加10分
    {
        gameScoreAdd();
    }
    timerBuffAddScore.start(1500);//1.5s的加分buff
}

void MainWindow::addIce()//冰冻
{
    fairy->setBuff(1);//仙女的Buff状态置为1
    changeStyle4();//改变形态4
    timer.start(35);//减速到35ms每帧
    timerBuffIce.start(8000);//8s的冰冻buff
}

//游戏结束界面
void MainWindow::board1Stop()//计分板
{
    btnQuit->setVisible(false);//quit键不可见
    scoreBoard->clearAllFrame();//清除所有帧
    QPixmap pixmap(":/Images/scoreboard.png");//板子
    QPixmap pixmap2;//奖牌
    QPainter painter(&pixmap);
    if (score<50)//分数<50为铜牌
        pixmap2.load(":/Images/medal2.png");
    else if (score<150)//50<分数<150为银牌
        pixmap2.load(":/Images/medal1.png");
    else//分数>150为金牌
        pixmap2.load(":/Images/medal0.png");
    painter.drawPixmap(85,85,pixmap2);//显示奖牌
    painter.setFont(QFont("Script MT Bold",15,70));//显示分数等的字体、字号、粗细
    painter.setPen(Qt::black);//显示的颜色
    painter.drawText(315,105,QString("%1").arg(score,3,10,QChar('0')));
                                //分数显示的xy位置,显示的内容,显示的数位,进制数,空位的数
    painter.drawText(315,170,QString("%1").arg(bestscore,3,10,QChar('0')));
                                //BEST的xy位置和内容
    scoreBoard->addFrame(pixmap);//增加帧
    scoreBoard->setRect(730,900,300.0,153.0);//板子的位置和长宽
    scoreBoard->setEnabled(true);//状态为可用
    Elementlist.append(scoreBoard);//元素名单增加板子元素
}

void MainWindow::board2Stop()//排名键
{
    btnPlay->setVisible(false);//play键不可见
    btnQuit->setVisible(false);//quit键不可见
    btnReplay->setVisible(true);//replay键可见
    btnRank->setVisible(true);//排名键可见
}

void MainWindow::replay()//返回主界面
{
    btnPlay->setVisible(true);//play键可见
    btnQuit->setVisible(true);//quit键可见
    btnReplay->setVisible(false);//replay键不可见
    btnRank->setVisible(false);//排名键不可见
    gameStatus=GAME_OVER;//游戏状态为游戏结束
    Elementlist.clear();//清空元素
    Elementlist.append(guide);//元素列表增加开始界面
}

void MainWindow::play()
{
    btnPlay->setVisible(false);//play键不可见
    btnQuit->setVisible(false);//quit键不可见
    QStone::vx=-6;
    lcdScore->setVisible(true);//七段译码管分数变为为可见
    lcdScore->display("000");//初始显示为000
    fairy->setRect(400.0,60.0,30.0,30.0);//放置仙女的初始xy位置和长宽
    fairy->setVy(2.0);//设置仙女下落的初速度为2

    //最初出现的障碍物
    intr->setRect(1920,150,100.0,70);

    stone[0]->setRect(1920.0,150,100.0,70.0);//障碍物0的出现初始位置xy和长宽
    stone[1]->setRect(1920.0,600,100.0,70.0);//障碍物1的出初始现位置xy和长宽

    stone[2]->setRect(2300.0,125,100.0,70.0);//障碍物2的出现初始位置xy和长宽
    stone[3]->setRect(2300.0,400,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[4]->setRect(2300.0,650,100.0,70.0);//障碍物3的出现初始位置xy和长宽

    stone[5]->setRect(2680.0,300,100.0,70.0);//障碍物4的出现初始位置xy和长宽
    stone[6]->setRect(2680.0,500,100.0,70.0);//障碍物5的出现初始位置xy和长宽

    stone[7]->setRect(3060.0,100,100.0,70.0);//障碍物6的出现初始位置xy和长宽
    stone[8]->setRect(3060.0,400,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[9]->setRect(3060.0,600,100.0,70.0);//障碍物6的出现初始位置xy和长宽

    stone[10]->setRect(3440.0,100,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[11]->setRect(3440.0,300,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[12]->setRect(3440.0,600,100.0,70.0);//障碍物7的出现初始位置xy和长宽
    stone[13]->setRect(3440.0,800,100.0,70.0);//障碍物7的出现初始位置xy和长宽

    meteor->setRect(8000,450,100,70);//流星出现的初始位置xy和长宽

    buffdestroy->setRect(4800.0,250,100.0,70);//毁灭buff果实出现的位置xy和长宽
    buffinvcb->setRect(4500.0,250,100.0,70);//无敌buff果实的出现位置xy和长宽
    buffaddscore->setRect(3000.0,500,100.0,70);//加分buff果实的出现位置xy和长宽
    buffice->setRect(3500,500,100,70);//冰冻buff果实出现的位置xy和长宽

    Elementlist.clear();//元素列表清空
    Elementlist.append(intr);//元素列表增加说明
    Elementlist.append(fairy);//元素列表增加仙女
    Elementlist.append(stone[0]);//元素列表增加障碍物0
    Elementlist.append(stone[1]);//元素列表增加障碍物1
    Elementlist.append(stone[2]);//元素列表增加障碍物2
    Elementlist.append(stone[3]);//元素列表增加障碍物3
    Elementlist.append(stone[4]);//元素列表增加障碍物4
    Elementlist.append(stone[5]);//元素列表增加障碍物5
    Elementlist.append(stone[6]);//元素列表增加障碍物6
    Elementlist.append(stone[7]);//元素列表增加障碍物7
    Elementlist.append(stone[8]);//元素列表增加障碍物8
    Elementlist.append(stone[9]);//元素列表增加障碍物9
    Elementlist.append(stone[10]);//元素列表增加障碍物10
    Elementlist.append(stone[11]);//元素列表增加障碍物10
    Elementlist.append(stone[12]);//元素列表增加障碍物10
    Elementlist.append(stone[13]);//元素列表增加障碍物10
    Elementlist.append(meteor);//元素列表增加流星
    Elementlist.append(buffdestroy);//元素列表增加毁灭buff果实
    Elementlist.append(buffinvcb);//元素列表增加无敌buff果实
    Elementlist.append(buffaddscore);//元素列表增加加分buff果实
    Elementlist.append(buffice);//元素列表增加冰冻buff果实

    buffaddscore->clearAllFrame();
    buffaddscore->addFrame(QPixmap(":/Images/buffaddscore.png"));
    buffdestroy->clearAllFrame();
    buffdestroy->addFrame(QPixmap(":/Images/buffdestroy_big.png"));
    buffice->clearAllFrame();
    buffice->addFrame(QPixmap(":/Images/buffice.png"));
    buffinvcb->clearAllFrame();
    buffinvcb->addFrame(QPixmap(":/Images/buffinvcb.png"));

    for (QGameElement *e:Elementlist)//对于元素列表中的每一个元素
        e->setEnabled(true);//状态改为可用
    score=0;//得分初始化为0
    gameStatus=GAME_PLAYING;//游戏状态改为游戏中
}

void MainWindow::quit()
{
    exit(0);
}

void MainWindow::rank()//排名
{

    gameover->setEnabled(false);//游戏结束界面无效
    scoreBoard->setEnabled(false);//计分板无效
    Elementlist.clear();//元素列表清空
    rankBoard->clearAllFrame();//清除所有帧
    QPixmap pixmap(":/Images/rankboard.png");//板子
    QPainter painter(&pixmap);//生成qpainter

    painter.setFont(QFont("Script MT Bold",28,70));//显示分数等的字体、字号、粗细
    painter.setPen(Qt::black);//显示的颜色

    //排名分数显示相对于板子的xy位置,显示的内容,显示的数位,进制数,空位的数
    painter.drawText(245,130,QString("%1").arg(scorerank[0],3,10,QChar('0')));
    painter.drawText(244,266,QString("%1").arg(scorerank[1],3,10,QChar('0')));
    painter.drawText(245,400,QString("%1").arg(scorerank[2],3,10,QChar('0')));

    rankBoard->addFrame(pixmap);//增加板子元素
    rankBoard->setRect(700.0,70.0,500.0,500.0);//板子的位置和长宽
    rankBoard->setEnabled(true);//状态为可用
    Elementlist.append(rankBoard);//元素名单增加板子元素
}

//鼠标点击
void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标点击
{
    if (event->button()==Qt::LeftButton)//鼠标左键点击
    {
        if (gameStatus==GAME_PLAYING)//游戏状态为游戏中时
            fairy->fairyUp();//鼠标左键点击则仙女上升(fairyup()函数)
        else if (gameStatus==GAME_PAUSEDTRUE) //游戏处于暂停状态时
            {
                btnQuit->setVisible(false);
                btnReplay->setVisible(false);
                gameStatus=GAME_PLAYING;//游戏状态改为游戏中
                for (QGameElement *e:Elementlist)//对于元素列表中的每一个元素
                    e->setEnabled(true);//状态改为可用
            }
    }
    //右键暂停
    if (event->button()==Qt::RightButton&&gameStatus==GAME_PLAYING)
    {
        pausegame();
        btnQuit->setVisible(true);
        btnReplay->setVisible(true);
    }

}

void MainWindow::paintEvent(QPaintEvent *)//绘制
{
    QPainter painter(this);//QPainter对象
    if (!(gameStatus==GAME_OVER))//游戏状态不是游戏结束
        painter.drawPixmap(0,0,pixmapBkgnd);//绘制背景图
    for (QGameElement* e:Elementlist)//对于所有元素列表中的元素e
    {
        e->logic();//进行逻辑判断
        e->draw(&painter);//绘制元素
    }
}
