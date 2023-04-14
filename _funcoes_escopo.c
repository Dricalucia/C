#include <stdio.h>

void funcao1();
int funcao2(int a);

int a = 10;

int main(void)
{

    printf("O valor de a em main é %d\n", a);
    funcao1();
    a = 15;
    int a = 20;

    a = funcao2(a);
    printf("O valor de a em main é %d\n", a);
    funcao1();

    return 0;
}

void funcao1()
{
    printf("O valor de a em funcao1 é %d\n", a);
}

int funcao2(int a)
{
    a += 10; // a = a + 10;
    printf("O valor de a em funcao2 é %d\n", a);
    return 50;
}