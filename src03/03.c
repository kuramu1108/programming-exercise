#include <stdio.h>
#include <stdlib.h>

void donkatsu(int i) {
  //hint iが0のとき終了，それ以外は・・・
  if (i != 0) {   
    printf("自分が何やったかわかっとんのか\n");
    donkatsu(--i);
  } else printf("カツ丼食えよ\n");
}

//これ以降は変更しない
int main() {
  donkatsu(2);
  return 0;
}
