#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *newArrayList = malloc(sizeof(ArrayList));
  newArrayList->data = malloc(2 * sizeof(ArrayList));
  newArrayList->capacity = 2;
  newArrayList->size = 0;
  
  return newArrayList;
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity)
  {
    l->data = realloc(l->data, (l->capacity * 2) * sizeof(void*));
    l->capacity *= 2;
  }

  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i >l->size)
  {
    return;
  }

  if(l->size == l->capacity)
  {
    l->data = realloc(l->data, (l->capacity * 2) * sizeof(void*));
    l->capacity *= 2;
  }

  for(int k = l->size; k > i; k--)
  {
    l->data[k] = l->data[k-1];
  }

  l->data[i] = data;
  l->size++;

}

void* pop(ArrayList * l, int i){
  if(l == NULL) return NULL;

  if(l->size == 0) return NULL;

  if(i < 0)
  {
    i += l->size + i;
  }

  if(i < 0 || i > l->size) return NULL;

  void *datoElim = l->data[i];

  for(int k = i; k <l->size - 1; k++)
  {
    l->data[k] = l->data[k+1];
  }
  
  return datoElim;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
