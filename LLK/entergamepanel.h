#ifndef ENTERGAMEPANEL_H
#define ENTERGAMEPANEL_H
#include<QPushButton>
#include<QVBoxLayout>
#include<QCloseEvent>
#include"basicgame.h"
#include"lowlevelgame.h"
#include"leisuregame.h"
#include"gamemediauitl.h"
#define WIDTH 500
#define HEIGHT 400
class MainWindow;


class EnterGamePanel : public QWidget
{

public:
    explicit EnterGamePanel(MainWindow* mainWindow,QWidget* parent=nullptr);
    void initBtnEvents();
    GameMediaUitl* getGameMediaUtil();
    MainWindow* getMainWindow();
    ~EnterGamePanel();
     //关闭窗口时的监听事件
      void closeEvent(QCloseEvent *event);
signals:

public slots:
    //基础关卡的点击事件
    void on_basicModelBtn_clicked();
    //休闲关卡的点击事件
    void on_reisureModelBtn_clicked();
    //关于模式的点击事件
    void on_aboutModelBtn_clicked();
    //关于返回游戏主页的点击事件
    void on_backToIndexBtn_clicked();
private:
    //基础的游戏关卡按钮
    QPushButton*  basicModelBtn;
    //休闲游戏关卡按钮
    QPushButton* reisureModelBtn;
    //关于游戏关卡
    QPushButton* aboutModelBtn;
    //返回主界面按钮
    QPushButton*  backToIndexBtn;
    //按钮的垂直布局
    QVBoxLayout* layout ;
    //游戏主页面
    MainWindow *m_parent ;
    //游戏模式页面
    BasicGame* basicGame =NULL;
    //游戏多媒体设置
    GameMediaUitl* gameMediaUtil = NULL;
};

#endif // ENTERGAMEPANEL_H
