#ifndef LEISUREGAME_H
#define LEISUREGAME_H
#include"basicgame.h"
#include"leisuregamecontroller.h"
#include"leisuregameservice.h"
class LeisureGame:public BasicGame
{
public:
    LeisureGame(EnterGamePanel* enterGamePanel,QWidget *parent = nullptr);
    //实现父类的设置进度条的虚函数
     void  setProgressBarRange() ;
};

#endif // LEISUREGAME_H
