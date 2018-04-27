#include <stdio.h>
#include <stdlib.h>

void hari(int n) {
  if (n != 0) {
    printf("私ハリフキダシ見ると死んでしまいます\n");
    hari(--n);
  }
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  //引数で探す数字を指定
  int n = atoi(argv[1]);

  hari(n);

  return 0;
}
