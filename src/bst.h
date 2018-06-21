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
  node* root;
  int size;
}bst;

bst* newBST();

node* newNode(TYPE v);

TYPE nodeValue(node* n);

void deleteAllNodes(node* r);

void deleteBST(bst* t);

void insert(bst* t, TYPE i);

int insertNode(node*c, TYPE i);

node* search(bst* t, TYPE s);

node* searchNodes(node* n, TYPE s);

node* getMin(node* m);

node* delete(bst* t, TYPE d);

node* deleteNode(node* n, TYPE d);

int getSize(bst* t);

void printTree(bst* t);

void printNodes(node * p);
#endif
