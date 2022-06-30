#include "blockdata.h"

Block_Data::Block_Data()
{
    head = nullptr;
    tail = nullptr;
}

Block_Data::~Block_Data()
{
    clear();
}

void Block_Data::init(BlockData **d, int x, int y, int width, int height)
{
    BlockData *n = *d;
    n->x = x;
    n->y = y;
    n->width = width;
    n->height = height;
    n->next = NULL;
}

void Block_Data::insert(BlockData *d)
{
    if(!tail)
    {
        head = d;
        tail = d;
        return;
    }

    tail->next = d;
    tail = tail->next;
}

bool Block_Data::remove(int x,int y)
{
    if(!head)
        return false;

    if(x < head->x || head->x + head->width < x
            || y < head->y || head->y + head->height < y)
        return false;

    BlockData *n = head;
    if(n == tail)
        head = tail = NULL;

    else
        head = head->next;

    delete n;
    return true;
}

bool Block_Data::remove(int x)
{
    if(!head)
        return false;

    if(x < head->x || head->x + head->width < x)
        return false;

    BlockData *n = head;

    if(n == tail)
        head = tail = NULL;

    else
        head = head->next;

    delete n;
    return true;
}

void Block_Data::updata(int speed)
{
    BlockData *n = head;
    while(n)
    {
        n->y += speed;
        n = n->next;
    }
}

bool Block_Data::judge(int y)
{
    if(head && head->y >= y)
        return false;
    return true;
}

void Block_Data::clear()
{
    BlockData *n = head;
    while(n)
    {
        head = head->next;
        delete n;
        n = head;
    }
    tail = 0;
}

void Block_Data::show()
{
    BlockData *n = head;
    while(n)
    {
        printf("%d,%d,%d,%d\n",n->x,n->y,n->width,n->height);
        n = n->next;
    }
    printf("====================\n");
    fflush(stdout);
}

