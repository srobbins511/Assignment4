#ifndef GENDOUBLELINKEDLIST_H
#define GENDOUBLELINKEDLIST_H

#include "GenListNode.h"
#include <iostream>

using namespace std;

template<typename T>
class GenDoubleLinkedList
{
    private:
        GenListNode<T>* rear;
        unsigned int size;
    public:
        GenDoubleLinkedList();
        ~GenDoubleLinkedList();

        void insertFront(int k,T d);
        void insertBack(int k,T d);
        T removeFront();
        T removeBack();
        GenListNode<T>* remove(int k);
        T deletePos(int pos);
        int find(T d);

        bool isEmpty();
        void printList();
        unsigned int getSize();
        GenListNode<T>* front;
};

template<typename T>
GenDoubleLinkedList<T>::GenDoubleLinkedList()
{
    size = 0;
    front = NULL;
    rear = NULL;
}

template<typename T>
GenDoubleLinkedList<T>::~GenDoubleLinkedList()
{
    //research and finish correctly later
    
    while(front != NULL)
    {
        GenListNode<T> *temp = NULL;
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename T>
bool GenDoubleLinkedList<T>::isEmpty()//if list empty returns true
{
    return size==0;
}

template<typename T>
void GenDoubleLinkedList<T>::insertFront(int k, T data)
{
    GenListNode<T> *node = new GenListNode<T>(k, data);
    if(isEmpty()) //an Empty List
    {
        rear = node;
    }
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template<typename T>
T GenDoubleLinkedList<T>::removeFront()
{
    //check if empty before attempting to remove anything
    if( front == NULL )
    {
        throw 1;
    }
    //check if only one element
    GenListNode<T> *ft = front;

    if(size == 1) //front == back, front->next == NULL
    {
        //only node in list
        rear = NULL;
    }
    else{
        //have more than one element in the list
        front->next->prev = NULL;
    }
    front = front->next;
    T temp = ft->data;
    ft->next = NULL;
    delete ft;
    size--;
    return temp;
}

template<typename T>
void GenDoubleLinkedList<T>::insertBack(int k, T data)
{
    GenListNode<T> *node = new GenListNode<T>(k,data);
    if(isEmpty()) //empty list
    {
        front = node;
    }else{
        //not empty
        rear->next = node;
        node->prev = rear;
    }   
    rear = node;
    size++;
}

template<typename T>
T GenDoubleLinkedList<T>::removeBack()
{
    if(isEmpty())
    {
        throw 1;
    }

    GenListNode<T> *bk = rear;
    if(size == 1) //only one node in list
    {
        front = NULL;
    }
    else{
        rear->prev->next = NULL;
    }
    rear = rear->prev;
    T temp = bk->data;
    rear->prev = NULL;
    delete bk;
    size--;
    return temp;
}

template<typename T>
GenListNode<T>* GenDoubleLinkedList<T>::remove(int k) //the key
{
    if(isEmpty())
    {
        return NULL;
    }

    GenListNode<T> *curr = front;
    while(curr->key != k)
    {
        curr = curr->next;
        if(curr == NULL)
        {
            //did not find the value
            return NULL;
        }
    }

    if(curr == front)//check to see if the current value is the front
    {
        front = curr->next;
    }
    else{
        //not the front
        curr->prev->next = curr->next;
    }

    if(curr == rear)//check to see if the value is the back
    {
        rear = curr->prev;
    }
    else{
        //not the back
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    size--;
    return curr;
}

template<typename T>
int GenDoubleLinkedList<T>::find(T d)
{
    int idx = 0;
    GenListNode<T> *curr = front;
    while(curr != NULL)
    {
        if(curr->data = d)
        {
            //found the value
            break;
        }
        ++idx;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        //did not find the value
        idx = -1;
    }
    return idx;
}

template<typename T>
T GenDoubleLinkedList<T>::deletePos(int pos)
{
    //check to make sure that the position given actually exists
    if(pos>=size)
    {
        return NULL;
    }

    GenListNode<T> *curr = front;
    for(int i = 0; i<pos; ++i)
    {
        curr = curr->next;
    }

    if(curr == front)//check to see if the current value is the front
    {
        front = curr->next;
    }
    else{
        //not the front
        curr->prev->next = curr->next;
    }

    if(curr == rear)//check to see if the value is the back
    {
        rear = curr->prev;
    }
    else{
        //not the back
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    size--;
    return curr->data;
}

template<typename T>
void GenDoubleLinkedList<T>::printList()
{
    GenListNode<T> *curr = front;
    int idx = 0;
    while(curr != NULL)
    {
        cout<< ++idx << endl;
        cout<< "Key: " << curr->key << endl;
        cout<< "Date: " << curr->data << endl;
        curr = curr->next;
    }
}

template<typename T>
unsigned int GenDoubleLinkedList<T>::getSize()
{
    return size;
}

#endif