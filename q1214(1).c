#include <stdio.h>

float calculoMediaTurma(float x, int y);

int main()
{
    int C, i, j, alunosTurma;
    float somaNotas, mediaTurma, mediaAcima, cont;

    scanf("%d", &C);

    for (i = 0; i < C; i++)
    {
        scanf("%d", &alunosTurma);
        float N[alunosTurma];
        somaNotas = 0;

        for (j = 0; j < alunosTurma; j++)
        {
            scanf("%f", &N[j]);
            somaNotas += N[j];
        }

        mediaTurma = calculoMediaTurma(somaNotas, alunosTurma);
        cont = 0.0;
        for (j = 0; j < alunosTurma; j++)
        {
            if (N[j] > mediaTurma)
            {
                cont = cont + 1;
            }
        }
        mediaAcima = ((float)cont / alunosTurma) * 100;
        printf("%.3f%%\n", mediaAcima);
    }
    return 0;
}

float calculoMediaTurma(float x, int y)
{
    int resultado;

    resultado = x / y;
    return resultado;
}