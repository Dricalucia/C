#include <stdio.h>
#include <stdlib.h>

/* USAR LISTA ENCADEADA */
struct node
{
    char nome[10];
    struct node *next;
}; // celulas da minha lista

void add_node(struct node *head, char nome[]);
void printList(struct node *head);

int main()
{
    struct node *head = NULL;
    struct node *novo = NULL;
    struct node *temp = NULL;

    for (int i = 0; i < N; i++)
    {
        char *line1 = NULL;
        int line1_size = 0;
        getline(&line1, &line1_size, stdin);
        line1[strlen(line1) - 1] = '\0';

        char *token = strtok(line, " ");

        if (i == 0)
        {
            struct node *head1 = (struct node *)malloc(sizeof(struct node));
            strcpy(head1->item, token);
            head1->next = NULL;
        }

        while (token != NULL) // dividindo a string recebida no fgtes
        {
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                add_node(head, token);
            }
        }
    }
    /* recebendo os dados da 1a linha
       Ler em uma única linha a lista de amigos de Luiggy L, contendo
       somente o primeiro nome e separados por um espaço em branco.
    */

    for (linha = 1; i < 4; i++)
    {
        if (linha == 1)
        {
            /* incluir comando de repetição para receber varios nomes*/
            scanf("%s", &amigos_atual);

            char *token = strtok(amigos_atual, " ");
            while (token != NULL)
            {
                novo = (struct node *)malloc(sizeof(struct node));
                if (head == NULL)
                {
                    head->nome = token;
                    head->next = NULL;
                    novo = head;
                }
                else
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->nome = token;
                    temp->next = NULL;
                    novo->next = temp;
                    novo = temp;
                }
                token = strtok(NULL, " - ");
            }
        }
        else if (linha == 2)
        {
            /* recebendo os dados da 2a linha
            Na segunda linha deve ser informada a nova lista de amigos N
            (se houver o nome da 3a linha, inserir o(s) nome(s) da 2a linha)
            */

            /* incluir comando de repetição para receber varios nomes*/
            scanf("%s", &nome);

            novo = (struct node *)malloc(sizeof(struct node));
            novo->nome = NULL; // array[0] = Nulo
            novo->next = NULL; // primeiro elemento da lista
        }
        else // linha igual a 3
        {
            /*
            Na última linha, o nome do amigo S da rede que deseja indicar
            também essa nova lista de amigos N

            Caso não queira indicar para ninguém a nova lista de amigos,
            basta digitar na última linha a palavra “nao”.
            */
            scanf("%s", &nome);
        }
    }

    /* Ler os valores da primeira linha
       localiza a palavra da 3 linhas
       se for diferente de não, insere os nomes da 2a linha na primeira linha*/

    /*
        Saída
        exibir a nova lista de amigos de Luiggy atualizada.
        Se houver indicação de um amigo da lista, os novos amigos deverão
        ser inseridos antes do nome do amigo indicado. Caso não haja indicação,
        os novos nomes deverão ser inseridos no fim da lista de amigos de Luiggy.
    */

    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->valor);
        head = temp->next;
        free(temp);
        temp = head;
    }

    return 0;
}

void add_node(struct node *head, int var)
{                          // insercao de elementos no final da lista
    struct node *n = head; // ponteiro auxiliar
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    novo->valor = var; // criar o novo elemento

    if (n == NULL)
    { // lista vazia
        n = novo;
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