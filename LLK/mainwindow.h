#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDebug>
#include <QMainWindow>
#include"entergamepanel.h"
#include"settingpanel.h"
#include"introductionpanel.h"
#include"helppanel.h"
#include"rankingpanel.h"
#include"gamemediauitl.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    GameMediaUitl* getGameMediaUtil();
    SettingPanel* getSettingPanel();
    void initEvents();
    ~MainWindow();

private slots:
    void on_startBtn_clicked();

    void on_gameIntronduceBtn_clicked();

    void on_gameExitBtn_clicked();

    void on_gameSettingBtn_clicked();

    void on_gameHelpBtn_clicked();

    void on_rankingBtn_clicked();

private:
    //主页的UI
    Ui::MainWindow *ui;
    //进入游戏的面板
    EnterGamePanel* enterGamePanel=NULL;
    //游戏设置的面板
    SettingPanel* settingPanel = NULL;
    //游戏介绍面板
    IntroductionPanel* introductionPanel =NULL;
    //游戏帮助面板
    HelpPanel* helpPanel = NULL;
    //游戏排行榜的面板
    RankingPanel* rankingPanel = NULL;
    //游戏多媒体类
    GameMediaUitl* gameMediaUtil = NULL;
};


#endif // MAINWINDOW_H
