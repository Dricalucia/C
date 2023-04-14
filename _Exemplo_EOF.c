#include <stdio.h>

/*Lendo linha por linha de uma entrada até chegar ao final do arquivo*/

int main(void)
{
    char ch;
    char str[100];
    int i, j = 0, q = 0;

    while ((ch = getchar()) != EOF)
    {
        i = 0;
        while (ch != '\n')
        {
            str[i] = ch;
            i++;
            ch = getchar();
        }
        str[i] = '\0';
        printf("linha %d: %s\n", j + 1, str);
        j++;
    }

    // usar este codigo na questão extra
    while (1)
    { //
        fgets(str, 100, stdin);
        if (feof(stdin))
        {
            break;
        }
        printf("linha %d: %s", q + 1, str);
        q++;
    }

    return 0;
}