/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 10 2014, 8:00 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "LnkdLst.h"

template<class T>
class Queue {
public:
    Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(T);
    void dequeue(T&);
    
private:
    int MAX_ITEMS;
};

template<class T>
Queue<T>::Queue()
{
    MAX_ITEMS = 0;
}

template<class T>
void Queue<T>::makeEmpty()
{
    
}

template<class T>
bool Queue<T>::isEmpty()
{
    return true;
}

template<class T>
bool Queue<T>::isFull()
{
    return false;
}

template<class T>
void Queue<T>::enqueue(T newNode)
{
    
}

template<class T>
void Queue<T>::dequeue(T& node)
{
    
}

#endif	/* QUEUE_H */
