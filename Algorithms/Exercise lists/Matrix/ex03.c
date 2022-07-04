#include <stdio.h>

#define L 10
#define C 3
int main(void) {
  int vetor1[L];
  int matriz1[L][C];
  int menor;
  for(int i = 0; i < L; i++){
      printf("Vetor - Posição %d: ", i);
      scanf("%d", &vetor1[i]);
  }
  menor = vetor1[0];

  for(int i = 0; i < L; i++){
    if(vetor1[i] < menor){
      menor = vetor1[i];
    }
  }



  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      if(j == 0){
        matriz1[i][j] = vetor1[i] * 5;
      }
      if(j == 1){
        matriz1[i][j] = vetor1[i] * vetor1[i];
      } 
      if(j == 2){
        matriz1[i][j] = vetor1[i] * menor;
      } 
    }
  }
  printf("\n");
  printf("Matriz resultado: \n");
  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("%d           ", matriz1[i][j]);
    }
    printf("\n");
  }
  return 0;
}