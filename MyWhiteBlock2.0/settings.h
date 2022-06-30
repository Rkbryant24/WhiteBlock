#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    int track_num,difficulty;

private:
    Ui::Settings *ui;

signals:
    void Set(int track,int diff);

public slots:
    void init();//初始化
    void quit();

};

#endif // SETTINGS_H
