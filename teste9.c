#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura do nó da lista encadeada
typedef struct node {
    char nome[20]; //nome do aluno
    char cor; //cor da camisa (B - branco, V - vermelho)
    char tamanho; //tamanho da camisa (P, M, G)
    struct node* prox; //ponteiro para o próximo nó
}Node;

//função que insere um nó na lista ordenadamente
void inserir_ordenado(Node** inicio, char nome[], char cor, char tamanho) {
    Node* novo = (Node*) malloc(sizeof(Node)); //aloca espaço para o novo nó
    strcpy(novo->nome, nome); //copia o nome para o novo nó
    novo->cor = cor; //atribui a cor para o novo nó
    novo->tamanho = tamanho; //atribui o tamanho para o novo nó

    Node* ant = NULL; //ponteiro auxiliar para percorrer a lista
    Node* atual = *inicio; //ponteiro auxiliar para percorrer a lista

    //percorre a lista até encontrar o lugar adequado para inserir o novo nó
    while (atual != NULL && atual->cor < cor) {
        ant = atual;
        atual = atual->prox;
    }
    while (atual != NULL && atual->cor == cor && atual->tamanho > tamanho) {
        ant = atual;
        atual = atual->prox;
    }
    while (atual != NULL && atual->cor == cor && atual->tamanho == tamanho && strcmp(atual->nome, nome) < 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL) { //insere o novo nó no início da lista
        novo->prox = *inicio;
        *inicio = novo;
    }
    else { //insere o novo nó em qualquer outra posição da lista
        ant->prox = novo;
        novo->prox = atual;
    }
}

//função que imprime os dados da lista
void imprimir(Node* inicio) {
    while (inicio != NULL) {
    printf("%s\n%c %c\n", inicio->nome, inicio->cor, inicio->tamanho);
    inicio = inicio->prox;
    }
}

//função que libera a memória alocada para a lista
void liberar(Node* inicio) {
    Node* aux;
    while (inicio != NULL) {
    aux = inicio->prox;
    free(inicio);
    inicio = aux;
    }
}

int main() {
    int n;
    char nome[20], cor, tamanho;
    Node* inicio = NULL; //ponteiro para o início da lista

    while (1) {
        scanf("%d", &n);
        if (n == 0) break; //interrompe a execução do programa se N for igual a zero
        
        //leitura dos dados e inserção na lista
        for (int i = 0; i < n; i++) {
            scanf(" %[^\n]", nome); //lê o nome do aluno (com espaços)
            scanf(" %c %c", &cor, &tamanho); //lê a cor e o tamanho da camisa
            inserir_ordenado(&inicio, nome, cor, tamanho); //insere o nó na lista
        }
        
        //imprime os dados da lista
        imprimir(inicio);
        printf("\n");
        
        //libera a memória alocada para a lista
        liberar(inicio);
        inicio = NULL;
    }
    return 0;
}