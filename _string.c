#include <stdio.h>
#include <string.h>

int my_strcmp(char *str1, char *str2);
int my_strlen(char *str1);

int main(void)
{
  // Diferentes maneiras de definir strings
  char cor[] = "azul";
  char *corptr = "azul";
  char cor_2[] = {'a', 'z', 'u', 'l', '\0'};
  char c;

  /* strcat(str_dest,str_org) = string destino tem a concatencao completa*/
  char *str, *new_cor = "escuro";
  str = strcat(cor, " ");
  str = strcat(str, new_cor);

  printf("Resultado concatenacao = %s\n", str);

  /*strlen = Calculo do tamanho da string (número de caracteres)*/
  printf("Tamanho concatencao %lu\n", strlen(str));
  printf("Novo tamanho concatencao %d\n\n", my_strlen(str));

  /* strcpy(str_dest,str_org) = string de origem é copiada na string de destino*/
  /*Tanto em strcat quanto strcpy, a string de destino precisa ter espaco suficiente para armazenar o resultado final*/
  str = strcpy(str, "verde");
  printf("Resultado da copia = %s\n", str);
  printf("Tamanho da copia %lu\n", strlen(str));

  /* strcmp(str1,str2) = 0 se ambas as strings sao iguais, diferente caso contrário*/
  printf("Comparacao de duas strings iquais %d\n", strcmp(cor_2, corptr));

  // string 1 tem caracteres com valores menores que string 2 (em ordem alfabetica)
  printf("Comparacao de duas string diferentes %d\n", strcmp(corptr, new_cor));

  // printf("****** my comp: %d\n", my_strcmp("amarelo","azul"));

  // string 1 tem caracteres com valores maiores que string 2
  // printf("Comparacao de duas string diferentes %d\n", strcmp(new_cor,corptr));

  /* Exemplo de uso do getchar*/
  /*printf("Digite um caractere\n");
  c = getchar();
  putchar(c); //imprimindo caractere
  printf("\n");
  printf("%d\n",c);//imprimindo codigo ASCII*/

  return 0;
}

// funcao para verificar se duas strings sao iguais ou nao
int my_strcmp(char *str1, char *str2)
{

  int i, count = 0;
  for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
  {
    if (str1[i] < str2[i])
    {
      count--;
      break;
    }
    else if (str1[i] > str2[i])
    {
      count++;
      break;
    }
    else
    {
      continue;
    }
  }
  return count;
}

// funcao para contar o tamanho total de uma string
int my_strlen(char *str1)
{
  int i, count = 0;
  for (i = 0; str1[i] != '\0'; i++)
  {
    if (str1[i] != ' ')
    {
      count++;
    }
  }

  return count;
}