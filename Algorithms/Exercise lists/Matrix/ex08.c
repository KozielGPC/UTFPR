#include <stdio.h>

#define L 12
#define C 4
int main(void) {
  float matriz[L][C];
  float total = 0, total_mes = 0, total_semana = 0;

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Posição %d - %d:", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      total += matriz[i][j];
      total_mes += matriz[i][j];
    }

    printf("O total do mês %d foi de R$%'.2f \n", i+ 1, total_mes);
    total_mes = 0;
  }

  for(int i = 0; i < C; i++){
    for(int j= 0; j < L; j++){
      total_semana += matriz[j][i];
    }

    printf("O total da semana %d foi de R$%'.2f \n", i+ 1, total_semana);
    total_semana = 0;
  }

  printf("O total anual foi de R$%'.2f \n", total);
  return 0;
}