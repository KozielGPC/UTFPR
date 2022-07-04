#include <stdio.h>

int main(void) {
  int matriz[5][5];
  int maior = matriz[0][0];
  int menor = matriz[0][0];

  for(int i = 0; i < 5; i++){
    for(int j= 0; j < 5; j++){
      printf("Posição %d - %d:", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j= 0; j < 5; j++){
      if(matriz[i][j] > maior){
        maior = matriz[i][j];
      }
      if(matriz[i][j] < menor){
        menor = matriz[i][j];
      }
    }
  }

  printf("Menor número: %d \n", menor);
  printf("Maior número: %d \n", maior);
  return 0;
}