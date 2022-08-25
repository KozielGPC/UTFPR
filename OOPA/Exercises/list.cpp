#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class No
{
  int dado;
  No *proximo;
  No *anterior;

public:
  No(int dado)
  {
    this->dado = dado;
    this->anterior = NULL;
    this->proximo = NULL;
  }

  void atualizaProximo(No *no);
  void atualizaAnterior(No *no);
  No *getProximo();
  No *getAnterior();
  int getDado();
};

class Lista
{

  int tamanho;
  No *sentinela;

public:
  Lista()
  {
    this->sentinela = new No(-1);
    this->sentinela->atualizaProximo(this->sentinela);
    this->sentinela->atualizaAnterior(this->sentinela);
    this->tamanho = 0;
  };

  void imprimir();
  void anexar(int valor);
  void inserir(int valor, int posicao);
  void inserirDireita(No *referencia, No *novo);
  No *procuraNo(int posicao);
  void atualizaTamanho(int valor);
  bool vazia();
  int removerElemento(int elemento);
};

// NO ------------------

int No::getDado()
{
  return this->dado;
}

No *No::getProximo()
{
  return this->proximo;
}

No *No::getAnterior()
{
  return this->anterior;
}

void No::atualizaProximo(No *no)
{
  this->proximo = no;
}
void No::atualizaAnterior(No *no)
{
  this->anterior = no;
}

// LISTA ------------------

No *Lista::procuraNo(int posicao)
{
  No *auxiliar = this->sentinela;
  for (int i = 0; i <= posicao; i++)
  {
    auxiliar = auxiliar->getProximo();
  }
  return auxiliar;
}

void Lista::atualizaTamanho(int valor)
{
  this->tamanho += valor;
}

void Lista::inserirDireita(No *referencia, No *novo)
{
  novo->atualizaProximo(referencia->getProximo());
  novo->atualizaAnterior(referencia);
  referencia->getProximo()->atualizaAnterior(novo);
  referencia->atualizaProximo(novo);
}

void Lista::imprimir()
{
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

void Lista::anexar(int valor)
{
  No *no = new No(valor);
  int posicao = this->tamanho - 1;
  No *ultimo = this->procuraNo(posicao);
  this->inserirDireita(ultimo, no);
  this->atualizaTamanho(1);
}

bool Lista::vazia()
{
  bool vazia = this->tamanho == 0;
  if (vazia)
  {
    printf("Lista esta vazia \n");
  }
  else
  {
    printf("Lista não esta vazia \n");
  }
  return vazia;
}

int Lista::removerElemento(int elemento)
{
  No *aux = this->sentinela;
  No *referencia;
  int posicao = -1;
  for (int i = 0; i < this->tamanho; i++)
  {
    if (aux->getDado() == elemento)
    {
      referencia = aux;
      posicao = i;
    }
    aux = aux->getProximo();
  }

  No *anterior = referencia->getAnterior();
  No *prox = referencia->getProximo();
  prox->atualizaAnterior(anterior);
  anterior->atualizaProximo(prox);
  this->atualizaTamanho(-1);
  return posicao;
}
int main()
{
  std::cout << "Hello World!\n";
  Lista *lista = new Lista();
  bool vazia;
  vazia = lista->vazia();

  lista->anexar(3);
  lista->anexar(4);
  lista->anexar(5);
  lista->anexar(6);
  lista->imprimir();

  vazia = lista->vazia();

  int elemento = 5;
  int posicao = lista->removerElemento(elemento);
  printf("elemento %d removido na posicao %d\n", elemento, posicao);

  lista->imprimir();
}
