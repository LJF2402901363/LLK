#ifndef LEISUREGAMESERVICE_H
#define LEISUREGAMESERVICE_H
#include"gameservice.h"

class LeisureGameService:public  GameService
{
public:
    LeisureGameService();
    //实现布局初始化
     int** initGameLayout();
     //实现设置加载图片的参数
     void setLoadImageParams();
};

#endif // LEISUREGAMESERVICE_H
