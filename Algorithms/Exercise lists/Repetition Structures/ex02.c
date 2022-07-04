#include <stdio.h>

int main() {
  int n;
  float soma;
  printf("Digite um numero: \n");
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    soma += (float)1/i;
  }
  printf("Soma = %f", soma);
  return 0;
}