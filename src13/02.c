#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef struct celltype {
  int key;
  struct celltype *prev;
  struct celltype *next;
} cell_t;
void print_list(cell_t *head);

cell_t* insert(cell_t *head, int key) {
  cell_t* c = malloc(sizeof(struct celltype));
  c->key = key;
  c->next = head;
  c->prev = NULL;
  if (head != NULL)
    head->prev = c;
  return c;
}

//keyが見つかったときは1を，見つからなかったときは0を返すようにする
int search(cell_t *head, int key) {
  //ここを実装
  while(head != NULL) {
    if(head->key == key) return 1;
    head = head-> next;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  cell_t *head = NULL;
  int *keys, size, i;
  char *filename = argv[1];
  int key = atoi(argv[2]);
  size = set_array(filename, &keys);


  for (i = 0; i < size; i++)
    head = insert(head, keys[i]);

  if (search(head, key))
    printf("わーい！%dなフレンズなんだね！\n", key);
  else
    printf("けものはいてものけものはないない！ただし，%d，テメーはダメだ！\n", key);

  return 0;
}

void print_list(cell_t *head) {
  cell_t *tmp;
  for (tmp = head; tmp != NULL; tmp = tmp->next) {
    printf("%d", tmp->key);
    if (tmp->next != NULL) printf(" <-> ");
  }
  printf("\n");
}
