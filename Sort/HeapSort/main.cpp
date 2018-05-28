
#include "function.h"

int main()
{
    myMaxHeap a;

    a.print();


    a.push(2);
    a.print();
    a.push(3);
    a.print();
    a.push(5);
    a.print();
    a.push(10);
    a.print();
    a.push(1);
    a.print();
    a.push(15);
    a.print();
    a.push(7);
    a.print();
    a.push(9);
    a.print();
    a.push(6);
    a.print();
    a.pop();
    a.print();
    a.pop();
    a.print();
    a.pop();
    a.print();

    vector<int> text = {1,2,3,4,5,6,7,8,9,10,11,12};


    myMaxHeap b(text);

    b.print();



}
