#include <stdio.h>

int main(void) {
  int vetor1 [5];
  int vetor2[5];
  int vetor3[10];
  int menorNumero;
  int vetor3Posicao = 0;
  int total1 = 0;
  int total2 = 0;

  printf ("digite 5 numeros para o primeiro vetor\n");
  for (int i = 0; i < 5; i++) 
    {
       scanf("%d", &vetor1[i]);
    }


  printf ("digite 5 numeros para o segundo vetor\n");
  for (int i = 0; i < 5; i++) 
    {
       scanf("%d", &vetor2[i]);
    }

  menorNumero = vetor1[0];
  for(int i = 1; i < 5; i++){
    if(vetor1[i] <menorNumero){
      menorNumero = vetor1[i];
    }
  }

  for(int i = 0; i < 5; i++){
    if(vetor2[i] < menorNumero){
      menorNumero = vetor2[i];
    }
  }

  while(total1 < 5 && total2 <5)
    while (vetor1[total1] == menorNumero){
        vetor3[vetor3Posicao] = vetor1[total1];
        total1 += 1;
        printf("Menor numero 1: %d \n", menorNumero);
        printf("Vetor 3: \n");
        for(int i = 0; i < 10; i++){
           printf("Vetor na posicao %d = %d \n", i, vetor3[i]);
      }
      }
    while (vetor2[total2] == menorNumero){
        vetor3[vetor3Posicao] = vetor2[total2];
        total2 += 1;
        printf("Menor numero 2: %d \n", menorNumero);
    }

    if(total1 < total2){
      menorNumero = vetor1[total1];
    }
    else{
      menorNumero = vetor2[total2];
    }
  

  printf("Vetor 3: \n");
  for(int i = 0; i < 10; i++){
    printf("Vetor na posicao %d = %d \n", i, vetor3[i]);
  }
  return 0;
}