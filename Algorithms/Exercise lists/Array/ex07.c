#include <stdio.h>
int main(void) {
  int vetor1[5];
  int vetor2[5];
  int fatorial = 1;
  
  for (int i = 0; i < 5; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %d", &vetor1[i]);
        while(vetor1[i] <0){
            printf ("Fatorial não admite numero negativo, digite outro: ");
            scanf(" %d", &vetor1[i]);
        }
    }

  for (int i = 0; i < 5; i++) 
    {
      for(int j = 1; j <= vetor1[i]; j++){
          fatorial = fatorial * j;
      }
      vetor2[i] = fatorial;
      fatorial = 1;
    }
  

  printf ("Vetor 2: \n");
    for (int i = 0; i < 5; i++) 
    {
        printf ("Numero %d: %d \n", i + 1, vetor2[i]);
    }
  return 0;
}