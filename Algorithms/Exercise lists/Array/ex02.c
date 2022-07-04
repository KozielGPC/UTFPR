#include <stdio.h>
#include <math.h>
int main(void) {
  int vetor1[5];
  int vetor2[5];

  printf ("digite 5 numeros para o primeiro vetor\n");
  for (int i = 0; i < 30; i++) 
    {
       scanf(" %d", &vetor1[i]);
    }

  for(int i = 0; i < 30; i++){
      vetor2[i] = pow(vetor1[i], 3); 
  }

  printf ("Vetor final: \n");
  for(int i = 0; i < 5; i++){
      printf ("%d\n", vetor2[i]); 
  }

  return 0;
}