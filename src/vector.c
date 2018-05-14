#include "vector.h"

vector* newVector(){
  vector* v = (vector*) malloc(sizeof(vector));   
  if(v == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }
  
  v->msz = MAXSIZE;

  v->vec = (TYPE*) malloc(sizeof(TYPE) * v->msz);
  if(v->vec == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }
  
  v->end = 0;
  
  return v;
}

void deleteVector(vector* v){
  free(v->vec);
  free(v);
}

void push(vector* v, int e){
  if(v->msz - v->end < 2){ // check if resizing needs to be done
    v->msz *= 2; 
    v->vec = (TYPE*) realloc(v->vec, sizeof(TYPE) * v->msz);
    if(v->vec == NULL){
      fprintf (stderr, "realloc() failed. Reallocation error upon resizing.\n");
      exit(1);
    }
  }
  v->vec[v->end++] = e; // add element to end and increase end pointer 
}

void insert(vector* v, int p, int e){
  if(v->msz - v->end < 2){ // check if resizing needs to be done
    v->msz *= 2; 
    v->vec = (TYPE*) realloc(v->vec, sizeof(TYPE) * v->msz);
    if(v->vec == NULL){
      fprintf (stderr, "realloc() failed. Reallocation error upon resizing.\n");
      exit(1);
    }
  }
  
  int* tmp = (TYPE*) malloc(sizeof(TYPE) * v->msz);
  if(tmp == NULL){
    fprintf (stderr, "malloc() failed. Remove will fail.\n");
    exit(1);
  }else{
    for(size_t i = 0; i < p; i++) tmp[i] = v->vec[i];
    tmp[p] = e;
    for(size_t j = p; j < v->end; j++) tmp[j+1] = v->vec[j];
    free(v->vec);
    v->vec = tmp;
    v->end++;
  }
}

int find(vector* v, int t){
  // simple linear search
  int found = -1;
  
  for(size_t i = 0; i < v->end; i++){
    if(v->vec[i] == t){
      found = i;
      break;
    }
  }
  
  return found; // -1 if not found
}

// sorting procedure 
void swap(int* vec, int i, int j){
  int tmp = vec[i];
  vec[i] = vec[j];
  vec[j] = tmp;
}

int partition(int* vec, int i, int j, int p){
  int lp = i-1; // left pointer
  int rp = j; // right pointer

  while(1){
    while(vec[++lp] < p) {} // do nothing
    while(rp > 0 && vec[--rp] > p){} //do nothing
    if (lp >= rp) break; // end condition
    swap(vec,lp,rp);
  }

  swap(vec,lp,j);
  return lp;
}

void quickSort(int* vec, int i, int j){
  if (j-i <= 0) return;
  int p = vec[j];
  p = partition(vec,i,j,p);
  quickSort(vec,i,p-1);
  quickSort(vec,p+1,j);
}
// end of sorting routine "back end"

int search(vector* v, int t){
  // binary search, more efficient for large collections
  // boolean return type: 1 if TRUE (element in vec), 0 if FALSE (element not in vec)
  TYPE* copy = (TYPE*) malloc(sizeof(TYPE) * v->msz);
  for(size_t i = 0; i < v->end; i++) copy[i] = v->vec[i];
  quickSort(copy, 0, v->end-1);

  int left = 0;
  int right = v->end-1;
  int mid = (left+right)/2;
  
  while(left<=right){
    if (copy[mid] == t){
      free(copy);
      return 1;
    }else if(copy[mid] < t){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
    mid = (left+right)/2;
  }
  
  free(copy);
  return 0;
};

void del(vector* v, int r){
  int found = find(v,r);

  if (found == -1){
    fprintf(stderr, "Value %d not in vector.\n", r);
  }else{
    TYPE* tmp = (TYPE*) malloc(sizeof(TYPE) * v->msz);
    if(tmp == NULL){
      fprintf (stderr, "malloc() failed. Remove will fail.\n");
      exit(1);
    }else{
      for(size_t i = 0; i < found; i++) tmp[i] = v->vec[i];
      for(size_t j = found+1; j < v->end; j++) tmp[j-1] = v->vec[j];
      free(v->vec);
      v->vec = tmp;
      v->end--;
    }
  }  
}

void sort(vector* v){
  quickSort(v->vec, 0, v->end-1); //call to quickSort with init args
};
