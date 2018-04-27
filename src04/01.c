#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int bobunemimicci(n) {
  return n < 2? n: bobunemimicci(n - 1) + bobunemimicci(n - 2);
}

int* array_bobu(int n) {
  int* p; //メモリが確保されたポインタ
  p = (int*) malloc(n * sizeof(int));
  //ここにコード追加
  int i;
  for (i = 0; i < n; i++) {
    p[i] = bobunemimicci(i);
  }
  return p;
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int* p;
  p = array_bobu(n);
  print_array(p, n);
  free(p);

  return 0;
}
