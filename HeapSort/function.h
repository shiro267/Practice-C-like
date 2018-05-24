

#ifndef FUNCTION_H_
#define FUNCTION_H_


#include <iostream>
#include <vector>

using namespace std;

class myMaxHeap{

public:
    myMaxHeap(): point(vector<int>{0}),nextPoint(1),level(0){
        cout << "myMaxHeap() constructor" << endl;

    };
    // 用一個binary tree (vextor type)建立
    // myHeap(vector<int> p);
    // 用一個binary tree (list tree type)建立
    // friend myTree;
    // myHeap(myTree p);
    // void reorder(); // reorder the heap

   //-----------------------------------------//

    int head();  // get max
    bool push(int i); // insert i into myMaxHeap,  return 是否成功insert
    int pop();   //return the max and delete it, reorder the heap
    void print();
    int currentLevel();

private:
    void reSize(int n);

    vector<int> point;
    size_t nextPoint;
    int level;
};


#endif

