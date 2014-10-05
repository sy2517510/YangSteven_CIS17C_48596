/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on October 3 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define LNKDLST_H

#include <string>
#include <iostream>

using namespace std;

template<class T>
class LnkdLst {
public:
    LnkdLst(int);
    LnkdLst(const LnkdLst&);
    LnkdLst<T>& operator= (const LnkdLst<T>&);
    void prepend(int);
    void append(int);
    void extract(int);
    void insertAfter(int, int);
    void insertBefore(int, int);
    int getHead() const;
    int getTail() const;
    string toString();
    virtual ~LnkdLst();
private:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
};

int main()
{
    LnkdLst<int> list(0);
    
    list.append(3);
    list.append(5);
    list.prepend(2);
    list.prepend(7);
    list.extract(5);
    list.extract(2);
    list.insertAfter(3,9); 
    list.insertAfter(0,1);
    list.insertBefore(7, 3);
    list.insertBefore(1,8);
    
    cout << "The first value is: " << list.getHead() << endl;
    cout << "The last value is: " << list.getTail() << endl;
    cout << list.toString();
    
    return 0;
}

template<class T>
LnkdLst<T>::LnkdLst(int num)
{
    Node * newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    head = newNode;
}

template<class T>
LnkdLst<T>::LnkdLst(const LnkdLst& other)
{

}

template<class T>
LnkdLst<T>& LnkdLst<T>::operator= (const LnkdLst<T>& other)
{
    
}

template<class T>
void LnkdLst<T>::append(int num)
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
void LnkdLst<T>::prepend(int num)
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
void LnkdLst<T>::extract(int num)
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
void LnkdLst<T>::insertAfter(int value, int input)
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
void LnkdLst<T>::insertBefore(int value, int input)
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
int LnkdLst<T>::getHead() const
{
    return head->data;
}

template<class T>
int LnkdLst<T>::getTail() const
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
