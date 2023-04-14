#include <stdio.h>
#include <string.h>

/*Diferente exemplos de como ler uma string de entrada*/

int main(void)
{

  char str[50], ch;
  int i = 0;
  printf("Digite uma frase: \n");
  // scanf("%s", str); // scanf apenas até o primeiro espaço em branco
  // gets(str); //função desconitnuada - pode gerar problemas de buffer overflow
  // fgets(str,50,stdin); //função recomendada
  ch = getchar(); // usando getchar para coletar caracter por carcater até chegar ao final da linha

  while (ch != '\n')
  { // ler cada carcater enquanto não mudarmos de linha
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0'; // não esquecer de adicionar o \0 no final da string
  printf("%s\n", str);
  puts(str); // alternativa para printar
             // Usando agora putchar para imprimir os valores da string
  for (int i = 0; str[i] != '\0'; i++)
    putchar(str[i]);
  putchar('\n');

  return 0;
}