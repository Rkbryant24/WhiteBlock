#include "start.h"
#include "ui_start.h"
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDesktopWidget>
#include <QIcon>

QMap<QString,QString> mp;
QMap<QString,int> id_mp;
int best[1010][3];
QString userlist[1010];

Start::Start(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    this->resize(600,800);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));
    this->user_num = 0;
    this->move((QApplication::desktop()->width()-this->width())/2,(QApplication::desktop()->height()-this->height())/2);
    QObject::connect(this->ui->login, &QPushButton::clicked,this,&Start::loginbut);
    QObject::connect(this->ui->exit, &QPushButton::clicked,this,&Start::quitbut);
    QObject::connect(this->ui->register_2, &QPushButton::clicked,this,&Start::registbut);
}

Start::~Start(){delete ui;}

void Start::init()
{
    QFile file("user_data");
    if(file.open(QFile::ReadOnly))
    {
        QDataStream in(&file);
        this->user_num = 0;
        char *str;
        int score;
        while(!in.atEnd())
        {
            in>>str;
            QString user(str);
            in>>str;
            QString pswd(str);
            this->user_num++;
            userlist[this->user_num] = user;
            in>>score,best[this->user_num][0] = score;
            in>>score,best[this->user_num][1] = score;
            in>>score,best[this->user_num][2] = score;
            mp[user] = pswd,id_mp[user] = this->user_num;
        }
        file.close();
    }
    this->show();
}

void Start::loginbut()
{
    emit login(this->geometry().x(), this->geometry().y());
}

void Start::registbut()
{
    emit regist(this->geometry().x(),this->geometry().y());
}

void Start::quitbut()
{
    QMessageBox::StandardButton result = QMessageBox::question(this,"Warning","确定退出游戏?");
    if(result==QMessageBox::Yes)
        this->close();
}
void Start::updhis(int diff, int score)
{
    int id = id_mp[this->cur];
    if(score>best[id][diff])
    {
        best[id][diff] = score;
        QFile file("user_data");
        if(file.open(QFile::WriteOnly|QFile::Truncate))
        {
            QDataStream out(&file);
            for(int i = 1;i<=this->user_num;i++)
            {
                QString usr = userlist[i];
                int Id = id_mp[usr];
                out<<usr.toUtf8()<<mp[usr].toUtf8()<<best[Id][0]<<best[Id][1]<<best[Id][2];
            }
        }
    }emit userbest(diff,best[id][diff]);
}

void Start::updusr(QString user, QString pswd)
{
    if(mp.find(user)!=mp.end())
        emit(register_fail());
    else
    {
        emit(register_success());
        this->user_num++;
        mp[user] = pswd,id_mp[user] = this->user_num;
        userlist[this->user_num] = user;
        QFile file("user_data");
        int score = 0;
        if(file.open(QFile::Append))
        {
            QDataStream out(&file);
            out<<user.toUtf8()<<pswd.toUtf8()<<score<<score<<score;
            file.close();
        }
    }
}

void Start::check(QString user, QString pswd)
{
    if(mp.find(user)!=mp.end())
    {
        if(mp[user]!=pswd)
            emit(login_fail(0));
        else
        {
            emit(login_success(user));
            this->cur = user,this->close();
        }
    }
    else emit(login_fail(1));
}
