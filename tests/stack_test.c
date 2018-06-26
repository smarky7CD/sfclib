#include "../include/stack.h"

#define N printf("\n");

void printStack(stack* s){
  for(size_t i = 0; i < s->top; i++) printf("%d ", s->stk[i]);
  N;
};


int main(){
  stack* t = newStack(); //t for test

  // test pushing, tested MAXSIZE 1 for resizing test
  printf("Testing pushing and resizing\n");
  push(t,0);
  printStack(t);
  push(t,1);
  printStack(t);
  push(t,2);
  printStack(t);
  push(t,3);
  printStack(t);
  push(t,4);
  printStack(t);\
  push(t,5);
  printStack(t);
  N;

  //test peek and pop
  printf("Testing peeking and popping\n");
  printf("Peek: %d\n", peek(t));
  printf("Popping...\n");
  pop(t);
  printf("Peek: %d\n", peek(t));
  printf("Popping...\n");
  pop(t);
  printf("Peek: %d\n", peek(t));
  printf("Popping...\n");
  pop(t);
  N;
  
  //test deletion
  printf("Testing destruction of stack\n");
  deleteStack(t);
  N;

  return 0;
}
