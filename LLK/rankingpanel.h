#ifndef RANKINGPANEL_H
#define RANKINGPANEL_H
#include<QCloseEvent>
#include <QWidget>
#include"gameglobalconstants.h"
class MainWindow;
namespace Ui {
class RankingPanel;
}
class RankingPanel : public QWidget
{

public:
    explicit RankingPanel( MainWindow* mainWindow,QWidget *parent = nullptr);
    ~RankingPanel();
    void closeEvent(QCloseEvent *event);
signals:

public slots:
private:
    Ui::RankingPanel* ui;
    MainWindow* mainWindow=NULL;
};

#endif // RANKINGPANEL_H
