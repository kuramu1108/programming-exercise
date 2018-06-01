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

cell_t* delete(cell_t *head, int key) {
  cell_t* temp = head;
  while(temp != NULL) {
    if (temp-> key == key) {
      if (temp->next != NULL) temp->next->prev = temp->prev;
      if (temp->prev != NULL) temp->prev->next = temp->next;
      else head = temp->next;
    }
    temp = temp->next;
  }
  return head;
}

int main(int argc, char *argv[])
{
  cell_t *head = NULL;
  int *keys, size, i;
  char *filename = argv[1];
  size = set_array(filename, &keys);

  for (i = 0; i < size; i++)
    head = insert(head, keys[i]);
  print_list(head);

  for (i = 2; i < argc; i++)
	  head = delete(head, atoi(argv[i]));

  print_list(head);

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
