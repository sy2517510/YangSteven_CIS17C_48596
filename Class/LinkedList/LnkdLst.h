/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on September 20, 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

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

int main()
{
    //Create a linked list
    LnkdLst list(1);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    list.toString();
    return 0;
}

LnkdLst::LnkdLst(int num)
{
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
    }
}

void LnkdLst::append(int num)
{
  int count = 0;
  worker = head;
  while(worker)
    {
      count++;
      worker = worker->next;
    }
  delete worker;
  Node *newList = new Node[count+num];
  head = newList;

  for(int i = 0; i < count+num; i++)
    {
    	if(i == ((count+num) - 1))
        {
          newList[i].next = NULL;
          break;
        }
      newList[i].data = i;
      newList[i].next = &newList[i+1];
    }
  newList[count+num+1].next = NULL;
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
  delete worker;
}

#endif	/* LNKDLST_H */
