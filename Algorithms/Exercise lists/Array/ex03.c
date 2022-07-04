#include <stdio.h>
int main(void) {
  int vetor[5];
  int menorNumero, maiorNumero, posicaoMaior, posicaoMenor;

  
  for (int i = 0; i < 25; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %d", &vetor[i]);
    }
  menorNumero = vetor[0];
  maiorNumero = vetor[0];
  posicaoMaior = 0;
  posicaoMenor = 0;
  for(int i = 0; i < 25; i++){
      if(vetor[i] < menorNumero){
        menorNumero = vetor[i];
        posicaoMenor = i;
      } 
      if(vetor[i] > maiorNumero){
        maiorNumero = vetor[i];
        posicaoMaior = i;
      }
  }

  printf ("Posicao Menor: %d\n", posicaoMenor);
  printf ("Posicao Maior: %d\n", posicaoMaior);
  

  return 0;
}