#include "lowlevelgame.h"
LowLevelGame::LowLevelGame(EnterGamePanel* enterGamePanel,QWidget *parent ):
 BasicGame(enterGamePanel,new LowLevelGameController(new LowLevelGameService()),parent)
{

}
void LowLevelGame::setProgressBarRange(){
     this->setMaxProgressBarRange(100);
}
