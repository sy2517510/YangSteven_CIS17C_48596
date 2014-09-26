/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on September 20, 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define LNKDLST_H

#include <string>
#include <iostream>

using namespace std;

class LnkdLst {
public:
    LnkdLst(int);
    void append(int);
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

LnkdLst::LnkdLst(int num)
{
    Node * newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    head = newNode;
/*
  Node *list = new Node[num];
  head = list;
  for(int i = 0; i < num; i++)
    {
      list[i].data = i;
      if(i == (num - 1))
        {
          list[i].next = NULL;
          break;
        }
      list[i].next = &list[i+1];
    } */
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
