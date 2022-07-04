#include <stdio.h>

int main(void) {
  int n, termo1 = 0, termo2 = 1, termo3 = 0;

  printf("Quantidade de termos: ");
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    if(i == 1){
      printf("Termo %d: %d \n", i, termo2);
    }
    else{
    termo3 = termo1 + termo2;
    termo1 = termo2;
    termo2 = termo3;
    printf("Termo %d: %d \n", i, termo3);
    }
  }

  return 0;
}