#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int A[], int a, int b) {
  int temp = A[a];
  A[a] = A[b];
  A[b] = temp;
}

int partition(int A[], int p, int r) {
  //ここを実装
  int x = A[r];
  int i = p - 1, j;
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, ++i, r);
  return i;
}

void quick_sort(int A[], int p, int r) {
  if (p < r) {
     int q = partition(A, p, r);
     quick_sort(A, p, q-1);
     quick_sort(A, q+1, r);
  }
}

int main(int argc, char *argv[]) {
  int size;
  int* A;
  char* filename = argv[1];

  size = set_array(filename, &A);
  print_array(A, size);
  quick_sort(A, 0, size - 1);
  print_array(A, size);

  return 0;
}

