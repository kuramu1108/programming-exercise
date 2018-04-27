#include <stdio.h>
#include <stdlib.h>
#include "utils.h" 

//要素の合計を返す関数
int accum(int numbers[], int size) {
//ここに書いてね
  int i,sum = 0;
  for (i =0; i < size; i++)
    sum += numbers[i];
  return sum;
}

int main(int argc, char *argv[]) {
  int *numbers;
  //引数で読み込むファイルを指定
  char *filename = argv[1];
  //numbersという配列にfileの中の数字を設定してる
  int size = set_array(filename, &numbers);

  printf("タイマーはステージ決定と同時にスタートします．終わりました．タイムは%d秒です．さて，乾燥した間奏ですが，\n", accum(numbers, size));

  return 0;
}
