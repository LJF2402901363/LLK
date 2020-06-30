#include "leisuregame.h"

LeisureGame::LeisureGame(EnterGamePanel* enterGamePanel,QWidget *parent ):
    BasicGame(enterGamePanel,new LeisureGameController(new LeisureGameService()),parent)

{

}
void LeisureGame::setProgressBarRange(){
     this->setMaxProgressBarRange(200);
}
