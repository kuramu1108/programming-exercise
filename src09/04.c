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

void uniq(int A[], int size) {
  //ここを実装
  //print_arrayを使って，重複を排除した配列を表示
  quick_sort(A, 0, size-1);
  int v = A[0], i, _size = 0;
  int B[size];
  B[0] = v;
  _size++;
  for (i = 0; i < size; i++) {
    if (A[i] != v) {
      B[_size] = A[i];
      v = A[i];
      _size++;
    }
  }
  print_array(B, _size);
}

int main(int argc, char *argv[]) {
  int size;
  int* A;
  char* filename = argv[1];

  size = set_array(filename, &A);
  print_array(A, size);
  uniq(A, size);

  return 0;
}
