#include "lista.h"
#include <string.h>

/***********************************************
 * ESPECIFICAÇÃO DOS DADOS
 ************************************************/
struct lista
{
    TipoElemento *vetor;
    int tam;
    int qtde;
};

/***********************************************
 * FUNÇÕES AUXILIARES
 ************************************************/
TipoElemento *dobraVetor(int tamanho, TipoElemento *vetor)
{
    TipoElemento *vetorNovo = malloc(tamanho * 2 * sizeof(TipoElemento));
    for (int i = 0; i < tamanho; i++)
    {
        vetorNovo[i] = vetor[i];
    }
    return vetorNovo;
}

/***********************************************
 * IMPLEMENTAÇÃO
 ************************************************/

Lista *lista_criar()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    TipoElemento *vetor = (TipoElemento *)malloc(20 * sizeof(TipoElemento));
    nova->vetor = vetor;
    nova->tam = 20;
    nova->qtde = 0;
    return nova;
}

void lista_destruir(Lista **endLista)
{
    Lista *lista = *endLista;
    free(lista->vetor);
    free(lista);
}
bool lista_anexar(Lista *l, TipoElemento elemento)
{
    if (l->qtde + 1 == l->tam)
    {
        l->vetor = dobraVetor(l->tam, l->vetor);
    }
    printf("elemento: %d \n", elemento);
    l->vetor[l->qtde] = elemento;
    l->qtde ++;
    return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    printf("Elemento: %d\n", elemento);
    if (elemento == -1)
    {
        return false;
    }
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    for (int i = posicao; i < l->qtde + 1; i++)
    {
        printf("Antes ---------------");
        lista_imprimir(l);
        printf("i: %d\n", i);
        l->vetor[i + 1] = l->vetor[i];
        printf("i + 1: %d\n", l->vetor[i+ 1]);
        printf("i elemento: %d\n", l->vetor[i]);
        printf("Depois ---------------");
        lista_imprimir(l);
    }
    l->vetor[posicao] = elemento;
    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }
    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            *endereco = l->vetor[i];
            l->vetor[i] = NULL;
        }
    }
    return true;
}
int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    int posicao = -1;
    for (int i = 0; i < l->qtde; i++)
    {
        if (l->vetor[i] == elemento)
        {
            l->vetor[i] = NULL;
            posicao = i;
        }
    }
    return posicao;
}
bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }

    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            l->vetor[i] = novoElemento;
        }
    }
    return true;
};
bool lista_vazia(Lista *l)
{
    return l->qtde == 0;
};
int lista_posicao(Lista *l, TipoElemento elemento)
{
    for (int i = 0; i < l->qtde; i++)
    {
        if (l->vetor[i] == elemento)
        {
            return i;
        }
    }
    return -1;
};
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    if (posicao < 0 || posicao > l->qtde)
    {
        return false;
    }

    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            *endereco = l->vetor[i];
        }
    }
    return true;
};
bool lista_contem(Lista *l, TipoElemento elemento)
{
    bool existe = false;
    for (int i = 0; i < l->qtde; i++)
    {
        if (l->vetor[i] == elemento)
        {
            existe == true;
        }
    }
    return existe;
};
int lista_tamanho(Lista *l)
{
    return l->qtde;
};

bool lista_toString(Lista *l, char *str)
{
    strcat(str, "[");

    printf("quantidade: %d\n", l->qtde);
    for (int i = 0; i < l->qtde; i++)
    {
        char elemento[100];
        sprintf(elemento, "%d", l->vetor[i]); // convertendo o aux->dado em uma string
        strcat(str, elemento);

        if (i != l->qtde - 1)
            strcat(str, ",");
    }

    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista *l)
{
    printf("[");
    for (int i = 0; i < l->qtde; i++)
    {
        printf("%d", l->vetor[i]);

        if (i != l->qtde - 1)
            printf(",");
    }
    printf("]\n");
};