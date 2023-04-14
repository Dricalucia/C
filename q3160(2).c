#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
    char nome[11];
    struct node *next;
};

void add_node(struct node *amigos_atual, char item[]);
void ord_node(struct node *atual, struct node *novo, char nome[]);
void freeList(struct node *head);

int main()
{

    // recebe a primeira linha - amigos atuais
    char *line1 = NULL;
    int line1_size = 0;
    getline(&line1, &line1_size, stdin);
    line1[strlen(line1) - 1] = '\0';

    char *token = strtok(line1, " ");

    struct node *amigos = (struct node *)malloc(sizeof(struct node));
    strcpy(amigos->nome, token);
    amigos->next = NULL;

    while (token != NULL) //
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            add_node(amigos, token);
        }
    }

    // recebe a segunda linha - amigos novos
    char *line2 = NULL;
    int line2_size = 0;
    getline(&line2, &line2_size, stdin);
    line2[strlen(line2) - 1] = '\0';

    char *token = strtok(line2, " ");

    struct node *amigos_novos = (struct node *)malloc(sizeof(struct node));
    strcpy(amigos_novos->nome, token);
    amigos_novos->next = NULL;

    // recebe a primeira linha - amigos atuais
    while (token != NULL) //
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            add_node(amigos_novos, token);
        }
    }

    // recebe a terceira linha - amigo que indica
    char *line3 = NULL;
    int line3_size = 0;
    getline(&line3, &line3_size, stdin);
    line3[strlen(line3) - 1] = '\0';

    ord_node(amigos, amigos_novos, line3);

    // imprime a lista de amigos
    printList(amigos);

    // liberar memoria
    freeList(amigos_novos);
    freeList(amigos);
    free(line1);
    free(line2);
    free(line3);

    return 0;
}

// insercao de elementos no final da lista
void add_node(struct node *head, char item[])
{
    struct node *n = head; // ponteiro auxiliar

    // adiciona o novo novo ao final da lista
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    strcpy(novo->item, nome);
    novo->next = NULL;
    n->next = novo;
}

void ord_node(struct node *atual, struct node *novo, char nome[])
{
    struct node *n1 = atual; // ponteiro auxiliar
    struct node *n2 = novo;  // ponteiro auxiliar

    if (strcmp(nome, 'nao') == 0)
    {
        n1->next = n2;
    }
    else
    {
        struct node *temp = NULL;
        temp = (struct node *)malloc(sizeof(struct node));
        while (n1 != NULL)
        {
            if (strcmp(n1->nome, nome) == 0)
            {
                temp = n1->next;
                n1->next = n2;
                n2->next = temp;
                return;
            }
        }
        n1 = n->next;
    }
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