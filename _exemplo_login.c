#include <stdio.h>
#include <string.h>

/*Usando strcmp para fazer uma sistema de login e senha (comparar se as strings informadas são iguais as contida no sistema*/

int main(void)
{
    char str1[10], str2[10];
    char senha[10] = "senha";
    char login[10] = "pamela";
    int result;

    printf("Digite seu login\n");
    scanf("%s", str1);
    result = strcmp(str1, login);
    /* retorno da funcao strcmp eh um valor inteiro
    strcmp = 0 caso as strings sejam iguais*/

    if (result == 0)
    {

        printf("Digite sua senha\n");
        scanf("%s", str2);

        result = strcmp(str2, senha);

        if (result == 0)
        {
            printf("Bem-vindo\n");
        }
        else
        {
            printf("Senha nao cadastrada %d\n", result);
        }
    }
    else
    {
        printf("Login nao cadastrado %d\n", result);
    }

    return 0;
}