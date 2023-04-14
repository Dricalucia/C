#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *next;
}; // celulas da minha lista

void printList(struct node *head);
struct node *busca_node(struct node *head, int var);
int busca_valor(struct node *head, int pos);
int tamanho_lista(struct node *head);
void add_node(struct node *head, int var);
void delete_node(struct node *head, int var);

int main(void)
{

    struct node *head = NULL;
    struct node *tail = NULL; // inicializando ponteiros

    struct node *novo = NULL;
    struct node *temp = NULL;
    int i, valor;

    // head = (struct node *)malloc(sizeof(struct node));
    // head->valor = 1; //array[0] = 1
    // head->next = NULL; //primeiro elemento da lista

    novo = (struct node *)malloc(sizeof(struct node));
    novo->valor = 2;   // array[1] = 2
    novo->next = NULL; // PRIMEIRO elemento da FILA
    head = novo;
    tail = novo;

    printf("Lista encadeada\n");
    printList(head);

    temp = busca_node(head, 3);
    if (temp == NULL)
    {
        printf("Elemento nao existe na lista\n");
    }

    // inserindo tres elementos na lista
    add_node(head, 3);
    add_node(head, 6);
    add_node(head, 5);

    printf("Nova lista encadeada\n");
    printList(head);

    printf("Tamanho atual da lista = %d\n", tamanho_lista(head));

    valor = busca_valor(head, 4);
    printf("valor do quarto elemento da lista = %d\n", valor);

    temp = busca_node(head, 5);
    if (temp == NULL)
    {
        printf("Elemento nao existe na lista\n");
    }
    else
    {
        delete_node(head, 5);
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

// busca uma elemento especifico da lista e o retorna
struct node *busca_node(struct node *head, int var)
{
    struct node *n = head;
    while (n != NULL && n->valor != var)
    {
        n = n->next;
    }
    return n;
}

int busca_valor(struct node *head, int pos)
{ // busca valor de uma posicao especifica
    struct node *n = head;
    int count = 1;
    while (n != NULL && count < pos)
    {
        n = n->next;
        count++;
    }
    return n->valor;
}

int tamanho_lista(struct node *head)
{ // retorna o tamanha total da lista
    struct node *n = head;
    int count = 0;
    while (n != NULL)
    {
        n = n->next;
        count++;
    }
    return count;
}

void add_node(struct node **head, int var)
{                           // insercao de elementos no final da lista
    struct node *n = *head; // ponteiro auxiliar
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    novo->valor = var; // criar o novo elemento

    if (*head == NULL)
    { // lista vazia
        *head = novo;
        novo->next = NULL;
    }
    else
    {
        while (n->next != NULL && n->next->valor < var)
        {
            n = n->next;
        }
        if (n->next == NULL)
        { // insere no ultimo elemento
            novo->next = NULL;
            n->next = novo;
        }
        else
        {
            novo->next = n->next;
            n->next = novo;
        }
    }
}

// remove um elementos especifico da lista
void delete_node(struct node *head, int var)
{
    struct node *n = head;
    struct node *temp;

    while (n->next->next != NULL && n->next->valor != var)
    {
        n = n->next;
    }

    temp = n->next;
    n->next = n->next->next;
    free(temp);
}