#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"
#include <stdlib.h>
#include <string.h>

int main()
{
   char *texto = "Teste de string";
    Pilha *pilha = pilha_criar();
    for (int i = 0; i < strlen(texto); i++)
    {
        pilha_empilhar(pilha, texto[i]);
    }
    printf("String normal: ");
    pilha_imprimir(pilha);
    pilha_inverter(pilha);
    printf("String invertida: ");
    pilha_imprimir(pilha);

    char expressao []= "223+*";
    float resultado = resolveExpressao(expressao);
    printf("%f \n", resultado);
}
