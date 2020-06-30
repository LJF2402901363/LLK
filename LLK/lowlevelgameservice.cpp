#include "lowlevelgameservice.h"
#include<QDebug>
LowLevelGameService::LowLevelGameService():GameService()
{

}

int** LowLevelGameService::initGameLayout(){
    int ** gameMap = NULL;
     for(int i = 0 ; i < this->rows;i++){
         gameMap= new int*[this->rows];
     }
     for(int i = 0 ; i < this->columns;i++){
         gameMap[i]= new int[this->columns];
     }
     srand((int)time(NULL));
     for(int i = 0 ; i < this->rows;i++){
         for(int j = 0 ; j < this->columns;j++){
              gameMap[i][j]= rand()%(this->totalImageCount);
         }
     }
     return gameMap;
}
void LowLevelGameService::setLoadImageParams(){

   this->setImageRow(7);
    this->setImageColumn(4);
    this->setImagePath("../images/lowLevelGame.png");
}
