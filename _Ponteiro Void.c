#include <stdio.h>

int main(void)
{
    int i = 5, *pi;
    float f = 3.3, *pf;

    void *pv; // ponteiro generico
    pv = &i;  // endereco de um int

    pi = (int *)pv; // convertendo o tipo do ponteiro
    printf("%d %p %p\n", *pi, pi, pv);

    pv = &f; // endereco de um float
    pf = (float *)pv;
    printf("%.2f %p %p\n", *pf, pf, pv);
    return 0;
}