#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int max(int numbers[], int size) {
  //ここに書いてね
  int i, max = numbers[0];
  for (i =1; i < size; i++) 
    if (numbers[i] > max) max = numbers[i];
  return max;
}

int main(int argc, char *argv[]) {
  int *numbers;
  //引数で読み込むファイルを指定
  char *filename = argv[1];

  //numbersという配列にfileの中の数字を設定してる
  int size = set_array(filename, &numbers);

  printf("出ておじゃれ．姿は隠しても%dは臭いでわかりまするぞ．\n", max(numbers, size));

  return 0;
}
