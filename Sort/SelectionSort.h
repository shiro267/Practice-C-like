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




#ifndef SELECTION_SORT
#define SELECTION_SORT

template <typename T>
void SelectionSort(T& input)
{
    int min;
    for(size_t i=0 ; i<input.size()-1 ; ++i)
    {
        min = i;
        for(size_t j=i+1 ; j<input.size() ; ++j)
        {
            if(input[min]>input[j]) min = j;
        }
        myswap(input[min],input[i]);
    }
    return;
}


#endif // SELECTION_SORT






