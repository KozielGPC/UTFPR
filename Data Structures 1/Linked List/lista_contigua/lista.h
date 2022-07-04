#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int TipoElemento;

/**************************************
 * DADOS
 **************************************/
typedef struct lista Lista;

/**************************************
 * PROTÓTIPOS
 **************************************/
Lista *lista_criar();
void lista_destruir(Lista **endLista);
bool lista_anexar(Lista *l, TipoElemento elemento);
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao);
bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);
bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento);
bool lista_vazia(Lista *l);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco);
bool lista_contem(Lista *l, TipoElemento elemento);
int lista_tamanho(Lista *l);
bool lista_toString(Lista *l, char *str);
void lista_imprimir(Lista *l);

#endif