#include <stdio.h>
#include <math.h>
#include <string.h>

//exercicio 1
int dobro(int x){
  x = 2*x;
  return x;
}

//exercicio 2
float media(float nota1, float nota2, float nota3){
  float resultado;
  resultado = (nota1 * 3 + nota2 * 4 + nota3 * 3) / 10; 
  return resultado;
}


//exercicio 3
float raiz(int x, int indice) {
  float resultado;
  resultado =  pow(x, 1.0/indice);
  return resultado;
}

//exercicio 4
int fatorial(int x) {
  double resultado = 1;

  if(x <= 0){
    return -1;
  }

  for(int i = 1; i <= x; i++){
    resultado = resultado * i;
  }
  return resultado;
}

// exercicio 5 
int primo(int x) {
  int divisores = 0;
  for(int i = 1; i <= x; i++){
    if(x%i == 0){
      divisores +=1;
    }
  }
  if(divisores == 2){
    return 1;
  }
  else{
    return -1;
  }
}


//exercicio 6
int consoante(char a){
  if(a == 'A' || a == 'a' || a == 'E' || a == 'e' ||
  a == 'I' || a == 'i' || a == 'O' || a == 'o' || 
  a == 'U' || a == 'u' ){
    return 0;
  }
  else if(a == 'b' || a == 'B' || a == 'c' || a == 'C' || a == 'd' || a == 'D' || a == 'f' || a == 'F' || a == 'g' || a == 'G'
  || a == 'h' || a == 'H' || a == 'j' || a == 'J' || a == 'k'
  || a == 'K' || a == 'l' || a == 'L' || a == 'm' || a == 'M'
  || a == 'n' || a == 'N' || a == 'p' || a == 'P' || a == 'q'
  || a == 'Q' || a == 'r' || a == 'R' || a == 's' || a == 'S'
  || a == 't' || a == 'T' || a == 'v' || a == 'V' || a == 'x'
  || a == 'X' || a == 'w' || a == 'W' || a == 'y' || a == 'Y' 
  || a == 'z' || a == 'Z'){
    return 1;
  }
  return -1;
    
}

//exercicio 7

int capicuia(int numero){
    int inicial, inverso = 0, resto = 0;
    inicial = numero;

    while(inicial != 0){
      resto = inicial % 10;
      inverso = inverso * 10 + resto;
      inicial = inicial/10;
    }

    if(numero == inverso){
      return 1;
    }
    else{
      return 0;
    }
}


//exercicio 8

int menor;
int maior;
int posicao;
void ordena(int vetor[], int tamanho){
    
    menor = vetor[0];
    maior = vetor[0];
    int vetor2[tamanho];
    for(int i =0; i < tamanho; i++){
      if(vetor[i] > maior){
        maior = vetor[i];
      }
    }

    for(int j =0; j < tamanho; j++){
      for(int i =0; i < tamanho; i++){
        if(vetor[i] <= menor){
          menor = vetor[i];
          posicao = i;
        }
      }
      vetor2[j] = menor;
      vetor[posicao] = maior;
      menor = maior;
    }

    printf("\n");
    printf("Vetor ordenado: \n");
    for(int i = 0; i <tamanho; i++){
          printf("Posicao %d: %d \n", i, vetor2[i]);
    }
}

//exercicio 9

int temnovetor(int vetor[], int tamanho, int n){
    for(int i =0; i < tamanho; i++){
      if(vetor[i] == n){
        return i;
      }
    }
    return -1;
}


//exercicio 10

void inverte(int vetor[], int tamanho){
    int vetor2[tamanho];
    for(int i =1; i <= tamanho; i++){
      vetor2[tamanho -i] = vetor[i -1]; 
    }

    printf("\n");
    printf("Vetor Original: \n");
    for(int i = 0; i <tamanho; i++){
          printf("Posicao %d: %d \n", i, vetor[i]);
    }

    printf("\n");
    printf("Vetor invertido: \n");
    for(int i = 0; i <tamanho; i++){
        printf("Posicao %d: %d \n", i, vetor2[i]);
    }
}


int x;
float nota1, nota2, nota3;
char a;
int indice;
int resultado;
float resultadoFloat;
int main(void) {
  int questao;
  do{
    printf("Menu \n");
    printf("1 - Dobro \n");
    printf("2 - Media ponderada (3, 4, 3) \n");
    printf("3 - Raiz \n");
    printf("4 - Fatorial \n");
    printf("5 - É primo? \n");
    printf("6 - É consoante ou vogal? \n");
    printf("7 - É capicua? \n");
    printf("8 - Ordena de forma crescente \n");
    printf("9 - Existe no vetor? \n");
    printf("10 - Inverter vetor \n");
    printf("0 - Sair \n");
    printf("Questão: ");
    scanf("%d", &questao);

    switch(questao){
      case 1:
        //exercicio 1
        
        printf("Exercicio 1 \n");
        printf("Digite um número: ");
        scanf("%d", &x);
        resultado = dobro(x);
        printf("Dobro: %d \n", resultado);
        printf("------------------------------ \n \n");
        break;
      
      case 2:
        //exercicio 2
        
        printf("Exercicio 2 \n");
        printf("Nota 1: ");
        scanf("%f", &nota1);
        printf("Nota 2: ");
        scanf("%f", &nota2);
        printf("Nota 3: ");
        scanf("%f", &nota3);
        resultadoFloat = media(nota1, nota2, nota3);
        printf("Media ponderada: %.2f \n", resultadoFloat);
        printf("------------------------------ \n \n");
        break;
      

      case 3: 
        //exercicio 3
        
        printf("Exercicio 3 \n");
        printf("Digite um número: ");
        scanf("%d", &x);
        printf("Indice da raiz: ");
        scanf("%d", &indice);
        resultadoFloat = raiz(x, indice);
        if(resultadoFloat == -1){
          printf("Raiz indisponivel \n");
        }
        else{
          printf("Raiz: %.2f \n", resultadoFloat);
        }
        printf("------------------------------ \n \n");
        break;

      case 4:
        //exercicio 4

        printf("Exercicio 4 \n");
        printf("Digite um número: ");
        scanf("%d", &x);
        resultado = fatorial(x);
        if(resultado == -1){
          printf("Fatorial indisponivel \n");
        }
        else{
          printf("Fatorial: %d \n", resultado);
        }
        printf("------------------------------ \n \n");
        break;

      case 5:
        //exercicio 5
        printf("Exercicio 5 \n");
        printf("Digite um número: ");
        scanf("%d", &x);
        resultado = primo(x);
        if(resultado == 1){
          printf("Número é primo! \n");
        }
        else{
          printf("Número não é primo! \n");
        }
        printf("------------------------------ \n \n");
        break;
      
      case 6:{
        //exercicio 6
        printf("Exercicio 6 \n");
        printf("Digite um caractere: ");
        scanf(" %c", &a);
        resultado = consoante(a);
        if(resultado == 1){
          printf("É consoante! \n");
        }
        else if(resultado == 0){
          printf("É vogal! \n");
        }
        else{
          printf("Não é nenhum dos dois! \n");
        }
        printf("------------------------------ \n \n");
        break;
        }

      case 7:{
        //exercicio 7
        printf("Exercicio 7 \n");
        printf("Digite um numero: ");
        scanf(" %d", &x);
        resultado = capicuia(x);
        if(resultado == 1){
          printf("É capicua \n");
        }
        else{
          printf("Não é capicua \n");
        }
        printf("------------------------------ \n \n");
        break;
      }

      case 8:{
        //exercicio 8
        printf("Exercicio 8 \n");
        printf("Tamanho do Vetor: ");        
        scanf("%d", &x);
        int vetor1[x];
        int vetorResultado[x];
        printf("Vetor: \n");
        for(int i = 0; i <x; i++){
          printf("Posicao %d: ", i);
          scanf("%d", &vetor1[i]);
        }
        ordena(vetor1, x);

        printf("------------------------------ \n \n");
        break;
      }

      case 9:{
        //exercicio 9
        printf("Exercicio 9 \n");
        printf("Tamanho do Vetor: ");        
        scanf("%d", &x);
        int vetor[x];
        printf("Vetor: \n");
        for(int i = 0; i <x; i++){
          printf("Posicao %d: ", i);
          scanf("%d", &vetor[i]);
        }
        int n;
        printf("Numero: ");        
        scanf("%d", &n);
        resultado = temnovetor(vetor, x, n);

        if(resultado == -1){
          printf("Numero nao existe no vetor \n");
        }
        else{
          printf("Posicao do numero no vetor: %d \n", resultado);
        }
        printf("------------------------------ \n \n");
        break;
      }

      case 10:{
        //exercicio 10
        printf("Exercicio 10 \n");
        printf("Tamanho do Vetor: ");        
        scanf("%d", &x);
        int vetor10[x];
        printf("Vetor: \n");
        for(int i = 0; i <x; i++){
          printf("Posicao %d: ", i);
          scanf("%d", &vetor10[i]);
        }
        inverte(vetor10, x);

        printf("------------------------------ \n \n");
        break;
      }
    }
    
    }while(questao != 0);  

  printf("Saiu! \n");
  return 0;
}