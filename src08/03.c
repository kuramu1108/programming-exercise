#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int A[], int a, int b) {
  int temp = A[a];
  A[a] = A[b];
  A[b] = temp;
}

void max_heapify(int A[], int i, int size) {
  if (i > size || i < 1) return;
  int l = i*2;
  int r = i *2 +1;
  int largest = i;
  if (l <= size && A[i] < A[l]) largest = l;
  if (r <= size && A[largest] < A[r]) largest = r;
  if (largest != i) {
    swap(A, largest, i);
    max_heapify(A, largest, size);
  } 
}

void build_max_heap(int A[], int size) {
  int i;
  for (i = size/2 + 1; i > 0; i--) max_heapify(A, i, size);
}

void heap_increase_key(int A[], int i, int key) {
  if (key < A[i]) {
    fprintf(stderr, "new key is smaller than current key\n");
    exit(1);
  }

  //ここを実装
  A[i] = key;
  while (i > 1 && A[i/2] < A[i]) {
    swap(A, i/2, i);
    i/=2;
  }
}

int main(int argc, char *argv[]) {

  int size, *A;
  char *filename = argv[1];
  int pos = atoi(argv[2]), val = atoi(argv[3]);

  size = set_heap(filename, &A);

  build_max_heap(A, size);
  heap_increase_key(A, pos, val);
  print_heap(A, size);

  return 0;
}
