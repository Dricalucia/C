#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "1345a24";
    char *string = "15.2% foram adimitidos";
    char *ptr;
    int i, total = 300;
    float z;
    double d;

    i = atoi(str);
    z = atof(str);
    d = strtod(string, &ptr);

    printf("String convertida em inteiro %d. String + 10 igual a %d\n", i, i + 10);

    printf("String convertida em float %.3f. String dividida por 3 eh %.3f\n", z, z / 3);

    printf("String \"%s\" convertida em double %.3f e a substring  \"%s\" \n", string, d, ptr);

    d = total * (d / 100);

    printf("Total de adimtidos %.2f\n", d);

    return 0;
}