#include <QApplication>
#include "login.h"
#include "start.h"
#include "regist.h"
#include "end.h"
#include "game_widget.h"
#include "gamehall.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start *S = new Start();
    S->resize(500,400);
    S->move(700,200);

    Login *L = new Login();
    Regist *R = new Regist();
    End *E = new End();
    Gamehall *G = new Gamehall();
    Settings *St = new Settings();
    game_widget *w = new game_widget();

    QObject::connect(S, &Start::login, L, &Login::_init);  //点击登录
    QObject::connect(S, &Start::regist, R, &Regist::_init);  //点击注册
    QObject::connect(L, &Login::login, S, &Start::check);
    QObject::connect(R, &Regist::regist, S, &Start::updusr);
    QObject::connect(S, &Start::login_success, L, &Login::success);
    QObject::connect(S, &Start::login_success, G, &Gamehall::init);//进入游戏大厅
    QObject::connect(St, &Settings::Set, w,&game_widget::Set); //点击确定，进入游戏
    QObject::connect(S, &Start::login_fail, L, &Login::fail);
    QObject::connect(S, &Start::register_success, R, &Regist::success);//注册成功
    QObject::connect(S, &Start::register_fail, R, &Regist::fail);//注册失败
    QObject::connect(S, &Start::userbest, E, &End::updbest);
    QObject::connect(G, &Gamehall::logout, S, &Start::show);//点击结束
    QObject::connect(G, &Gamehall::gotoSetting, St, &Settings::init);//进入设置
    QObject::connect(G, &Gamehall::gotoStart, w, &game_widget::refresh);
    QObject::connect(G, &Gamehall::gotoStart, w, &game_widget::show);
    QObject::connect(w, &game_widget::gameover, E, &End::_init);
    QObject::connect(E, &End::hall, w, &game_widget::close);
    QObject::connect(E, &End::hall, G, &Gamehall::show);
    QObject::connect(E, &End::restart, w, &game_widget::refresh);
    QObject::connect(E, &End::updhis, S, &Start::updhis);

    S->init();
    return a.exec();
}
