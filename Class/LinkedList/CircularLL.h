/*
* File:   CircularLL.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include "LnkdLst.h"

template<class T>
class CircularLL : public LnkdLst<T> {
public:
	CircularLL(T);
	CircularLL(const CircularLL<T>&);
	CircularLL<T>& operator= (const CircularLL<T>&); 
	void prepend(T);
	void append(T);
	void extract(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	T getTail() const;

};

template<class T>
CircularLL<T>::CircularLL(T num) : LnkdLst<T>(num)
{
	
}

template<class T>
CircularLL<T>::CircularLL(const CircularLL<T>&)
{

}

template<class T>
CircularLL<T>& CircularLL<T>::operator= (const CircularLL<T>&)
{

} 

template<class T>
void CircularLL<T>::prepend(T num)
{

}

template<class T>
void CircularLL<T>::append(T num)
{

}

template<class T>
void CircularLL<T>::extract(T num)
{

}

template<class T>
void CircularLL<T>::insertBefore(T value, T input)
{

}

template<class T>
void CircularLL<T>::insertAfter(T value, T input)
{

}

template<class T>
T CircularLL<T>::getTail() const
{

}

#endif	/* CIRCULARLL_H */
