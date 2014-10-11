/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 10 2014, 8:00 PM
 */

#ifndef STACK_H
#define STACK_H

#include "LnkdLst.h"

template<class T>
class Stack {
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(T);
    void pop();
    T top();

private:
    int MAX_ITEMS;
};

template<class T>
Stack<T>::Stack()
{
    MAX_ITEMS = 0;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return true;
}

template<class T>
bool Stack<T>::isFull()
{
    return false;
}

template<class T>
void Stack<T>::push(T newNode)
{
    
}

template<class T>
void Stack<T>::pop()
{
    
}

template<class T>
T Stack<T>::top()
{
    
}

#endif	/* STACK_H */
