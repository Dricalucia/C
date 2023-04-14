#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int N = 0, cont = 0;

    scanf("%d\n", &N);

    while (cont != N)
    {
        char letra;
        char texto[200], letras[200];
        int posicao = 0, quantidade, contador[200], j, frequencia = 0;

        letra = getchar();

        while (letra != '\n')
        {
            texto[posicao] = tolower(letra);
            posicao++;
            letra = getchar();
        }
        texto[posicao] = '\0';

        for (int i = 0; i <= strlen(texto) - 1; i++)
        {
            int contou = 0;
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                // printf("i=%d; texto[i]=%c;\n", i, texto[i]);
                for (j = 0; j < strlen(letras); j++)
                {
                    // printf("strlen(letras)=%lu; i=%d; j=%d; texto[i]=%c; letras[j]=%c;\n", strlen(letras), i, j, texto[i], letras[j]);
                    if (texto[i] == letras[j])
                    {
                        contador[j]++;
                        contou = 1;
                        break;
                    }
                }
                if (contou == 0)
                {
                    letras[j] = texto[i];
                    contador[j] = 1;
                }
            }
        }

        // for (int k = 0; k < strlen(letras); k++){
        //     printf("%c %d\n", letras[k], contador[k]);
        // }

        // varrer todo array de contador até achar o maior
        for (int l = 0; l < strlen(letras); l++)
        {
            if (contador[l] > frequencia)
            {
                frequencia = contador[l];
            }
        }
        // varrer todo array de contador para achar as posições que tem valor igual ao maior e imprimir
        for (int m = 0; m < strlen(letras); m++)
        {
            if (contador[m] == frequencia)
            {
                printf("%c", letras[m]);
            }
            // contador[m] = 0;
        }
        letras[0] = '\0';
        printf("\n");
    }

    return 0;
}