#include <stdio.h>
#include <stdlib.h>

typedef struct celltype {
  int key;
  struct celltype *prev;
  struct celltype *next;
} cell_t;

void print_list();
void reverse_print_list();

cell_t *head;

void insert(int key) {
  // ここを実装
  // 問１と比べてキレイにかけるのを実感してください
  cell_t* c = malloc(sizeof(struct celltype));
  c->key = key;
  c->next = head->next;
  head->next->prev = c;
  head->next = c;
  c->prev = head;
}

int main(int argc, char *argv[])
{
  //番兵準備
  head = malloc(sizeof(cell_t));
  head->prev = head;
  head->next = head;

  int i;

  for (i = 1; i < argc; i++)
    insert(atoi(argv[i]));

  print_list();
  reverse_print_list();

  return 0;
}

void print_list() {
  cell_t *tmp;
  for (tmp = head->next; tmp != head; tmp = tmp->next) {
    printf("%d", tmp->key);
    if (tmp->next != head) printf(" <-> ");
  }
  printf("\n");
}

void reverse_print_list() {
  cell_t *tmp;
  for (tmp = head->prev; tmp != head; tmp = tmp->prev) {
    printf("%d", tmp->key);
    if (tmp->prev != head) printf(" <-> ");
  }
  printf("\n");
}
