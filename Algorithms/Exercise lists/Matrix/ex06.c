#include <stdio.h>

int main(void) {
  int matriz[3][5];
  int quantidade = 0;

  for(int i = 0; i < 3; i++){
    for(int j= 0; j < 5; j++){
      printf("Posição %d - %d:", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j= 0; j < 5; j++){
      if(15 <= matriz[i][j] && matriz[i][j] <= 20){
        quantidade+=1;
      }
    }
  }

  printf("Quantidade de números entre 15 e 20: %d \n", quantidade);
  return 0;
}