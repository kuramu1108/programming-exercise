#include <stdio.h>
#include <stdlib.h>

#define HSIZE 19
void print_hash();

int hashTable[HSIZE] = {0};

int gen_hash(int key) {
  return key % 19;
}

void insert (int key) {
  int k = gen_hash(key);

  if (hashTable[k] == 0) {
    hashTable[k] = key;
  }
  else {
    printf("collision!\n");
    exit(0);
  }
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
