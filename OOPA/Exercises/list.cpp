#include <iostream>

class No{
  int dado;
  No * proximo;
  No * anterior;

public:
  No(int dado){
    this->dado = dado;
    this->anterior = NULL;
    this->proximo = NULL;
  }

  void atualizaProximo(No * no);
  void atualizaAnterior(No * no);
  No * getProximo();
  No * getAnterior();
  int getDado();
};

class Lista{
  No * sentinela;
  int tamanho;

public:
  Lista(){
    this->sentinela = new No(-1);
    this->tamanho = 0;
  };

  void imprimir();
  void anexar(int valor);
  void inserir(int valor, int posicao);
  void inserirDireita(No * referencia, No * novo);
  No * procuraNo(int posicao);
  void atualizaTamanho(int valor);
};

int No::getDado(){
  return this->dado;
}

No * Lista::procuraNo(int posicao){
  No * auxiliar = this->sentinela;
  for (int i = 0; i <= posicao; i++){
      auxiliar =  auxiliar->getProximo();
  }
  return auxiliar;
}

No * No::getProximo(){
  return this->proximo;
}

No * No::getAnterior(){
  return this->anterior;
}

void Lista::atualizaTamanho(int valor){
  this->tamanho+=valor;
}

void Lista::inserirDireita(No * referencia, No * novo){
  novo->atualizaProximo(referencia->getProximo());
novo->atualizaAnterior(referencia);
  referencia->getProximo()->atualizaAnterior(novo);
  referencia->atualizaProximo(novo);
  
}

void Lista::imprimir(){
    printf("[");
    No *aux = this->sentinela->getProximo();
    while (aux != this->sentinela)
    {
        printf("%d", aux->getDado());

        if (aux->getProximo() != this->sentinela)
            printf(",");
        aux = aux->getProximo();
    }
    printf("]\n");
};


void Lista::anexar(int valor){
  No * no = new No(valor);
  int posicao = this->tamanho - 1;
  No * ultimo = this->procuraNo(posicao);
  this->inserirDireita(ultimo, no);
  this->atualizaTamanho(1);
}

int main() {
  std::cout << "Hello World!\n";
  Lista * lista = new Lista();
  lista->anexar(3);
  lista->imprimir();
}