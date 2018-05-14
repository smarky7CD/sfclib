#ifndef __LLIST_H
#define __LLIST_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int // default type, easy to change here 

typedef struct node_tag{
  TYPE data; //can be changed to desired type in MACRO
  struct node_tag* next;
}node;

typedef struct{
  node* head;
  node* tail;
  int len;
}list;

list* newList();

void deleteList(list* l);

node* newNode(TYPE d);

node* getHead(list* l);

node* getTail(list* l);

node* getNode(list* l, TYPE v);

TYPE getData(node* n);

int len(list* l);

void prepend(list* l, TYPE p);

void append(list* l, TYPE a);

void del(list* l, TYPE d);
#endif
