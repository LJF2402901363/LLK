#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include"gameservice.h"
#include<QDebug>

class GameController
{
public:
    GameController(GameService* gameservice = nullptr);
    /*开始游戏*/
    void statrtGame() ;
    /*获取行列对应的图片编号*/
    int  getElement(int row,int column);
    QPixmap* getImage(int row,int column);
    /*获取坐标下对应的图片的行号和列号的节点*/
    Vertex* getVertex(int x,int y);
    /*判断是否一条直线连通*/
    bool isLink(Vertex *from,Vertex *to);
    /*判断是否两条直线连通*/
    bool isTowLineLink(Vertex *from,Vertex *to);
    /*判断是否三条直线连通*/
    bool isThreeLineLink(Vertex *from,Vertex *to);
    /*修改两个点的颜色状态是否隐藏*/
    void setLinePointStatus(Vertex *from,Vertex *to,int imageNum);
    /*获取图片的宽度*/
    int getImageWidth();
    /*获取图片的高度*/
    int getImageHeiht();
    /*重新排列布局*/
    void rescheduleLayout();
protected:
   int** gameMap = nullptr;
   GameService* gameservice = nullptr;
};

#endif // GAMECONTROLLER_H
