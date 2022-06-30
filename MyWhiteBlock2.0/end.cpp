#include "end.h"
#include "ui_end.h"
#include <QDebug>

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));

    QObject::connect(this->ui->restart,&QPushButton::clicked,this,&End::restartbut);
    QObject::connect(this->ui->hall,&QPushButton::clicked,this,&End::hallbut);
}

End::~End(){delete ui;}

void End::_init(int x,int y,int diff,int score)
{
    this->move(x+200,y+300);
    this->ui->score->setText(QString::number(score));
    emit updhis(diff,score);
    this->show();
}

void End::restartbut()
{
    emit(restart());
    this->close();
}

void End::hallbut()
{
    emit(hall());
    this->close();
}

void End::updbest(int diff, int score)
{
    QString Diff;
    if(diff==0)Diff = "简单";
    else if(diff==1)Diff = "普通";
    else Diff = "困难";
    this->ui->his->setText("历史最高分("+Diff+"模式）："+QString::number(score));
}
