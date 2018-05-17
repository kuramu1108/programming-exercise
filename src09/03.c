#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//ここで前に実装したquick_sortを準備するといいかも
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

float median(int A[], int size) {
  quick_sort(A, 0, size-1);
  if (size % 2 == 0) {
    return (A[size/2-1] + A[size/2])/2.0;
  } else {
    return (float)A[size/2];
  }
}

int main(int argc, char *argv[]) {
  int size;
  int* A;
  char* filename = argv[1];

  size = set_array(filename, &A);
  printf("median %0.2f\n", median(A, size));

  return 0;
}

