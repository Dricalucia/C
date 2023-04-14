#include <stdio.h>
#include <string.h>

// Postado no Beecrowd e aceito!

int main()
{
    int i, j = 0, q = 0, italico, negrito;
    char ch;
    char texto[50];

    while ((ch = getchar()) != EOF)
    {
        i = 0;
        italico = 0;
        negrito = 0;

        while (ch != '\n')
        {
            texto[i] = ch;
            i++;
            ch = getchar();
        }
        texto[i] = '\0';

        for (int i = 0; (texto[i] != '\0'); i++)
        {
            if (texto[i] == '_')
            {
                if (italico == 0)
                {
                    printf("<i>");
                    italico += 1;
                }
                else
                {
                    printf("</i>");
                    italico = 0;
                }
            }
            else if (texto[i] == '*')
            {
                if (negrito == 0)
                {
                    printf("<b>");
                    negrito += 1;
                }
                else
                {
                    printf("</b>");
                    negrito = 0;
                }
            }
            else
            {
                putchar(texto[i]);
            }
        }
        printf("\n");
        j++;
    }
}