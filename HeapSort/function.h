

#ifndef FUNCTION_H_
#define FUNCTION_H_


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class myMaxHeap{

public:
    myMaxHeap(): point(vector<int>{0}),nextPoint(1),level(0){};
    // �Τ@��binary tree (vextor type)�إ�
    myMaxHeap(vector<int> &p);
    // �Τ@��binary tree (list tree type)�إ�
    // friend myTree;
    // myHeap(myTree p);
    // void reorder(); // reorder the heap

   //-----------------------------------------//


    void push(int i); // insert i into myMaxHeap,  return �O�_���\insert
    int pop();   //return the max and delete it, reorder the heap

    int head();  // get max
    int currentLevel();
    void print();



private:
    void reSize(int n);
    void rebuild(); // for constructor  myMaxHeap(vector<int> &p);
    vector<int> point;
    size_t nextPoint;
    int level;
};


#endif

