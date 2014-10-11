/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 10 2014, 8:00 PM
 */

#ifndef PRIORITYLL_H
#define PRIORITYLL_H

#include "LnkdLst.h"

template<class T>
class PriorityLL : public LnkdLst<T> {
public:
    PriorityLL(T);
    PriorityLL(const PriorityLL<T>&);
    PriorityLL<T>& operator= (const PriorityLL<T>&);
    void prepend(T);
    void append(T);
    void extract(T);
    void insertAfter(T, T);
    void insertBefore(T, T);
    
};
template<class T>
PriorityLL<T>::PriorityLL(T num)
{
    
}

template<class T>
PriorityLL<T>::PriorityLL(const PriorityLL<T>&)
{
    
}

template<class T>
PriorityLL<T>& PriorityLL<T>::operator= (const PriorityLL<T>&)
{
    
}

template<class T>
void PriorityLL<T>::prepend(T num)
{
    
}

template<class T>
void PriorityLL<T>::append(T num)
{
    
}

template<class T>
void PriorityLL<T>::extract(T num)
{
    
}
template<class T>
void PriorityLL<T>::insertBefore(T value, T input)
{
    
}

template<class T>
void PriorityLL<T>::insertAfter(T value, T input)
{
    
}

#endif	/* PRIORITYLL_H */
