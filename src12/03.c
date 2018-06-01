#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

/*
+---+---+---+---+---+
|   | 1 | 2 | 3 |   |
+---+---+---+---+---+
  ^           ^
  |           |
  head        tail
*/

int queue[MAXSIZE] = {0};
int head = 0, tail = 0;

void enqueue(int x) {
  //ここを実装
  tail = (tail+1)% MAXSIZE;
  queue[tail] = x;
}

int dequeue(void) {
  //ここを実装
  int v = queue[head+1];
  head = (head+1)% MAXSIZE;
  return v;
}

void print_queue() {
  int i = head;
  printf("[");
  do {
    i = (i + 1) % MAXSIZE;
    printf("%d ", queue[i]);
  } while(i != tail);
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
