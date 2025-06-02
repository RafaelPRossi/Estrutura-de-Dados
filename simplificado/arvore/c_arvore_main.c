#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore
{
    int valor;
    struct arvore *esquerda;
    struct arvore *centro;
    struct arvore *direita;
}
arvore;

arvore *corrente, *raiz, *auxiliar;

void esquerda()
{
    while(auxiliar->esquerda != NULL)
    {
        auxiliar = auxiliar->esquerda;
    }
    auxiliar->esquerda = corrente;
    
    printf("\nInserido na esquerda!\n");
}

void centro()
{
    while(auxiliar->centro != NULL)
    {
        auxiliar = auxiliar->centro;
    }
    auxiliar->centro = corrente;

    printf("\nInserido na centro!\n");
}

void direita()
{
    while(auxiliar->direita != NULL)
    {
        auxiliar = auxiliar->direita;
    }
    auxiliar->direita = corrente;

    printf("\nInserido na direita!\n");
}

void insertTree()
{   
    int opc;

    corrente = (arvore *) malloc(sizeof(arvore));
    corrente->esquerda = NULL;
    corrente->centro   = NULL;
    corrente->direita  = NULL;

    printf("Valor: ");
    scanf("%i", &corrente->valor);

    if(raiz == NULL)
    {
        raiz = corrente;
    }
    else
    {
        auxiliar = raiz;
        do
        {
            printf("ESQUERDA [1]\n");
            printf("CENTRO   [2]\n");
            printf("DIREITA  [3]\n");
            printf("Opcao   - ");
            scanf("%i", &opc);

            switch(opc)
            {
                case 1:
                    esquerda();
                    break;
                case 2:
                    centro();
                    break;
                case 3:
                    direita();
                    break;
                default:
                    printf("Opcao invalida!");
            }
        }
        while(opc < 1 || opc > 3);
    }
}

int main()
{   
    int opc;
    do
    {
        system("pause");
        system("cls");

        printf("INSERIR [1]\n");
        printf("EXIBIR  [2]\n");
        printf("REMOVER [3]\n");
        printf("Opcao  - ");
        scanf("%i", &opc);

        switch(opc)
        {
            case 1:
                insertTree();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!");
        }
    }
    while(opc != 4);

    return 0;
}
