#ifndef END_H
#define END_H

#include <QWidget>

namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = 0);
    ~End();

signals:
    void hall();
    void restart();
    void updhis(int diff,int score);

public slots:
    void updbest(int diff,int score);
    void _init(int x,int y,int diff,int score);
    void hallbut();
    void restartbut();

private:
    Ui::End *ui;
};

#endif // END_H
