#include <stdio.h>

int main(void) {
  int n;
  double resultado = 1;

  printf("Digite o valor de n: ");
  scanf("%d", &n);

  if(n == 0){
    printf("O fatorial de 0 é 1 \n");
  }

  for(int i = 1; i <= n; i++){
    resultado = resultado * i;
  }
  printf("O fatorial de %d = %'.lf \n", n, resultado);
  return 0;
}