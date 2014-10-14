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
	void insert(T num);

};
template<class T>
SortedLL<T>::SortedLL(T num) : LnkdLst<T>(num)
{
	;
}

template<class T>
SortedLL<T>::SortedLL(const SortedLL& other) : LnkdLst<T>(other)
{
	;
}

template<class T>
SortedLL<T>& SortedLL<T>::operator= (const SortedLL& other)
{
	Node * origPtr;
	Node * otherPtr;
	Node * newNode;

	origPtr = this->head;
	otherPtr = other.head;

	if (origPtr == NULL || otherPtr == NULL)
	{
		return *this;
	}

	do
	{
		this->worker = this->head;
		this->head = this->head->next;
		delete this->worker;
	} while (this->head);

	newNode = new Node;
	newNode->data = otherPtr->data;
	newNode->next = NULL;
	this->head = newNode;
	origPtr = this->head;

	while (otherPtr->next != NULL)
	{
		otherPtr = otherPtr->next;
		newNode = new Node;
		newNode->data = otherPtr->data;
		newNode->next = NULL;
		origPtr->next = newNode;
		origPtr = origPtr->next;
	}

	return *this;
}

template<class T>
void SortedLL<T>::insert(T num)
{
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	if (head)
	{
		Node * nodePtr;
		nodePtr = head;

		if (nodePtr->data > num)
		{
			newNode->next = nodePtr;
			head = newNode;
			return;
		}
		while (nodePtr->next != NULL)
		{
			if (nodePtr->next->data > num)
			{
				worker = nodePtr->next;
				nodePtr->next = newNode;
				newNode->next = worker;
				return;
			}
			nodePtr = nodePtr->next;
		} 
		nodePtr->next = newNode; 
	}
	else
	{
		head = newNode;
	}
}

#endif	/* SORTEDLL_H */
