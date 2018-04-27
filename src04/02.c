#include <stdio.h>
#include <stdlib.h>

char getChar(int i) {
  return "hihanwananimoumanaisoredokoroka"[(i % 31)];
}

char* fan(int n) {
  char *p; /* 文字列の最初を指すポインタ */
  /* mallocを使って，必要な領域のみを確保すること */
  /* 注意： 文字列は最後に\0が入るので，その分余計に領域を確保すること */

  //ここにコード追加
  p = (char*) malloc((n+1)* sizeof(char));
  int i;
  for (i = 0; i < n; i++) {
    p[i] = getChar(i);
  }
  return p;
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  char* p;

  p = fan(n);
  printf("%s\n", p);
  free(p);

  return 0;
}
