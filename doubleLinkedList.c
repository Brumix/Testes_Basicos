#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLinkedList
{
    int value;
    struct doubleLinkedList *pnext;
    struct doubleLinkedList *pback;

} DOUBLE;

void add(int val);
void print_double_front_end(void);
void print_double_end_front(void);

DOUBLE *head = NULL;
DOUBLE *tail = NULL;

void main(void)
{
    printf("\n######Double Linked List#####\n");
    for (int i = 0; i < 10; i++)
    {
        add(i);
    }
    printf("\n###### Front_End #####\n");
    print_double_front_end();
    printf("\n###### End_Front #####\n");
    print_double_end_front();
}

void add(int val)
{

    DOUBLE *temp;
    DOUBLE *current;
    temp = (DOUBLE *)malloc(sizeof(DOUBLE));
    temp->value = val;
    temp->pnext = NULL;
    temp->pback = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        current = head;
        while (current->pnext != NULL)
            current = current->pnext;
        temp->pback = current;
        tail = temp;
        current->pnext = temp;
    }
}

void print_double_front_end(void)
{

    DOUBLE *current;
    current = head;
    while (current != NULL)
    {
        if (current->pnext == NULL)
            printf("%d\n", current->value);
        else
            printf("%d-", current->value);

        current = current->pnext;
    }
}

void print_double_end_front(void)
{

    DOUBLE *current;
    current = tail;
    while (current != NULL)
    {
        if (current->pback == NULL)
            printf("%d\n", current->value);
        else
            printf("%d-", current->value);

        current = current->pback;
    }
}
