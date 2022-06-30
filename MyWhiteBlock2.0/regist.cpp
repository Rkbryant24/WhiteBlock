#include "regist.h"
#include "ui_regist.h"
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Regist::Regist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_ShowModal,true);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));

    QObject::connect(this->ui->cancel,&QPushButton::clicked,this,&Regist::close);
    QObject::connect(this->ui->register_2,&QPushButton::clicked,this,&Regist::registbut);
}

Regist::~Regist(){delete ui;}

void Regist::clear()
{
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
    this->ui->lineEdit_3->clear();
}

void Regist::_init(int x,int y)
{
    this->show();
    this->clear();
    this->move(x+130,y+160);
}

void Regist::registbut()
{
    QString username = ui->lineEdit->text(),pswd = ui->lineEdit_2->text(),Pswd = ui->lineEdit_3->text();
    if(username=="")QMessageBox::critical(this,"Error","用户名不能为空!");
    else if(pswd!=Pswd)QMessageBox::critical(this,"Error","两个密码不相同!");
    else if(pswd.length()<6)QMessageBox::critical(this,"Error","密码至少要有6位!");
    else emit(regist(username,pswd));
}

void Regist::success(){QMessageBox::information(this,"Tips","注册成功!"),this->close();}
void Regist::fail(){QMessageBox::critical(this,"Error","用户名已存在!"),this->clear();}
