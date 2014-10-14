/*
* File:   DoublyLL.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#ifndef DOUBLYLL_H
#define DOUBLYLL_H

#include <string>
#include <iostream>

template<class T>
class DoublyLL {
public:
	DoublyLL(T);
	DoublyLL(const DoublyLL<T>&);
	DoublyLL<T>& operator= (const DoublyLL<T>&);
	void prepend(T);
	void append(T);
	void extract(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	string toString();

private:
	struct Node {
		T data;
		Node *next;
		Node *prev;
	}; 
	Node * head;
	Node * worker;
};

template<class T>
DoublyLL<T>::DoublyLL(T num)
{
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	head = newNode;
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
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head)
	{
		Node *nodePtr;
		nodePtr = head;

		newNode->next = nodePtr;
		head = newNode;
	}
	else { head = newNode; }
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

template<class T>
string DoublyLL<T>::toString()
{
	string display = " ";
	if (head){
		worker = head;
		do{
			cout << "Data element in the list ->" << worker->data << endl;
			worker = worker->next;
		} while (worker);
	}
	return display;
}

#endif	/* DOUBLYLL_H */
