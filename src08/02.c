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

int heap_extract_max(int A[], int size) {
  if (size < 1) {
    fprintf(stderr, "heap underflow\n");
    exit(1);
  }
  //ここを実装
  int max = A[1];
  A[1] = A[size];
  build_max_heap(A, size-1);
  return max;
}


int main(int argc, char *argv[]) {

  int size, *A;
  char *filename = argv[1];

  size = set_heap(filename, &A);

  build_max_heap(A, size);
  printf("Max is %d and extracted\n", heap_extract_max(A, size));
  print_heap(A, size - 1);

  return 0;
}

