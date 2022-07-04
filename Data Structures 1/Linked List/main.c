#include "lista.h"
#include <string.h>

void verifica(char *elemento1, char *elemento2, char *msg)
{
    char resultado[10];
    if (strcmp(elemento1, elemento2) == 0)
    {
        strcpy(resultado, "PASS");
    }
    else
    {
        strcpy(resultado, "FAIL");
    }

    printf("[%s] - %s\n", resultado, msg);
    // [PASS] - Teste anexar
    // [PASS] - Teste inserir
    // [PASS] - Teste remover por posicao
    //  [FAIL] - Teste remover por elemento
}

void teste_anexar()
{
    Lista *l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);

    char str[200];
    lista_toString(l, str);
    verifica(str, "[10,20,30]", "Teste da funcao Anexar");
}

void teste_inserir()
{
    Lista *l = lista_criar();
    lista_inserir(l, 100, 0); // [100]
    lista_inserir(l, 50, 0);  // [50,100]
    lista_inserir(l, 150, 2); // [50,100,150]
    lista_inserir(l, 80, 1);  // [50,80,100,150]

    char str[200];
    lista_toString(l, str);
    verifica(str, "[50,80,100,150]", "Teste inserir");
}

int main()
{

    teste_anexar();
    teste_inserir();
    return 0;
}