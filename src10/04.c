#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void shell_sort(int a[], int h, int size) {
  //ここを実装
  int i, j;
  for (i = 0; i < size; i++) {
    for (j = i-h; j >=0 && a[j] > a[j+h]; j-=h) {
        int temp = a[j];
        a[j] = a[j+h];
        a[j+h] = temp;
    }
  }
}

int main(int argc, char *argv[]) {
  char* filename = argv[1];

  int *a, i;
  int size = set_array(filename, &a);

  for (i = 3; i > 0; i--) {
    print_array(a, size);
    shell_sort(a, i, size);
  }
  print_array(a, size);

  return 0;
}
