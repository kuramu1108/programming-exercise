#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

/*
+---+---+---+---+---+
| 1 | 2 | 3 |   |   |
+---+---+---+---+---+
  ^           ^
  |           |
  head        tail
*/

int queue[MAXSIZE] = {0};
int head = 0, tail = 0;

void enqueue(int x) {
  //ここを実装
  queue[tail++] = x;
}

int dequeue(void) {
  //ここを実装
  return queue[head++];
}

void print_queue() {
  int i;
  printf("[");
  for (i = head; i < tail; i++)
    printf("%d ", queue[i]);
  printf("]\n");
}

int main(int argc, char* argv[]) {

  int i, n;

  for (i = 1; i < argc; i++) {
    n = atoi(argv[i]);
    if (n < 0)
      printf("%d has been dequeued\n", dequeue());
    else
      enqueue(n);

    print_queue();
  }

  return 0;
}
