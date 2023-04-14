#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// correçao do Lucas

struct node
{
    char item[21];
    struct node *next;
};

void add_node(struct node *head, char item[]);
void printList(struct node *head);
void sortList(struct node *head);
void freeList(struct node *head);

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // retira o caractere '\n' após o número de casos de teste

    for (int i = 0; i < n; i++)
    {
        // lê a lista de compras e remove o caractere '\n' final
        char *line = NULL;
        int line_size = 0;
        getline(&line, &line_size, stdin);
        line[strlen(line) - 1] = '\0';

        // divide a lista em tokens e adiciona na lista encadeada
        char *token = strtok(line, " ");
        struct node *head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->item, token);
        head->next = NULL;
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                add_node(head, token);
            }
        }

        // ordena e imprime a lista
        sort_list(head);
        print_list(head);

        // libera a memória alocada para a lista
        free_list(head);
        free(line);
    }

    return 0;
}

void add_node(struct node *head, char *item)
{
    // busca pelo último nó da lista
    struct node *last = head;
    while (last->next != NULL)
    {
        // verifica se o item já está na lista
        if (strcmp(last->item, item) == 0)
        {
            return;
        }
        last = last->next;
    }
    // verifica o último item da lista
    if (strcmp(last->item, item) == 0)
    {
        return;
    }
    // adiciona o novo item ao final da lista
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->item, item);
    newNode->next = NULL;
    last->next = newNode;
}

void print_list(struct node *head)
{
    struct node *n = head;
    while (n != NULL)
    {
        printf("%s ", n->item);
        n = n->next;
    }
    printf("\n");
}

void sort_list(struct node *head)
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

void free_list(struct node *head)
{
    struct node *n = head;
    while (n != NULL)
    {
        struct node *nextNode = n->next;
        free(n);
        n = nextNode;
    }
}