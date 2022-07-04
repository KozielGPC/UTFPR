#include <stdio.h>

int main() {
  char combustivel;
  float litros, total;

  printf("Combustivel (a = alcool, g = gasolina: \n");
  scanf("%c", &combustivel);
  
  printf("Litros: \n");
  scanf("%f", &litros);

  switch(combustivel){
    case 'a':
      if(litros <= 40){
        total = 3*litros - 3*litros*0.04;
        printf("Total a ser pago: R$%'.2f", total);
        break; 
      }
      else{
        total = 3*litros - 3*litros*0.06;
        printf("Total a ser pago: R$%'.2f", total);
        break; 
      }
    case 'g':
      if(litros <= 40){
        total = 4.5*litros - 4.5*litros*0.03;
        printf("Total a ser pago: R$%'.2f", total);
        break; 
      }
      else{
        total = 4.5*litros - 4.5*litros*0.05;
        printf("Total a ser pago: R$%'.2f", total);
        break; 
      }
    default:
      printf("Valor invalido \n");
      break;
  }
  return 0;
}