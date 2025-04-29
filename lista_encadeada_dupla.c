#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct no
{
    struct no *anterior;
    int RA;
    char nome[20];
    struct no *proximo;
}
no;

no *inicio = NULL;
no *auxiliar = NULL;
no *corrente = NULL;
no *fim = NULL;

void inserir()
{
    char continuar;
    no *auxiliar2 = NULL;

    do
    {
        corrente = (no *) malloc(sizeof(no));

        printf("INFORME O RA: ");
        scanf("%i", &corrente->RA);

        printf("INFORME O NOME: ");
        scanf("%s", &corrente->nome);

        corrente->proximo = NULL;

         // Se a lista estiver vazia, o novo nó será o primeiro
        if(inicio == NULL)
        {
            inicio = corrente;
            fim = corrente;
            corrente->anterior = NULL;
        }
        else
        {
            auxiliar = inicio;

            // Inserção no início (quando o nome do corrente é menor que o primeiro)
            if(strcmp(corrente->nome, auxiliar->nome) < 0)
            {
                corrente->proximo = auxiliar;
                auxiliar->anterior = corrente;
                inicio = corrente;  // Atualiza o início da lista
                corrente->anterior = NULL;  // O primeiro nó não tem nó anterior
                printf("\nElemento inserido no início da lista.\n");
            }
            else
            {
                // Busca pelo local correto para inserção ordenada
                while(auxiliar != NULL)
                {
                    // Se o nome do corrente for igual ao do auxiliar, insere no meio
                    if(auxiliar->proximo != NULL && strcmp(corrente->nome, auxiliar->nome) > 0 && strcmp(corrente->nome, auxiliar->proximo->nome) < 0)
                    {
                        auxiliar2 = auxiliar->proximo;
                        corrente->proximo = auxiliar2;
                        corrente->anterior = auxiliar;
                        auxiliar->proximo = corrente;
                        auxiliar2->anterior = corrente;

                        printf("\nElemento inserido no meio da lista.\n");
                        break;
                    }

                    // Se o auxiliar é o último nó, insira no final
                    if(auxiliar->proximo == NULL)
                    {
                        auxiliar->proximo = corrente;
                        corrente->anterior = auxiliar;
                        fim = corrente;  // Atualiza o fim da lista
                        break;
                    }

                    auxiliar = auxiliar->proximo;
                }
            }
        }

        do
        {
            printf("Deseja continuar [S/N]: ");
            scanf(" %c", &continuar);
            fflush(stdin);
            continuar = toupper(continuar);
        }
        while(continuar != 'S' && continuar != 'N');
    }
    while(continuar == 'S');
}

void exibir()
{
    int opc;

    printf("INICIO -> FIM [0]\n");
    printf("FIM -> INICIO [1]\n");
    printf("Selecione a opcao: ");
    scanf("%i", &opc);

    if(opc != 0 && opc != 1)
    {
        printf("Opcao invalida!");
        return;
    }

    if(inicio == NULL)
    {
        printf("Lista vazia!");
        return;
    }

    if(opc == 0)
    {
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            printf("%i - %s \n", auxiliar->RA, auxiliar->nome);

            auxiliar = auxiliar->proximo;
        }
    }
    else
    {
        auxiliar = fim;

        while(auxiliar != NULL)
        {
            printf("%i - %s \n", auxiliar->RA, auxiliar->nome);

            auxiliar = auxiliar->anterior;
        }
    }
}

void pesquisar()
{
    int opc;

    printf("INICIO -> FIM [0]\n");
    printf("FIM -> INICIO [1]\n");
    printf("Selecione a opcao: ");
    scanf("%i", &opc);

    if(opc != 0 && opc != 1)
    {
        printf("Opcao invalida!");
        return;
    }

    if(inicio == NULL)
    {
        printf("Lista vazia!");
        return;
    }

    int RA;

    printf("Pesquise pelo RA: ");
    scanf("%i", &RA);

    if(opc == 0)
    {
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(auxiliar->RA == RA)
            {
                printf("Encontrado!\n");
                printf("%i - %s \n", auxiliar->RA, auxiliar->nome);
                return;
            }

            auxiliar = auxiliar->proximo;
        }

        if(auxiliar == NULL)
        {
            printf("RA nao encontrado!");
        }
    }
    else
    {
        auxiliar = fim;

        while(auxiliar != NULL)
        {
            if(auxiliar->RA == RA)
            {
                printf("Encontrado!\n");
                printf("%i - %s \n", auxiliar->RA, auxiliar->nome);
                return;
            }

            auxiliar = auxiliar->anterior;
        }

        if(auxiliar == NULL)
        {
            printf("RA nao encontrado!");
        }
    }
}

void remover()
{
    int opc;

    printf("INICIO -> FIM [0]\n");
    printf("FIM -> INICIO [1]\n");
    printf("Selecione a opcao: ");
    scanf("%i", &opc);

    if(opc != 0 && opc != 1)
    {
        printf("Opcao invalida!");
        return;
    }

    if(inicio == NULL)
    {
        printf("Lista vazia!");
        return;
    }

    int RA;

    printf("Pesquise pelo RA: ");
    scanf("%i", &RA);

    if(opc == 0)
    {
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(auxiliar->RA == RA)
            {
                printf("%i - %s \n", auxiliar->RA, auxiliar->nome);
                printf("Removido!\n");

                if(auxiliar == inicio)
                {
                    inicio = auxiliar->proximo;
                    inicio->anterior = NULL;
                }
                else if(auxiliar == fim)
                {
                    fim = auxiliar->anterior;
                    fim->proximo = NULL;
                }
                else
                {
                    auxiliar->anterior->proximo = auxiliar->proximo;
                    auxiliar->proximo->anterior = auxiliar->anterior;
                }

                free(auxiliar);

                return;
            }

            auxiliar = auxiliar->proximo;
        }

        if(auxiliar == NULL)
        {
            printf("RA nao encontrado!");
        }
    }
    else
    {
        auxiliar = fim;

        while(auxiliar != NULL)
        {
            if(auxiliar->RA == RA)
            {
                printf("%i - %s \n", auxiliar->RA, auxiliar->nome);
                printf("Removido!\n");

                if(auxiliar == inicio)
                {
                    inicio = auxiliar->proximo;
                    inicio->anterior = NULL;
                }
                else if(auxiliar == fim)
                {
                    fim = auxiliar->anterior;
                    fim->proximo = NULL;
                }
                else
                {
                    auxiliar->anterior->proximo = auxiliar->proximo;
                    auxiliar->proximo->anterior = auxiliar->anterior;
                }

                free(auxiliar);

                return;
            }

            auxiliar = auxiliar->anterior;
        }

        if(auxiliar == NULL)
        {
            printf("RA nao encontrado!");
        }
    }
}

int main()
{
    int opc = 0;

    do
    {
        opc = 0;

        printf("\n [ 1 ] INSERINDO ELEMENTOS NA LISTA");
        printf("\n [ 2 ] EXIBINDO ELEMENTOS DA LISTA ");
        printf("\n [ 3 ] REMOVENDO ELEMENTOS DA LISTA");
        printf("\n [ 4 ] CONSULTA ELEMENTOS DA LISTA ");
        printf("\n [ 5 ] SAIR ");

        printf("\n INFORME A OPCAO: ");
        scanf("%i", &opc);

        switch(opc)
        {
            case 1:
                inserir();
                break;
            case 2:
                exibir();
                system("pause");
                break;
            case 3:
                remover();
                system("pause");
                break;
            case 4:
                pesquisar();
                system("pause");
                break;
            case 5:
                return 0;

            default:
                printf(" OPCAO INVALIDA ");
                system("pause");
        }
        system("cls");
    }
    while(opc >= 1 || opc <= 5);

    return 0;
}
