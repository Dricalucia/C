#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;
    // int arr[6]
    int len, i;

    printf("Qual o tamanho do array: \n");
    scanf("%d", &len);

    /*malloc retorna um endereco do tipo de void
    não é possivel ler um conteudo do tipo de void
    Por isso, no codigo abaixo o retorno do malloc foi
    convertido em um ponteiro int*/

    arr = (int *)malloc(len * sizeof(int));

    printf("Quais os elementos do array:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    } // leitura dos elementos

    printf("Novo array obtido\n");
    for (i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    } // impressao dos elementos

    /*
    Liberar o espaço de memoria que foi alocado pelo malloc
    */

    free(arr);
    return 0;
}