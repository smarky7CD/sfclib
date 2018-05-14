#include "llist.h"

list* newList(){
  list* l = (list*) malloc(sizeof(list));   
  if(l == NULL){
    fprintf (stderr, "malloc() failed. List initialization error.\n");
    exit(1);
  }
  
  l->len = 0;
  
  return l;
}

void deleteList(list* l){
  node* tmp;
  while(l->head!=NULL){
    tmp = l->head->next;
    free(l->head);
    l->head = tmp;
  };
  
  free(l);
}

node* newNode(TYPE d){
  node* n = (node*) malloc(sizeof(node));
  if(n == NULL){
    fprintf (stderr, "malloc() failed. Node initialization error.\n");
    exit(1);
  };
  n->data = d;
  n->next = NULL;
  return n;
};

node* getHead(list* l){
  return l->head;
};

node* getTail(list* l){
  return l->tail;
};

node* getNode(list* l, TYPE v){
  node* tmp = l->head;
  while (tmp != NULL) {
    if (tmp->data == v) return tmp;
    tmp = tmp->next;
  }
  return tmp;
};

TYPE getData(node* n){
  return n->data;
};

int len(list* l){
  return l->len;
}

void prepend(list* l, TYPE p){
  node* n = newNode(p);
  if(l->head == NULL){
    l->head = n;
    l->tail = n;
  }else{
  n->next = l->head;
  l->head = n;
  }
  l->len++;
};

void append(list* l, TYPE a){
  node* n = newNode(a);
  if(l->head == NULL){
    l->head = n;
    l->tail = n;
  } else{
    l->tail->next = n;
    l->tail = n;
  }
  l->len++;
};

void del(list* l, TYPE d){
  node* prev = NULL;
  node* cur = l->head;

  while (cur != NULL) {
    if (cur->data == d) { // match
      l->len--;
      if (cur == l->head) { // head node case
	l->head = cur->next;
      }
      else {
	prev->next = cur->next; 
      }
      if (cur == l->tail) l->tail = prev;
      free(cur);
      break;
    }
    prev = cur;
    cur = cur->next;
  }
}
