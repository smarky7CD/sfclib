#include "../include/bst.h"

bst* newBST(){
  bst* t = (bst*) malloc(sizeof(bst));   
  if(t == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }

  t->root = NULL;
  t->size = 0;
  
  return t;
}

node* newNode(TYPE v){
  node* n = (node*) malloc(sizeof(node));
  n->value = v;
  n->left = NULL;
  n->right = NULL;
  return n;
}

TYPE nodeValue(node* n){
  return n->value;
}

void deleteAllNodes(node* r){
  if (r->left == NULL && r->right == NULL){
    free(r);
  }else{
    deleteAllNodes(r->left);
    deleteAllNodes(r->right);
  }
}

void deleteBST(bst* t){
  deleteAllNodes(t->root); //recursively delete all nodes
  if(t->root != NULL) free(t->root);
  free(t);
}

void insert(bst* t, TYPE i){
  if(t->root == NULL){
    t->size++;
    t->root = newNode(i);
  }else{
    if(insertNode(t->root, i) != -1){
      t->size++;
    }
  }
}


int insertNode(node* c, TYPE i){
  if(c->value == i){
    return -1;
  }else if(c->value < i && c->right == NULL){
    c->right = newNode(i);
    return 1;
  }else if(c->value > i && c->left == NULL){
    c->left = newNode(i);
    return 1;
  }else if(c->value < i){
    insertNode(c->right,i);
  }else{
    insertNode(c->left,i);
  }
  return -2;
}

node* search(bst* t, TYPE s){
  if(t->root == NULL){
    return t->root;
  }else{
    return searchNodes(t->root, s);
  }
}

node* searchNodes(node* n, TYPE s){
  while(n){
    if (n->value == s){
      return n;
    }else if(n->value > s){
      n = n->left;
    }else{
      n = n->right;
    }   
  }
  return n;
}

node* getMin(node* m){
  node* cn = m;
  while(cn->left != NULL){
    cn = cn->left;
  }
  return cn;
}

node* delete(bst* t, TYPE d){
  if(t->root == NULL){
    return t->root;
  }else{
    return deleteNode(t->root, d);
  }
}
node* deleteNode(node* n, TYPE d){
  if (n->value > d){
    n->left = deleteNode(n->left,d);
  }else if(n->value < d){
    n->right = deleteNode(n->right,d);
  }else{
    if(n->left == NULL){
      node* tmp = n->left;
      free(n);
      return tmp;
    }else if(n->right == NULL){
      node* tmp = n->left;
      free(n);
      return tmp;
    }
    node* tmp = getMin(n->right);
    n->value = tmp->value;
    n->right = deleteNode(n->right, tmp->value);    
  }
  return n;
}

int getSize(bst* t){
  return t->size;
}

void printTree(bst* t){
  printNodes(t->root);
  printf("\n\n");
}

void printNodes(node *p){
  if(p != NULL){
    printNodes(p->left);
    printf("%d ", p->value);
    printNodes(p->right);
  }
}
