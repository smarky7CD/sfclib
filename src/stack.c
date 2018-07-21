#include "../include/stack.h"

stack* newStack(){
  stack* s = (stack*) malloc(sizeof(stack));   
  if(s == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }
  
  s->msz = MAXSIZE;

  s->stk = (TYPE*) malloc(sizeof(TYPE) * s->msz);
  if(s->stk == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }
  
  s->top = 0;
  
  return s;
}

void deleteStack(stack* s){
  free(s->stk);
  free(s);
}

void push(stack* s, int p){
  if(s->msz - s->top < 2){ // check if resizing needs to be done
    s->msz *= 2; 
    s->stk = (TYPE*) realloc(s->stk, sizeof(TYPE) * s->msz);
    if(s->stk == NULL){
      fprintf (stderr, "realloc() failed. Reallocation error upon resizing.\n");
      exit(1);
    }
  }
  s->stk[s->top++] = p; // add element to end and increase end pointer 
}

TYPE peek(stack* s){
  return s->stk[s->top - 1];
}

void pop(stack* s){
  s->top--;
}

int len(stack* s){
  return s->top;
}
