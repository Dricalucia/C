#include <stdio.h>
#include <string.h>

int main()
{
  int N, K, i, j;
  char idiomaNativo[21], idiomaConversa[21];

  scanf("%d\n", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%d\n", &K);
    ingles = 0;

    for (j = 0; j < K; j++)
    {
      scanf("%s", idiomaNativo[j]);
    }

    for (int k = 0; k < pessoas - 1; k++)
    {
      if (strcmp(idioma[k], idioma[k + 1]) != 0)
      {
        contador++;
      }
    }

    if (contador > 0)
    {
      printf("ingles\n");
    }
    else
    {
      printf("%s\n", idioma[0]);
    }
  }
}
