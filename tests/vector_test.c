#include "../include/vector.h"

#define N printf("\n");

void printVector(vector* v){
  for(size_t i = 0; i < v->end; i++) printf("%d ", v->vec[i]);
  N;
};


int main(){
  vector* t = newVector(); //t for test

  // test pushing, tested MAXSIZE 1 for resizing test
  printf("Testing pushing and resizing\n");
  push(t,11);
  printVector(t);
  push(t,5);
  printVector(t);
  push(t,7);
  printVector(t);
  push(t,13);
  printVector(t);
  push(t,2);
  printVector(t);\
  push(t,3);
  printVector(t);
  N;
  
  // test find
  printf("Testing find\n");
  printf("7 is at position: %d\n", find(t,7));
  printf("9 is at position: %d\n", find(t,9));
  N;
  
  // test sort
  printf("Testing sort\n");
  sort(t);
  printVector(t);
  N;
  
  // test del
  printf("Testing del\n");
  del(t,9);
  del(t,5);
  printVector(t);
  printf("t->cur = %d\n", t->end);
  N;
  
  //test insert
  printf("Testing insert\n");
  insert(t,0,17);
  printVector(t);
  insert(t,4,19);
  printVector(t);
  N;

  //test search
  printf("Testing search\n");
  printf("19?: %d\n", search(t,19));
  printf("100?: %d\n", search(t,100));
  N;
  
  //test deletion
  printf("Testing destruction of vector\n");
  deleteVector(t);
  N;

  return 0;
}
