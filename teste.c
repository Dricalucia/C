#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Entrada
A primeira linha de entrada contém um inteiro N (N < 100) que indica a quantidade
de casos de teste que vem a seguir, ou melhor, a quantidade de listas de compras
que Valentina quer organizar. Cada lista de compra consiste de uma única linha que
contém de 1 a 1000 itens ou palavras compostas apenas de letras minúsculas (de 1 a 20 letras),
sem acentos e separadas por um espaço.*/
struct node
{
   char item[20];
   struct node *next;
}; // células da minha lista
void add_node(struct node *head, char item[]);
void printList(struct node *head);
void sortList(struct node *head);
void freeList(struct node *head);
int main()
{
   struct node *head = NULL;
   int N;
   char itens[10001];
   char *token;
   scanf("%d\n", &N);
   for (int i = 0; i < N; i++)
   {
      head = NULL;
      fgets(itens, 10001, stdin);
      if (itens[strlen(itens) - 1] == '\n')
      {
         itens[strlen(itens) - 1] = '\0';
      }
      token = strtok(itens, " ");
      while (token) // dividindo a string recebida no fgtes
      {
         if (head == NULL)
         {
            head = (struct node *)malloc(sizeof(struct node));
            strcpy(head->item, token);
            head->next = NULL;
         }
         else
         {
            add_node(head, token);
         }
         token = strtok(NULL, " ");
      }
      /*
      Saída
      A saída contém N linhas, cada uma representando uma das listas de compras de Valentina,
      sem itens repetidos e em ordem alfabética.
      */
      sortList(head);
      printList(head);
      // liberar memoria
      freeList(head);
   }
   return 0;
}
// inserção de elementos no final da lista
void add_node(struct node *head, char item[])
{
   struct node *n = head; // ponteiro auxiliar
   int valida = 0;        // chave para item repetido
   while (n->next != NULL)
   {
      if (strcmp(n->item, item) == 0)
      {
         valida = 1;
      }
      n = n->next;
   }
   /* ERRO
   o ultimo item não esta sendo comparado, por isso esta sendo repetido na impressão */
   if (strcmp(n->item, item) == 0)
   {
      valida = 1;
   }
   if (valida == 0)
   {
      // insere no ultimo elemento
      struct node *novo = (struct node *)malloc(sizeof(struct node));
      strcpy(novo->item, item);
      novo->next = NULL;
      n->next = novo;
   }
}
// imprime os elementos da lista
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
// limpa a memoria que foi alocada
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