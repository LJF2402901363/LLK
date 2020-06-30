#ifndef INTRODUCTIONPANEL_H
#define INTRODUCTIONPANEL_H
#include<QCloseEvent>
#include <QWidget>
#include"gameglobalconstants.h"

class MainWindow;
namespace Ui {
class IntroductionPanel;

}
class IntroductionPanel : public QWidget
{

public:
    explicit IntroductionPanel(MainWindow* mainWindow ,QWidget *parent = nullptr);
   ~IntroductionPanel();
    //窗口关闭事件
    void closeEvent(QCloseEvent *event);
signals:

public slots:
private:
    Ui::IntroductionPanel *ui;
    MainWindow* mainWindow = NULL;
};

#endif // INTRODUCTIONPANEL_H
