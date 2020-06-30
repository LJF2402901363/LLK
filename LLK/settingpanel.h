#ifndef SETTINGPANEL_H
#define SETTINGPANEL_H
#include <QWidget>
#include<QCloseEvent>
#include"gamemediauitl.h"
#include<time.h>
class MainWindow;
namespace Ui {
class SettingPanel;
}
class SettingPanel : public QWidget
{
 Q_OBJECT
public:

    explicit SettingPanel( MainWindow* mainWindow ,QWidget *parent = nullptr);
   void  loadSettings();
   void initEvents();
    ~SettingPanel();
    //关闭窗口事件
    void closeEvent(QCloseEvent *event);
signals:

public slots:
    void closeBgmBtn_clicked();
    void openBgmBtn_clicked();
    void returnBtn_clicked();
    void resetSetting_onlicked();


private slots:
    void soundsCombox_currentIndexChanged();

private:
  Ui::SettingPanel *ui;
  MainWindow* mainWindow = NULL;
  GameMediaUitl* gameMediaUitl = NULL;
};

#endif // SETTINGPANEL_H
