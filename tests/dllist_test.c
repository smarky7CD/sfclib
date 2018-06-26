#include "../include/dllist.h"

#define N printf("\n");

void printList(dlist* l){
  node* tmp = l->head;
  while(tmp != NULL){
    printf("%d->",getData(tmp));
    tmp = tmp->next;
  }
  printf("NULL");
  N;
};


int main(){
  dlist* t = newList(); // t for test

  // appends and prepends
  printf("Testing append and prepend...\n");
  append(t, 5);
  printList(t);
  append(t, 12);
  prepend(t, 14);
  printList(t);
  prepend(t, 3);
  append(t, 6);
  printList(t);
  prepend(t, 8);
  N;

  // len test one
  printf("The length is : %d\n", len(t));
  N;
  
  // util functions
  printf("Testing util functions...\n");
  node* h = getHead(t);
  node* ta = getTail(t);
  node* three = getNode(t,3);
  printf("The value of the head = %d\n", getData(h));
  printf("The value of the tail = %d\n", getData(ta));
  printf("The value of the node three = %d\n", getData(three));
  N;

  // del
  printf("Testing deletions...\n");
  del(t,8);
  printList(t);
  del(t,6);
  printList(t);
  del(t,14);
  printList(t);
  N;
  
  // len test two
  printf("The length after deletions is : %d\n", len(t));
  N;

  printf("Testing list destruction...");
  deleteList(t);
  N;

  return 0;
 }
