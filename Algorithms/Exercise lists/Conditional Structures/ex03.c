#include <stdio.h>

int main() {
  float salarioInicial, aumento, salarioFinal;
  int percentual;

  printf("Salário inicial: ");
  scanf("%f", &salarioInicial);

  if (salarioInicial <= 280){
    aumento = salarioInicial * 0.2;
    percentual = 20;
  }
  else if(salarioInicial <= 700){
    aumento = salarioInicial * 0.15;
    percentual = 15;
  }
  else if(salarioInicial <= 1500){
    aumento = salarioInicial * 0.1;
    percentual = 10;
  }
  else{
    aumento = salarioInicial * 0.05;
    percentual = 5;
  }

  salarioFinal = salarioInicial + aumento;
  printf("O salário inicial era de R$%'.2f \n", salarioInicial);
  printf("O aumento foi de R$%'.2f, com um percentual de %d%% \n", aumento, percentual);
  printf("O salário final é de R$%'.2f \n", salarioFinal);
  return 0;
}