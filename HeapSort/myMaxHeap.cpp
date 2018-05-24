#include "function.h"


myMaxHeap::myMaxHeap(vector<int> &p)
{
    point = p;
    point.insert(point.begin(),0);
    nextPoint = point.size();
    level = static_cast<int>(static_cast<float>(log(nextPoint-1))/static_cast<float>(log(2)))+1;
    rebuild();
}

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

void myMaxHeap::push(int n)
{
    size_t checkP(nextPoint/2);
    size_t curP(nextPoint);

    if(curP+1 > point.size())
    {
        reSize(1);
    }

    while(n>point[checkP] && checkP!=0)
    {
            point[curP] = point[checkP];
            curP = checkP;
            checkP /= 2;
    }
    point[curP] = n;
    ++nextPoint;
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

void myMaxHeap::rebuild()
{
    for(size_t i=(nextPoint-1)/2; i>0 ; --i)
    {
        auto curP = i;
        int tmp = point[curP];
        while(curP<nextPoint/2)
        {
            if(point[curP*2]>point[curP*2+1])  // 左邊大
            {
                if(tmp<point[curP*2])
                {
                    point[curP] = point[curP*2];
                    curP *= 2;
                }
                else
                {
                    break;
                }
            }
            else // 右邊大
            {
                if(tmp<point[curP*2+1])
                {
                    point[curP] = point[curP*2+1];
                    curP = curP*2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        if(curP*2+1==nextPoint)
        {
            if(tmp<point[curP*2])
            {
                point[curP] = point[curP*2];
                curP *= 2;
            }
        }
        point[curP] = tmp;
    }
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
