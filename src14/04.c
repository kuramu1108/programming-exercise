#include <stdio.h>
#include <stdlib.h>

#define HSIZE 19

void print_hash();

int hashTable[HSIZE] = {0};

int gen_hash(int key) {
  return key % HSIZE;
}

void insert (int key) {
  int k = gen_hash(key);
  while (hashTable[k%HSIZE] != 0) k++;
  hashTable[k] = key;
}

int main(int argc, char *argv[])
{
  int i;
  for (i = 1; i < argc; i++)
    insert(atoi(argv[i]));

  print_hash();

  return 0;
}

void print_hash() {
  int i;
  printf("[");
  for (i = 0; i < HSIZE; i++)
    printf("%d ", hashTable[i]);
  printf("]\n");
  //2017
}
