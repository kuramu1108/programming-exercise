#include <stdio.h>
#include <stdlib.h>

int* girl_drop(int n) {
  //ここでメモリ領域を確保し，そのポインタを返す．
  int* p;

  // メモリを確保

  p = (int*) malloc(sizeof(int));
  // 確保した場所にnを代入
  *p = n;
  return p;
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int number = atoi(argv[1]);
  int* pnumber;

  pnumber = girl_drop(number);

  printf("星色ガールドロップ%d話\n", *pnumber);

  free(pnumber);

  return 0;
}
