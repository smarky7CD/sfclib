#ifndef __BST_H
#define __BST_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int // default type, easy to change here 

typedef struct node_tag{
  TYPE value; //can be changed to desired type in MACRO
  struct node_tag* left;
  struct node_tag* right;
}node;

typedef struct{
  node* roots;
  int size;
}bst;

bst* newBST();

void deleteBST(bst* t);

node* newNode(TYPE v);

void insert(bst* t, TYPE i);

TYPE find(bst* t, TYPE f);

void del(bst* t, TYPE d);

int getSize(bst* t);

int getHeight(bst* t);
#endif
