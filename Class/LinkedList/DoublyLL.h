/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 10 2014, 8:00 PM
 */

#ifndef DOUBLYLL_H
#define DOUBLYLL_H

#include "LnkdLst.h"

template<class T>
class DoublyLL : public LnkdLst<T> {
public:
    DoublyLL(T);
    DoublyLL(const DoublyLL<T>&);
    DoublyLL<T>& operator= (const DoublyLL<T>&);
    void prepend(T);
    void append(T);
    void extract(T);
    void insertAfter(T, T);
    void insertBefore(T, T);

private:
    Node *prev;
};

template<class T>
DoublyLL<T>::DoublyLL(T num)
{
    
}

template<class T>
DoublyLL<T>::DoublyLL(const DoublyLL<T>&)
{
    
}

template<class T>
DoublyLL<T>& DoublyLL<T>::operator= (const DoublyLL<T>&)
{
    
}

template<class T>
void DoublyLL<T>::prepend(T num)
{
    
}

template<class T>
void DoublyLL<T>::append(T num)
{
    
}

template<class T>
void DoublyLL<T>::extract(T num)
{
    
}

template<class T>
void DoublyLL<T>::insertBefore(T value, T input)
{
    
}

template<class T>
void DoublyLL<T>::insertAfter(T value, T input)
{
    
}

#endif	/* DOUBLYLL_H */
