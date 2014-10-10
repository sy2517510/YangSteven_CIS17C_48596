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
class Stack : public LnkdLst<T> {
    
};

template<class T>
class Queue : public LnkdLst<T> {
    
};

template<class T>
class DoublyLL : public LnkdLst<T> {
   
};

template<class T>
class CircularLL : public LnkdLst<T> {
    
};

template<class T>
class PriorityLL : public LnkdLst<T> {
    
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

#endif	/* LNKDLST_H */
