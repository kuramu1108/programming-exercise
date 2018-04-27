#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int bSwap = 0, sSwap = 0;

void swap(int numbers[], int i, int j) {
  //問1の実装
  int temp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = temp;
}

void bubble_sort(int a[], int size) {
    //問2の実装 + bSwapを使う
  int i, j;
  for (i= 0; i < size-1; i++) {
    for (j = size-1; j > i; j--) {
      if (a[j] < a[j-1]) {
        swap(a, j, j-1);
        bSwap = bSwap + 1;
      }
    }
  }
}

void select_sort(int a[], int size) {
    //問3の実装 + sSwapを使う
  int i, j, min, k;
  for (i =0; i < size-1 ; i++) {
   k = i;
   min = a[i];
   for (j = i; j < size; j++) {
     if (min > a[j]) {
       min = a[j];
       k = j;
     }
   }
     swap(a, i, k);
     sSwap = sSwap + 1;
   
  }   
}

int main(int argc, char *argv[]) {
  int *bnumbers, size;
  int *snumbers;
  //引数で読み込むファイルを指定
  char *filename = argv[1];
  //numbersという配列にfileの中の数字を設定してる
  size = set_array(filename, &bnumbers);
  set_array(filename, &snumbers);
  bubble_sort(bnumbers, size);
  select_sort(snumbers, size);

  printf("bubble swap %d\n", bSwap);
  printf("select swap %d\n", sSwap);
  return 0;
}
