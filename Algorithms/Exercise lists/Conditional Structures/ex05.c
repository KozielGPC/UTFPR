#include <stdio.h>

int main() {
  double preco_fabrica, preco_final;

  printf("Preço de fábrica: \n");
  scanf("%lf", &preco_fabrica);

  if(preco_fabrica <= 12000){
    preco_final = preco_fabrica + preco_fabrica*0.05;
  }
  else if(preco_fabrica <= 25000){
    preco_final = preco_fabrica + preco_fabrica*0.25;
  }
  else{
    preco_final = preco_fabrica + preco_fabrica*0.35;
  }

  printf("Preço final: R$%'.2lf", preco_final);
  return 0;
}