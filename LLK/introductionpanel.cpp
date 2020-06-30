#include "introductionpanel.h"
#include"mainwindow.h"
#include"ui_introductionpanel.h"
IntroductionPanel::IntroductionPanel(MainWindow* mainWindow ,QWidget *parent) : QWidget(parent),ui(new Ui::IntroductionPanel)
{
  this->ui->setupUi(this);
  this->mainWindow=mainWindow;
  this->setWindowTitle("游戏介绍");
  this->resize(INTRODUCETIONPANEL_WIDTH,INTRODUCETIONPANEL_HEIGHT);
}
 IntroductionPanel::~IntroductionPanel(){
    delete this->ui;
}
void  IntroductionPanel::closeEvent(QCloseEvent *event){
    if(this->mainWindow != NULL){
        this->mainWindow->show();
    }
    this->close();
}
