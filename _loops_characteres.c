#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;

    for (ch = '0'; ch <= '9'; ch++)
    { // For loop com caracteres
        printf("\n O valor ASCII de %c eh %d", ch, ch);
    }

    printf("\n");
    return 0;
}