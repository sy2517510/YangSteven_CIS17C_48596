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

class LnkdLst {
public:
    LnkdLst(int);
    LnkdLst(const LnkdLst&);
    LnkdLst& operator= (const LnkdLst&);
    void prepend(int);
    void append(int);
    void extract(int);
    void insertAfter(int, int);
    void insertBefore(int, int);
    int getHead();
    int getTail();
    string toString();
    virtual ~LnkdLst();
private:
    struct Node{
         int data;
         Node *next;
    };
    Node *head;
    Node *worker;
};

int main()
{
    LnkdLst list(0);
    
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

LnkdLst::LnkdLst(int num)
{
    Node * newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    head = newNode;
}

LnkdLst::LnkdLst(const LnkdLst& other)
{

}

LnkdLst& LnkdLst::operator= (const LnkdLst& other)
{
    
}

void LnkdLst::append(int num)
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

void LnkdLst::prepend(int num)
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

void LnkdLst::extract(int num)
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

void LnkdLst::insertAfter(int value, int input)
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

void LnkdLst::insertBefore(int value, int input)
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

int LnkdLst::getHead()
{
    return head->data;
}

int LnkdLst::getTail()
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

string LnkdLst::toString()
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

LnkdLst::~LnkdLst()
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
