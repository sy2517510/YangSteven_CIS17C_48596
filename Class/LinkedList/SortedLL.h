/*
* File:   SortedLL.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#ifndef SORTEDLL_H
#define SORTEDLL_H

#include "LnkdLst.h"

template<class T>
class SortedLL : public LnkdLst<T> {
public:
	SortedLL(T);
	SortedLL(const SortedLL<T>&);
	SortedLL<T>& operator= (const SortedLL<T>&);
	void prepend(T);
	void append(T);
	void insertAfter(T, T);
	void insertBefore(T, T);

};
template<class T>
SortedLL<T>::SortedLL(T num) : LnkdLst<T>(num)
{

}

template<class T>
SortedLL<T>::SortedLL(const SortedLL&)
{

}

template<class T>
SortedLL<T>& SortedLL<T>::operator= (const SortedLL&)
{

}

template<class T>
void SortedLL<T>::prepend(T num)
{

}

template<class T>
void SortedLL<T>::append(T num)
{

}

template<class T>
void SortedLL<T>::insertBefore(T value, T input)
{

}

template<class T>
void SortedLL<T>::insertAfter(T value, T input)
{

}

#endif	/* SORTEDLL_H */
