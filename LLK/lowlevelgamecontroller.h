#ifndef LOWLEVELGAMECONTROLLER_H
#define LOWLEVELGAMECONTROLLER_H
#include"gamecontroller.h"

class LowLevelGameController:public GameController
{
public:
    LowLevelGameController(GameService* gameservice = nullptr);
    ~LowLevelGameController();

};

#endif // LOWLEVELGAMECONTROLLER_H
