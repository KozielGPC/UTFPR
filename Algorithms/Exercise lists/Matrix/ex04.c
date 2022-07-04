#include <stdio.h>

#define L 5
#define C 4
int main(void) {
  int matriz1[L][C];
  int matriz2[C][3];
  int matriz3[L][3] = {0};
  int multiplicacao = 0;


  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Matriz 1 - Posição %d - %d: ", i, j );
      scanf("%d", &matriz1[i][j]);
    }
  }

  for(int i = 0; i < C; i++){
    for(int j= 0; j < 3; j++){
      printf("Matriz 2 - Posição %d - %d: ", i, j );
      scanf("%d", &matriz2[i][j]);
    }
  }
  for(int i = 0; i < L; i++){
    for(int j= 0; j < 3; j++){
        for(int k =0; k < C; k++){
          matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
        }
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j= 0; j < 3; j++){
      printf("%d \t",  matriz3[i][j] );
    }
    printf("\n");
  }
  return 0;
}