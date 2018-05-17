#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int r(int value, int d) {
  int f = 1;
  for (; d > 1; d--)
    f*= 10;
  return (value/f) % 10;
}

void counting_sort(int a[], int b[], int k, int c[], int size, int d) {
  //前の実装を使いつつ，任意の桁の数字を返す関数をどこかに作るといいかも
  int i;
  for (i=0; i <= k; i++)
    c[i] = 0;
  for (i=0; i < size; i++)
    c[r(a[i], d)] = c[r(a[i], d)] + 1;
  for (i = 1; i <=k; i++)
    c[i] = c[i] + c[i-1];
  for (i= size-1; i >= 0; i--) {
    b[c[r(a[i], d)]-1] = a[i];
    c[r(a[i], d)] = c[r(a[i], d)] -1;
  }
}

void radix_sort(int a[], int k, int c[], int size) {
  //ここを実装．malloc使うかな．
  int d;
  int *b = malloc(sizeof(int) * size);
  for (d = 1; d <= 3; d++) {
    counting_sort(a, b, k, c, size, d);
    a = b;
    print_array(b,size);
    b = malloc(sizeof(int) * size);
  }
}

int main(int argc, char *argv[]) {
  char* filename = argv[1];
  int k = 10;

  int *a;
  int size = set_array(filename, &a);
  int *c = malloc(sizeof(int) * k);

  print_array(a, size);
  radix_sort(a, k, c, size);

  return 0;
}
