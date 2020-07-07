#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
  int value;
  struct Stack *pnext;
} STACK;

void push(int val);
void pirntStacck();
void pop();

STACK *head = NULL;

int main(void)
{

  printf("###### Stack #####\n");

  for (int i = 0; i < 10; i++)
  {
    push(i);
  }

  pirntStacck();
  for (int i = 0; i < 5; i++)
  {
    pop();
  }
  pirntStacck();
}

void push(int val)
{
  STACK *temp;
  temp = (STACK *)malloc(sizeof(STACK));
  temp->value = val;
  temp->pnext = head;
  head = temp;
}

void pop()
{
  STACK *temp;
  temp = (STACK *)malloc(sizeof(STACK));
  temp = head;
  head = temp->pnext;
  free(temp);
}

void pirntStacck()
{

  STACK *curent;
  curent = malloc(sizeof(STACK));
  curent = head;
  while (curent != NULL)
  {
    if (curent->pnext == NULL)
      printf("%d\n", curent->value);
    else
      printf("%d-", curent->value);
    curent = curent->pnext;
  }

  free(curent);
}
