#include <stdio.h>
#include <string.h>
#define MAX 5 // Esta sendo criado atraves de uma diretiva do compilador
              // esta diretiva permite criar uma constante que pode ser usada em todo o codigo
              // o define não aloca espaco na memoria - ele troca a informação no texto e depois compila
#define COUNT 10
/*
Pode-se usar tambem o comando define com um comando de uma função
#define S(x) strlen(x)
*/

struct student
{
    char name[20];
    int roll_no;
    float marks;
};

int main()
{
    // vetor criado com o tipo struct
    struct student arr_student[MAX]; // vetor de tamanho 5 (vlr da constante)
    int i;

    // num mesmo indice haverá três elementos (da struct)
    for (i = 0; i < MAX; i++)
    {
        printf("\nEnter details of student %d\n\n", i + 1);
        printf("Enter name: ");
        scanf("%s", arr_student[i].name);

        printf("Enter roll no: ");
        scanf("%d", &arr_student[i].roll_no);

        printf("Enter marks: ");
        scanf("%f", &arr_student[i].marks);
    }

    printf("\n");

    printf("Name\tRoll no\tMarks\n"); // primeira coluna da tabela

    for (i = 0; i < MAX; i++)
    {
        // comando padrão de impressao da struct

        printf("%s\t %d\t %.2f\n",
               arr_student[i].name, arr_student[i].roll_no, arr_student[i].marks);
    }

    // signal to operating system program ran fine
    return 0;
}