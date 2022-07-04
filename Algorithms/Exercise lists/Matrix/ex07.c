#include <stdio.h>

#define L 2
#define C 4
int main(void) {
  int matriz1[L][C];
  int quantidade = 0;
  float media = 0;


  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Posição %d - %d: ", i, j );
      scanf("%d", &matriz1[i][j]);
    }
  }

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      if(matriz1[i][j] % 2 == 0){
        quantidade += 1;
        media += matriz1[i][j];
      }
    }
  }

  media = media / quantidade;

  printf("\n");
  printf("Com %d números pares, a média entre eles é de %'.2f: \n", quantidade, media);
  return 0;
}