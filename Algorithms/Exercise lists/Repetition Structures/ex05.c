#include <stdio.h>

int main(void) {
  char tipo_pagamento = 'z';
  float pagamento = 0, total_prazo = 0, total_vista = 0;

  for(int i = 0; i <= 15; i++){
    printf("Tipo de pagamento (v - à vista; p - à prazo )\n");
    scanf(" %c", &tipo_pagamento);
    while(tipo_pagamento != 'v' && tipo_pagamento != 'p'){
      printf("Valor invalido, digite novamente \n");
    scanf(" %c", &tipo_pagamento);
    }

    printf("Total: \n");
    scanf(" %f", &pagamento);

    if(tipo_pagamento == 'v'){
      total_vista += pagamento;
    }
    else{
      total_prazo += pagamento;
    }

    printf("Total Prazo: R$%'.2f \n", total_prazo);
    printf("Total vista: R$%'.2f \n", total_vista);
  }
  printf("Total Prazo: R$%'.2f \n", total_prazo);
  printf("Total vista: R$%'.2f \n", total_vista);

  return 0;
}