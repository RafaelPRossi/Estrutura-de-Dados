#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    struct pilha *acima;
    char operador;
    struct pilha *abaixo;
}
pilha;

pilha *topo = NULL;
pilha *auxiliar = NULL;

char operacao[20];

void inserindo()
{
    printf("Insira a funcao: ");
    fgets(operacao, 20, stdin);
    fflush(stdin);

    operacao[strcspn(operacao, "\n\0")] = 0;

}

void push(char operador)
{
    topo = (pilha *) malloc(sizeof(pilha));

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

    topo->operador = operador;
}

void top()
{
    if(topo == NULL)
    {
        return;
    }

    printf("%c", topo->operador);
}

void pop()
{
    if(topo == NULL)
    {
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


int main()
{
    int achou = 0;

    inserindo();

    char operadores[4] = {'+','-','/','*'};

    for(int i = 0; i < strlen(operacao); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(operacao[i] == operadores[j])
            {
                push(operacao[i]);
                achou = 1;
                break;
            }
        }

        if(achou == 0 && operacao[i] != '(' && operacao[i] != ')')
        {
            printf("%c", operacao[i]);
        }

        if(operacao[i] == ')')
        {
            top();
            pop();
        }

        achou = 0;
    }

    while(topo != NULL)
    {
        top();
        pop();
    }

    return 0;
}

