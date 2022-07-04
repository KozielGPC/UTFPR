#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_INICIAL 5
/**************************************
 * DADOS
 **************************************/
struct fila
{
	TipoElemento *vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
	Fila *fila = (Fila *)malloc(1 * sizeof(Fila));
	TipoElemento *vetor = (TipoElemento *)malloc(TAM_INICIAL * sizeof(TipoElemento));
	fila->fim = 0;
	fila->inicio = 0;
	fila->qtdeElementos = 0;
	fila->tamVetor = TAM_INICIAL;
	fila->vetor = vetor;
	return fila;
};
void fila_destruir(Fila **enderecoFila)
{
	Fila *fila = *enderecoFila;
	free(fila->vetor);
	free(fila);
};
bool fila_inserir(Fila *f, TipoElemento elemento)
{
	if (f->qtdeElementos == f->tamVetor)
	{
		return false;
	}
	if (f->qtdeElementos == 0)
	{
		f->inicio = f->fim;
		f->vetor[f->fim] = elemento;
		f->qtdeElementos += 1;
	}
	else
	{
		f->vetor[(f->fim + 1) % f->tamVetor] = elemento;

		f->fim = (f->fim + 1) % f->tamVetor;
		f->qtdeElementos += 1;
	}
	return true;
};
bool fila_remover(Fila *f, TipoElemento *saida)
{
	if (f->qtdeElementos == 0)
	{
		return false;
	}

	*saida = f->vetor[f->inicio];
	f->inicio = (f->inicio + 1) % f->tamVetor;
	if (f->qtdeElementos - 1 == 0)
	{
		f->fim = (f->fim + 1) % f->tamVetor;
	}
	f->qtdeElementos -= 1;

	return true;
};
bool fila_primeiro(Fila *f, TipoElemento *saida)
{
	if (f->qtdeElementos == 0)
	{
		return false;
	}
	*saida = f->vetor[f->inicio];
	return true;
};
bool fila_vazia(Fila *f)
{
	return f->qtdeElementos == 0;
};
int fila_tamanho(Fila *f)
{
	return f->qtdeElementos;
};
void fila_imprimir(Fila *f)
{
	printf("[");
	for (int i = f->inicio, count = 0; count < f->qtdeElementos; i = (i + 1) % f->tamVetor, count++)
	{
		printf("%d", f->vetor[i]);
		if (count != f->qtdeElementos - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
};
Fila *fila_clone(Fila *f)
{
	Fila *fila = fila_criar();
	fila->fim = f->fim;
	fila->inicio = f->inicio;
	fila->qtdeElementos = f->qtdeElementos;
	fila->tamVetor = f->tamVetor;

	for (int i = f->inicio, count = 0; count < f->qtdeElementos; i = (i + 1) % f->tamVetor, count++)
	{
		fila->vetor[i] = f->vetor[i];
	}
	return fila;
};
bool fila_toString(Fila *f, char *str)
{
	if (f == NULL)
	{
		return false;
	}

	strcat(str, "[");

	for (int i = f->inicio, count = 0; count < f->qtdeElementos; i = (i + 1) % f->tamVetor, count++)
	{
		char casting[50];
		sprintf(casting, "%d", f->vetor[i]);
		strcat(str, casting);
		if (i < f->qtdeElementos - 1)
		{
			strcat(str, ",");
		}
	}
	strcat(str, "]");
	return true;
};
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{
	if (f->qtdeElementos + tamVetor >= f->tamVetor)
	{
		return false;
	}
	for (int i = f->inicio, count = 0; count < tamVetor; i = (i + 1) % f->tamVetor, count++)
	{
		fila_inserir(f, vetor[count]);
	}
	return true;
};
