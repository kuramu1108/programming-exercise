#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int numbers[], int i, int j) {
  //問1の実装
  int temp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = temp;
}

void select_sort(int a[], int size) {
  //ここを実装しましょう
  //どこかでprint_array(a, size);を使いましょう
  int i, j, min, k;
  for (i = 0; i < size-1; i++) {
    min = a[i];
    k = i;
    for (j = i; j < size; j++) {
      if (min > a[j]) {
        min = a[j];
        k = j;
      }
    }
    swap(a, i, k);
    print_array(a, size);
  }
}

int main(int argc, char *argv[]) {
  int *numbers, size;
  //引数で読み込むファイルを指定
  char *filename = argv[1];

  size = set_array(filename, &numbers);
  print_array(numbers, size);
  select_sort(numbers, size);
  return 0;
}
