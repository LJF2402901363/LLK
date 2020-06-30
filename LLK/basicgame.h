#ifndef BASICGAME_H
#define BASICGAME_H
#include<QCloseEvent>
#include <QWidget>
#include<QProgressBar>
#include<QString>
#include<QTimer>
#include"gameview.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"gameglobalconstants.h"
#include"gamemediauitl.h"
#include"settingpanel.h"
#include"playerthread.h"
class EnterGamePanel;

namespace Ui {
class BasicGame;
}
class BasicGame : public QWidget
{
 Q_OBJECT
public:

    explicit BasicGame(EnterGamePanel* enterGamePanel,GameController* gameController = NULL,QWidget *parent = nullptr);
    ~BasicGame();
    //初始化游戏
    void initGame();
    //加载游戏音频
    void loadMediaFile();
    void closeEvent(QCloseEvent *event);
    //设置进度条的值
    void setProgressBarValue(int value);
    //设置进度条的范围
   virtual  void  setProgressBarRange() = 0;
    //设置积分
    void setScore(int score);
    //给控件注册事件监听
    void initEvents();
    //开始背景音乐
    void startSong();
    //开始游戏音效
    void startBgm();
     //停止游戏音效
    void stopBgm();

      //停止背景音乐
    void stopSong();
protected:
    //时间进度条的剩余时间
 int progressBarValue = 0;
 //设置进度条的范围[minValue,maxValue]
 void  setMaxProgressBarRange(int maxValue);

signals:
private slots:
    void progressBar_valueChanged(int value);
    void endGameBtn_clicked();
    void startGameBtn_clicked();
    void pauseGameBtn_clicked();
    void hitTextBtn_clicked();
    void restartGameBtn_clicked();
    void rescheduleBtn_clicked();
    void settingBtn_clicked();
    void helpBtn_clicked();

private:
  Ui::BasicGame* basicUi;
  //模式窗口的界面
  EnterGamePanel* enterGamePanel = NULL;
  //定时器
  QTimer* timer ;
  //游戏控制器
  //积分
  int score = 0;
  GameView* gameView = NULL;
  //多媒体播放器
  QMediaPlayer* player = NULL;
  //多媒体列表
  QMediaPlaylist* playerList = NULL;
  //多媒体设置
  GameMediaUitl* gameMediaUtil = NULL;
  //设置面板
  SettingPanel* settingPanel = NULL;
  //播放背景音乐的线程
  PlayerThread* bgmThread = NULL;
  //播放游戏音效的线程
  PlayerThread* songThread = NULL;
};

#endif // BASICGAME_H
