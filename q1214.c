#include <stdio.h>

// int mediaTurma(int x, int y);

int main()
{

    /**
     * PARA ESTA QUESTÃO, CRIAR A PRÓPRIA FUNÇÃO PARA O CÁLCULO DA MÉDIA.
     */

    int C, i, j, alunosTurma, somaNotas, cont;
    float mediaTurma, mediaAcima;
    scanf("%d", &C);

    for (i = 0; i < C; i++)
    {
        scanf("%d", &alunosTurma);
        int N[alunosTurma];
        somaNotas = 0;
        cont = 0;

        for (j = 0; j < alunosTurma; j++)
        {
            scanf("%d", &N[j]);
            somaNotas += N[j];
        }

        mediaTurma = somaNotas / alunosTurma;
        for (j = 0; j < alunosTurma; j++)
        {
            if (N[j] > mediaTurma)
            {
                cont += 1;
            }
        }
        mediaAcima = cont / (alunosTurma * 100);
        printf("%3.f%%\n", mediaAcima);
    }
    return 0;
}

// int mediaTurma(int x, int y)
//{
// CRIAR A PRÓPRIA FUNÇÃO PARA O CÁLCULO DA MÉDIA
//}