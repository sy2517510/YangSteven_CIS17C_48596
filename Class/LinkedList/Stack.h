/*
* File:   Stack.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
public:
	Stack();
	Stack(T);
	bool isEmpty();
	void push(T);
	void pop();
	T top();

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
Stack<T>::Stack()
{
	ITEMS = 0;
}

template<class T>
Stack<T>::Stack(T num)
{
	ITEMS = 0;
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	head = newNode;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (ITEMS == 0) return true;
	else{ return false; }
}

template<class T>
void Stack<T>::push(T newNode)
{

}

template<class T>
void Stack<T>::pop()
{

}

template<class T>
T Stack<T>::top()
{

}

#endif	/* STACK_H */
