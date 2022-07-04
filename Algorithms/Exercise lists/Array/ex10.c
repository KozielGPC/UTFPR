#include <stdio.h>
int main(void) {
  int vetor1[30];
  int vetor2[30];
  int maiorNumero;

  
  for (int i = 0; i < 30; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %d", &vetor1[i]);
    }
  maiorNumero = vetor1[0];
  for(int i = 0; i < 30; i++){
      if(vetor1[i] > maiorNumero){
        maiorNumero = vetor1[i];
      }
  }

  for (int i = 0; i < 30; i++) 
    {
      vetor2[i] = vetor1[i] * maiorNumero;
    }
  
  printf ("Maior numero: %d\n", maiorNumero);

  printf ("Vetor 2: \n");
  for (int i = 0; i < 30; i++) 
    {
      printf ("Numero %d: %d\n", i + 1, vetor2[i]);
    }
  return 0;
}