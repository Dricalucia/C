#include <stdio.h>
#include <math.h>

struct point
{ // estrutura que define um ponto no plano cartesiano
    int x;
    int y;
};

int max_x = 100; // variaveis globais definindo
int max_y = 100; // pontos maximos possiveis no plano

int main(void)
{
    struct point pt;
    struct point maxpt = {4, 3};
    double dist; // distancia euclidiana dos dois pontos

    printf("Digite as coordenadas do novo ponto: \n");
    scanf("%d %d", &pt.x, &pt.y);

    printf("Novo ponto igual a: x = %d, y = %d \n", pt.x, pt.y);

    dist = sqrt(((pt.x - maxpt.x) * (pt.x - maxpt.x) + (pt.y - maxpt.y) * (pt.y - maxpt.y)));

    printf("Distancia euclidiana igual a %.3f \n", dist);

    return 0;
}