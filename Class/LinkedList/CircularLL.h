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
	int getListCount() const;
	string toString();
private:
	int LIST_COUNT;

};

template<class T>
CircularLL<T>::CircularLL(T num) : LnkdLst<T>(num)
{
	LIST_COUNT++;
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
	Node *newNode;
	Node *nodePtr;
	Node *headPtr;

	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	headPtr = head;

	if (!head)
	{
		head = newNode;
	}
	else{
		nodePtr = head;
		newNode->next = nodePtr;
		head = newNode;
		newNode->next = headPtr;
	}
	LIST_COUNT++;
}

template<class T>
void CircularLL<T>::append(T num)
{
	Node * headPtr;
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	headPtr = head;

	if (!head)
	{
		head = newNode;
	}

	if (head)
	{
		Node * nodePtr;
		nodePtr = head;
		for (int i = 1; i < LIST_COUNT; i++)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->next = headPtr;
		LIST_COUNT++;
	}
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

template<class T>
int CircularLL<T>::getListCount() const
{
	return LIST_COUNT;
}

template<class T>
string CircularLL<T>::toString()
{
	string display = " ";
	worker = head;
	for (int i = 0; i < LIST_COUNT; i++)
	{
		cout << "Data element in the list ->" << worker->data << endl;
		worker = worker->next;
	}
	return display;
}


#endif	/* CIRCULARLL_H */
