#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila
{
    struct fila *proximo;
    int RA;
    char nome[20];
    struct fila *anterior;
}
fila;

fila *corrente, *inicio, *fim, *auxiliar;

int limite = 5;
int c = 0;

void enqueue()
{
    if(c > limite)
    {
        return;
    }

    corrente = (fila *) malloc(sizeof(fila));
    corrente->proximo = NULL;
    corrente->anterior = NULL;

    printf("RA: ");
    scanf("%i", &corrente->RA);
    
    printf("Nome: ");
    scanf("%s", &corrente->nome);

    if(inicio == NULL)
    {
        inicio = corrente;
    }
    else
    {
        fim->anterior = corrente;
        corrente->proximo = fim;
    }
    c++;
    fim = corrente;
}

void dequeue()
{
    if(inicio == NULL)
    {
        return;
    }

    printf("RA removido: %i ", inicio->RA);
    
    if(inicio == fim)
    {
        free(inicio);
        inicio = NULL;
        auxiliar = NULL;
        fim = NULL;
    }
    else
    {
        auxiliar = inicio->anterior;
        free(inicio);
        inicio = auxiliar;
    }
    
    c--;
}

void seaqueue()
{
    if(inicio == NULL)
    {
        return;
    }

    char nome[20];
    int i = 1;

    printf("Nome: ");
    scanf("%s", &nome);

    auxiliar = inicio;
    while(auxiliar != NULL)
    {
        if(strcmp(auxiliar->nome, nome) == 0)
        {
            printf("Posicao %i", i);
            break;
        }
        auxiliar = auxiliar->anterior;
        i++;
    }
    
    if(auxiliar == NULL)
    {
        printf("Nao encontrado");
    }
}

int main()
{   
    int opc;

    do
    {
        system("pause");
        system("cls");

        printf("Enqueue  [1]\n");
        printf("Dequeue  [2]\n");
        printf("Seaqueue [3]\n");
        printf("Opcao -   ");
        scanf("%i", &opc);

        switch(opc)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                seaqueue();
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida");
        }
    }
    while(opc != 4);

    return 0;
}
