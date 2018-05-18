#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void apply(list_t* p) {
  // リストの最後まで来たら，改行しましょう
  // toupper関数を使って，大文字にしましょう．
  if (p != NULL) {
    printf("%c ", toupper(p->c));
    apply(p->next);
  } else
    printf("\n");
}

int main(int argc, char *argv[])
{
  int i;
  list_t* head = NULL;
  for (i = 0; i < argc - 1; i++)
    head = append(head, *argv[i + 1]);

  apply(head);

  return 0;
}
