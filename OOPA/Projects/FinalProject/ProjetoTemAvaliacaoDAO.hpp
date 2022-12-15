#pragma once
#include <string>
#include "ProjetoTemAvaliacao.hpp"

using namespace std;

class ProjetoTemAvaliacaoDAO
{
private:
    ProjetoTemAvaliacao avaliacoes[10];
    int tamanho = 0;

public:
    bool criar(ProjetoTemAvaliacao *);
    ProjetoTemAvaliacao *buscar(int id);
    void imprimirAvaliacao(int id);
};