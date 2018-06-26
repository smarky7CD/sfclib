#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int // default type, easy to change here 
#define MAXSIZE 32 // default size, easy to change here

typedef struct{
  TYPE *vec; //can be changed to desired type in MACRO
  int end; // end pointer for vector
  int msz; // dynamic, initially set to default
}vector;

vector* newVector();

void deleteVector(vector* v);

void push(vector* v, int e);

void insert(vector* v, int p, int e);

int find(vector* v, int t);

int search(vector*v, int t);

void del(vector* v, int r);
  
void sort(vector* v);
#endif
