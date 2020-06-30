#ifndef LEISUREGAMECONTROLLER_H
#define LEISUREGAMECONTROLLER_H
#include"gamecontroller.h"

class LeisureGameController:public  GameController
{
public:
    LeisureGameController(GameService* gameservice );
    ~LeisureGameController();
};

#endif // LEISUREGAMECONTROLLER_H
