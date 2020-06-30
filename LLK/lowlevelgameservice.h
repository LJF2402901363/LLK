#ifndef LOWLEVELGAMESERVICE_H
#define LOWLEVELGAMESERVICE_H
#include"gameservice.h"

class LowLevelGameService:public  GameService
{
public:
    LowLevelGameService();
    //实现布局初始化
     int** initGameLayout();
     //实现设置加载图片的参数
     void setLoadImageParams();
};

#endif // LOWLEVELGAMESERVICE_H
