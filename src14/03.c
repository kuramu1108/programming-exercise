#include <stdio.h>
#include <stdlib.h>

#define HSIZE 19
void set_hash(char *file_name);

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

void search(int key) {
  //ここを実装
  int k = gen_hash(key);
  cell_t* c = hashTable[k];
  int found = 0;
  if (c != 0) {
    do {
      if (c->key == key) {
        found = 1;
        break;
      }
      c = c->next;
    } while (c != 0);
  }
  if (found) printf("found\n");
  else printf("not found\n");
}

int main(int argc, char *argv[])
{
  char *filename = argv[1];
  int i;

  set_hash(filename);

  search(atoi(argv[2]));

  return 0;
}

void set_hash(char *file_name) {
  FILE *fp;
  int i, v;
  fp = fopen(file_name, "r");
  for (i = 0; fscanf(fp, "%d", &v) != EOF; i++) {
    insert(v);
  }
  fclose(fp);
  //2017
}
