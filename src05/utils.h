#ifndef _INCLUDE_UTILS_
#define _INCLUDE_UTILS_

void print_array(int ary[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", ary[i]);
  printf("\n");
}

void print_array_two_mark(int ary[], int size, int a, int b) {
  int i;
  for (i = 0; i < size; i++) {
    if (i == a || i == b)
      printf("o ");
    else
      printf("  ");
  }
  printf("\n");
  for (i = 0; i < size; i++) printf("%d ", ary[i]);
  printf("\n");
}

int set_array(char *file_name, int **array) {
  FILE *fp;
  int i, size, tmp;
  fp = fopen(file_name, "r");
  for (i = 0; fscanf(fp, "%d", &tmp) != EOF; i++) {}
  size = i;
  *array = malloc(sizeof(int) * size);

  rewind(fp);
  for (i = 0; i < size; i++) {fscanf(fp, "%d", &*(*array + i));}
  fclose(fp);

  return size;
}

#endif
