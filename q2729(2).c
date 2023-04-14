#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char item[20];
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

        // char itens[10001];
        char *token;
        token = strtok(line, " ");

        // scanf("%[^\n]s", itens);
        // getchar();
        // fgets(itens, 10001, stdin);

        struct node *head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->item, token);
        head->next = NULL;

        while (token != NULL) // dividindo a string recebida no fgtes
        {
            add_node(head, token);
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
        printf("\n");
        printList(head);

        // liberar memoria
        freeList(head);
    }

    return 0;
}

// insercao de elementos no final da lista
void add_node(struct node *head, char item[])
{
    struct node *n = head; // ponteiro auxiliar

    while (n->next != NULL)
    {
        if (strcmp(n->item, item) == 0)
        {
            return;
        }
        n = n->next;
    }
    /* ERRO
    o ultimo item nao esta sendo comparado, por isso esta sendo repetido na impressão */

    if (strcmp(n->item, item) == 0)
    {
        return;
    }

    // insere no ultimo elemento
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
    struct node *n = head;
    while (n != NULL)
    {
        struct node *m = n->next;
        while (m != NULL)
        {
            if (strcmp(n->item, m->item) > 0)
            {
                char temp[20];
                strcpy(temp, n->item);
                strcpy(n->item, m->item);
                strcpy(m->item, temp);
            }
            m = m->next;
        }
        n = n->next;
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