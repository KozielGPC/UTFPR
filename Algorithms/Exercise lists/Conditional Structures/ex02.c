#include <stdio.h>

int main() {
  float n1, n2, n3;

  printf("Primeiro número: ");
  scanf("%f", &n1);

  printf("Segundo número: ");
  scanf("%f", &n2);

  printf("Terceiro número: ");
  scanf("%f", &n3);

  if(n1 >= n2 && n1 >= n3){
    if(n2 >= n3){
      printf("%f >= %f >= %f", n1, n2, n3);
    }
    else {
      printf("%f >= %f >= %f", n1, n3, n2);
    }
  }
  else if(n2 >= n1 && n2 >= n3){
    if(n1 >= n3){
      printf("%f >= %f >= %f", n2, n1, n3);
    }
    else {
      printf("%f >= %f >= %f", n2, n3, n1);
    }
  }
  else{
    if(n1 >= n2){
      printf("%f >= %f >= %f", n3, n1, n2);
    }
    else {
      printf("%f >= %f >= %f", n3, n2, n1);
    }
  }
  return 0;
}