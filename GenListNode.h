#ifndef GENLISTNODE_H
#define GENLISTNODE_H
#include <iostream>

using namespace std;

template<typename T>
class GenListNode{

    public:
        int key;
        T data;
        GenListNode *next;
        GenListNode *prev;
        
        //constructor
        GenListNode();
        GenListNode(int k,T d);
        ~GenListNode();
};

template<typename T>
GenListNode<T>::GenListNode()
{
    key = 0;
    data = NULL;
    next = NULL;
    prev = NULL;
}

template<typename T>
GenListNode<T>::GenListNode(int k,T d)
{
    key = k;
    data = d;
    next = NULL;
    prev = NULL;
}

template<typename T>
GenListNode<T>::~GenListNode()
{
    //research the destructor for doubly linked lists and list nodes
}

#endif