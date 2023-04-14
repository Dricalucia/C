#include <stdio.h>

int main()
{

    /*
    G ≤ 600 = Número de cursos de graduação
    A ≤ 100 = Número total de tipos de atividade
    M ≤ 2000 = Número de campi da UFFS
    C ≤ 100 = Número total de tipos de material

    */

    /*
    Formatação espaço entre as colunas
    - Cada tabela é precedida por uma linha em branco
    - Entre duas colunas consecutivas de uma mesma tabela há uma coluna de espaços de largura 1
    - E espaços adicionais podem preceder cada inteiro duma tabela a fim de que todas as colunas
      daquela tabela fiquem alinhadas à direita e haja ao menos um inteiro por coluna que não seja
      precedido por espaços adicionais.
    */

    int G, A, M, C;

    int i, j, k;
    float soma;

    // int UFFS[4];

    scanf("%d %d %d %d", &G, &A, &M, &C);
    // printf("\n");

    // MATRIZ 1
    /*
    A primeira tabela consiste de G linhas, cada uma contendo A inteiros não maiores que 10,
    de modo que o j-ésimo inteiro da i-ésima linha representa quantas atividades do tipo j
    um curso de graduação i precisa realizar no ano corrente.
    */

    int tabelaR[G][A];
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            scanf("%d", &tabelaR[i][j]);
        }
    }
    // printf("\n");

    // MATRIZ 2
    /*
    A segunda tabela consiste de A linhas, cada uma contendo M inteiros não maiores que 10,
    de modo que o j-ésimo inteiro da i-ésima linha representa de quantos materiais do tipo j
    a realização de uma atividade do tipo i precisa.
    Esta tabela é a que contam o custo
    */
    int tabelaS[A][M];
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &tabelaS[i][j]);
        }
    }
    // printf("\n");

    // MATRIZ 3
    /*
    A terceira e última tabela consiste de M linhas, cada uma contendo C inteiros não maiores que 100,
    de modo que o j-ésimo inteiro da i-ésima linha representa o preço, em bitcoins, de uma unidade do
    material do tipo i no planeta em que se situa o campus j.
    */
    int tabelaT[M][C];
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &tabelaT[i][j]);
        }
    }
    // printf("\n");

    /*
    R = Grad x Ativ
    S = Ati x Mat
    T = Mat x Camp

    AUX = R x S
    Result = AUX x T

    multiplicar a primeira matriz pela terceira matriz (R e T)
    Multiplicar R e S - reserva em outra matriz
    Depois multiplca a matriz reserva por T
    */

    // MATRIZ AUXILIAR
    // Esta matriz irá realizar a operação da primeira tabela com a segunda tabela
    // AUX = R x S

    int tabelaAux[G][M]; // Qtd linhas 1a tabela e qtd colunas da 2a tabela
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tabelaAux[i][j] = 0;
            for (int k = 0; k < A; k++)
            {
                tabelaAux[i][j] += tabelaR[i][k] * tabelaS[k][j];
            }
        }
    }

    // MATRIZ Resultado
    // Esta matriz irá realizar a operação da matrix aulixar com a segunda matriz

    int tabelaResult[G][C]; // Qtd linhas 1a tabela e qtd colunas da 2a tabela
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tabelaResult[i][j] = 0;
            for (int k = 0; k < M; k++)
            {
                tabelaResult[i][j] += tabelaAux[i][k] * tabelaT[k][j];
            }
        }
    }

    // achar o maior valor da matriz
    int maior = tabelaResult[0][0];
    int li = 0, cj = 0, cont = 0;
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (tabelaResult[i][j] > maior)
            {
                maior = tabelaResult[i][j];
                while (maior != 0)
                {
                    maior = maior / 10;
                    cont += 1;
                }
            };
        }
    }

    int tamanhoNr, contar, difer;

    // impressão da tabela resultado
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < C; j++)
        {
            contar = 0;
            tamanhoNr = tabelaResult[i][j];
            while (tamanhoNr != 0)
            {
                tamanhoNr = tamanhoNr / 10;
                contar += 1;
            }
        }
        difer = contar - cont;
        difer += 1;
        printf("%*d", difer + 1, tabelaResult[i][j]);
    }
    printf("\n");
    return 0;
}
