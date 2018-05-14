#ifndef __STACK_H
#define __STACK_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int // default type, easy to change here 
#define MAXSIZE 32 // default size, easy to change here

typedef struct{
  TYPE *stk; //can be changed to desired type in MACRO
  int top; // top pointer
  int msz; // dynamic, initially set to default
}stack;

stack* newStack();

void deleteStack(stack* s);

void push(stack* s, int p);

TYPE peek(stack* s);

void pop(stack* s);
#endif
