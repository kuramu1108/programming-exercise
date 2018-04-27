#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

//INT_MAXを新しく確保した配列の最後に入れる
int *appendMax(int ary[], int size) {
  int *p;//新しく確保した配列の先頭アドレス

  //ここにコードを書く
  p = (int*) malloc((size + 1) * sizeof(int));
  int i;
  for (i =0; i < size+1; i++) {
    if (i != size) p[i] = ary[i];
    else p[i] = INT_MAX;
  }

  return p;
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int *numbers, *numbersWithMax, size;
  //引数で読み込むファイルを指定
  char *filename = argv[1];

  size = set_array(filename, &numbers);
  print_array(numbers, size);
  numbersWithMax = appendMax(numbers, size);
  print_array(numbersWithMax, size + 1);
  free(numbersWithMax);
  return 0;
}
