#ifndef GAMESERVICE1_H
#define GAMESERVICE1_H
#include<QPixmap>
#include"gameglobalconstants.h"
#include"vertex.h"
#include<QString>
class GameService
{
public:
    GameService();
    //设置图片加载的参数，包括图片的行数，列数以及图片路径,交给子类实现
    virtual void setLoadImageParams()= 0;
    //加载图片资源获取image_Row*image_column个图片
    void loadImages();
    //加载游戏布局
    virtual int** initGameLayout() = 0;
     void setImageRow(int image_Row) ;
     void setImageColumn(int image_column);
     void setImagePath(const char* imagePath);
     //释放游戏布局
     void deleteGameLayout(int** gameMap);
     //通过索引获取某个图片
    QPixmap* getImage(int num);
    /*设置游戏的行数*/
    void setGameRows(int rows);
      /*设置游戏的列数*/
    void setGameColumns(int columns);
      /*获取游戏的行数*/
    int getGameRows();
      /*获取游戏的列数*/
    int getGameColumns();
    Vertex* getVertex(int x,int y);
  
    /*判断是否纵向连通*/
    bool isLinkCol(int** gameMap,Vertex *from,Vertex *to);
     /*判断是否横向连通*/
    bool isLinkRow(int** gameMap,Vertex *from,Vertex *to);
    /*判断两条线是否纵向连通*/
    bool isTowLineLinkeCol(int** gameMap,Vertex *from,Vertex *to);
    /*判断两条直线是否横向连通*/
    bool isTowLineLinkeRow(int** gameMap,Vertex *from,Vertex *to);
      /*判断三条线是否纵向连通*/
    bool isThreeLineLinkeCol(int** gameMap,Vertex *from,Vertex *to);
     /*判断三条线是否横向连通*/
    bool isThreeLineLinkeRow(int** gameMap,Vertex *from,Vertex *to);

    
    
    /*获取图片的宽度*/
    int getImageWidth();
    /*获取图片的高度*/
    int getImageHeight();
    /*重新排列布局*/
    void rescheduleLayout(int** gameMap);
 ~GameService();
protected:
  QPixmap imagesMap[COUNTIMAGES];
    //每个小图片的宽
    int image_width = 0;
    //每个小图片的高
    int  image_height = 0;
    //加载的图片的行数
     int image_Row = IMAGE_ROWS ;
     //加载图片的列数
     int image_column =IMAGE_COLMUNS;
     //总的图片数
     int totalImageCount = IMAGE_ROWS * IMAGE_COLMUNS;
    //游戏行数
    int rows = GAME_ROWS;
    //游戏列数
    int columns = GAME_COLMUNS;
    //文件路径
    QString* imagePath = NULL;
};

#endif // GAMESERVICE1_H
