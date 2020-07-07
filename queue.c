#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int val;
    struct queue *pnext;
} QUEUE;

void enqueue(int valor);
void printqueue();
void dequeue();

QUEUE *head = NULL;

int main(void)
{

    printf("###### Queue #####\n");
    for (int i = 0; i < 10; i++)
    {
        enqueue(i);
    }

    printqueue();
    for (int i = 5; i > 0; i--)
    {
        dequeue();
    }

    printqueue();
}

void enqueue(int valor)
{

    QUEUE *temp = NULL;
    temp = (QUEUE *)malloc(sizeof(QUEUE));
    temp->val = valor;
    temp->pnext = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        QUEUE *curent = NULL;
        curent = head;
        while (curent->pnext != NULL)
            curent = curent->pnext;
        curent->pnext = temp;
    }
}

void dequeue()
{
    QUEUE *temp = NULL;
    temp = head;
    head = temp->pnext;
}

void printqueue()
{

    QUEUE *current;
    current = (QUEUE *)malloc(sizeof(QUEUE));
    current = head;
    while (current != NULL)
    {
        if (current->pnext == NULL)
            printf("%d\n", current->val);
        else
            printf("%d-", current->val);

        current = current->pnext;
    }
    free(current);
}
