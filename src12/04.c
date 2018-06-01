#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int queue[MAXSIZE] = {0};
int head = 0, tail = 0;

int size() {
  return tail >= head ? tail-head: MAXSIZE - head + tail;
}

void enqueue(int x) {
  //if (size() == MAXSIZE -1) {
  if ((tail + 1)%MAXSIZE == head) {
     printf("overflow\n"); exit(0);
  }
  tail = (tail+1)%MAXSIZE;
  queue[tail] = x;
}

int dequeue(void) {
  if (head == tail) {
    printf("underflow\n");exit(0);
  }
  int v = queue[head+1];
  head = (head+1)%MAXSIZE;
  return v;
}

void print_queue() {
  int i = head;
  if (head == tail) {
    printf("[]\n");
  }
  else {
    printf("[");
    do {
      i = (i + 1) % MAXSIZE;
      printf("%d ", queue[i]);
    } while(i != tail);
    printf("]\n");
  }
}

int main(int argc, char *argv[]) {

  int i, n;

  for (i = 1; i < argc; i++) {
    n = atoi(argv[i]);
    if (n < 0)
      dequeue();
    else
      enqueue(atoi(argv[i]));
    print_queue();
  }

  return 0;
}
