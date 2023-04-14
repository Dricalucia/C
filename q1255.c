#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  int N, i, j, letra;
  char texto[201];
  int contLetras[26] = {0};

  // quantidade de casos de teste.
  scanf("%d", &N);

  i = 0;
  while (i < N)
  {
    // for (i = 0; i < N; i++)
    //
    fgets(texto, 201, stdin);
    // fgets(texto, sizeof(texto), stdin);

    // Converte para minúsculas
    for (j = 0; texto[j] != '\n'; j++)
    {
      letra = tolower(texto[j]);
      if (letra >= 'a' && letra <= 'z')
      {
        contLetras[letra - 'a'] += 1;
      }
    }

    // imprima uma linha contendo a(s) letra(s) que mais ocorreu(ocorreram)
    for (j = 0; j < 26; j++)
    {
      if (contLetras[j] != 0)
      {
        printf(" %c-%d", j + 'a', contLetras[j]);
      }
    }
    printf("\n");
    // ordenar o contador pela maior ocorrencia

    // se todas as ocorrencias forem iguais, imprimir as letras em ordem alfabética).
    i += 1;
  }
}