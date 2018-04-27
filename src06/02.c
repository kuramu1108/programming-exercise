#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

int *appendMax(int ary[], int size) {
  //前の実装を使いましょう
  int* p;
  p = (int*) malloc((size + 1) * sizeof(int));
  int i;
  for (i =0; i < size+1; i++) {
    if (i != size) p[i] = ary[i];
    else p[i] = INT_MAX;
  }
  return p;
}

/*
 * lとrの配列の要素を比較し，小さい方からaに代入する
 */
void merge_array(int a[], int l[], int r[], int lsize, int rsize) {
  int* n_l = appendMax(l, lsize);
  int* n_r = appendMax(r, rsize);
  int i, j = 0, k = 0;
  for (i = 0; i < lsize + rsize; i++) {
    if (n_l[j] < n_r[k]) {
      a[i] = n_l[j];
      j = j + 1;
    } else {
      a[i] = n_r[k];
      k = k + 1;
    }
  }
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int *l, *r, *a, size1, size2;
  //引数で読み込むファイルを指定
  char *filename1 = argv[1];
  char *filename2 = argv[2];

  size1 = set_array(filename1, &l);
  size2 = set_array(filename2, &r);
  a = malloc(sizeof(int) * (size1 + size2));
  merge_array(a, l, r, size1, size2);
  print_array(a, size1 + size2);
  return 0;
}
