#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//numbers 数字が入ってる配列
//i, j 入れ替えるインデックス
//size 配列の大きさ
void swap(int numbers[], int i, int j) {
  //ここを実装しましょう
  int temp;
  temp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = temp;
}

int main(int argc, char *argv[]) {
  int *numbers, size;
  //引数で読み込むファイルを指定
  char *filename = argv[1];
  //引数で探す数字を指定
  int i = atoi(argv[2]);
  int j = atoi(argv[3]);

  size = set_array(filename, &numbers);
  print_array(numbers, size);
  swap(numbers, i, j);
  print_array_two_mark(numbers, size, i, j);
  return 0;
}
