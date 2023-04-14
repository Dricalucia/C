#include <stdio.h>

int main()
{
    enum week
    {
        sun = 0,
        mon,
        tue,
        wed,
        thu,
        fri,
        sat
    };

    enum week input;

    printf("Digite o dia da semana (domingo = 0, segunda = 1, etc): ");
    scanf("%d", &input);

    switch (input)
    {
    case sun:
        printf("\nHoje é domingo, pé de cachimbo!\n");
        break;
    case mon:
        printf("\nSegunda! Bora trabalhar!!\n");
        break;
    case tue:
        printf("\nNo embalo da terça!\n");
        break;
    case wed:
        printf("\nQuarta, será que hoje tem jogo?\n");
        break;
    case thu:
        printf("\nBora logo com essa quinta que já tá quase no fim de semana!\n");
        break;
    case fri:
        printf("\nSEXTOU!\n");
        break;
    case sat:
        printf("\nPrainha no sábado é de boa!\n");
        break;
    default:
        printf("\nTu num entendeu minha pergunta não foi?\n");
        break;
    }

    return 0;
}