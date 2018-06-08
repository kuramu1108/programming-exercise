#include <stdio.h>
#include <stdlib.h>

long int** lookup;

long int calc(int n, int k) {
    if (n == 0 && k != 0) return 0;
    else if (n == 0 &&k == 0 ) return 0;
    else if (k ==0) return 1;
    else if (lookup[n][k] != 0) return lookup[n][k];
    else {
      lookup[n][k] = calc(n-1, k-1) + calc(n+1, k-1);
      return lookup[n][k];
    }
}

void printarray(int n,int k) {
    int i, j;
    for (i=0; i <= n+k; i++) {
      for (j =0; j<=k;j++) {
       printf("%ld ", lookup[i][j]);
      }
      printf("\n");
    }
}



int main(int argc, char* argv[]){
    //入力 n:コインの枚数 k:ゲームの回数
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    lookup = malloc((n+k+1) * sizeof(long int*));
    int i, j;
    for (i=0; i <=n+k; i++) {
      lookup[i] = malloc((k+1) * sizeof(long int));
      for (j=0; j<=k; j++) lookup[i][j] = 0;
    }
    printf("%ld\n", calc(n, k));
//    printarray(n,k);
    return 0;
}
