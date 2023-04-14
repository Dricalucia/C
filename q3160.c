#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
    char nome[11];
    struct node *next;
};

void printList(struct node *amigos);
void freeList(struct node *amigos);
struct node *unionList(struct node *amigos_atuais, struct node *amigos_novos, char nome[]);

int main()
{
    // Primeira linha - relação de amigos
    char *line = NULL;
    int line_size = 0;
    getline(&line, &line_size, stdin);
    line[strlen(line) - 1] = '\0';

    char *token = strtok(line, " ");

    struct node *amigos = (struct node *)malloc(sizeof(struct node));
    strcpy(amigos->nome, token);
    amigos->next = NULL;
    while (token != NULL) // dividindo a string recebida no fgtes
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            struct node *n = amigos; // ponteiro auxiliar

            // verifica se o item já está na lista
            while (n->next != NULL)
            {
                n = n->next;
            }

            // adiciona o novo item ao final da lista
            struct node *novo = (struct node *)malloc(sizeof(struct node));
            strcpy(novo->nome, token);
            novo->next = NULL;
            n->next = novo;
        }
    }

    // segunda linha
    line = NULL;
    line_size = 0;
    getline(&line, &line_size, stdin);
    line[strlen(line) - 1] = '\0';

    token = strtok(line, " ");

    // print
    struct node *amigos_novos = (struct node *)malloc(sizeof(struct node));
    strcpy(amigos_novos->nome, token);
    amigos_novos->next = NULL;
    while (token != NULL) // dividindo a string recebida no fgtes
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            struct node *n2 = amigos_novos; // ponteiro auxiliar

            // verifica se o item já está na lista
            while (n2->next != NULL)
            {
                n2 = n2->next;
            }

            // adiciona o novo item ao final da lista
            struct node *novo2 = (struct node *)malloc(sizeof(struct node));
            strcpy(novo2->nome, token);
            novo2->next = NULL;
            n2->next = novo2;
        }
    }

    // Terceira linha - novos amigos
    char nome_indica[11];
    fgets(nome_indica, 11, stdin);
    nome_indica[strcspn(nome_indica, "\n")] = 0; // remover o \n da linha

    /* uniao de amigos
       função retorna a lista de amigos_atuais (da mesma forma que o void)
       para confirmar as alterações foi atribuido a variavel de amigos essa função
    */
    amigos = unionList(amigos, amigos_novos, nome_indica);

    // imprimi lista
    printList(amigos);

    // libera memoria
    // freeList(amigos_novos);
    freeList(amigos);
    free(line);
    return 0;
}

// imprime os elementos da lista (cod ok)
void printList(struct node *amigos)
{
    struct node *n = amigos;
    while (n != NULL)
    {
        printf("%s", n->nome);
        if (n->next != NULL)
        {
            printf(" ");
        }
        n = n->next;
    }
    printf("\n");
}

// limpa a memoria que foi alocada (cod ok)
void freeList(struct node *amigos)
{
    struct node *n = amigos;
    while (n != NULL)
    {
        struct node *next = n->next;
        free(n);
        n = next;
    }
}

// ordena os elementos da lista
struct node *unionList(struct node *amigos_atuais, struct node *amigos_novos, char nome[])
{
    struct node *n = amigos_atuais;
    struct node *m = amigos_novos;

    // se nao houver indicacao, a nova lista de amigos deve ser incluso no final da 1a lista de amigos
    if (strcmp(nome, "nao") == 0)
    {
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = m;
    }
    else
    {
        /* localizar o nome da indicacao, inserir a nova lista de amigos na primeira lista.
        Porem antes do nome da indicação */

        while (m->next != NULL)
        {
            m = m->next;
        }

        struct node *aux = amigos_novos;   // ponteiro auxiliar para o início da lista amigos_novos
        /*
            comparar se o nome na lista de amigos atuais é igual ao nome informado
            caso o nome for igual , então a lista de amigos atuais agora será igual ao valor inicial da lista de amigos novos.
            Do contrário, ele irá fazer aquela comparação que a gente já tinha visto antes.
        */
        if (strcmp(n->nome, nome) == 0)
        {
            m->next = n;
            amigos_atuais = aux;
        }
        else
        {
            while (n->next != NULL)
            {
                if (strcmp(n->next->nome, nome) == 0)
                {
                    m->next = n->next;
                    n->next = aux;
                    break;
                }
                n = n->next;
            }
        }
    }
    return amigos_atuais;
}