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
void remove_double(int val);

DOUBLE *head = NULL;
DOUBLE *tail = NULL;

void main(void)
{

    printf("\n######Double Linked List#####\n");
    for (size_t i = 0; i < 10; i++)
    {
        add(i);
    }
    printf("\n###### Front_End #####\n");
    print_double_front_end();
    printf("\n###### End_Front #####\n");

    remove_double(0);
    remove_double(9);
    remove_double(5);

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

void remove_double(int val)
{
    
    DOUBLE *current;
    current = tail;
    if (current->value == val)
    {
        free(tail);
        current->pback->pnext = NULL;
        tail = current->pback;
        return;
    }
    else
    {
        while (current != NULL)
        {
            if (current->pback->value == val)
            {
                if (current->pback->pback == NULL)
                {
                    free(current->pback);
                    current->pback = NULL;
                    head = current;
                    return;
                }
                else
                {
                    free(current->pback);
                    current->pback = current->pback->pback;
                    current->pback->pback->pnext = current->pback->pnext;
                    return;
                }
            }
            current = current->pback;
        }
    }
}
