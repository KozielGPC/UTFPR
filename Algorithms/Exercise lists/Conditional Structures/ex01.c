#include <stdio.h>

int main() {
  float n1, n2;

  printf("Primeiro número: ");
  scanf("%f", &n1);

  printf("Segundo número: ");
  scanf("%f", &n2);

  if(n1 > n2){
    printf("Maior número = %f", n1);
  }
  else if(n2 > n1){
    printf("Maior número = %f", n2);
  }
  else{
    printf("Os números são iguais!");
  }
  return 0;
}