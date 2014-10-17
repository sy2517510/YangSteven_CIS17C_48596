#include "LnkdLst.h"
#include "CircularLL.h"
#include "DoublyLL.h"
#include "PriorityLL.h"
#include "SortedLL.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
	//Linked List
	cout << "Linked List" << endl;
	cout << "=============" << endl;
	LnkdLst<float> list1(0);
	LnkdLst<float> list2(list1);

	list2.append(4);
	list2.append(8);
	list2.append(10);

	list1.append(3);
	list1.append(5);
	list1.prepend(2);
	list1.prepend(7);
	list1.extract(5);
	list1.extract(2);
	list1.insertAfter(3, 9);
	list1.insertAfter(0, 1);
	list1.insertBefore(7, 3);
	list1.insertBefore(1, 8);

	LnkdLst<float> list3(list1);

	cout << "This is list [1]" << endl;
	cout << "================" << endl;
	cout << "The first value is: " << list1.getHead() << endl;
	cout << "The last value is: " << list1.getTail() << endl;
	cout << list1.toString() << endl;

	cout << "This is list [2]" << endl;
	cout << "================" << endl;
	cout << "The first value is: " << list2.getHead() << endl;
	cout << "The last value is: " << list2.getTail() << endl;
	cout << list2.toString() << endl;

	cout << "Setting list[1] = list[2]" << endl;
	list1 = list2;
	cout << "================" << endl;
	cout << "The first value is: " << list1.getHead() << endl;
	cout << "The last value is: " << list1.getTail() << endl;
	cout << list1.toString() << endl;

	cout << "This is list [3]" << endl;
	cout << "================" << endl;
	cout << "The first value is: " << list3.getHead() << endl;
	cout << "The last value is: " << list3.getTail() << endl;
	cout << list3.toString() << endl; 


	//Stack
	cout << "Stack" << endl;
	cout << "=============" << endl;
	Stack<float> stack(2);
	stack.push(4);
	stack.push(8);
	stack.toString();
	cout << "Stack top: " << stack.top() << endl;
	cout << "Stack size: " << stack.size() << endl;
	stack.pop();
	stack.pop();
	stack.toString(); 
	cout << stack.size() << endl; 

	//Queue
	cout << "Queue" << endl;
	cout << "=============" << endl;
	Queue<float> queue(4);
	queue.enqueue(7);
	queue.enqueue(0);
	queue.toString();
	queue.makeEmpty();
	queue.enqueue(2);
	queue.toString(); 

	//Doubly LL
	cout << "Doubly Linked List" << endl;
	cout << "=============" << endl;
	DoublyLL<float> doubly(8);
	doubly.prepend(4);
	doubly.prepend(0);
	doubly.append(7);
	doubly.append(9);
	doubly.extract(0);
	doubly.extract(1);
	doubly.insertBefore(9, 2);
	doubly.insertBefore(2, 3);
	doubly.insertAfter(4, 1);
	doubly.insertAfter(1, 5);
	doubly.toString(); 

	DoublyLL<float> doubly2(doubly);
	cout << "List 2" << endl;
	doubly2.toString();

	DoublyLL<float> doubly3(4);
	cout << "List 3" << endl;
	doubly3 = doubly2;
	doubly3.toString(); 

	//Circular LL
	cout << "Circular Linked List" << endl;
	cout << "=============" << endl;
	CircularLL<float> circList(8);
	circList.prepend(3);
	circList.append(2);
	circList.append(4);
	circList.extract(2);
	circList.insertBefore(8, 0);
	circList.insertAfter(4, 7);
	circList.toString();
	cout << "This is the tail: " << circList.getTail() << endl;

	CircularLL<float> circList2(circList);
	circList2.toString();

	//Sorted LL
	cout << "Sorted Linked List" << endl;
	cout << "=============" << endl;
	SortedLL<float> sorted(4);
	sorted.insert(7);
	sorted.insert(5);
	sorted.insert(2);
	sorted.insert(4.5);
	sorted.insert(9);
	sorted.toString();

	cout << "Second List" << endl;
	SortedLL<float> sorted2(sorted);
	sorted2.insert(3);
	sorted2.toString();

	sorted = sorted2;
	sorted.toString(); 
	
	/*
	PriorityLL<float> priority(2);
	priority.appendP(8);
	priority.prependP(7);
	priority.extract(2);
	priority.toString(); */

	//To exit
	char c;
	cin >> c;

	return 0;
}
