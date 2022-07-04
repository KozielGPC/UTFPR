#include <stdio.h>

int main(void) {
  char cor_olhos = 'z', cor_cabelos = 'z';
  int idade, pessoas5060 = 0, pessoas_naoazul = 0, media_idades_cont = 0;
  float peso = 0, altura = 0, media_idades = 0, pessoas_azul = 0;

  for(int i = 1; i <= 20; i++){
    printf("Pessoa %d \n", i);

    printf("Idade: \n");
    scanf(" %d", &idade);

    printf("Peso em kg: \n");
    scanf(" %f", &peso);

    printf("altura em m: \n");
    scanf(" %f", &altura);

    printf("Cor dos olhos (a - azul; p - preto; v - verde; c - castanho)\n");
    scanf(" %c", &cor_olhos);
    while(cor_olhos != 'v' && cor_olhos != 'a' && cor_olhos != 'p' && cor_olhos != 'c'){
      printf("Valor invalido, digite novamente \n");
      scanf(" %c", &cor_olhos);
    }

    printf("Cor dos cabelos (p - preto; l - louro; r - ruivo)\n");
    scanf(" %c", &cor_cabelos);
    while(cor_cabelos != 'l' && cor_cabelos != 'p' && cor_cabelos != 'r'){
      printf("Valor invalido, digite novamente \n");
      scanf(" %c", &cor_cabelos);
    }

    if(idade > 50 && peso < 60){
      pessoas5060 += 1;
    }

    if(altura < 1.50){
      media_idades += idade;
      media_idades_cont += 1;
    }

    if(cor_olhos == 'a'){
      pessoas_azul += 1;
    }

    if(cor_cabelos == 'r' && cor_olhos != 'a'){
      pessoas_naoazul += 1;
    }
  }

  printf("Total de pessoas com idade superior a 50 anos e peso inferior a 60kg: %d \n", pessoas5060);

  media_idades = media_idades / 5;
  printf("Média de idade das pessoas com altura inferior a 1.50m: %'.2f \n", media_idades);

  pessoas_azul = (pessoas_azul/5) * 100;
  printf("Porcentagem de pessoas com olhos azuis: %'.2f \n", pessoas_azul);

  printf("Quantidade de pessoas ruivas que não possuem olhos azuis: %d \n", pessoas_naoazul);
  return 0;
}