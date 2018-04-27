#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define N 6

int main(int argc, char *argv[]) {
  int popuko[N] = {9, 1, 1, 10, 2, 6};
  int pipimi[N];
  int i;

  //ここで配列をコピーしましょう！
  for (i =0; i < N; i++) {
    pipimi[i] = popuko[N-i-1];
  }
  //ここから下は表示部分なので，変えないように！
  for (i = 0; i < N; i++) {
    printf("%d ", pipimi[i]);
  }
  printf("\n");

  return 0;
}
