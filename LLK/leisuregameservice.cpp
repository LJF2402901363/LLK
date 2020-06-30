#include "leisuregameservice.h"

LeisureGameService::LeisureGameService():GameService()
{

}
int** LeisureGameService::initGameLayout(){
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
void LeisureGameService::setLoadImageParams(){
    this->setImageRow(6);
    this->setImageColumn(3);
    this->setImagePath("../images/LeisureGame.png");
}
