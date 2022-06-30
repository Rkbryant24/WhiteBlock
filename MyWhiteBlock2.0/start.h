#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();
    int user_num;
    QString cur;
    void init();

signals:
    void login(int x,int y);
    void regist(int x,int y);
    void register_success();
    void register_fail();
    void login_success(QString user);
    void login_fail(int x);
    void userbest(int diff,int score);

private:
    Ui::Start *ui;

public slots:
    void updhis(int diff,int score);
    void loginbut();
    void quitbut();
    void registbut();
    void updusr(QString user,QString pswd);
    void check(QString user,QString pswd);
};

#endif // START_H
