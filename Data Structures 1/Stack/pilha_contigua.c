#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_INICIAL 5

/**************************************
 * DADOS
 **************************************/
struct pilha
{
    TipoElemento *vetor;
    int tamVetor;
    int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
    TipoElemento *vetor = (TipoElemento *)malloc(TAM_INICIAL * sizeof(TipoElemento));
    Pilha *pilha = (Pilha *)malloc(1 * sizeof(Pilha));
    pilha->qtdeElementos = 0;
    pilha->tamVetor = TAM_INICIAL;
    pilha->vetor = vetor;
    return pilha;
};

void pilha_destruir(Pilha **endereco)
{
    Pilha *pilha = (Pilha *)malloc(1 * sizeof(Pilha));
    pilha = *endereco;
    free(pilha->vetor);
    pilha->vetor = NULL;

    free(pilha);
    pilha = NULL;
};
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
    if (p->tamVetor == p->qtdeElementos)
    {
        p->vetor = aumenta_vetor(p->vetor, p->tamVetor);
        p->tamVetor += 1;
    }
    p->vetor[p->qtdeElementos] = elemento;
    p->qtdeElementos += 1;
    return true;
};
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    if (p->qtdeElementos == 0)
        return false;

    *saida = p->vetor[p->qtdeElementos - 1];
    if (p->qtdeElementos == p->tamVetor)
    {
        TipoElemento *vetor_novo = (TipoElemento *)malloc((p->qtdeElementos - 1) * sizeof(TipoElemento));
        if (vetor_novo == NULL)
            return false;
        for (int i = 0; i < p->qtdeElementos - 1; i++)
        {
            vetor_novo[i] = p->vetor[i];
        }
        p->vetor = vetor_novo;
        p->tamVetor -= 1;
    }

    else
    {
        for (int i = 0; i < p->qtdeElementos - 1; i++)
        {
            p->vetor[i] = p->vetor[i];
        }
    }

    p->qtdeElementos -= 1;
    return true;
};
bool pilha_topo(Pilha *p, TipoElemento *saida)
{
    *saida = p->vetor[p->qtdeElementos - 1];
    return true;
};
bool pilha_vazia(Pilha *p)
{
    return p->qtdeElementos == 0;
};
void pilha_imprimir(Pilha *p)
{
    printf("[");
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        if (i == p->qtdeElementos - 1)
        {
            printf("%d", p->vetor[i]);
        }
        else
        {
            printf("%d;", p->vetor[i]);
        }
    }
    printf("]\n");
};
int pilha_tamanho(Pilha *p)
{
    return p->qtdeElementos;
};
Pilha *pilha_clone(Pilha *p)
{
    Pilha *pilha = pilha_criar();
    TipoElemento *vetor = (TipoElemento *)malloc(p->tamVetor * sizeof(TipoElemento));
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        vetor[i] = p->vetor[i];
    }
    pilha->qtdeElementos = p->qtdeElementos;
    pilha->tamVetor = p->tamVetor;
    pilha->vetor = vetor;
};
void pilha_inverter(Pilha *p)
{
    TipoElemento *vetor_auxiliar = (TipoElemento *)malloc(p->qtdeElementos * sizeof(TipoElemento));

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        vetor_auxiliar[i] = p->vetor[p->qtdeElementos - i - 1];
    }

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        p->vetor[i] = vetor_auxiliar[i];
    }
};
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{
    if (p->qtdeElementos + tamVetor > p->tamVetor)
    {
        return false;
    }
    printf("%d \n", vetor[1]);
    for (int i = 0; i < tamVetor; i++)
    {
        printf("%d \n", vetor[i]);
        pilha_empilhar(p, vetor[i]);
    }
    return true;
};

bool pilha_toString(Pilha *pilha, char *str)
{
    if (pilha == NULL)
    {
        return false;
    }
    strcat(str, "[");

    for (int i = 0; i < pilha->tamVetor; i++)
    {
        char casting[50];
        sprintf(casting, "%d", pilha->vetor[i]);
        strcat(str, casting);
        if (i < (pilha->tamVetor) - 1)
        {
            strcat(str, ",");
        }
    }
    strcat(str, "]");
    return true;
};

TipoElemento *aumenta_vetor(TipoElemento *vetor, int tamanho)
{
    TipoElemento *vetor_novo = (TipoElemento *)malloc((tamanho + 1) * sizeof(TipoElemento));
    if (vetor_novo == NULL)
        return false;

    for (int i = 0; i < tamanho; i++)
    {
        vetor_novo[i] = vetor[i];
    }
    return vetor_novo;
}
