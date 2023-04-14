#include <stdio.h>
#include <stdlib.h>

char minusculo(char ch);

int main(void)
{

    char ch;
    ch = getchar();
    printf("%c", minusculo(ch));
    return 0;
}

char minusculo(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return (ch + 'a' - 'A'); // retorno 1
    }
    else
    {
        return (ch); // retorno 2
    }
}