#include <stdio.h>
#include <stdlib.h>

#define HSIZE 19
void print_hash();

typedef struct celltype {
  int key;
  struct celltype *next;
} cell_t;

cell_t* hashTable[HSIZE] = {0};

int gen_hash(int key) {
  return key % HSIZE;
}

void insert (int key) {
  int k = gen_hash(key);
  
  cell_t* c = malloc(sizeof(struct celltype));
  c->key = key;
  if (hashTable[k] != 0) c->next = hashTable[k];
  hashTable[k] = c;
}

int main(int argc, char *argv[])
{
  //3 5 77 109 190 245 832 852 9924 10346
  int i;
  for (i = 1; i < argc; i++)
    insert(atoi(argv[i]));

  print_hash();

  return 0;
}

void print_list(cell_t *head) {
  cell_t *tmp;
  if (head == NULL)
    printf("/");

  for (tmp = head; tmp != NULL; tmp = tmp->next) {
    printf("%d", tmp->key);
    if (tmp->next != NULL) printf(" <-> ");
  }
  printf("\n");
}

void print_hash() {
  //2017
  int i;
  for (i = 0; i < HSIZE; i++)
    print_list(hashTable[i]);
}
