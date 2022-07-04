#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
	TipoElemento dado;
	struct no *prox;
} No;

struct pilha
{
	No *topo;
	int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
	Pilha *p = (Pilha *)malloc(1 * sizeof(Pilha));
	p->topo = NULL;
	p->qtdeElementos = 0;
	return p;
};
void pilha_destruir(Pilha **endereco)
{
	Pilha *pilha = (Pilha *)malloc(1 * sizeof(Pilha));
	pilha = *endereco;

	No *atual, *proximo;

	atual = pilha->topo;

	while (atual != NULL)
	{
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}

	free(pilha);
};
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
	No *no = (No *)malloc(1 * sizeof(No));
	no->dado = elemento;
	no->prox = NULL;
	p->qtdeElementos += 1;
	if (p->topo != NULL)
	{
		no->prox = p->topo;
	}
	p->topo = no;
};
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
	if (p->topo == NULL)
	{
		return false;
	}
	*saida = p->topo->dado;
	p->topo = p->topo->prox;
	p->qtdeElementos -= 1;
	return true;
};
bool pilha_topo(Pilha *p, TipoElemento *saida)
{
	*saida = p->topo->dado;
	return true;
};
bool pilha_vazia(Pilha *p)
{
	return p->qtdeElementos == 0;
};
void pilha_imprimir(Pilha *p)
{
	printf("[");
	No *aux = (No *)malloc(1 * sizeof(No));
	aux = p->topo;
	for (int i = 0; i < p->qtdeElementos; i++)
	{
		if (i == p->qtdeElementos - 1)
		{
			printf("%d", aux->dado);
		}
		else
		{
			printf("%d;", aux->dado);
		}
		aux = aux->prox;
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
	int tamanho = p->qtdeElementos;
	printf("Tamanho: %d\n", tamanho);
	TipoElemento *elementos = (TipoElemento *)malloc(p->qtdeElementos * sizeof(TipoElemento));
	No *aux = p->topo;
	for (int i = 0; i < tamanho; i++)
	{
		elementos[i] = aux->dado;
		aux = aux->prox;
	}

	for (int i = tamanho - 1; i >= 0; i--)
	{
		pilha_empilhar(pilha, elementos[i]);
	}
	return pilha;
};

void pilha_inverter(Pilha *p)
{
	Pilha *pilha = pilha_criar();
	int tamanho = p->qtdeElementos;
	printf("Tamanho: %d\n", tamanho);
	TipoElemento *elementos = (TipoElemento *)malloc(p->qtdeElementos * sizeof(TipoElemento));
	No *aux = p->topo;
	for (int i = 0; i < tamanho; i++)
	{
		elementos[i] = aux->dado;
		aux = aux->prox;
	}

	aux = p->topo;
	for (int i = tamanho -1 ; i >= 0; i--)
	{
		aux->dado = elementos[i];
		aux = aux->prox;
	}
};
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{
	for (int i = 0; i < tamVetor; i++)
	{
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

	No *aux = (No *)malloc(1 * sizeof(No));
	aux = pilha->topo;
	for (int i = 0; i < pilha->qtdeElementos; i++)
	{
		char casting[50];
		sprintf(casting, "%d", aux->dado);
		strcat(str, casting);
		if (i < (pilha->qtdeElementos) - 1)
		{
			strcat(str, ",");
		}

		aux = aux->prox;
	}
	strcat(str, "]");
	return true;
};
