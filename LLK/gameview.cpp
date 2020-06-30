#include "gameview.h"
#include"basicgame.h"
#include<QPalette>
#include<QBrush>
GameView::GameView( BasicGame* basicGame, GameController* gameController ,QWidget *parent) : QWidget(parent)
{
   this->basicGame = basicGame;
  this->gameController = gameController;

}
void GameView::initGame(){
    //加载背景图片
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/images/gameBgm.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
     this->setPalette(palette);
    this->gameController->statrtGame();
    //设置时间进度条的范围,休闲模式和基础模式的时间是不同的，这里会发生多态
    this->basicGame->setProgressBarRange();
    this->image_height = this->gameController->getImageHeiht();
    this->imag_width = this->gameController->getImageWidth();
}

void GameView::paintEvent(QPaintEvent *event){
    //声明画家并设置面板为当前对象
    QPainter p(this);
    QPen pen;
    pen.setColor(QColor(Qt::red));
    p.setPen(pen);
    for(int i = 0 ;i < GAME_ROWS;i++){
        for(int j = 0 ;j < GAME_COLMUNS;j++){
       if(this->gameController->getElement(i,j) >= 0 ){
        QPixmap* pixMap = this->gameController->getImage(i,j);
        if(pixMap != NULL){
          p.drawPixmap(j*imag_width,i*image_height,QPixmap(*pixMap));
        }
          }else{
       p.fillRect(j*this->imag_width,
                  i*this->image_height,
                   this->imag_width,
                   this->image_height,
                  QColor(253,252,252));
       }
        }
    }

}
 void GameView::mousePressEvent(QMouseEvent* event){
     if(this->isGameStart == false){
         return ;
     }
      int mouse_x=event->x();
      int mouse_y=event->y();
      this->currVertex = this->gameController->getVertex(mouse_x,mouse_y);
      if(this->vertexCount == 0){
          this->fromVertex = this->currVertex;
          this->vertexCount++;
    }else{
          this->toVertex =this->currVertex;
          qDebug()<<"fromVex:"<<this->fromVertex->getRow()<<","<<this->fromVertex->getColumn()
                  <<"toVex"<<this->toVertex->getRow()<<","<<this->toVertex->getColumn();

        //  qDebug()<<"该两点可以消去："<<isLink;
          if(this->gameController->isLink(fromVertex,toVertex)){
              //设置这两个点的图片颜色为白色也就是隐藏
             this->gameController->setLinePointStatus(fromVertex,toVertex,-1);
              //重新更新页面
              this->update();
              //游戏声效播放
              this->basicGame->startBgm();
             this->basicGame->setScore(5);

          }else if(this->gameController->isTowLineLink(fromVertex,toVertex)){
              //设置这两个点的图片颜色为白色也就是隐藏
             this->gameController->setLinePointStatus(fromVertex,toVertex,-1);
              //重新更新页面
              this->update();
              //游戏声效播放
              this->basicGame->startBgm();
             this->basicGame->setScore(10);
          }else if(this->gameController->isThreeLineLink(fromVertex,toVertex)){
              //设置这两个点的图片颜色为白色也就是隐藏
             this->gameController->setLinePointStatus(fromVertex,toVertex,-1);
              //重新更新页面
              this->update();
              //游戏声效播放
              this->basicGame->startBgm();
             this->basicGame->setScore(15);
          }

              //消去这两个接节点后重新开始
              this->fromVertex = NULL;
              this->toVertex = NULL;
              this->vertexCount = 0;

      }

 }
void GameView::setIsGameStart(bool isGameStart){
    this->isGameStart = isGameStart;
}
void  GameView::rescheduleLayout(){
   this->gameController->rescheduleLayout();
   this->repaint();
}
bool GameView::getIsGameStart(){
    return this->isGameStart;
}
