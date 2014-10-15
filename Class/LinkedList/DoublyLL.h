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
DoublyLL<T>::DoublyLL(const DoublyLL<T>& other)
{
	Node *nodePtr;
	Node * newNode;
	Node * otherPtr;

	otherPtr = other.head;

	newNode = new Node;
	newNode->data = 0;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (other.head == NULL)
	{
		this->head = newNode;
	}
	else
	{
		newNode->data = otherPtr->data;
		this->head = newNode;
		nodePtr = this->head;
		while (otherPtr->next != NULL)
		{
			otherPtr = otherPtr->next;
			newNode = new Node;
			newNode->data = otherPtr->data;
			newNode->next = NULL;
			nodePtr->next = newNode;
			newNode->prev = nodePtr;
			nodePtr = nodePtr->next;
		}
	}
}

template<class T>
DoublyLL<T>& DoublyLL<T>::operator= (const DoublyLL<T>& other)
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
	newNode->prev = NULL;
	this->head = newNode;
	origPtr = this->head;

	while (otherPtr->next != NULL)
	{
		otherPtr = otherPtr->next;
		newNode = new Node;
		newNode->data = otherPtr->data;
		newNode->next = NULL;
		newNode->prev = NULL;
		origPtr->next = newNode;
		origPtr->prev = origPtr;
		origPtr = origPtr->next;
	}

	return *this;
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
		nodePtr->prev = newNode;
		head = newNode;
	}
	else { head = newNode; }
}

template<class T>
void DoublyLL<T>::append(T num)
{
	Node * nodePtr;

	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (!head)
	{
		nodePtr = head;
		newNode->prev = nodePtr;
		nodePtr->next = newNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
	}
}

template<class T>
void DoublyLL<T>::extract(T num)
{
	Node * nodePtr;
	Node * tracker;
	bool found = false;

	nodePtr = NULL;
	tracker = NULL;

	if (!head)
	{
		return;
	}
	if (head->data == num)
	{
		worker = head;
		if (head->next != NULL)
		{
			head = head->next;
			delete worker;
			return;
		}
		delete worker;
		head = NULL;
	}
	else
	{ 
		nodePtr = head;
			while (nodePtr->data != num)
			{
				nodePtr = nodePtr->next;
				if (nodePtr->data == num) found = true;
				if (nodePtr->next == NULL) break;
			}
			if (found)
			{
				tracker = nodePtr;
				nodePtr = nodePtr->prev;
				if (tracker->next != NULL)
				{
					worker = tracker->next;
					nodePtr->next = worker;
				}
				else { nodePtr->next = NULL; }
				delete tracker;
			} 
	}

}

template<class T>
void DoublyLL<T>::insertBefore(T value, T input)
{
	Node * nodePtr;
	Node * tracker;
	Node * newNode;
	bool found = false;

	newNode = new Node;
	newNode->data = input;
	newNode->next = NULL;
	newNode->prev = NULL;

	nodePtr = NULL;
	tracker = NULL;

	if (!head)
	{
		head = newNode;
		return;
	}
	nodePtr = head;
	if (nodePtr->data == value)
	{
		newNode->next = nodePtr;
		nodePtr->prev = newNode;
		head = newNode;
		return;
	}
	while (nodePtr->next != NULL)
	{
		nodePtr = nodePtr->next;
		if (nodePtr->data == value)
		{
			tracker = nodePtr;
			found = true;
			break;
		}
		if (nodePtr->next == NULL) break;
	}
	if (found)
	{
		newNode->next = tracker;
		if (nodePtr->prev != NULL)
		{
			nodePtr = nodePtr->prev;
			nodePtr->next = newNode;
			newNode->prev = nodePtr;
		}
	}
}

template<class T>
void DoublyLL<T>::insertAfter(T value, T input)
{
	Node * nodePtr;
	Node * tracker;
	Node * newNode;
	bool found = false;

	newNode = new Node;
	newNode->data = input;
	newNode->next = NULL;
	newNode->prev = NULL;

	nodePtr = NULL;
	tracker = NULL;

	if (!head)
	{
		head = newNode;
		return;
	}
	nodePtr = head;
	if (nodePtr->data == value)
	{
		worker = nodePtr->next;
		nodePtr->next = newNode;
		newNode->next = worker;
		newNode->prev = nodePtr;
		return;
	}
	while (nodePtr->next != NULL)
	{
		nodePtr = nodePtr->next;
		if (nodePtr->data == value)
		{
			tracker = nodePtr;
			found = true;
			break;
		}
		if (nodePtr->next == NULL) break;
	}
	if (found)
	{
		if (tracker->next != NULL)
		{
			nodePtr = tracker->next;
			tracker->next = newNode;
			newNode->next = nodePtr;
			newNode->prev = tracker;
		}
		else 
		{ 
			tracker->next = newNode;
			newNode->prev = tracker;
		}
	}
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
