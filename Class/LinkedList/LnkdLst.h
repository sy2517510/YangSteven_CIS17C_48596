/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 9 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define LNKDLST_H

#include <string>
#include <iostream>

using namespace std;

struct Node;

template<class T>
class LnkdLst {
public:
    LnkdLst(T);
    LnkdLst(const LnkdLst<T>&);
    LnkdLst<T>& operator= (const LnkdLst<T>&);
    void prepend(T);
    void append(T);
    void extract(T);
    void insertAfter(T, T);
    void insertBefore(T, T);
    T getHead() const;
    T getTail() const;
    string toString();
    virtual ~LnkdLst();
protected:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
};

template<class T>
class Stack {
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(T);
    void pop();
    T top();

private:
    int MAX_ITEMS;
};

template<class T>
class Queue {
public:
    Queue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(T);
    void dequeue(T&);
    
private:
    int MAX_ITEMS;
};

template<class T>
class DoublyLL : public LnkdLst<T> {
public:
    DoublyLL(T);
    DoublyLL(const DoublyLL<T>&);
    DoublyLL<T>& operator= (const DoublyLL<T>&);
    void prepend(T);
    void append(T);
    void extract(T);
    void insertAfter(T, T);
    void insertBefore(T, T);

private:
    Node *prev;
};

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
    string toString();
    
};

template<class T>
class PriorityLL : public LnkdLst<T> {
public:
    PriorityLL(T);
    PriorityLL(const PriorityLL<T>&);
    PriorityLL<T>& operator= (const PriorityLL<T>&);
    void prepend(T);
    void append(T);
    void extract(T);
    void insertAfter(T, T);
    void insertBefore(T, T);
    
};

template<class T>
class SortedLL : public LnkdLst<T> {
    
};

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
    list1.insertAfter(3,9); 
    list1.insertAfter(0,1);
    list1.insertBefore(7, 3);
    list1.insertBefore(1,8);
    
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
     
    return 0;
}

template<class T>
LnkdLst<T>::LnkdLst(T num)
{
    Node * newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    head = newNode;
}

template<class T>
LnkdLst<T>::LnkdLst(const LnkdLst<T>& other)
{
    Node *nodePtr;
    Node * newNode;
    Node * otherPtr;
    
    otherPtr = other.head;
    
    newNode = new Node;
    newNode->data = 0;
    newNode->next = NULL;
    if(other.head == NULL)
    {
        this->head = newNode;
    }else
    {
        newNode->data = otherPtr->data;
        this->head = newNode;
        nodePtr = this->head;
        while(otherPtr->next != NULL)
        {
            otherPtr = otherPtr->next;
            newNode = new Node;
            newNode->data = otherPtr->data;
            newNode->next = NULL;
            nodePtr->next = newNode;
            nodePtr = nodePtr->next;
        }
    }
}

template<class T>
LnkdLst<T>& LnkdLst<T>::operator= (const LnkdLst<T>& other)
{
    Node * origPtr;
    Node * otherPtr;
    Node * newNode;
    
    origPtr = this->head;
    otherPtr = other.head;
    
    if(origPtr == NULL || otherPtr == NULL)
    {
        return *this;    
    }
    
    do
    {
        this->worker = this->head;
        this->head = this->head->next;
        delete this->worker;
    }while(this->head);
    
    newNode = new Node;
    newNode->data = otherPtr->data;
    newNode->next = NULL;
    this->head = newNode;
    origPtr = this->head;
    
    while(otherPtr->next != NULL)
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
void LnkdLst<T>::append(T num)
{
    Node * newNode;
    Node * nodePtr;
    
    newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    if(!head)
    {
    	head = newNode;
	}
	else{
		nodePtr = head;
		while(nodePtr->next){
		nodePtr = nodePtr->next;
	}
	nodePtr->next = newNode;
	}
}

template<class T>
void LnkdLst<T>::prepend(T num)
{
    Node *newNode;
    Node *nodePtr;
    
    newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    if(!head)
    {
        head = newNode;   
    } 
    else{
        nodePtr = head;
        newNode->next = nodePtr;
        head = newNode;
    }
}

template<class T>
void LnkdLst<T>::extract(T num)
{
    Node *nodePtr;
    Node *tracker;
    Node *prev;
    
    if(!head)
    {
        return;
    }
    else{
        if(head->data == num && head->next == NULL)
        {
            head = NULL;
            
        }else {
            bool found = false;
            nodePtr = head;
            while(nodePtr->data != num && nodePtr->next != NULL)
            {
                prev = nodePtr;
                nodePtr = nodePtr->next;
                if(nodePtr->data == num){ found = true;}
            }
            if(found)
            {
            tracker = nodePtr;
            nodePtr = tracker->next;
            prev->next = nodePtr;
            delete tracker;
            }
        }   
    }
}

template<class T>
void LnkdLst<T>::insertAfter(T value, T input)
{
    Node * nodePtr;
    Node * newNode;
    Node * tracker;
    
    newNode = new Node;
    newNode->data = input;
    newNode->next = NULL;
    
    if(!head)
    {
        return;
    }else
    {
        if(head->data == value)
        {
            tracker = head;
            if(tracker->next == NULL)
            {
                tracker->next = newNode;
            }else{
                nodePtr = tracker->next;
                newNode->next = nodePtr;
                tracker->next = newNode;
            }
        }else
        {
        nodePtr = head;
        bool found = false;
        while(nodePtr->data != value && nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
        if(nodePtr->data == value) found = true;
        }
            if(found)
            {
                tracker = nodePtr;
                if(nodePtr->next != NULL)
                {
                    nodePtr = nodePtr->next;
                    tracker->next = newNode;
                    newNode->next = nodePtr;
                }else{tracker->next = newNode;}
            }
        }
    }
}

template<class T>
void LnkdLst<T>::insertBefore(T value, T input)
{
    Node * nodePtr;
    Node * newNode;
    Node * prev;
    Node * tracker;
    
    newNode = new Node;
    newNode->data = input;
    newNode->next = NULL;
    
    if(!head)
    {
        return;
    }else
    {
        if(head->data == value)
        {
            tracker = head;
            if(tracker->next == NULL)
            {
                tracker->next = newNode;
            }else{
                newNode->next = tracker;
                head = newNode;
            }
        }else
        {
        nodePtr = head;
        bool found = false;
        while(nodePtr->data != value && nodePtr->next != NULL)
        {
            prev = nodePtr;
            nodePtr = nodePtr->next;
        if(nodePtr->data == value) found = true;
        }
            if(found)
            {
                tracker = nodePtr;
                prev->next = newNode;
                newNode->next = tracker;
            }
        }
    }
}

template<class T>
T LnkdLst<T>::getHead() const
{
    return head->data;
}

template<class T>
T LnkdLst<T>::getTail() const
{
    Node * nodePtr;
    nodePtr = head;
    
    if(nodePtr->next == NULL)
    {
        return nodePtr->data;   
    }else
    {
        while(nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
        }
        return nodePtr->data;
    }
}

template<class T>
string LnkdLst<T>::toString()
{
  string display = " ";
  if(head){
      worker=head;
      do{
           cout<<"Data element in the list ->"<<worker->data<<endl;
           worker=worker->next;
      }while(worker);
  }
  return display;
}

template<class T>
LnkdLst<T>::~LnkdLst()
{
    if(head){
        do{
            worker = head;
            head = head->next;
            delete worker;
        }while(head);
    }
}

template<class T>
Stack<T>::Stack()
{
    MAX_ITEMS = 0;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return true;
}

template<class T>
bool Stack<T>::isFull()
{
    return false;
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

template<class T>
Queue<T>::Queue()
{
    MAX_ITEMS = 0;
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
bool Queue<T>::isFull()
{
    return false;
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
DoublyLL<T>::DoublyLL(T num)
{
    
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
CircularLL<T>::CircularLL(T num)
{
    
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
    
}

template<class T>
void CircularLL<T>::append(T num)
{
    
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
string CircularLL<T>::toString()
{
    string word = ' ';
    
    return word;
}

template<class T>
PriorityLL<T>::PriorityLL(T num)
{
    
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
void PriorityLL<T>::prepend(T num)
{
    
}

template<class T>
void PriorityLL<T>::append(T num)
{
    
}

template<class T>
void PriorityLL<T>::extract(T num)
{
    
}
template<class T>
void PriorityLL<T>::insertBefore(T value, T input)
{
    
}

template<class T>
void PriorityLL<T>::insertAfter(T value, T input)
{
    
}
#endif	/* LNKDLST_H */
