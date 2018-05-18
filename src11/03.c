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

list_t* append(list_t *cell, char c) {
  //前の実装を使う
  return cons(c, cell);
}

int length(list_t *head) {
  //再帰で書きましょう
  if (head != NULL)
    return 1 + length(head->next);
  else
    return 0;
}

int main(int argc, char *argv[])
{
  int i;
  list_t* head = NULL;
  for (i = 0; i < argc - 1; i++)
    head = append(head, *argv[i + 1]);

  printf("length = %d\n", length(head));

  return 0;
}
