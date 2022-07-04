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

struct lista
{
    No *inicio;
    No *fim;
    int qtde;
};

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

No *procuraNo(Lista *l, int posicao)
{
    No *aux;
    if (posicao < l->qtde / 2)
    {
        aux = l->inicio;
        for (int i = 0; i < posicao; i++)
            aux = aux->prox;
    }
    else
    {
        aux = l->fim;
        for (int i = l->qtde - 1; i > posicao; i--)
            aux = aux->ant;
    }
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
    novo->ant = referencia;
    novo->prox = referencia->prox;
    referencia->prox->ant = novo;
    referencia->prox = novo;
}

/***********************************************
 * IMPLEMENTAÇÃO
 ************************************************/

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qtde = 0;
    return nova;
}

void lista_destruir(Lista **endLista)
{
    Lista *lista = *endLista;
    No *aux = lista->inicio;
    No *temp;
    for (int i = 0; i < lista->qtde; i++)
    {
        temp = aux;
        free(temp);
        aux = aux->prox;
    }
    free(lista);
}
bool lista_anexar(Lista *l, TipoElemento elemento)
{

    No *novo = criarNo(elemento);

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        novo->ant = l->fim;
        l->fim->prox = novo;
    }

    l->fim = novo;
    l->qtde++;
    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    No *novo = criarNo(elemento);

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else if (posicao == 0)
    {
        novo->prox = l->inicio;
        novo->ant = NULL;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    else if (posicao == l->qtde)
    {
        novo->prox = NULL;
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }
    else
    {

        // No* aux = procuraNo(l, posicao); // procurar a posicao correta
        // inserirEsquerda(aux, novo);
        No *aux = procuraNo(l, posicao - 1); // procurar a posicao correta
        inserirDireita(aux, novo);
    }
    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->inicio;
    No *referencia;
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            referencia = aux;
            *endereco = aux->dado;
        }
        aux = aux->prox;
    }

    No *anterior = referencia->ant;
    No *prox = referencia->prox;
    prox->ant = anterior;
    anterior->prox = prox;
    return true;
}
int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    No *aux = l->inicio;
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

    return posicao;
}
bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    No *aux = l->inicio;
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }

    for (int i = 0; i <= posicao; i++)
    {
        if (i == posicao)
        {
            aux->dado = novoElemento;
        }
        aux = aux->prox;
    }
    return true;
};
bool lista_vazia(Lista *l)
{
    return l->qtde == 0;
};
int lista_posicao(Lista *l, TipoElemento elemento)
{
    No *aux = l->inicio;
    for (int i = 0; i < l->qtde; i++)
    {
        if (aux->dado == elemento)
        {
            return i;
        }
        aux = aux->prox;
    }
    return -1;
};
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    No *aux = l->inicio;
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }

    for (int i = 0; i <= posicao; i++)
    {
        if (i == posicao)
        {
            *endereco = aux->dado;
        }
        aux = aux->prox;
    }
    return true;
};
bool lista_contem(Lista *l, TipoElemento elemento)
{
    No *aux = l->inicio;
    bool existe = false;
    while (aux != NULL || existe != true)
    {
        if (aux->dado == elemento)
        {
            existe == true;
        }
        aux = aux->prox;
    }
    return existe;
};
int lista_tamanho(Lista *l)
{
    return l->qtde;
};

bool lista_toString(Lista *l, char *str)
{

    str[0] = '\0';
    strcat(str, "[");

    No *aux = l->inicio;
    while (aux != NULL)
    {
        char elemento[100];
        sprintf(elemento, "%d", aux->dado); // convertendo o aux->dado em uma string
        strcat(str, elemento);

        if (aux->prox != NULL)
            strcat(str, ",");
        aux = aux->prox;
    }

    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista *l)
{
    printf("[");
    No *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d", aux->dado);

        if (aux->prox != NULL)
            printf(",");
        aux = aux->prox;
    }
};