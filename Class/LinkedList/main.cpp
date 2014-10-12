#include "LnkdLst.h"
#include "CircularLL.h"
#include "DoublyLL.h"
#include "PriorityLL.h"
#include "SortedLL.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
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

	//To exit
	char c;
	cin >> c;

	return 0;
}
