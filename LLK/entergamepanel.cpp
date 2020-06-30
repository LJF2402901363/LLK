#include "entergamepanel.h"
#include"mainwindow.h"

EnterGamePanel::EnterGamePanel(MainWindow* mainWindow,QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("游戏模式界面");
    this->m_parent = mainWindow;
    this->gameMediaUtil = mainWindow->getGameMediaUtil();
    this->layout = new QVBoxLayout();
    this->basicModelBtn = new QPushButton("基础模式",this);
    this->reisureModelBtn = new QPushButton("休闲模式",this);
    this->aboutModelBtn = new QPushButton("关于模式",this);
    this->backToIndexBtn = new QPushButton("返回游戏主页",this);
    this->layout->addWidget(this->basicModelBtn);
    this->layout->addWidget(this->reisureModelBtn);
    this->layout->addWidget(this->aboutModelBtn);
    this->layout->addWidget(this->backToIndexBtn);
    this->layout->setAlignment(Qt::AlignHCenter);
    this->basicModelBtn->resize(200,100);
    this->reisureModelBtn->resize(200,100);
    this->aboutModelBtn->resize(200,100);
    this->backToIndexBtn->resize(200,100);
    this->setLayout(this->layout);
    this->resize(ENTERGAMEPANEL_WIDTH,ENTERGAMEPANEL_HEIGHT);
    initBtnEvents();

}
void EnterGamePanel::initBtnEvents(){
    //给基础按钮注册事件
  connect(this->basicModelBtn,&QPushButton::clicked,this,on_basicModelBtn_clicked);
  //给休闲模式按钮注册事件
  connect(this->reisureModelBtn,&QPushButton::clicked,this,on_reisureModelBtn_clicked);
  //给关于关卡按钮注册事件
  connect(this->aboutModelBtn,&QPushButton::clicked,this,on_aboutModelBtn_clicked);
  //给本返回主页的按钮添加点击事件
  connect(this->backToIndexBtn,&QPushButton::clicked,this,on_backToIndexBtn_clicked);


}
void EnterGamePanel::on_basicModelBtn_clicked(){
    if(this->basicGame == NULL){
        this->basicGame = new LowLevelGame(this,NULL);
    }else{
         delete this->basicGame;
         this->basicGame = new LowLevelGame(this,NULL);
    }
    this->hide();
    this->basicGame->initGame();
    this->basicGame->show();

}
void EnterGamePanel::on_reisureModelBtn_clicked(){
    if(this->basicGame == NULL){
        this->basicGame = new LeisureGame(this,NULL);
    }else{
         delete this->basicGame;
         this->basicGame = new LeisureGame(this,NULL);
    }
    this->hide();
    this->basicGame->initGame();
    this->basicGame->show();
}
void EnterGamePanel::on_aboutModelBtn_clicked(){

}
 void  EnterGamePanel::closeEvent(QCloseEvent *event){
        this->close();
     //重新展示主窗口,销毁本窗口
     this->m_parent->show();

 }
  void  EnterGamePanel::on_backToIndexBtn_clicked(){
      if(this->m_parent!= NULL){
          this->m_parent->show();
      }
      this->close();
  }

EnterGamePanel::~EnterGamePanel(){
    delete this->basicModelBtn;
    delete this->aboutModelBtn;
    delete this->reisureModelBtn;
    delete this->layout;

}
GameMediaUitl* EnterGamePanel::getGameMediaUtil(){
    return this->gameMediaUtil;
}
MainWindow* EnterGamePanel::getMainWindow(){
  return this->m_parent;
}
