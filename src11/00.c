#include <stdio.h>

struct popute {
  //ここにメンバーを書きます
  char* name;
  char* job;
  int number;
  int episode;
};

int main() {

  struct popute d;

  d.name = "ヘルシェイク矢野";
  d.job = "ギタリスト";
  d.number = 1;
  d.episode = 97;

  printf("名前:%s\n職業:%s\n登場:第%d巻%d話\n", d.name, d.job, d.number, d.episode);

  return 0;
}
