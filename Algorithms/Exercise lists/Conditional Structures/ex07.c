#include <stdio.h>

int main() {
  float media, nota1, nota2;

  printf("Nota 1: \n");
  scanf("%f", &nota1);

  printf("Nota 2: \n");
  scanf("%f", &nota2);


  media = (float)(nota1 + nota2 )/2;
  
  if (media < 40){
    printf("Conceito: E \n");
    printf("Reprovado \n");
    printf("Média: %'.2f", media);
  }
  else if(media < 60 ){
    printf("Conceito: D \n");
    printf("Reprovado \n");
    printf("Média: %'.2f", media);
  }
  else if(media < 75 ){
    printf("Conceito: C \n");
    printf("Aprovado \n");
    printf("Média: %'.2f", media);
  }
  else if(media < 90 ){
    printf("Conceito: B \n");
    printf("Aprovado \n");
    printf("Média: %'.2f", media);
  }
  else{
    printf("Conceito: A \n");
    printf("Aprovado \n");
    printf("Média: %'.2f", media);
  }
  return 0;
}