#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include<QPainter>
#include <QWidget>
#include<QMouseEvent>
#include"gameglobalconstants.h"
#include"gamecontroller.h"
#include<QPen>
#include<QColor>
#include<QDebug>
#include<QSize>
class BasicGame;
class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView( BasicGame* basicGame, GameController* gameController = NULL,QWidget *parent = nullptr);
    void initGame();
    bool getIsGameStart();
    void setIsGameStart(bool isGameStart);
    void  rescheduleLayout();
protected:
    //绘制图片函数
    void paintEvent(QPaintEvent *event);
    /*鼠标监听事件*/
    void mousePressEvent(QMouseEvent* event);

signals:

public slots:
private:
    GameController* gameController = NULL;
    //当前节点
     Vertex* currVertex =NULL;
     //起始点
     Vertex* fromVertex   = NULL;
     //结束点
     Vertex* toVertex   = NULL;
     //用于判断鼠标点击的次数
    int vertexCount = 0;
    //用于判断是否开始游戏
    bool isGameStart = false;
    //用于判断是否暂停游戏
    bool isGamePause = false;
    BasicGame* basicGame = NULL;
    //图片的宽
   int imag_width = 0;
   //图片的高
   int image_height =0;
};

#endif // GAMEVIEW_H
