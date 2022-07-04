#include <stdio.h>

#define L 7
#define C 2
int main(void) {
  int vetor1[L];
  int vetor2[L];
  int matriz1[L][C];

  for(int i = 0; i < L; i++){
      printf("Vetor 1: Posição %d: ", i);
      scanf("%d", &vetor1[i]);
  }

  for(int i = 0; i < L; i++){
      printf("Vetor 2: Posição %d: ", i);
      scanf("%d", &vetor2[i]);
  }

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      if(j == 0){
        matriz1[i][j] = vetor1[i];
      }
      if(j == 1){
        matriz1[i][j] = vetor2[i];
      } 
    }
  }
  printf("\n");
  printf("Matriz resultado: \n");
  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("%d  ", matriz1[i][j]);
    }
    printf("\n");
  }
  return 0;
}