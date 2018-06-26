#ifndef __LLIST_H
#define __LLIST_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int // default type, easy to change here 

typedef struct node_tag{
  TYPE data; //can be changed to desired type in MACRO
  struct node_tag* prev;
  struct node_tag* next;
}node;

typedef struct{
  node* head;
  node* tail;
  int len;
}dlist;

dlist* newList();

void deleteList(dlist* l);

node* newNode(TYPE d);

node* getHead(dlist* l);

node* getTail(dlist* l);

node* getNode(dlist* l, TYPE v);

TYPE getData(node* n);

int len(dlist* l);

void prepend(dlist* l, TYPE p);

void append(dlist* l, TYPE a);

void del(dlist* l, TYPE d);
#endif
