#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int numbers[], int i, int j) {
  //問1の実装
  int temp;
  temp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = temp;
}

void bubble_sort(int a[], int size) {
  //ここを書きましょう
  //どこかでprint_array(a, size);を使いましょう
  int i, j;
  for (i = 0; i < size-1; i++) {
    for (j = size-1; j > i; j--) {
      if (a[j] < a[j-1]) swap(a, j, j-1);
    }
    print_array(a, size);
  }
}

int main(int argc, char *argv[]) {
  int *numbers, size;
  //引数で読み込むファイルを指定
  char *filename = argv[1];

  size = set_array(filename, &numbers);
  print_array(numbers, size);
  bubble_sort(numbers, size);
  return 0;
}
