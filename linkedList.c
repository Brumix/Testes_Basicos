#include <stdio.h>
#include <stdlib.h>
typedef struct value
{
    int val;
    struct value *pnext;
} VALUE;

void add(int valor);
void printLits(VALUE *);
void find(VALUE *, int valor);
void addreverse(int valor);
void removelist(VALUE **head, int valor);

VALUE *head = NULL;
VALUE *top = NULL;

void main(void)
{
    printf("###### Linked List#####\n");
    for (int i = 0; i < 20; i++)
    {
        add(i);
    }

    printLits(head);
    for (int i = 0; i < 20; i ++)
    {
        
        removelist(&head, i);
     i++;
    }

    find(head, 12);
    find(head, 1);
    printLits(head);

    printf("\n######Reverse Linked List#####\n");
    for (int i = 0; i < 20; i++)
    {
        addreverse(i);
    }
    printLits(top);
    for (int i = 1; i < 20; i ++)
    {
        removelist(&top, i);
        i++;
    }
    find(top, 19);
    find(top, 14);
    printLits(top);

}

void add(int valor)
{
    VALUE *temp = NULL;
    VALUE *current = NULL;
    temp = (VALUE *)malloc(sizeof(VALUE));

    temp->val = valor;
    temp->pnext = NULL;
    if (head == NULL)
        head = temp;

    else
    {
        current = head;
        while (current->pnext != NULL)
            current = current->pnext;
        current->pnext = temp;
    }
}

void printLits(VALUE *head)
{
    VALUE *curent = NULL;
    curent = head;
    while (curent != NULL)
    {
        if (curent->pnext == NULL)
            printf("%d", curent->val);
        else
            printf("%d-", curent->val);

        curent = curent->pnext;
    }
    printf("\n");
    free(curent);
}

void find(VALUE *head, int valor)
{

    VALUE *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->val == valor)
        {
            printf("Exite o valor %d,na lista\n", temp->val);
            return;
        }
        temp = temp->pnext;
    }
    printf("Não exite o valor %d,na lista\n", valor);
}

void addreverse(int valor)
{
    VALUE *temp;
    temp = (VALUE *)malloc(sizeof(temp));
    temp->val = valor;
    temp->pnext = top;
    top = temp;
}


void removelist(VALUE **head, int valor)

{

    VALUE *temp;
    temp = *head;
    if (temp->val == valor)
    {
        free(*head);
        *head = temp->pnext;
        return;
    }

    else
    {
        while (temp != NULL)
        {
            if (temp->pnext->val == valor)
            {
                if (temp->pnext->pnext == NULL)
                {
                    free(temp->pnext);
                    temp->pnext = NULL;
                    return;
                }
                else
                {
                    free(temp->pnext);
                    temp->pnext = temp->pnext->pnext;
                    return;
                }
            }
            temp = temp->pnext;
        }
    }
}
