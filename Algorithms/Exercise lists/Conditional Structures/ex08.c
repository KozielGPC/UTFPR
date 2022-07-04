#include <stdio.h>

int main() {
  int idade;

  printf("Idade: \n");
  scanf("%d", &idade);
  
  if (5 <= idade && idade <= 7){
    printf("Infantil \n");
  }
  else if(idade <= 10 ){
    printf("Juvenil \n");
  }
  else if(idade <= 15 ){
    printf("Adolescente \n");
  }
  else if(idade <= 30 ){
    printf("Adulto \n");
  }
  else{
    printf("Sênior \n");
  }
  return 0;
}