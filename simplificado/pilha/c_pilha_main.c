#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    struct pilha *acima;
    int RA;
    char nome[20];
    struct pilha *abaixo;
}
pilha;

pilha *topo, *auxiliar;

void push()
{
    topo = (pilha *) malloc(sizeof(pilha));
    topo->acima = NULL;
    topo->abaixo = NULL;

    printf("RA: ");
    scanf("%i", &topo->RA);
    
    printf("Nome: ");
    scanf("%s", &topo->nome);

    if(auxiliar != NULL)
    {
        auxiliar->acima = topo;
        topo->abaixo = auxiliar;
    }
    auxiliar = topo;
}

void top()
{
    if(auxiliar == NULL)
    {
        return;
    }

    printf("%i - %s\n", topo->RA, topo->nome);
}

void pop()
{
    if(auxiliar == NULL)
    {
        return;
    }

    printf("RA removido: %i ", topo->RA);

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

int main()
{
    int opc;

    do
    {
        system("pause");
        system("cls");
        
        printf("PUSH [1]\n");
        printf("TOP  [2]\n");
        printf("POP  [3]\n");
        printf("SAIR [4]\n");
        printf("Opc - ");
        scanf("%i", &opc);

        switch(opc)
        {
            case 1:
                push();
                break;
            case 2:
                top();
                break;
            case 3:
                pop();
                break;
            case 4:
                return 0;
            default:
                printf("\nOpcao invalida!\n");
        }
    }
    while(opc != 4);
}
