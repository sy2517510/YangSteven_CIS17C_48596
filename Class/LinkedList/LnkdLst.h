/*
 * File:   LnkdLst.h
 * Author: Steven Yang
 * Created on September 20, 2014, 6:00 PM
 */

#ifndef LNKDLST_H
#define LNKDLST_H

#include <string>
#include <iostream>
#include <sstream>

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
  if(num == 0) head = NULL;
  else{
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
      newList[i].data = i;
        if(i == ((count+num) - 1))
        {
          newList[i].next = NULL;
          break;
        }
      newList[i].next = &newList[i+1];
    }
  newList[count+num+1].next = NULL;
}

string LnkdLst::toString()
{
  std::ostringstream o;
  if(head){
      worker=head;
      do{
           o << "Data element in the list -> " << worker->data
            << endl;
           worker=worker->next;
      }while(worker);
  }
  return o.str();
}

LnkdLst::~LnkdLst()
{
  delete worker;
}

#endif	/* LNKDLST_H */
