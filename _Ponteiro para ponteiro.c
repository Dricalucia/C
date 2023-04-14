#include <stdio.h>

int main(void)
{
    int var, *ptr1, **ptr2;
    var = 10;
    ptr1 = &var;
    ptr2 = &ptr1;

    printf("Endereco de ptr1 = %p\n", ptr2);
    printf("Endereco de ptr1 = %p\n\n", &ptr1);
    printf("Endereço de var = %p\n", *ptr2);
    printf("Endereço de var = %p\n\n", ptr1);
    printf("Valor em var = %d\n", **ptr2);
    printf("Valor em var = %d\n", *ptr1);

    return 0;
}