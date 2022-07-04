#include <stdio.h>

#define L 4
#define C 4
int main(void) {
  int matriz1[L][C];
  int magica = 1;
  int soma = 0;
  int valormagico = 0;


  for(int i = 0; i < L; i++){
    for(int j= 0; j < C; j++){
      printf("Matriz - Posição %d - %d: ", i, j );
      scanf("%d", &matriz1[i][j]);
    }
  }

  for(int i = 0; i < C; i++){
    for(int j= 0; j < C; j++){
      if(i == j){
        soma += matriz1[i][j];
      }
    }
  }

  valormagico = soma;
  printf("Valor Mágico: %d \n", valormagico);
  soma = 0;

  for(int i = 0; i < C; i++){
    for(int j= 0; j < C; j++){
      if(i + j == C - 1){
        soma += matriz1[i][j];
      }
    }
  }

  if (soma != valormagico){
      magica = 0;
    }
    soma = 0;

  for(int i = 0; i < C; i++){
    for(int j= 0; j < C; j++){
      soma += matriz1[i][j];
    }
    if (soma != valormagico){
      magica = 0;
    }
    soma = 0;
  }

  for(int i = 0; i < C; i++){
    for(int j= 0; j < C; j++){
      soma += matriz1[j][i];
    }
    if (soma != valormagico){
      magica = 0;
    }

    soma = 0;
  }
  if(magica == 0){
    printf("Não é uma matriz quadrado mágico! \n");
  }
  else{
    printf("É uma matriz quadrado mágico! \n");
  }

  return 0;
}