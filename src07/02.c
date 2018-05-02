#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int A[], int a, int b) {
  int temp = A[a];
  A[a] = A[b];
  A[b] = temp;
}

void max_heapify(int A[], int i, int size) {
  //ココを実装
  //別関数を定義する必要もあるかも
  if (i > size || i < 1) return;
  print_heap(A, size);
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

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int size, *A;
  char *filename = argv[1];
  int pos = atoi(argv[2]);

  size = set_heap(filename, &A);

  max_heapify(A, pos, size);

  print_heap(A, size);

  return 0;
}

