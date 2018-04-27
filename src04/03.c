#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char* remove_take(char lyric[]) {
  char* n;
  int length = 0;
  //ここにコードを確保
  int i, take_i = -1;
  for (i = 0; ;i++) {
    if (lyric[i] != '\0') length++;
    else break;
  }
  
  for (i = 0; i < length; i++) {
    if (lyric[i] == 't' && i <= length - 4 && lyric[i+1] == 'a' &&
        lyric[i+2] == 'k' && lyric[i+3] == 'e') {
      take_i = i;
      break;
    }
  }
  
  if (take_i != -1) {
    n = (char*) malloc((length - 4) * sizeof(char));
    for (i = 0; i < length - 4; i++) {
      if (i >= take_i) n[i] = lyric[i+4];
      else n[i] = lyric[i];
    }
  }
  return n;
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  char *lyric = argv[1];
  char *removed;
  printf("%s\n", lyric);
  removed = remove_take(lyric);
  printf("%s\n", removed);
  free(removed);
}
