#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
}
arvore;

arvore *corrente, *raiz, *auxiliar;

void insertTree()
{
    corrente = (arvore *) malloc(sizeof(arvore));
    corrente->esquerda = NULL;
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
        while(auxiliar != NULL)
        {
            while(corrente->valor == auxiliar->valor)
            {
                printf("Chaves iguais!, Novo Valor: ");
                scanf("%i", &corrente->valor);
                auxiliar = raiz;
            }

            if(corrente->valor > auxiliar->valor)
            {   
                if(auxiliar->direita == NULL)
                {
                    auxiliar->direita = corrente;
                    printf("add a direita\n");
                    break;
                }
                auxiliar = auxiliar->direita;
                printf("avancou a direita\n");
                continue;
            }
            else
            {
                if(auxiliar->esquerda == NULL)
                {
                    auxiliar->esquerda = corrente;
                    printf("add a esquerda\n");
                    break;
                }
                auxiliar = auxiliar->esquerda;
                printf("avancou a esquerda\n");
                continue;
            }
        }
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
