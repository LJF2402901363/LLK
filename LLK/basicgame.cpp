#include "basicgame.h"
#include"entergamepanel.h"
#include"ui_basicgame.h"
#include<QMediaPlayer>
#include"mainwindow.h"
#include<QDebug>

BasicGame::BasicGame(EnterGamePanel* enterGamePanel,GameController* gameController,QWidget *parent) :
    QWidget(parent),basicUi(new Ui::BasicGame)
{
    this->basicUi->setupUi(this);
    this->gameView= new GameView(this,gameController,this);
    this->player = new QMediaPlayer();
    this->playerList = new  QMediaPlaylist();
    this->gameView->move(20,20);
    this->gameView->resize(690,610);
    this->enterGamePanel = enterGamePanel;
    this->gameMediaUtil = enterGamePanel->getGameMediaUtil();
    this->timer = new QTimer();
    this->bgmThread = new PlayerThread(this->enterGamePanel->getGameMediaUtil()->getMediaBgmPlayer());
    this->songThread =new PlayerThread(this->enterGamePanel->getGameMediaUtil()->getMediaSongPlayer());
    initEvents();
    this->move(100,10);

}
void BasicGame::initGame(){
    this->gameView->initGame();

}

BasicGame::~BasicGame(){
    delete this->basicUi;
    delete this->timer;
}
 void BasicGame::setProgressBarValue(int value){
     if(value >0){
        this->basicUi->progressBar->setValue(value);
         if(value == 30){
   this->basicUi->progressBar->setStyleSheet("border:1px solid #FFFFFF;background:red;text-align: center;color:rgb(28, 161, 4);border-radius:10px;");
      }
     }else if(value == 0){
          this->basicUi->progressBar->setValue(value);
         this->basicUi->startGameBtn->setEnabled(true);
     }

 }

 void   BasicGame::setMaxProgressBarRange(int maxValue){
   this->progressBarValue = maxValue;
   this->basicUi->progressBar->setRange(0,maxValue);
   this->basicUi->progressBar->setValue(maxValue);
   this->basicUi->label->setText(QString::number(maxValue));
  }
void  BasicGame::initEvents(){
    //给进度条注册事件，当进度条发生变化的时候标签的值也发生变化
  connect(this->basicUi->progressBar,&QProgressBar::valueChanged,this,progressBar_valueChanged);
    //给结束游戏按钮添加点击事件
    connect(this->basicUi->endGameBtn,&QPushButton::clicked,this,endGameBtn_clicked);
    //给开始游戏按钮添加点击事件
   connect(this->basicUi->startGameBtn,&QPushButton::clicked,this,startGameBtn_clicked);
    //给提示按钮添加点击事件
   connect(this->basicUi->hitTextBtn,&QPushButton::clicked,this,hitTextBtn_clicked);
    //给重新开始游戏按钮添加点击事件
    connect(this->basicUi->restartGameBtn,&QPushButton::clicked,this,restartGameBtn_clicked);
    //给重排按钮添加点击事件
    connect(this->basicUi->rescheduleBtn,&QPushButton::clicked,this,rescheduleBtn_clicked);
    //给帮助按钮添加点击事件
   connect(this->basicUi->helpBtn,&QPushButton::clicked,this,helpBtn_clicked);
    //给暂停游戏按钮添加点击事件
  connect(this->basicUi->pauseGameBtn,&QPushButton::clicked,this,pauseGameBtn_clicked);
  //给游戏设置按钮添加点击事件
connect(this->basicUi->settingBtn,&QPushButton::clicked,this,settingBtn_clicked);

  //给时钟超时每秒钟设置一个事件
    connect(this->timer,&QTimer::timeout,this,[=](){
        this->setProgressBarValue(this->progressBarValue--);
    });
}


 void BasicGame::closeEvent(QCloseEvent *event){
     if(this->enterGamePanel!=NULL){
         this->enterGamePanel->show();
     }
     this->close();
 }

void BasicGame::progressBar_valueChanged(int value)
{

    this->basicUi->label->setText(QString::number(value));
}

void BasicGame::endGameBtn_clicked()
{
  if(enterGamePanel!= NULL){
      this->enterGamePanel->show();
  }
  this->close();
  this->stopSong();

}

void BasicGame::startGameBtn_clicked()
{
  if(this->progressBarValue > 0){
      this->gameView->setIsGameStart(true);
      this->timer->start(1000);
        //禁用开始游戏按钮
      this->basicUi->startGameBtn->setEnabled(false);
  }
    this->startSong();

}
void BasicGame::rescheduleBtn_clicked(){
    //重新排列布局
    this->gameView->rescheduleLayout();

}

void BasicGame::pauseGameBtn_clicked()
{
    if( this->gameView->getIsGameStart() == false){
        return;
    }
   if(QString::compare(this->basicUi->pauseGameBtn->text(),QString("暂停游戏"))== 0){
       this->timer->stop();
       this->basicUi->pauseGameBtn->setText(QString("继续游戏"));
   }else{
        this->basicUi->pauseGameBtn->setText(QString("暂停游戏"));
        this->timer->start(1000);
   }

}

void BasicGame::hitTextBtn_clicked()
{

}

void BasicGame::restartGameBtn_clicked()
{
    int maxValue = this->basicUi->progressBar->maximum();
  if(maxValue > 0){
      this->progressBarValue = maxValue;
      this->timer->stop();
      this->basicUi->progressBar->setValue(maxValue);
      this->basicUi->startGameBtn->setEnabled(true);
      this->basicUi->pauseGameBtn->setText(QString("暂停游戏"));
      this->basicUi->scoreLabel->setText("0");
      this->gameView->setIsGameStart(false);
      this->gameView->initGame();
      this->gameView->update();
  }
}

void BasicGame::settingBtn_clicked()
{
   if(this->settingPanel == NULL){
       this->settingPanel =this->enterGamePanel->getMainWindow()->getSettingPanel();

   }
   this->settingPanel->show();
}

void BasicGame::helpBtn_clicked()
{

}


void BasicGame::setScore(int score){
    this->score +=score;
    this->basicUi->scoreLabel->setText(QString::number(this->score));
}
void BasicGame::startBgm(){
    bool isPlayBgm =  this->enterGamePanel->getGameMediaUtil()->getIsPlayBgm();
   if(isPlayBgm){
       this->bgmThread->setIsRunning(true);
       this->bgmThread->start();
   }


}
void BasicGame::startSong(){
     bool isPlaySong = this->enterGamePanel->getGameMediaUtil()->getIsPlaySong();
    qDebug()<<"播放音乐："<<isPlaySong;
     if(isPlaySong){
        this->songThread->setIsRunning(true);
        this->songThread->start();
     }

}
void BasicGame::stopBgm(){
    this->bgmThread->setIsRunning(false);
    this->bgmThread->quit();
}
void BasicGame::stopSong(){
    this->songThread->setIsRunning(false);
    this->songThread->quit();
}
