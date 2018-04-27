#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

void merge(int A[], int p, int q, int r) {
  //前の実装を使いましょう
   int lsize = q-p+1;
   int rsize = r-q;
   int* L = (int*) malloc(lsize * sizeof(int));
   int* R = (int*) malloc(rsize * sizeof(int));
   int a;
   for (a = 0; a < lsize; a++) L[a] = A[p+a];
//   print_array(L, lsize);
   
   for (a = 0; a < rsize; a++) R[a] = A[q+1+a];
//   print_array(R, rsize);
   int i, j = 0, k = 0;
   for (i = p; i < r+1; i++) {
     if (j >= lsize) {
       A[i] = *R;
       R++;
k++;
     } else if (k >= rsize) {
       A[i] = L[j];
       j = j + 1;
     } else if (L[j] < *R) {
       A[i] = L[j];
       j = j + 1;
     } else {
       A[i] = *R;
       k = k+1;
R++;
     }
   }
   free(L);
   free(R-=rsize);
}

void merge_sort(int A[], int p, int r) {
  //ここを実装
  if (p < r) {
    int q = (p+r)/2;
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p ,q ,r);
  }
}

//これ以降は変更しない
int main(int argc, char *argv[]) {
  int *a, size;
  char *filename = argv[1];

  size = set_array(filename, &a);

  print_array(a, size);
  merge_sort(a, 0, size - 1);
  print_array(a, size);

  return 0;
}
