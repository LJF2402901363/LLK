#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->gameMediaUtil = new GameMediaUitl();
    initEvents();
}
 void MainWindow::initEvents(){
     //给开始按钮添加点击事件
      connect(this->ui->startBtn,&QPushButton::clicked,this,on_startBtn_clicked);
      //给结束按钮添加点击事件
      connect(this->ui->gameExitBtn,&QPushButton::clicked,this,on_gameExitBtn_clicked);
      //给游戏设置按钮添加点击事件
      connect(this->ui->gameSettingBtn,&QPushButton::clicked,this,on_gameSettingBtn_clicked);
      //给游戏介绍按钮添加点击事件
      connect(this->ui->gameIntronduceBtn,&QPushButton::clicked,this,on_gameIntronduceBtn_clicked);
      //给游戏帮助按钮添加点击事件
      connect(this->ui->gameHelpBtn,&QPushButton::clicked,this,on_gameHelpBtn_clicked);
      //给游戏排行榜按钮添加点击事件
      connect(this->ui->rankingBtn,&QPushButton::clicked,this,on_rankingBtn_clicked);

 }
 GameMediaUitl* MainWindow::getGameMediaUtil(){
     return this->gameMediaUtil;
 }

MainWindow::~MainWindow()
{
    delete ui;
    delete this->enterGamePanel;
    delete this->helpPanel;
    delete this->introductionPanel;
}

void MainWindow::on_startBtn_clicked()
{
    if(this->enterGamePanel==NULL){
         this->enterGamePanel = new EnterGamePanel(this,nullptr);
    }
    //隐藏主窗口
   this->hide();
    //显示进入游戏的窗口
  this->enterGamePanel->show();

}

void MainWindow::on_gameIntronduceBtn_clicked()
{

    if(this->introductionPanel == NULL){
        this->introductionPanel = new IntroductionPanel(this,nullptr);
    }
     this->introductionPanel->show();
     //隐藏主窗口
     this->hide();
}

void MainWindow::on_gameExitBtn_clicked()
{
    this->close();
}

void MainWindow::on_gameSettingBtn_clicked()
{
    if(this->settingPanel == NULL){
        this->settingPanel = new SettingPanel(this,nullptr);
    }
    //显示进入设置的窗口
  this->settingPanel->show();
}

void MainWindow::on_gameHelpBtn_clicked()
{
    if(this->helpPanel == NULL){
        this->helpPanel = new HelpPanel(this,NULL);
    }
    //隐藏主窗口
   this->hide();
    //显示帮助的窗口
  this->helpPanel->show();
}

void MainWindow::on_rankingBtn_clicked()
{
    if(this->rankingPanel == NULL){
        this->rankingPanel = new RankingPanel(this,NULL);
    }
    //隐藏主窗口
   this->hide();
    //显示帮助的窗口
  this->rankingPanel->show();
}
SettingPanel* MainWindow::getSettingPanel(){
    if(this->settingPanel == NULL){
        this->settingPanel = new SettingPanel(this,nullptr);
    }
   return this->settingPanel;
}
