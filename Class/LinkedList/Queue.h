/*
* File:   Queue.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#include <string>

#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue {
public:
	Queue();
	Queue(T);
	void makeEmpty();
	bool isEmpty();
	void enqueue(T);
	void dequeue(T&);
	string toString();

private:
	struct Node{
		T data;
		Node *next;
	};
	Node *head;
	Node *worker;
	int ITEMS;
};

template<class T>
Queue<T>::Queue()
{
	ITEMS = 0;
}

template<class T>
Queue<T>::Queue(T num)
{
	Node * newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	head = newNode;
	ITEMS = 1;
}

template<class T>
void Queue<T>::makeEmpty()
{

}

template<class T>
bool Queue<T>::isEmpty()
{
	return true;
}

template<class T>
void Queue<T>::enqueue(T newNode)
{

}

template<class T>
void Queue<T>::dequeue(T& node)
{

}

template<class T>
string Queue<T>::toString()
{
	string display = " ";
	if (head){
		worker = head;
		do{
			cout << "Data element in the queue ->" << worker->data << endl;
			worker = worker->next;
		} while (worker);
	}
	return display;
}

#endif	/* QUEUE_H */
