#ifndef HELPPANEL_H
#define HELPPANEL_H
#include<QCloseEvent>
#include <QWidget>
#include"gameglobalconstants.h"
class MainWindow;
namespace Ui {
class HelpPanel;
}
class HelpPanel : public QWidget
{

public:
    explicit HelpPanel( MainWindow* mainWindow,QWidget *parent = nullptr);
  ~HelpPanel();
    void closeEvent(QCloseEvent *event);
signals:

public slots:
private:
    Ui::HelpPanel* ui;
    MainWindow* mainWindow=NULL;
};

#endif // HELPPANEL_H
