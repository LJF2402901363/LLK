#include "rankingpanel.h"
#include"mainwindow.h"
#include"ui_rankingpanel.h"

RankingPanel::RankingPanel( MainWindow* mainWindow,QWidget *parent) : QWidget(parent),ui(new Ui::RankingPanel)
{
    this->ui->setupUi(this);
    this->mainWindow = mainWindow;
      this->resize(RANKINGPANEL_WIDTH,RANKINGPANEL_HEIGHT);

}
RankingPanel::~RankingPanel(){
    delete this->ui;
}
void RankingPanel::closeEvent(QCloseEvent *event){
    if(this->mainWindow != NULL){
        this->mainWindow->show();
    }
    this->close();
}
