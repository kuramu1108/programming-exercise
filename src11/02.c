#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  char c;
  struct list *next;
} list_t;

list_t* cons(char c, list_t *next) {
  list_t* l = malloc(sizeof(list_t));
  l->c = c;
  l->next = next;
  return l;
}

void print_list(list_t *head) {
  list_t *tmp = head;
  for (;tmp != NULL; tmp = tmp->next)
    printf("%c ", tmp->c);

  printf("\n");
}

list_t* append(list_t *cell, char c) {
  //consを使うといいですよ．
  return cons(c, cell);
}

int main(int argc, char *argv[])
{
  int i;
  list_t* head = NULL;
  for (i = 0; i < argc - 1; i++)
    head = append(head, *argv[i + 1]);

  print_list(head);

  return 0;
}
