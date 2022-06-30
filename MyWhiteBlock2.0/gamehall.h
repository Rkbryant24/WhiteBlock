#ifndef GAMEHALL_H
#define GAMEHALL_H

#include <QWidget>

namespace Ui {
class Gamehall;
}

class Gamehall : public QWidget
{
    Q_OBJECT

public:
    explicit Gamehall(QWidget *parent = 0);
    ~Gamehall();
    void goSetting();//点击设置的反应
    void goStart();//点击开始游戏的反应
    void logoutbut();

private:
    Ui::Gamehall *ui;
    
signals:
    void gotoSetting();//设置信号
    void gotoStart();//开始游戏信号
    void logout();

public slots:
    void init(QString user);//初始化游戏大厅
};

#endif // GAMEHALL_H
