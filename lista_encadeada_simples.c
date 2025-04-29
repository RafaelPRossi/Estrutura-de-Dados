#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct no
{
    int RA;
    char nome[20];
    struct no *proximo;
}no;

no *corrente, *auxiliar, *inicio;

void inserirDados()
{
    printf("INFORME O RA: ");
    scanf("%i", &corrente->RA);

    printf("INFORME O NOME: ");
    scanf("%s", &corrente->nome);
}

void inserir()
{
    char continuar;
    no *auxiliar2 = NULL;

    do
    {
        corrente = (no *)malloc(sizeof(no));

        inserirDados();

        corrente->proximo = NULL;

        // Para inicio ser NULL, significa que não tem nenhum nó
        if (inicio == NULL)
        {
            inicio = corrente;
            auxiliar = corrente;
            printf("\n Inserido o Primeiro elemento da lista \n");
            system("pause");
        }
        else // Se não for o primeiro nó, daqui pra frente precisa ordenar
        {
            auxiliar = inicio;

            if(strcmp(corrente->nome, auxiliar->nome) < 0)
            {
                corrente->proximo = auxiliar;
                inicio = corrente;
                printf("\n Elemento antecede o primeiro elemento da lista");
                system("pause");
            }
            else
            {
                if(auxiliar->proximo != NULL)
                {
                    auxiliar2 = auxiliar->proximo;

                    while(auxiliar2 != NULL)
                    {
                        if(strcmp(corrente->nome, auxiliar->nome) == 0)
                        {
                            auxiliar->proximo = corrente;
                            corrente->proximo = auxiliar2;
                            break;
                        }
                        else
                        {
                            if(strcmp(corrente->nome, auxiliar->nome) > 0 && strcmp(corrente->nome, auxiliar2->nome) < 0)
                            {
                                auxiliar->proximo = corrente;
                                corrente->proximo = auxiliar2;
                                printf("\n Inserido Elemento no meio da lista \n");
                                system("pause");
                                break;
                            }
                            else
                            {
                                auxiliar = auxiliar->proximo;
                                auxiliar2 = auxiliar2->proximo;
                            }
                        }
                    }

                    if(auxiliar2 == NULL)
                    {
                        auxiliar->proximo = corrente;
                    }
                }
                else
                {
                    auxiliar->proximo = corrente;
                    corrente->proximo = NULL;
                }
            }
        }


        do
        {
            printf("\nDESEJA CONTINUAR [S/N]: ");
            scanf(" %c", &continuar);
            fflush(stdin);
            continuar = toupper(continuar);
        }
        while (continuar != 'S' && continuar != 'N');
    }
    while (continuar == 'S');
}

void exibir()
{
    if(inicio == NULL)
    {
        printf("\nLISTA VAZIA\n");
        return;
    }

    int i = 0;

    auxiliar = inicio;

    while(auxiliar != NULL)
    {
        i = i + 1;
        printf("\n--- %i ---\nRA: %i \nNome: %s \n", i, auxiliar->RA, auxiliar->nome);
        auxiliar = auxiliar->proximo;
    }
}

void remover()
{
    if(inicio == NULL)
    {
        printf("\nLISTA VAZIA\n");
        return;
    }

    int RA;
    int i = 1;

    printf("\nPESQUISE PELO RA: ");
    scanf("%i", &RA);

    auxiliar = inicio;
    no *anterior = NULL;

    // Percorre a lista toda para encontrar o nó a ser removido
    while (auxiliar != NULL && auxiliar->RA != RA)
    {
        i = i + 1;
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    // Se não encontrou o nó
    if (auxiliar == NULL)
    {
        printf("\nRA não encontrado!\n");
        return;
    }

    // Se for o primeiro nó da lista
    // anterior será NULL, pois ele nem chegou a entrar no laço
    if (anterior == NULL)
    {
        inicio = auxiliar->proximo;
    }
    else
    {
        anterior->proximo = auxiliar->proximo;
    }

    printf("\n--- %i ---\nRA: %i \nNome: %s \n", i, auxiliar->RA, auxiliar->nome);

    free(auxiliar);

    printf("\nElemento removido com sucesso!\n\n");
}

void pesquisar()
{
    if(inicio == NULL)
    {
        printf("\nLISTA VAZIA\n");
        return;
    }

    int RA;
    int i = 0;
    int achou = 0;

    printf("\nPESQUISE PELO RA: ");
    scanf("%i", &RA);

    auxiliar = inicio;

    while(auxiliar != NULL)
    {
        i = i + 1;
        if(auxiliar->RA == RA)
        {
           printf("\n--- %i ---\nRA: %i \nNome: %s \n", i, auxiliar->RA, auxiliar->nome);
           achou = 1;
        }
        auxiliar = auxiliar->proximo;
    }

    if(achou == 0)
    {
        printf("\nRA não encontrado!\n");
    }
}

int main()
{
    corrente = NULL;
    auxiliar = NULL;
    inicio = NULL;

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
