#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct job
{
   struct job *proximo;
   int bandeira;
   int RA;
   char nome[20];
}
job;

job *corrente, *auxiliar, *primeiro, *ultimo;

int c = 1;
int limite = 5;

void enqueue() // insere elemento na fila
{
    corrente = (job *) malloc(sizeof(job));

    if(c > limite)
    {
        system("cls");
        printf("\nFila cheia\n");
        system("pause");
        return;
    }

    printf("\n-----------------------------\n");
    printf("RA: ");
    scanf("%i", &corrente->RA);

    printf("Nome: ");
    scanf("%s", &corrente->nome);

    if(primeiro == NULL)
    {
        primeiro = corrente;
        primeiro->proximo = NULL;
    }
    else
    {
        auxiliar = ultimo;
        auxiliar->proximo = corrente;
    }

    c++;

    auxiliar = corrente;
    ultimo = corrente;
}

void dequeue() // remove da fila
{
    job *segundo = NULL;

    if(primeiro == NULL)
    {
        printf("\nVAZIO\n");
        system("pause");
        return;
    }

    if(primeiro == ultimo)
    {
        free(primeiro);
        primeiro = NULL;
        ultimo   = NULL;
        corrente = NULL;
        auxiliar = NULL;
    }
    else
    {
        segundo = primeiro->proximo;
        free(primeiro);
        primeiro = segundo;
    }

    c--;

    printf("\nREMOVIDO!\n");
    system("pause");
}

void seaqueue() // pesquisa a posição em que o job esta
{
    if(primeiro == NULL)
    {
        printf("\nVAZIO\n");
        system("pause");
        return;
    }

    int i = 0;
    char nome[20];
    printf("PESQUISE: ");
    scanf("%s", &nome);

    auxiliar = primeiro;

    while(auxiliar != NULL)
    {
        i = i + 1;
        if(strcmp(auxiliar->nome, nome) == 0)
        {
            printf("posicao - %i", i);
            break;
        }

        auxiliar = auxiliar->proximo;
    }

    if(auxiliar == NULL)
    {
        printf("nao encontrado");
    }

    system("pause");
}

int main()
{
    corrente = NULL;
    auxiliar = NULL;
    primeiro = NULL;
    ultimo   = NULL;

    char continuar;
    int op;

    do
    {
        system("cls");

        printf("ENQUEUE  [1]\n");
        printf("DEQUEUE  [2]\n");
        printf("SEAQUEUE [3]\n");
        printf("SAIR     [4]\n");
        printf("\nOPCAO     ");
        scanf("%i", &op);

        switch(op)
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
                break;

            default:
                printf("opcao invalida!\n");
                system("pause");
        }

    }
    while(op != 4);

    return 0;
}
