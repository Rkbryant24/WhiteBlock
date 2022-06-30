#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_ShowModal,true);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));

    QObject::connect(this->ui->login, &QPushButton::clicked, this, &Login::loginbut);
    QObject::connect(this->ui->cancel, &QPushButton::clicked, this, &Login::close);
}

Login::~Login(){delete ui;}

void Login::clear()
{
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
}

void Login::_init(int x,int y)
{
    this->show();
    this->clear();
    this->move(x+150,y+170);
}

void Login::loginbut()
{
    QString username = ui->lineEdit->text(),pswd = ui->lineEdit_2->text();

    if(username=="")
        QMessageBox::critical(this,"Error","请输入用户名!"),this->ui->lineEdit_2->clear();
    else if(pswd=="")
        QMessageBox::critical(this,"Error","请输入密码!");
    else
        emit login(username,pswd);
}

void Login::success()
{
    QMessageBox::information(this,"Tips","登录成功!");
    this->close();
}

void Login::fail(int x)
{
    if(x)QMessageBox::critical(this,"Error","用户不存在!"),this->clear();
    else QMessageBox::critical(this,"Error","密码错误!"),this->ui->lineEdit_2->clear();
}
