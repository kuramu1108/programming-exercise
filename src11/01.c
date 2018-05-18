#include <stdio.h>

/* ここは前の問題と同じ考えで構造体を定義 */
typedef struct {
  char* dance;
  char* trend;
  int episode;
} popute_t;

void print_character(popute_t *p) {
  printf("おどり:%s\n流行るかな？:%s\n話数:%d\n", p->dance, p->trend, p->episode);
}

int main() {

  popute_t p;

  p.dance = "エイサイハラマスコイ";
  p.trend = "絶対流行る";
  p.episode = 8;

  print_character(&p);

  return 0;
}
