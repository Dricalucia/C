#include <stdio.h>
#include <string.h>
#include <math.h>

/*Criando a struct */
struct fogo // definição
{
  int R;
  int X;
  int Y;
};

int main()
{
  // float distCirculo;

  /*Criando a variável do tipo struct flor */
  struct fogo flor1;
  struct fogo flor2;

  while (scanf("%d %d %d %d %d %d", &flor1.R, &flor1.X, &flor1.Y, &flor2.R, &flor2.X, &flor2.Y) != EOF)
  {

    /* calculo dos circulos*/
    double distCirculo = sqrt(((double)(flor1.X - flor2.X) * (flor1.X - flor2.X)) + ((double)(flor1.Y - flor2.Y) * (flor1.Y - flor2.Y)));

    /*
    círculo desenhado pelo caçador possui raio R1 e centro (X1; Y1).
    O círculo representando a área da flor possui raio R2 e centro (X2; Y2).

    Ponto pertence à circunferência
    (Cx – Px)^2 + (Cy – Py)^2 = Raio^2

    */

    /* validar resultado (morto ou rico) */
    if (distCirculo + flor2.R <= flor1.R)
    {
      printf("RICO\n");
    }
    else
    {
      printf("MORTO\n");
    }
  }
}
