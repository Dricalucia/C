#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *next;
}; // celulas da minha lista

void printList(struct node *head);
void add_node(struct node **head, int var);
void delete_node(struct node **head);

int main(void)
{

    struct node *head = NULL;
    struct node *novo = NULL;
    int i;

    // head = (struct node *)malloc(sizeof(struct node));
    // head->valor = 1; //array[0] = 1
    // head->next = NULL; //primeiro elemento da lista

    // printf("Lista encadeada\n");
    // printList(head);

    for (i = 0; i < 5; i++)
    { // insercao
        add_node(&head, i + 3);
    }

    printf("Nova lista encadeada %p\n", head);
    printList(head);

    for (i = 0; i < 5; i++)
    {
        delete_node(&head);
    }

    printf("Outra lista encadeada\n");
    printList(head);

    return 0;
}

// imprime os elementos da lista
void printList(struct node *head)
{
    struct node *n = head;
    while (n != NULL)
    {
        printf(" %d ", n->valor);
        n = n->next;
    }
    printf("\n");
}

void add_node(struct node **head, int var)
{ // insercao de elementos no final da lista
    if (*head == NULL)
    { // verifica se lista esta vazia

        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->valor = var;
        (*head)->next = NULL;
    }
    else
    {
        struct node *n = *head;
        while (n->next != NULL)
        { // final da lista
            n = n->next;
        }

        n->next = (struct node *)malloc(sizeof(struct node)); // novo
        n->next->valor = var;
        n->next->next = NULL;
    }
}

// remove elementos no final da lista
void delete_node(struct node **head)
{
    struct node *n = *head;
    struct node *temp;

    if (*head == NULL)
    {
        printf("lista vazia\n");
        return;
    }
    else if (n->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        while (n->next->next != NULL)
        {
            n = n->next;
        }
        temp = n->next;
        n->next = n->next->next;
        free(temp);
    }
}