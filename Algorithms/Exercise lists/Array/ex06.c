#include <stdio.h>
int main(void) {
  int vetor1[10];
  int n, quantidade = 0;
  
  for (int i = 0; i < 10; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %d", &vetor1[i]);
    }

  printf ("Numero a ser analisado: ");
  scanf(" %d", &n);
  for (int i = 0; i < 10; i++) 
    {
      if(vetor1[i] == n){
          quantidade += 1;
      }
    }
  

  printf ("Quantidade: %d\n", quantidade);
  return 0;
}