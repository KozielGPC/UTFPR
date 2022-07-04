#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

int main()
{
    Pilha *pilha = pilha_criar();
    printf("Tamanho pilha: %d \n", pilha_tamanho(pilha));
    bool vazia = pilha_vazia(pilha);
    if (vazia)
    {
        printf("Está vazia \n");
    }
    else
    {
        printf("Não está vazia \n");
    }

    TipoElemento saida;
    pilha_empilhar(pilha, 10);

    pilha_topo(pilha, &saida);
    printf("Topo da Pilha: %d \n", saida);
    pilha_empilhar(pilha, 20);

    pilha_topo(pilha, &saida);
    printf("Topo da Pilha: %d \n", saida);
    pilha_empilhar(pilha, 30);

    pilha_topo(pilha, &saida);
    printf("Topo da Pilha: %d \n", saida);
    printf("Pilha >> ");
    pilha_imprimir(pilha);

    printf("Tamanho pilha: %d \n", pilha_tamanho(pilha));
    vazia = pilha_vazia(pilha);
    if (vazia)
    {
        printf("Está vazia \n");
    }
    else
    {
        printf("Não está vazia \n");
    }

    int vetor[2] = {1, 2};
    bool empilhaTodos = pilha_empilharTodos(pilha, vetor, 2);
    if (empilhaTodos)
    {
        printf("Vetor Empilhado \n");
    }
    else
    {
        printf("Vetor Não Empilhado \n");
    }

    pilha_topo(pilha, &saida);
    printf("Topo da Pilha: %d \n", saida);
    printf("Pilha >> ");
    pilha_imprimir(pilha);

    pilha_inverter(pilha);
    printf("Pilha invertida >> ");
    pilha_imprimir(pilha);

    pilha_empilhar(pilha, 50);

    pilha_topo(pilha, &saida);
    printf("Topo da Pilha: %d \n", saida);
    printf("Pilha >> ");
    pilha_imprimir(pilha);

    pilha_desempilhar(pilha, &saida);
    printf("Elemento desempilhado: %d \n", saida);

    printf("Pilha >> ");
    pilha_imprimir(pilha);

    pilha_desempilhar(pilha, &saida);
    printf("Elemento desempilhado: %d \n", saida);

    printf("Pilha >> ");
    pilha_imprimir(pilha);

    Pilha *pilha2 = pilha_criar();
    pilha2 = pilha_clone(pilha);

    printf("Pilha clonada >> ");
    pilha_imprimir(pilha2);

    int tamanho;
    tamanho = pilha_tamanho(pilha);
    printf("Pilha tamanho: %d \n", tamanho);

    char str[200];
    pilha_toString(pilha, str);
    printf("Pilha toString: %s \n", str);

    pilha_destruir(&pilha);
}
