#include <stdio.h>

int main(void) {
  int numero, divisores = 0;

  printf("Digite um numero: \n");
  scanf("%d", &numero);
  for(int i = 1; i <= numero; i++){
    if(numero%i == 0){
      divisores +=1;
    }
  }
  if(divisores == 2){
    printf("Número é primo \n");
  }
  else{
    printf("Número não é primo \n");
  }
  return 0;
}