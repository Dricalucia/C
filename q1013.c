#include <stdio.h>
#include <stdlib.h>

int calculo(int a, int b);

int main()
{

    int a, b, c;
    float result;

    scanf("%d %d %d", &a, &b, &c);

    result = calculo(a, b);
    result = calculo(c, result);

    printf("%1.f eh o maior \n", result);

    return 0;
}

int calculo(int a, int b)
{
    return ((a + b + abs(a - b)) / 2);
}
