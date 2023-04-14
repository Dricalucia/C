#include <stdio.h>
#include <string.h>

/*
Adapte a segunda questão da lista 04, o problema das camisetas
(https://www.beecrowd.com.br/judge/en/problems/view/1258 ) agora
para uma lista encadeada;
1 - O que precisamos mudar na struct inicial?
2 - Como será feita a inserção de novos elementos?
3 - Quais cuidados devemos ter com relação ao ponteiro *head?
4 - Que funções precisamos criar para correto funcionamento da questão?
*/

/*Criando a struct */
struct node // definição
{
    char nome[50];
    char cor[15];
    char tam;
    struct node *next;
};

void insert_node(struct node **head, char *name, char *color, char *tam);

int main()
{
    // insere e ordena os dados
    insert_node(**head, *name, color, *tam);

    // imprimir struct ordenada
    for (j = 0; j < N; j++)
    {
        printf("%s %c %s\n", estudante[j].cor, estudante[j].tam, estudante[j].nome);
    }

    scanf("%d", &N);
    if (N != 0)
    {
        printf("\n");
    }

    return 0;
}

void insert_node(struct node **head, char *name, char *color, char *tam)
{
    struct node *temp;
    temp = *head;

    if (*head == NULL) // verificar se a lista esta vazia
    {
        *head = (struct node *)malloc(sizeof(struct node));
        head->next = NULL;
        strcpy(head->nome, name);
        strcpy(head->cor, color);
        *head->tam = tam;
    }
    else
    {
        if strcmp (head->nome, name)
            > 0 // verificar se o novo nome tem que esta no inicio da head
            {
                // inserindo no começo da head
                temp = (struct node *)malloc(sizeof(struct node));
                strcpy(temp->nome, name);
                strcpy(temp->cor, color);
                temp->tam = tam;
                temp->next = *head;
                *head = temp;
            }
        else
        {
            while (temp->next != NULL && emp->nome, name)
            {
                temp = temp->next;
            }
            struct node *novo;
            novo = (struct node *)malloc(sizeof(struct node));
            novo->next = temp->next;

            FALTA FINALIZAR
        }
    }
}
