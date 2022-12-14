#pragma once
#include <string>
#include <ctime>
#include "Projeto.hpp"

using namespace std;

class ProjetoDAO
{
private:
    Projeto projetos[10];
    int tamanho = 0;

public:
    bool criar(Projeto *);
    Projeto *buscar(int id);
    void imprimirProjeto(int id);
};