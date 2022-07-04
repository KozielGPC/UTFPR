#include <stdio.h>

int main() {
  int idade1, idade2, idade3;
  float media;

  printf("Idade aluno 1: \n");
  scanf("%d", &idade1);

  printf("Idade aluno 2: \n");
  scanf("%d", &idade2);

  printf("Idade aluno 3: \n");
  scanf("%d", &idade3);

  media = (float)(idade1 + idade2 + idade3 )/3;
  
  if (media <= 25){
    printf("Turma jovem \n");
  }
  else if(media <= 40){
    printf("Turma adulta \n");
  }
  else{
    printf("Turma avançada \n");
  }
  return 0;
}