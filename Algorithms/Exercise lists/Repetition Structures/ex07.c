#include <stdio.h>

int main(void) {
  int total_ingressos = 120, total_ingressos_max;
  float lucroMaximo = 0, lucroAtual = 0, preco_ingresso_max = 0;

  for(float i = 5; i >= 1; i-=0.5){
    printf("Preço do ingresso: R$%'.2f \n", i);
    printf("Ingressos vendidos: %d \n", total_ingressos);
    lucroAtual = (total_ingressos * i) - 200;
    printf("Lucro obtido: R$%'.2f \n \n", lucroAtual);
    if(lucroAtual > lucroMaximo){
      lucroMaximo = lucroAtual;
      total_ingressos_max = total_ingressos;
      preco_ingresso_max = i;
    }

    total_ingressos += 26;

  }
  printf("----------------------------\n");
  printf("Lucro máximo esperado:  R$%'.2f \n", lucroMaximo);
  printf("Quantidade de ingressos necessários: %d \n", total_ingressos_max);
  printf("preço do ingresso:  R$%'.2f \n", preco_ingresso_max);
  

  
  return 0;
}