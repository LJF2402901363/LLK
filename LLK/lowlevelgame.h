#ifndef LOWLEVELGAME_H
#define LOWLEVELGAME_H
#include"basicgame.h"
#include"lowlevelgameservice.h"
#include"lowlevelgamecontroller.h"
class LowLevelGame:public BasicGame
{
public:
    LowLevelGame(EnterGamePanel* enterGamePanel,QWidget *parent = nullptr);
    //实现父类的设置进度条的虚函数
     void  setProgressBarRange() ;

};

#endif // LOWLEVELGAME_H
