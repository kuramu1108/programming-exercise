#include <stdio.h>
#include <stdlib.h>

/* 

 girl_drop(gd_t)型
 h: 星振そそぐの人数
 k: 月影の人数
 y: 夕陽ころなの人数
 n: 検査の個数
 data[n][4] 検査の値 A B C X
 
 */

typedef struct girl_drop{
    int h;
    int k;
    int y;
    int n;
    int** data;
} gd_t;

gd_t* set_girl_drop(char *file_name) {
    FILE *fp;
    int i;
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "file open error\n");
        exit(EXIT_FAILURE);
    }
    gd_t* girl  = (gd_t*)malloc(sizeof(gd_t));
    fscanf(fp,"%d %d %d",&(girl->h),&(girl->k),&(girl->y));
    fscanf(fp,"%d",&(girl->n));
    girl->data =(int**)malloc(sizeof(int*)*girl->n);
    for (i = 0; i < girl->n; ++i) {
        girl->data[i] = (int*)malloc(sizeof(int)*4);
        fscanf(fp,"%d %d %d %d",&(girl->data[i])[0],&(girl->data[i][1])
               ,&(girl->data[i][2]),&(girl->data[i][3]));
        
    }

    fclose(fp);
       
    return girl;
}

int main(int argc, char *argv[])
{
    //入力のデータを取得
    gd_t * girl = set_girl_drop(argv[1]);
    int t = girl->h + girl->k + girl->y;
    int* r = malloc((t+1) * sizeof(int));
    
    int i;
    for (i = 0; i <= t; i++) r[i]= 2;
    for (i = 0; i < girl->n; i++) {
      if (girl->data[i][3] == 1) {
        r[girl->data[i][0]] = 1;
        r[girl->data[i][1]] = 1;
        r[girl->data[i][2]] = 1;
      }
    }

    for (i = 0; i < girl->n; i++) {
      if (girl->data[i][3] ==0) {
        if (r[girl->data[i][0]] ==1 && r[girl->data[i][1]] ==1) r[girl->data[i][2]] = 0;
        else if (r[girl->data[i][1]] ==1 && r[girl->data[i][2]] ==1) r[girl->data[i][0]] = 0;
        else if (r[girl->data[i][0]] ==1 && r[girl->data[i][2]] ==1) r[girl->data[i][1]] = 0;
      } 
    }
    for (i=1; i<=t; i++) printf("%d\n", r[i]);
    return 0;
}
