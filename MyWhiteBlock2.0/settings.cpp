#include "settings.h"
#include "ui_settings.h"
#include <QDebug>

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix3/whiteblock.webp"));

    ui->difficulty_box->setChecked(true);//默认选中
    ui->track_num_box->setChecked(true);

    //难度选择
    connect(this->ui->easy, &QRadioButton::clicked, [&](){
        this->difficulty = 0;
        //qDebug() << "difficulty is " << difficulty;
    });

    connect(this->ui->normal, &QRadioButton::clicked, [&](){
        this->difficulty = 1;
        //qDebug() << "difficulty is " << difficulty;
    });

    connect(this->ui->difficult, &QRadioButton::clicked, [&](){
        this->difficulty = 2;
        //qDebug() << "difficulty is " << difficulty;
    });

    //轨道数选择
    connect(this->ui->track4, &QRadioButton::clicked, [&](){
        this->track_num = 4;
        //qDebug() << "track_num is " << track_num;
    });

    connect(this->ui->track6, &QRadioButton::clicked, [&](){
        this->track_num = 6;
        //qDebug() << "track_num is " << track_num;
    });

    //点击确认关闭设置窗口
    connect(this->ui->ensure_btn, &QPushButton::clicked, this, &Settings::quit);

}

Settings::~Settings()
{
    delete ui;
}
void Settings::quit()
{
    this->close();
    emit Set(this->track_num,this->difficulty);
}

void Settings::init()
{
    this->show();//显示界面
}
