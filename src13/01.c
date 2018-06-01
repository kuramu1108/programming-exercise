#include <stdio.h>
#include <stdlib.h>

typedef struct celltype {
  int key;
  struct celltype *prev;
  struct celltype *next;
} cell_t;

void print_list(cell_t *head);
void reverse_print_list(cell_t *head);

cell_t* insert(cell_t *head, int key) {
  //ここを実装
  //双方向リストのためにmallocは使います！
  cell_t* c = malloc(sizeof(struct celltype));
  c->key = key;
  c->next = head;
  c->prev = NULL;
  if (head != NULL)
    head->prev = c;
  return c;
}

int main(int argc, char *argv[])
{
  cell_t *head = NULL;
  int i;

  for (i = 1; i < argc; i++)
    head = insert(head, atoi(argv[i]));

  print_list(head);
  reverse_print_list(head);

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

void reverse_print_list(cell_t *head) {
  cell_t *tmp;
  if (head == NULL) return;

  for (tmp = head; tmp->next != NULL; tmp = tmp->next);

  do {
    printf("%d", tmp->key);
    if (tmp != head) printf(" <-> ");
    tmp = tmp->prev;
  } while (tmp != NULL);
  printf("\n");
}
