#include <stdio.h>
#include <string.h>

int main()
{
    int i, italico, negrito;
    char texto[50];

    // CTRL + D devera ser teclado na entrada para digitar que é fim de arquivo
    // fazer verificação caractere - usar o for
    while (1)
    {
        fgets(texto, 50, stdin);
        if (feof(stdin))
        {
            break;
        }
        italico = 0;
        negrito = 0;

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
        // putchar('\n');
    }
}