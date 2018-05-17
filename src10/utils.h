#ifndef _INCLUDE_UTILS_
#define _INCLUDE_UTILS_

#define DUMMY -1

void print_array(int ary[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", ary[i]);
  printf("\n");
}

void print_heap(int ary[], int size) {
  int i;
  for (i = 1; i < size + 1; i++) printf("%d ", ary[i]);
  printf("\n");
}

int set_heap(char *file_name, int **array) {
  FILE *fp;
  int i, size, tmp;
  if ((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "file open error\n");
		exit(EXIT_FAILURE);
	}
  for (i = 0; fscanf(fp, "%d", &tmp) != EOF; i++) {}
  size = i;
  *array = malloc(sizeof(int) * (size + 1));

  rewind(fp);
  for (i = 1; i < size + 1; i++) {fscanf(fp, "%d", &*(*array + i));}
  **array = DUMMY;
  fclose(fp);
  return size;
}

int set_array(char *file_name, int **array) {
  FILE *fp;
  int i, size, tmp;
  if ((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "file open error\n");
		exit(EXIT_FAILURE);
	}
  for (i = 0; fscanf(fp, "%d", &tmp) != EOF; i++) {}
  size = i;
  *array = malloc(sizeof(int) * size);

  rewind(fp);
  for (i = 0; i < size; i++) {fscanf(fp, "%d", &*(*array + i));}
  fclose(fp);

  return size;
}

#endif
