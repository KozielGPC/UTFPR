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
void pilha_imprimir(Pilha *p)
{
    printf("");
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%c", p->vetor[i]);
    }
    printf("\n");
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
    for (int i = 0; i < tamVetor; i++)
    {
        pilha_empilhar(p, vetor[i]);
    }
    return true;
};

bool checaSimbolo(char *caractere)
{
    if (strcmp(caractere, "*") == 0 || strcmp(caractere, "/") == 0 || strcmp(caractere, "^") == 0 || strcmp(caractere, "-") == 0 ||
        strcmp(caractere, "+") == 0)
        return true;
    return false;
}

float fazConta(float valor_1, float valor_2, char operacao)
{
    if (strcmp(&operacao, "*") == 0)
        return valor_1 * valor_2;
    else if (strcmp(&operacao, "+") == 0)
    {
        return valor_1 + valor_2;
    }
    else if (strcmp(&operacao, "/") == 0)
        return valor_1 / valor_2;
    else if (strcmp(&operacao, "-") == 0)
        return valor_1 - valor_2;
    else if (strcmp(&operacao, "^") == 0)
        return pow(valor_1, valor_2);
    else
        return 0;
}

float resolveExpressao(char *expressao)
{
    Pilha *p = pilha_criar();
    char caractere = "";
    char ultimo = '\0';
    int contador = 0;
    TipoElemento desempilhado_1, desempilhado_2;
    float resultado, desempilhado_1_float, desempilhado_2_float;
    for (int i = 0; i < strlen(expressao); i++)
    {
        caractere = expressao[contador];
        printf("%c \n", caractere);
        if (checaSimbolo(&caractere))
        {
            pilha_imprimir(p);
            pilha_desempilhar(p, &desempilhado_1);
            pilha_imprimir(p);
            pilha_desempilhar(p, &desempilhado_2);
            printf("desempilhado 1 %c \n", desempilhado_1);
            printf("desempilhado 2 %c \n", desempilhado_2);
            desempilhado_1_float = atof(&desempilhado_1);
            printf("valor 1: %f\n", desempilhado_1_float);
            desempilhado_2_float = atof(&desempilhado_2);
            printf("valor 2: %f\n", desempilhado_2_float);
            resultado = fazConta(atof(&desempilhado_1), atof(&desempilhado_2), caractere);
            printf("resultado: %f \n", resultado);
            char c[50];
            sprintf(c, "%f", resultado);
            pilha_empilhar(p, resultado);
            contador += 1;
        }
        else
        {
            pilha_empilhar(p, caractere);
            contador += 1;
        }
    }
    pilha_desempilhar(p, &desempilhado_1);
    resultado = atof(&desempilhado_1);
    return resultado;
}
