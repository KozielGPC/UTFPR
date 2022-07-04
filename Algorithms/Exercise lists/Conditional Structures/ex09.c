#include <stdio.h>

int main() {
  int codigo;

  printf("Codigo: \n");
  scanf("%d", &codigo);
  
  switch (codigo){
    case 1:
      printf("Sul \n");
      break;
    case 2:
      printf("Norte \n");
      break;
    case 3:
      printf("Sudeste \n");
      break;
    case 4:
      printf("Centro-oeste \n");
      break;
    case 5 ... 6:
      printf("Nordeste \n");
      break;
    case 7 ... 9:
      printf("Sudeste \n");
      break;
    case 10 ... 20:
      printf("Centro-oeste \n");
      break;
    case 21 ... 30:
      printf("Nordeste \n");
      break;
    default:
      printf("Valor invalido \n");
      break;
    

  }
  return 0;
}