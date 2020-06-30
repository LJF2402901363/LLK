#include "helppanel.h"
#include"mainwindow.h"
#include"ui_helppanel.h"
HelpPanel::HelpPanel( MainWindow* mainWindow,QWidget *parent) : QWidget(parent),ui(new Ui::HelpPanel)
{
  this->mainWindow = mainWindow;
  this->ui->setupUi(this);
  this->setWindowTitle("游戏帮助");
  this->resize(WIDTH,HEIGHT);
}
HelpPanel::~HelpPanel(){
    delete this->ui;
}

void HelpPanel::closeEvent(QCloseEvent *event){
      if(this->mainWindow != NULL){
          //重新显示主窗口
          this->mainWindow->show();
      }
      this->close();
}
