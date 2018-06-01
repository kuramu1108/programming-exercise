#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = -1;

void print_stack(){
  int i;
  printf("[");
  for (i = 0; i <= sp; i++) { printf("%d ", stack[i]);}
  printf("]\n");
}

void push(int i) {
  //ここを実装
  sp++;
  stack[sp] = i;
}

int pop() {
  if (stack[sp]== 0) {printf("error:underflow\n"); exit(0);}
  return stack[sp--];
}

int main(int argc, char *argv[])
{
  int i, n;

  for (i = 1; i < argc; i++) {
    n = atoi(argv[i]);
    if (n < 0)
      printf("%d has been removed\n", pop());
    else
      push(n);

    print_stack();
  }

  return 0;
}
