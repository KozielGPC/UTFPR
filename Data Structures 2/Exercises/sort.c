#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int pmin(int* v, int indice, int tamanho) { // Retornar posicao do maior valor
    int menor = indice;
    for(int i = indice + 1; i < tamanho; i++) {
        if(v[i] < v[menor]) {
            menor = i;
        }
    } return menor;
}

int * VetorAleatorio(int n, int seed, int max){
  srand(seed);
  int *v = malloc(sizeof(int) * n);

  for(int i = 0; i < n; i++){
    v[i] = (rand() % max) + 1;
  }

  return v;
}
	
void trocarPosicao(int* v, int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void selectionSort(int* v, int n) {
    int menor;
    for(int i = 0; i < n; i++) {
        menor = pmin(v, i, n);
        trocarPosicao(v, menor, i);
    }
}

void BubbleSort(int *v, int n){
  for(int j = n-1; j >=1; j--){
    for(int i = 0; i <j; i++){
      if(v[i] > v[i+1]){
        trocarPosicao(v, i, i+1);
      }
    }
  }
}

void InsertionSort(int * v, int k){
  int i = k -1;
  int x = v[k];
  while(i >= 0 && v[i] > x){
    v[i + 1] = v[i];
    i--;
  }
  v[i+1] = x;
}

void recursiveInsertionSort(int *v, int n){
  for(int j = 1; j < n; j++){
    InsertionSort(v, j);
  }
}

void merge(int * v, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int * e = malloc(sizeof(int) * (n1 + 1));
  int * d = malloc(sizeof(int) * (n2 + 1));
  int i, j, k;
  for(i = 0; i < n1; i++){
    e[i] = v[p + 1];
  }
  e[n1] = INT_MAX;

  for(j = 0; j < n1; j++){
    d[j]= v[q+1+j];
  }
  d[n2] = INT_MAX;
  i = 0;
  j = 0;

  for(k = p; k < r;k++){
    if(e[i] <= d[j]){
      v[k] = e[i];
      i++;
    }
    else{
      v[k] = d[j];
      j++;
    }
  }

  free(e);
  free(d);
}

void imprimirVetor(int tamanho, int * vetor){
  for(int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", vetor[i]);
    } printf("%d\n", vetor[tamanho - 1]);
}

int main(int argc, char ** argv){
  int n = 10;
  int * v = VetorAleatorio(n, 99, n * 100);
  imprimirVetor(n, v);
  selectionSort(v, n);
  int * v2 = VetorAleatorio(n, 80, n * 100);
  imprimirVetor(n, v2);
  recursiveInsertionSort(v2, n);
  imprimirVetor(n, v2);

  int v3[] = {3,5,6, 0, 4, 7};
  merge(v3,0, 2, 5);
  imprimirVetor(6, v3);
}

// int main() {
//     int tamanho = 6;
//     int v[] = {3,0,2,11,6,5};
//     selectionSort(v, tamanho);
//     for(int i = 0; i < tamanho - 1; i++) {
//         printf("%d, ", v[i]);
//     } printf("%d\n", v[tamanho - 1]);

//     int v2[] = {3,0,2,11,6,5};
//     BubbleSort(v2, 6);


//   return 0;
// }
