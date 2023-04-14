#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char item[21];
    struct node *next;
}; // celulas da minha lista

void add_node(struct node *head, char item[]);
void printList(struct node *head);
void sortList(struct node *head);
void freeList(struct node *head);

int main()
{
    int N;
    scanf("%d", &N);
    getchar(); // retirar '\n' após o número de casos de teste

    for (int i = 0; i < N; i++)
    {
        // lê a lista de compras e remove o caractere '\n' final
        char *line = NULL;
        int line_size = 0;
        getline(&line, &line_size, stdin);
        line[strlen(line) - 1] = '\0';

        char *token = strtok(line, " ");

        struct node *head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->item, token);
        head->next = NULL;

        while (token != NULL) // dividindo a string recebida no fgtes
        {
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                add_node(head, token);
            }
        }

        /*
        Saída
        A saída contém N linhas, cada uma representando uma das listas de compras de Valentina,
        sem itens repetidos e em ordem alfabética.
        */
        sortList(head);
        // printf("\n");
        printList(head);

        // liberar memoria
        freeList(head);
        free(line);
    }

    return 0;
}

// insercao de elementos no final da lista
void add_node(struct node *head, char item[])
{
    struct node *n = head; // ponteiro auxiliar

    // verifica se o item já está na lista
    while (n->next != NULL)
    {
        if (strcmp(n->item, item) == 0)
        {
            return;
        }
        n = n->next;
    }

    // verifica o último item da lista
    if (strcmp(n->item, item) == 0)
    {
        return;
    }

    // adiciona o novo item ao final da lista
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    strcpy(novo->item, item);
    novo->next = NULL;
    n->next = novo;
}

// imprime os elementos da lista  ok
void printList(struct node *head)
{
    struct node *n = head;
    while (n != NULL)
    {
        printf("%s ", n->item);
        n = n->next;
    }
    printf("\n");
}

// ordena os elementos da lista
void sortList(struct node *head)
{
    int trocou;
    struct node *node;
    struct node *last = NULL;

    // verifica se a lista está vazia
    if (head == NULL)
    {
        return;
    }

    do
    {
        trocou = 0;
        node = head;

        while (node->next != last)
        {
            if (strcmp(node->item, node->next->item) > 0)
            {
                char temp[21];
                strcpy(temp, node->item);
                strcpy(node->item, node->next->item);
                strcpy(node->next->item, temp);
                trocou = 1;
            }
            node = node->next;
        }
        last = node;
    } while (trocou);
}

// limpa a memoria que foi alocada ok
void freeList(struct node *head)
{
    struct node *n = head;
    while (n != NULL)
    {
        struct node *next = n->next;
        free(n);
        n = next;
    }
}