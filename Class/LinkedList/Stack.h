/*
* File:   Stack.h
* Author: Steven Yang
* Created on October 10 2014, 8:00 PM
*/

#ifndef STACK_H
#define STACK_H

#include <string>

template<class T>
class Stack {
public:
	Stack();
	Stack(T);
	bool isEmpty();
	void push(T);
	void pop();
	T top();
	int size();
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
Stack<T>::Stack()
{
	ITEMS = 0;
}

template<class T>
Stack<T>::Stack(T num)
{
	ITEMS = 1;
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
void Stack<T>::push(T num)
{
	Node * newNode;
	newNode = new Node;
	newNode->data = num;
	newNode->next = head;

	head = newNode;
	ITEMS++;
}

template<class T>
void Stack<T>::pop()
{
	if (head)
	{
		Node * tracker;
		tracker = head;
		if(head->next != NULL) head = head->next;
		else{ head = NULL; }
		delete tracker;
		ITEMS--;
	}
}

template<class T>
T Stack<T>::top()
{
	if (head) return head->data;
}

template<class T>
int Stack<T>::size()
{
	return ITEMS;
}

template<class T>
string Stack<T>::toString()
{
	string display = " ";
	if (head){
		worker = head;
		do{
			cout << "Data element in the stack ->" << worker->data << endl;
			worker = worker->next;
		} while (worker);
	}
	return display;
}

#endif	/* STACK_H */
