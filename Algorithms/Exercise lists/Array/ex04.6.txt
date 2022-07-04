#include <stdio.h>
int main(void) {
  int vetor1[5];
  int divisores = 0;
  
  for (int i = 0; i < 5; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %d", &vetor1[i]);
    }

  for (int i = 0; i < 5; i++) 
    {
      for(int j = 1;  j<=vetor1[i]; i++){
          if(vetor1[i] %i == 0){
              divisores +=1;
          }
      if(divisores == 2){
          printf("Número %d é primo, na posição %d \n", vetor1[i], i);
      }
  }
  
    }
  
  return 0;
}