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
    LnkdLst(const LnkdLst&);
    LnkdLst& operator= (const LnkdLst&);
    void prepend(int);
    void append(int);
    void extract(int);
    void insertAfter(int);
    void insertBefore(int);
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

/*
int main()
{
    LnkdLst list(0);
    list.append(3);
    list.append(5);
    cout << list.toString();
    
    return 0;
}
*/

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
    
}

void LnkdLst::extract(int num)
{
    
}

void LnkdLst::insertAfter(int num)
{
    
}

void LnkdLst::insertBefore(int num)
{
    
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
