#include <stdlib.h>
#include <stdio.h>

typedef struct pilha
{
    struct pilha *acima;
    int RA;
    char nome[20];
    struct pilha *abaixo;
}
pilha;

pilha *topo = NULL;
pilha *auxiliar = NULL;

void push()
{
    char continuar;

    do
    {
        topo = (pilha *) malloc(sizeof(pilha));

        printf("RA: ");
        scanf("%i", &topo->RA);

        printf("Nome: ");
        scanf("%s", &topo->nome);

        topo->acima = NULL;

        if(auxiliar == NULL)
        {
            topo->abaixo = NULL;
        }
        else
        {
            auxiliar->acima = topo;
            topo->abaixo = auxiliar;
        }

        auxiliar = topo;

        printf("\nInserido com sucesso!\n");

        do
        {
            printf("DESEJA CONTINUAR [S/N]? ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);
        }
        while(continuar != 'N' && continuar != 'S');
    }
    while(continuar == 'S');
}

void pop()
{
    if(topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }

    if(topo->abaixo == NULL)
    {
        free(topo);
        topo = NULL;
        auxiliar = NULL;
    }
    else
    {
        auxiliar = topo->abaixo;
        auxiliar->acima = NULL;

        free(topo);
        topo = auxiliar;
    }
}

void top()
{
    if(topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }

    printf("\n%i - %s ", topo->RA, topo->nome);
}

int main()
{
    int operacao;

    do
    {
        operacao = 0;

        system("cls");

        printf("PUSH    [1]\n");
        printf("POP     [2]\n");
        printf("TOP     [3]\n");
        printf("SAIR    [4]\n");
        printf("ESCOLHA: ");
        scanf("%i", &operacao);

        switch(operacao)
        {
            case 1:
                push();
                system("pause");
                break;

            case 2:
                pop();
                system("pause");
                break;

            case 3:
                top();
                system("pause");
                break;

            case 4:
                return;

            default:
                system("cls");
                printf("opcao invalida");
                system("pause");
        }
    }
    while(operacao > 0 || operacao < 5);

    return 0;
}
