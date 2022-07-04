#include <stdio.h>

#define L 5
#define C 3
int main(void) {
  int matriz1[L][C];
  int matriz2[L][C];
  int matriz3[L][C];

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Matriz 1: Posição %d - %d: ", i, j);
      scanf("%d", &matriz1[i][j]);
    }
  }

  printf("\n");
  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Matriz 2: Posição %d - %d: ", i, j);
      scanf("%d", &matriz2[i][j]);
    }
  }

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  printf("\n");
  printf("Matriz 3: \n");
  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("%d  ", matriz3[i][j]);
    }
    printf("\n");
  }
  return 0;
}