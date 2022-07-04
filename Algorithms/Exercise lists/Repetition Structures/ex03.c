#include <stdio.h>

int main(void) {
  int resultado;

  for(int i = 1; i <= 10; i++){
    printf("Tabuada do %d \n", i);
    for(int j = 1; j <= 10; j++){
        resultado = i * j;
        printf("%d x %d = %d \n", i, j, resultado);
  }
  }
  return 0;
}