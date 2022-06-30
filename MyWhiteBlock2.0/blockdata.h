#ifndef BLOCK_DATA_H
#define BLOCK_DATA_H

#include<QDebug>
#include<stdio.h>

struct BlockData
{
    int x, y;
    int width, height;
    BlockData * next;
};

class Block_Data
{
public:
    Block_Data();
    ~Block_Data();
    void init(BlockData **d, int x=0,int y=0, int width=0,int height=0);
    void insert(BlockData *d);
    void updata(int speed);

    bool remove(int x);
    bool remove(int x,int y);
    bool judge(int y);
    void clear();

    BlockData * get_pos(){ return head; }
    void show();

private:
    BlockData * head;
    BlockData * tail;
};

#endif // BLOCK_DATA_H
