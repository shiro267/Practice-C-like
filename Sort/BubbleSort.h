#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <vector>
using namespace std;

#endif // LIBRARY


#ifndef SWAP
#define SWAP

template <typename S>
void myswap(S& a,S& b)
{
    S tmp;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

#endif // SWAP


#ifndef BUBBLE_SORT
#define BUBBLE_SORT

template<typename T>
void BubbleSort(T& input)
{
    for(size_t i=0 ; i<input.size()-1 ; ++i)
    {
        bool swaped = false;
        for(size_t j=input.size()-1 ; j>i ; --j)
        {
            if(input[j-1]>input[j])
            {
                swaped = true;
                myswap(input[j-1],input[j]);
            }
        }
        if(swaped==false)return;
    }
    return;
}

#endif //BUBBLE_SORT




