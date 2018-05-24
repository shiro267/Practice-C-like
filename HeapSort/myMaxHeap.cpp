#include "function.h"


int myMaxHeap::head()
{
    if(point.size()==1){
        return -1;
    }
    return point[1];
}



void myMaxHeap::reSize(int n)
{
    // n=0 縮小兩倍
    // n=1 放大兩倍


    if(n==0)
    {
        point.resize(point.size()/2);
        point.reserve(point.capacity()/2);
        --level;
    }
    else
    {

        if(point.size()==1)
        {
            point.reserve(1+1);
            point.resize(1+1);
            level = 1;
        }
        else
        {
            point.reserve(point.capacity()*2);
            point.resize(point.size()*2);
            ++level;
        }
    }
}

bool myMaxHeap::push(int i)
{
    size_t checkP(nextPoint/2);
    size_t curP(nextPoint);

    if(curP+1 > point.size())
    {
        reSize(1);
    }

    while(i>point[checkP] && checkP!=0)
    {
            point[curP] = point[checkP];
            curP = checkP;
            checkP /= 2;
    }
    point[curP] = i;
    ++nextPoint;
    return true;
}





int myMaxHeap::pop()
{
    point[0] = point[1];
    --nextPoint;
    size_t curP = 1;
    int tail = point[nextPoint];
    while((tail < point[curP*2] || tail < point[curP*2+1])&& curP*2 < nextPoint)
    {
        if(point[curP*2] > point[curP*2+1])
        {
            point[curP] = point[curP*2];
            curP *= 2;
        }
        else
        {
            point[curP] = point[curP*2+1];
            curP = curP*2 + 1;
        }
    }
    point[curP] = tail;

    if(nextPoint < point.size()/2)
    {
        reSize(0);
    }
    return point[0];
}

int myMaxHeap::currentLevel()
{
    return level;
}

void myMaxHeap::print()
{
    cout << "element numbers : " << nextPoint-1 << endl;
    cout << "current Level : " << level << endl;
    for(size_t i=1 ; i<nextPoint ; ++i){
        cout << point[i] << " ";
    }
    cout << endl;
    cout << endl;
}
