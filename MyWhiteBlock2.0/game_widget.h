#ifndef GAME_WIDGET_H
#define GAME_WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "blockdata.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class game_widget;
}

class game_widget : public QWidget
{
    Q_OBJECT

public:
    explicit game_widget(QWidget *parent = nullptr);
    ~game_widget();
    void StartGame();
    void refresh();
    void SetBlockData(int width, int height);

public slots:
    void Set(int track,int diff);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void gameover(int x,int y,int diff,int score);

private slots:
    void UpdataData();

private:
    Ui::game_widget *ui;
    QTimer timer;
    Block_Data bData;
    double speed;
    int Bwidth, Bheight;

    bool failed;
    int score = 0;
    int track_num;
    int difficulty;
    QMediaPlayer * musicplayer;
    QMediaPlaylist * myplaylist;
};

#endif // GAME_WIDGET_H
