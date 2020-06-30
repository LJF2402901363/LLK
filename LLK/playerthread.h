#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H
#include<QThread>
#include<QMediaPlayer>
class PlayerThread :public QThread
{
public:
    PlayerThread(QMediaPlayer* player);
    void setIsRunning(bool isRunning);
    bool getIsRunning();
   void quit();
protected:
    virtual void run();

private:
    bool isRunning = false;
    QMediaPlayer* player = NULL;
};

#endif // PLAYERTHREAD_H
