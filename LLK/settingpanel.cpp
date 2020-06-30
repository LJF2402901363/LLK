#include "settingpanel.h"
#include"ui_settingpanel.h"
#include"mainwindow.h"
#include<QDebug>
SettingPanel::SettingPanel( MainWindow* mainWindow ,QWidget *parent) : QWidget(parent),ui(new Ui::SettingPanel)
{
   this->mainWindow = mainWindow;
   this->gameMediaUitl = mainWindow->getGameMediaUtil();
  this->ui->setupUi(this);
  this->ui->openBgmBtn->setChecked(true);
   this->setWindowTitle("游戏设置");
   loadSettings();
   initEvents();

}
void SettingPanel::initEvents(){
    //给开启背景音乐添加点击事件
    connect(this->ui->openBgmBtn,&QRadioButton::clicked,this,openBgmBtn_clicked);
    //给关闭游戏背景音乐添加点击事件
    connect(this->ui->closeBgmBtn,&QRadioButton::clicked,this,closeBgmBtn_clicked);
    //给返回按钮添加事件监听
    connect(this->ui->returnBtn,&QPushButton::clicked,this,returnBtn_clicked);
    //给一键恢复默认数据按钮添加事件监听
    connect(this->ui->resetSettingBtn,&QPushButton::clicked,this,resetSetting_onlicked);
  //给选择游戏音效添加事件监听
    connect(this->ui->soundsCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(soundsCombox_currentIndexChanged()));

}

void SettingPanel::loadSettings(){
    this->ui->soundsCombox->addItem(QString("关闭"));
    int size = this->gameMediaUitl->getBgmPlayerList()->count();
    for(int i = 0 ; i < size;i++){
          QString qstr("音效");
          QString s ;
          s= s.asprintf("%d",i+1);
           qstr = qstr.append(s);
          this->ui->soundsCombox->addItem(qstr);
    }
}

void SettingPanel::closeEvent(QCloseEvent *event){
    this->close();
}

SettingPanel::~SettingPanel(){
  delete this->ui;
}


void SettingPanel::openBgmBtn_clicked(){
    this->gameMediaUitl->setIsPlaySong(true);
    srand((int)time(NULL));
    //在在两首歌中随机切换
    this->gameMediaUitl->setCurrSongIndex(rand()%2);
}
void SettingPanel::closeBgmBtn_clicked(){
    this->gameMediaUitl->setIsPlaySong(false);
}


void SettingPanel::returnBtn_clicked(){
    this->close();
}
void SettingPanel::resetSetting_onlicked(){
    this->ui->openBgmBtn->setChecked(true);
    this->ui->soundsCombox->setCurrentIndex(0);
    this->mainWindow->getGameMediaUtil()->setIsPlayBgm(true);
    this->mainWindow->getGameMediaUtil()->setIsPlaySong(false);
}



void SettingPanel::soundsCombox_currentIndexChanged()
{

    //设置游戏音效
    int  index =this->ui->soundsCombox->currentIndex();
    if(index = 0){
       this->gameMediaUitl->setIsPlayBgm(false);
    }else{
       this->gameMediaUitl->setIsPlayBgm(true);
       this->gameMediaUitl->setCurrBgmIndex(index -1);
    }
}
