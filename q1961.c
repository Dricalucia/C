#include <stdio.h>

int main()
{

    /**
    Esse problema tem uma pegadinha, porque além do calculo se o pulo + cano é >= ao próximo cano,
    você tem que fazer o cálculo se o próximo cano é muito baixo para o pulo.
    Segue o enunciado para prestar atenção:
    "Caso a altura do cano seguinte seja muito alta, o sapo bate no cano e cai. Se a altura do cano seguinte
    for muito baixa, o sapo não aguenta a queda. O sapo sempre começa em cima do cano mais à esquerda."

    A altura do próximo cano, não pode ser mais baixa que o cano anterior - pulo..
    */

    int i, j, status = 1;
    int alturaPulo, numeroCanos, diferencaAltura = 0;

    scanf("%d %d", &alturaPulo, &numeroCanos);

    int segundaLinha[numeroCanos];

    for (j = 0; j < numeroCanos; j++)
    {
        // printf("Digite a altura do cano %d: ", j);
        scanf("%d", &segundaLinha[j]);
    }

    for (j = 0; j < (numeroCanos - 1); j++)
    {
        if (segundaLinha[j + 1] > segundaLinha[j])
        {
            diferencaAltura = segundaLinha[j + 1] - segundaLinha[j];
            if (diferencaAltura > alturaPulo)
            {
                status = 0;
                break;
            }
        }
        else
        {
            diferencaAltura = segundaLinha[j] - segundaLinha[j + 1];
            if (diferencaAltura > alturaPulo)
            {
                status = 0;
                break;
            }
        }
    }

    if (status == 1)
    {
        printf("YOU WIN\n");
    }
    else
    {
        printf("GAME OVER\n");
    }

    return 0;
}