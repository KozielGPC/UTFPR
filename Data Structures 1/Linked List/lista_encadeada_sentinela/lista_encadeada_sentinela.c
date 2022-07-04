#include "lista.h"
#include <string.h>

/***********************************************
 * ESPECIFICAÇÃO DOS DADOS
 ************************************************/

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct
{
    No *sentinela;
    int qtde;
} Lista;

/***********************************************
 * FUNÇÕES AUXILIARES
 ************************************************/
No *criarNo(TipoElemento elemento)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = elemento;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

No *criarNo(TipoElemento elemento)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = elemento;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

No *procuraNo(Lista *l, int posicao)
{
    No *aux = l->sentinela;
    for (int i = 0; i <= posicao; i++)
        aux = aux->prox;
    return aux;
}

void inserirEsquerda(No *referencia, No *novo)
{
    novo->prox = referencia;
    novo->ant = referencia->ant;
    referencia->ant->prox = novo;
    referencia->ant = novo;
}

void inserirDireita(No *referencia, No *novo)
{
    novo->prox = referencia->prox;
    novo->ant = referencia;
    referencia->prox->ant = novo;
    referencia->prox = novo;
}

/***********************************************
 * IMPLEMENTAÇÃO
 ************************************************/

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    No *sentinela = (No *)malloc(sizeof(No));
    sentinela->prox = sentinela;
    sentinela->ant = sentinela;
    nova->sentinela = sentinela;
    nova->qtde = 0;
    return nova;
}

void lista_destruir(Lista **endLista)
{
    Lista *lista = *endLista;
    No *aux = lista->sentinela;
    No *temp;
    for (int i = 0; i < lista->qtde; i++)
    {
        temp = aux;
        free(temp);
        aux = aux->prox;
    }
    free(lista);
}
void lista_imprimir(Lista *l)
{
    printf("[");
    No *aux = l->sentinela->prox;
    while (aux != l->sentinela)
    {
        printf("%d", aux->dado);

        if (aux->prox != l->sentinela)
            printf(",");
        aux = aux->prox;
    }
    printf("]\n");
};

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    if (elemento == -1)
        return false;
    int posicao = l->qtde;
    No *novo = criarNo(elemento);
    No *aux = procuraNo(l, posicao - 1);
    inserirDireita(aux, novo);
    l->qtde++;
    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    if (l == NULL)
        return false;
    if (posicao > l->qtde || posicao < 0)
        return false;
    No *novo = criarNo(elemento);
    No *aux = procuraNo(l, posicao - 1);
    inserirDireita(aux, novo);

    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{

    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    No *removido = procuraNo(l, posicao);
    *endereco = removido->dado;

    No *anterior = removido->ant;
    No *prox = removido->prox;

    prox->ant = anterior;
    anterior->prox = prox;

    free(removido);
    l->qtde--;
    return true;
}
int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
        return -1;
    No *aux = l->sentinela;
    No *referencia;
    int posicao = -1;
    for (int i = 0; i < l->qtde; i++)
    {
        if (aux->dado == elemento)
        {
            referencia = aux;
            posicao = i;
        }
        aux = aux->prox;
    }

    No *anterior = referencia->ant;
    No *prox = referencia->prox;
    prox->ant = anterior;
    anterior->prox = prox;

    free(aux);
    l->qtde--;

    return posicao;
}
bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    if (l == NULL)
        return false;
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    No *aux = procuraNo(l, posicao);
    aux->dado = novoElemento;
    return true;
};
bool lista_vazia(Lista *l)
{
    if (l == NULL)
        return false;
    return l->qtde == 0;
};
int lista_posicao(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
        return -1;
    No *aux = l->sentinela;
    for (int i = 0; i < l->qtde; i++)
    {
        aux = aux->prox;
        if (aux->dado == elemento)
        {
            return i;
        }
    }
    return -1;
};
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    if (l == NULL)
        return false;

    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    No *aux = procuraNo(l, posicao);
    *endereco = aux->dado;
    return true;
};
bool lista_contem(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
        return false;
    No *aux = l->sentinela->prox;
    bool existe = false;
    while (aux != l->sentinela || existe != true)
    {
        if (aux->dado == elemento)
        {
            existe = true;
        }
        aux = aux->prox;
    }
    return existe;
};
int lista_tamanho(Lista *l)
{
    if (l == NULL)
        return -1;
    return l->qtde;
};

bool lista_toString(Lista *l, char *str)
{
    if (l == NULL)
        return false;
    str[0] = '\0';
    strcat(str, "[");

    No *aux = l->sentinela->prox;
    while (aux != l->sentinela)
    {
        char elemento[100];
        sprintf(elemento, "%d", aux->dado); // convertendo o aux->dado em uma string
        strcat(str, elemento);

        if (aux->prox != l->sentinela)
            strcat(str, ",");
        aux = aux->prox;
    }

    strcat(str, "]");
    return true;
}