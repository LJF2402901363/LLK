#include "GameService.h"
#include<QDebug>

GameService::GameService()
{

}


void GameService::loadImages(){
    this->totalImageCount = this->image_Row * this->image_column;
    //加载背景图片
     QPixmap p(*this->imagePath);
     this->image_width =(p.width()+this->image_Row-1)/this->image_Row;
     this->image_height=(p.height()+this->image_column-1)/this->image_column;
     int index = 0;
     //切分每个小图片存入到一个数组中
     for(int i = 0 ;i < this->image_Row;i++){
         for(int j = 0 ;j < this->image_column;j++){

          imagesMap[index++] = p.copy(i*this->image_width,j*this->image_height,this->image_width,this->image_height);
         }
     }

 }
GameService::~GameService(){

}
 QPixmap* GameService::getImage(int num){


     if(num <0 || num >= totalImageCount ){
      return NULL;
     }
     return &imagesMap[num];
 }

void GameService::deleteGameLayout(int **gameMap){
    for(int i = 0; i < this->rows;i++){
        delete[] gameMap[i];
    }
    delete [] gameMap;
}
int GameService::getGameColumns(){
    return this->columns;
}
int GameService::getGameRows(){
    return this->rows;
}

void GameService::setGameColumns(int columns){
    this->columns = columns;
}
void GameService::setGameRows(int rows){
    this->rows= rows;
}
  Vertex* GameService::getVertex(int x,int y){
      if(x <0|| x > this->columns*this->image_width|| y < 0||y > this->rows*this->image_height){
          return NULL;
      }
      int column = x/this->image_width;
      int row = y/this->image_height;
     Vertex* vertex = new Vertex(row,column,Vertex::COLOR_BLACK);
      return vertex;
  }
 bool GameService::isLinkRow(int **gameMap, Vertex *from, Vertex *to){
     if(from == nullptr||to == nullptr||gameMap==nullptr){
         return false;
     }
     int fromRow = from->getRow();
     int fromColumn = from->getColumn();
     int toRow = to->getRow();
     int toColumn = to->getColumn();
     if(gameMap[fromRow][fromColumn] != gameMap[toRow][toColumn]){
         return false;
     }
     //如果两个点为同一个那么直接返回false
     if(fromRow == toRow&& fromColumn == toColumn){
         return false;
     }
     if(fromRow == toRow){
         //从左往右查找两点之间是否存在阻碍的图片，如果存在直接返回false
         if(fromColumn < toColumn){
             for(int i= fromColumn+1;i < toColumn;i++){
                 if(gameMap[fromRow][i] >= 0){
                     return false;
                 }
             }
         }else{
             for(int i= toColumn+1;i < fromColumn;i++){
                 if(gameMap[fromRow][i] >= 0){
                     return false;
                 }
             }
         }
         return true;
         
     }else{
         return false;
     }
 }

 bool  GameService::isLinkCol(int** gameMap,Vertex *from,Vertex *to){
     if(from == nullptr||to == nullptr||gameMap==nullptr){
         return false;
     }
     int fromRow = from->getRow();
     int fromColumn = from->getColumn();
     int toRow = to->getRow();
     int toColumn = to->getColumn();
     if(gameMap[fromRow][fromColumn] != gameMap[toRow][toColumn]){
         return false;
     }
     //如果两个点为同一个那么直接返回false
     if(fromRow == toRow && fromColumn == toColumn){
         return false;
     }
     //这两个点都在同一列上
     if(fromColumn == toColumn){
         if(fromRow < toRow){
             for(int i= fromRow+1;i < toRow;i++){
                 if(gameMap[i][fromColumn] >= 0){
                     return false;
                 }
             }
             
         }else{
             for(int i= toRow+1;i < fromRow;i++){
                 if(gameMap[i][fromColumn] >= 0){
                     return false;
                 }
             }
         }
             return true;
     }else{
         return false;
     }
     
 }
 bool GameService::isTowLineLinkeCol(int **gameMap, Vertex *from, Vertex *to){
     //处理为空的情况
     if(gameMap == NULL || from == NULL|| to==NULL){
         return false;
     }
     int toRowIndex = to->getRow();
     int toColumnIndex = to->getColumn();
     int fromRowIndex = from->getRow();
     int fromColumnIndex = from->getColumn();
     if(gameMap[fromRowIndex][fromColumnIndex] != gameMap[toRowIndex][toColumnIndex]){
         return false;
     }
     //同一个点
     if(fromColumnIndex == toColumnIndex&&toRowIndex == fromRowIndex){
         return false;
     }
      //如果不在同一列
     if(from->getColumn() != to->getColumn()){

         return false;
     }
     //处理列为最左边和最右边的情况
     if((fromColumnIndex == 0 && toColumnIndex==0)||
    (fromColumnIndex == GAME_COLMUNS -1 &&toColumnIndex == GAME_COLMUNS -1)){

         return true;
     }

    bool fla = true;
     if(toRowIndex < fromRowIndex){
         //处理左侧直线
         for(int i = toRowIndex+1;i < fromRowIndex;i++){
            if(gameMap[i][toColumnIndex-1]  >= 0){
                fla = false;
                break;
            }
         }
         if(fla){
             return true;
         }
         //处理右侧直线
         for(int i = toRowIndex+1;i < fromRowIndex;i++){
            if(gameMap[i][toColumnIndex+1] >= 0){
                fla = false;
                break;
            }
         }
         if(fla){
             return true;
         }
     }else{
         //处理左侧直线
         for(int i = fromRowIndex+1;i < toRowIndex;i++){
            if(gameMap[i][toColumnIndex-1]  >= 0){
                fla = false;
                break;
            }
         }
         if(fla){
             return true;
         }
         //处理右侧直线
         for(int i = fromRowIndex+1;i < toRowIndex;i++){
            if(gameMap[i][toColumnIndex+1] >= 0){
                fla = false;
                break;
            }
         }
         if(fla){
             return true;
         }
     }
     return false;
 }
 bool GameService::isTowLineLinkeRow(int **gameMap, Vertex *from, Vertex *to){
     //处理为空的情况
     if(gameMap == NULL || from == NULL|| to==NULL){
         return false;
     }
     int toRowIndex = to->getRow();
     int toColumnIndex = to->getColumn();
     int fromRowIndex = from->getRow();
     int fromColumnIndex = from->getColumn();
     if(gameMap[fromRowIndex][fromColumnIndex] != gameMap[toRowIndex][toColumnIndex]){
         return false;
     }
     //如果不在同一行
     if(toRowIndex != fromRowIndex){
         return false;
     }
      qDebug()<<true;
     //同一个点
     if(fromColumnIndex == toColumnIndex && toRowIndex == fromRowIndex){
         return false;
     }
    //处理第一行或者最后一行
    if((toRowIndex == 0 && fromRowIndex == 0) ||
       (toRowIndex == GAME_ROWS-1&& fromRowIndex == GAME_ROWS-1)){
        return true;
    }
    bool fla = true;
    if(toColumnIndex < fromColumnIndex){
        //处理上方行
        for(int i = toColumnIndex+1; i < fromColumnIndex;i++){
            if(gameMap[toRowIndex-1][i] >= 0){
                fla = false;
                break;
            }
        }
        if(fla){
            return true;
        }
        //处理下方行
        for(int i = toColumnIndex+1; i < fromColumnIndex;i++){
            if(gameMap[toRowIndex+1][i] >= 0){
                fla = false;
                break;
            }
        }
        if(fla){
            return true;
        }
    }else{
        //处理上方行
        for(int i = fromColumnIndex+1; i < toRowIndex;i++){
            if(gameMap[toRowIndex-1][i] >= 0){
                fla = false;
                break;
            }
        }
        if(fla){
            return true;
        }
        //处理下方行
        for(int i = fromColumnIndex+1; i < toRowIndex;i++){
            if(gameMap[toRowIndex+1][i] >= 0){
                fla = false;
                break;
            }
        }
        if(fla){
            return true;
        }
    }
    return false;
 }
 bool GameService::isThreeLineLinkeCol(int **gameMap, Vertex *from, Vertex *to){
     //处理为空的情况
     if(gameMap == NULL || from == NULL|| to==NULL){
         return false;
     }

     int toRowIndex = to->getRow();
     int toColumnIndex = to->getColumn();
     int fromRowIndex = from->getRow();
     int fromColumnIndex = from->getColumn();
     return false;
 }
 bool GameService::isThreeLineLinkeRow(int **gameMap, Vertex *from, Vertex *to){
     //处理为空的情况
     if(gameMap == NULL || from == NULL|| to==NULL){
         return false;
     }
     return false;
 }

 int GameService::getImageHeight(){
     return this->image_height;
 }
 int GameService::getImageWidth(){
     return this->image_width;
 }
void GameService::setImagePath(const char *imagePath){
   this->imagePath = new QString(imagePath);
}
void GameService::setImageRow(int image_Row){
    this->image_Row = image_Row;
}
void GameService::setImageColumn(int image_column){
    this->image_column = image_column;
}
 void  GameService::rescheduleLayout(int** gameMap){
     if(gameMap == NULL){
         return;
     }
      int* tempMap = new int[this->totalImageCount];
     //统计剩余未消去的图片
     int count = 0;
     for(int i = 0;i < GAME_ROWS;i++){
         for(int j = 0;j < GAME_COLMUNS;j++){
             if(gameMap[i][j] >= 0){
                 tempMap[count++] = gameMap[i][j];
             }
         }
     }

    //随机打乱一维数组的排列
     srand((int)time(NULL));
     int j = 0;
     int temp = 0;
         for(int i = 0; i < count; i++)
         {
             j = rand()%(count-i)+i;
             temp = tempMap[i];
             tempMap[i] = tempMap[j];
             tempMap[j] = temp;
         }


         //利用一维数组来使二维数组随机排列
         int index = 0;
         for(int i = 0;i < GAME_ROWS;i++){
             for(int j = 0;j < GAME_COLMUNS;j++){
                 if(gameMap[i][j] >= 0){
                     gameMap[i][j]=tempMap[index++] ;
                 }
             }
         }

 }
