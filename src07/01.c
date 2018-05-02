#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int parent(int i) {
  //必要なら実装
  return i/2;
}

void print_leaves(int ary[], int size) {
  //printf("%d ", ary[i]); //配列の要素を表示するときは最後にスペースを
  //printf("\n");//要素を表示し終わったら，改行
  int i;
  for (i=size/2+1; i <= size;i++)  printf("%d ", ary[i]);
  printf("\n");

}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int *numbers, size;
  //引数で読み込むファイルを指定
  char *filename = argv[1];

  size = set_heap(filename, &numbers);
  print_leaves(numbers, size);
  return 0;
}
