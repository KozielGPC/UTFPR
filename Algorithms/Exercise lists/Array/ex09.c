#include <stdio.h>
int main(void) {
  float vetor1[50];
  float media;
  int quantidade = 0;
  
  for (int i = 0; i < 50; i++) 
    {
        printf ("Numero %d: ", i + 1);
        scanf(" %f", &vetor1[i]);
        media += vetor1[i];
    }

  media = media/50;

  for(int i = 0; i < 50; i++){
      if(vetor1[i] > media){
        quantidade+=1;
      }
  }

  printf ("Média: %f\n", media);
  printf ("Quantidade de números acima da média: %d\n", quantidade);
  return 0;
}