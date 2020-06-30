#include "gamecontroller.h"

GameController::GameController(GameService* gameservice)
{
 this->gameservice = gameservice;
}
int GameController::getElement(int row, int column){
    if(row < 0 || row >= GAME_ROWS||column >= GAME_COLMUNS){
     return -1;
 }
    return this->gameMap[row][column];
}
 QPixmap* GameController::getImage(int row,int column){
     if(row < 0 || row >= GAME_ROWS || column <0 || column>=GAME_COLMUNS){
         return NULL;
     }

     return this->gameservice->getImage(this->gameMap[row][column]);
 }

void GameController::statrtGame(){
    //设置加载图片的参数
    this->gameservice->setLoadImageParams();
    //加载游戏图片
    this->gameservice->loadImages();
    //获取图片的二维数组
  this->gameMap = this->gameservice->initGameLayout();

}
 Vertex* GameController::getVertex(int x,int y){
     return this->gameservice->getVertex(x,y);
 }


void GameController::setLinePointStatus(Vertex *from,Vertex *to,int imageNum){
    this->gameMap[from->getRow()][from->getColumn()] = imageNum;
    this->gameMap[to->getRow()][to->getColumn()] = imageNum;
}
 bool GameController::isLink(Vertex *from,Vertex *to){
     if(this->gameservice->isLinkCol(this->gameMap,from,to)
             || this->gameservice->isLinkRow(this->gameMap,from,to)
            // || this->gameservice->isTowLineLinkeCol(this->gameMap,from,to)
            // || this->gameservice->isTowLineLinkeRow(gameMap,from,to)
             ){
         return true;
     }
     return false;
 }
 bool GameController::isThreeLineLink(Vertex *from, Vertex *to){
     if( this->gameservice->isThreeLineLinkeCol(this->gameMap,from,to)
             || this->gameservice->isThreeLineLinkeRow(gameMap,from,to)){
         return true;
     }
     return false;
 }
 bool GameController::isTowLineLink(Vertex *from, Vertex *to){
     if( this->gameservice->isTowLineLinkeCol(this->gameMap,from,to)
             || this->gameservice->isTowLineLinkeRow(gameMap,from,to)){
         return true;
     }
     return false;
 }

int GameController::getImageHeiht(){
   return this->gameservice->getImageHeight();
}
int GameController::getImageWidth(){
     return this->gameservice->getImageWidth();
}
 void GameController::rescheduleLayout(){
     this->gameservice->rescheduleLayout(this->gameMap);
 }
