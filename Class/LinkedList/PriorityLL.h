/*
* File:   PriorityLL.h
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
	void prependP(T);
	void appendP(T);
	void extract(T);
	void pullHighestP();
	void insertAfterP(T, T);
	void insertBeforeP(T, T);

};
template<class T>
PriorityLL<T>::PriorityLL(T num) : LnkdLst<T>(num)
{
	;
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
void PriorityLL<T>::prependP(T num)
{

}

template<class T>
void PriorityLL<T>::appendP(T num)
{

}

template<class T>
void PriorityLL<T>::extract(T num)
{

}

template<class T>
void PriorityLL<T>::pullHighestP()
{

}

template<class T>
void PriorityLL<T>::insertBeforeP(T value, T input)
{

}

template<class T>
void PriorityLL<T>::insertAfterP(T value, T input)
{

}

#endif	/* PRIORITYLL_H */
