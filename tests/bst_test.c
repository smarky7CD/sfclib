#include "../src/bst.h"

#define N printf("\n");

int main(){
  bst* t = newBST(); // t for test

  // inserts
  printf("Testing insert...\n");
  insert(t, 5);
  printTree(t);
  insert(t, 12);
  insert(t, 14);
  printTree(t);
  insert(t, 3);
  insert(t, 6);
  printTree(t);
  insert(t, 8);
  N;

  // size test one
  printf("The size is : %d\n", getSize(t));
  N;
  
  // serach and util functions
  printf("Testing search and util functions...\n");
  node* x = search(t,5);
  node* y = search(t,100); // should return NULL
  node* z = search(t,3);
  printf("The value of x = %d\n", nodeValue(x));
  y == NULL ? printf("y does note exist in tree.\n") : printf("The value of y = %d\n", nodeValue(y));
  printf("The value of z = %d\n", nodeValue(z));
  N;

  // del
  printf("Testing deletions...\n");
  delete(t,8);
  printTree(t);
  delete(t,6);
  printTree(t);
  delete(t,14);
  printTree(t);
  N;
  
  // size test two
  printf("The size after deletions is : %d\n", getSize(t));
  N;

  printf("Testing list destruction...");
  deleteBST(t);
  N;

  return 0;
 }
