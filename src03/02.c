#include <stdio.h>
#include <stdlib.h>

void katsudon(int h) {
  //hint 0とそれ以外で分ける 
  if (h != 0) printf("自分が何やったかわかっとんのか\n");
  else printf("カツ丼食えよ\n");
}

//これ以降は変更しない
void donkatsu() {
  int i;
  for (i = 2; i >= 0; i--)
    katsudon(i);
}

int main() {
  donkatsu();
  return 0;
}
