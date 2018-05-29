
#ifndef LIBRARY
#define LIBRARY

#include <string>
#include <iostream>
using namespace std;

#endif // LIBRARY


#ifndef MY_STACK_LINK_LIST
#define MY_STACK_LINK_LIST


template <typename T> class myLinkStack;

// LinkStack //
template <typename T>
class LinkStack{

friend class myLinkStack<T>;
public:
    LinkStack(T);
private:
    T val;
    LinkStack* next;
};

// myLinkStack //

template <typename T>
class myLinkStack{

public:
    myLinkStack(): head(nullptr) {};

    bool isEmpty();
    bool push(T);
    bool pop();
    T getHead();
private:
    LinkStack<T>* head;
};





// LinkStack implementation //

template <typename T>
LinkStack<T>::LinkStack(T x)
{
    val = x;
    next = nullptr;
}



// myLinkStack implementation //

template <typename T>
bool myLinkStack<T>::isEmpty()
{
    if(head==nullptr) return true;
    return false;
}

template <typename T>
bool myLinkStack<T>::push(T val)
{
    auto newVal = new LinkStack<T>(val);

    if(!isEmpty())
    {
        newVal->next = head;
    }
    head = newVal;
    return true;
}


template <typename T>
bool myLinkStack<T>::pop()
{
    if(isEmpty())return false;

    auto tmp = head;
    head = head->next;
    delete tmp;
    return true;
}

template <typename T>
T myLinkStack<T>::getHead()
{
    if(!isEmpty()) return head->val;
    cout << "myLinkStack is Empty!" << endl;
    return T();
}

#endif // MY_STACK_LINK_LIST
