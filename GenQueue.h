#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include "GenDoubleLinkedList.h"

template<typename T>
class GenQueue
{
    public:
        GenQueue(); // default constructor
        GenQueue(int maxSize); //Overloaded constructor
        ~GenQueue();

        //core functions

        void insert(int k,T d);
        T* remove();
        

        //aux functions
        T* peak();
        //bool isFull();
        bool isEmpty();
        int getSize();
        //Vars
        //ListNode* front; //aka head
        // ListNode* rear; // aka tail
        unsigned int size; //num items in queue
        //int numElements;

        GenDoubleLinkedList<T> *myQueue; //DoubleLinked List
};

template<typename T>
GenQueue<T>::GenQueue()
{
    myQueue = new GenDoubleLinkedList<T>();
    size = 0;
}

template<typename T>
GenQueue<T>::~GenQueue()
{
    delete myQueue;
}

template<typename T>
void GenQueue<T>::insert(int k, T d)
{
    myQueue->insertBack(k,d);
    ++size;
}

template<typename T>
T* GenQueue<T>::remove()
{
    T *temp;
    try
    {
        temp = myQueue->removeFront();
        size--;
    }
    catch(int e)
    {
        if(e = -1)
        {
            cout << "No Element to Remove" << endl;
        }
        else{
            cout << "Unknown Error Occurred, Exiting" << endl;
        } 
    }
    return temp;
}

template<typename T>
T* GenQueue<T>::peak()
{
    T *temp = myQueue->front->data;
    return temp;
}

template<typename T>
bool GenQueue<T>::isEmpty()
{
    return (size==0);
}

template<typename T>
int GenQueue<T>::getSize()
{
    return size;
}

#endif