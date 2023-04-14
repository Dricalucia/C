#include <stdio.h>
#include <string.h>

int main()
{

    char buffer[10];
    int i = 0;

    char caractere = getchar();

    while (caractere != '\n')
    {

        buffer[i] = caractere;
        i++;
        caractere = getchar();
    }

    buffer[i] = '\0';

    printf("%s\n", buffer);

    return 0;
}