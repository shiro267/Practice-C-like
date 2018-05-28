#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <vector>
using namespace std;

#endif // LIBRARY


#ifndef INSERT_SORT
#define INSERT_SORT

template <typename T>
void InsertSort(T& input)
{

    for(size_t i=1 ; i<input.size() ; ++i)
    {
        auto tmp = input[i];
        int j;
        for(j=i-1 ; j>=0 && tmp < input[j] ; --j)
        {
            input[j+1] = input[j];
        }
        input[j+1]=tmp;
    }

    return;
}



#endif // InsertSort
