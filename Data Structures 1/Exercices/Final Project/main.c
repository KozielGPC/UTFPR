#include <stdio.h>
#include <stdbool.h>
#include "disco.h"

int main()
{
    Disco *disco = disco_cria("disco", 150000000000);

    // imprimeSetoresLivres(disco);

    bool result = disco_grava(disco, "./arquivos/parabensJOAO.png");
    if (!result)
    {
        printf("Deu erro");
    }

    result = disco_grava(disco, "./arquivos/parabens.jpeg");
    if (!result)
    {
        printf("Deu erro");
    }

    // disco_lista(disco);
    // imprimeSetoresLivres(disco);

    // result = disco_remove(disco, "./arquivos/parabens.jpeg");

    // if (!result)
    // {
    //     printf("Deu erro no remove \n");
    // }

    // disco_lista(disco);
    // imprimeSetoresLivres(disco);
}
