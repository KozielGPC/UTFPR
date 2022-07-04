#include <stdio.h>

#define L 6
#define C 4
int main(void) {
  int matriz1[L][C];
  int maior;


  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Posição %d - %d: ", i, j );
      scanf("%d", &matriz1[i][j]);
    }
  }

  printf("Matriz original: \n");

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("%d \t", matriz1[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < L; i++){
    maior = matriz1[i][0];
    printf("Maior inicial > %d \n", maior);
    for(int j= 0; j < C; j++){
      if(matriz1[i][j] > maior){
        maior = matriz1[i][j];
        printf("Maior do meio > %d \n", maior);
      }

    }

    for(int j= 0; j < C; j++){
        matriz1[i][j] = matriz1[i][j] * maior;
    }

  }


  printf("Matriz multiplicada: \n");

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("%d \t", matriz1[i][j]);
    }
    printf("\n");
  }



  return 0;
}