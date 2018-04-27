#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//numbers 数字が入ってる配列
//n 探す数字
//size 配列の大きさ
//見つかった場所を返す．見つからなかった場合は-1を返す
int indexOf(int numbers[], int n, int size) {
  //ここにコードを書いてね
  int i;
  for (i =0; i < size; i++)
    if (numbers[i] == n)  return i;
  return -1;
}

int main(int argc, char *argv[]) {
  //配列のサイズは10に固定
  int *numbers;
  //引数で読み込むファイルを指定
  char *filename = argv[1];
  //引数で探す数字を指定
  int n = atoi(argv[2]);
  //numbersという配列にfileの中の数字を設定してる
  int size = set_array(filename, &numbers);

  int idx = indexOf(numbers, n, size);

  if (idx != -1)
    printf("何気ない%dがサンバ師匠をきずつけた\n", idx);
  else
    printf("何気ないオーレがフラメンコ師匠をきずつけた\n");

  return 0;
}
