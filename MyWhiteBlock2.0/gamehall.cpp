#include "gamehall.h"
#include "ui_gamehall.h"
#include "settings.h"
#include <QMessageBox>
#include <QDesktopWidget>

Gamehall::Gamehall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamehall)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));

    //点击退出游戏
    connect(ui->exit_btn, &QPushButton::clicked,this,&Gamehall::logoutbut);

    //点击设置
    connect(ui->setting_btn, &QPushButton::clicked, this, &Gamehall::goSetting);

    //点击开始游戏
    connect(ui->start_btn, &QPushButton::clicked, this, &Gamehall::goStart);
}

Gamehall::~Gamehall(){delete ui;}


void Gamehall::init(QString user)
{
    this->setWindowTitle("游戏大厅");
    this->move((QApplication::desktop()->width()-this->width())/2,(QApplication::desktop()->height()-this->height())/2);
    this->ui->label->setText("当前用户："+user);
    this->show();
}

void Gamehall::logoutbut()
{
    QMessageBox::StandardButton result = QMessageBox::question(this,"Warning","确定退出登录?");
    if(result==QMessageBox::Yes)
    {
        emit logout();
        this->close();
    }
}

void Gamehall::goSetting()
{
    emit Gamehall::gotoSetting();
}

void Gamehall::goStart()
{
    this->close();
    emit Gamehall::gotoStart();
}
