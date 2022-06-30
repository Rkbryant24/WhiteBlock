#ifndef REGIST_H
#define REGIST_H

#include <QWidget>

namespace Ui {
class Regist;
}
class Regist : public QWidget
{
    Q_OBJECT

public:
    explicit Regist(QWidget *parent = 0);
    ~Regist();
    void clear();

private:
    Ui::Regist *ui;

signals:
    void regist(QString user,QString pswd);

public slots:
    void success();
    void fail();
    void _init(int x,int y);
    void registbut();

};

#endif // REGIST_H
