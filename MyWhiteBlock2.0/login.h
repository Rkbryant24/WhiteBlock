#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void clear();

private:
    Ui::Login *ui;

signals:
    void login(QString user,QString pswd);
public slots:
    void success();
    void fail(int x);
    void _init(int x,int y);
    void loginbut();
};

#endif // LOGIN_H
