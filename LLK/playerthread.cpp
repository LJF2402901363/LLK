#include "playerthread.h"
#include<QDebug>
PlayerThread::PlayerThread(QMediaPlayer *player):QThread()
{
  this->player = player;
}
bool PlayerThread::getIsRunning(){

    return this->isRunning;
}
void PlayerThread::setIsRunning(bool isRunning){
    this->isRunning =  isRunning;
}
void PlayerThread::run(){

    if(isRunning){
        this->player->play();
    }else{
        this->player->stop();
    }
}

void PlayerThread::quit(){
    this->player->stop();
    QThread::quit();
}
