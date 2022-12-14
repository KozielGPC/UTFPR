#pragma once

#include "ProjetoDAO.hpp"
#include <string>
#include <iostream>

using namespace std;

bool ProjetoDAO::criar(Projeto *projeto)
{
    int id = this->tamanho;
    if (id == 10)
        return false;
    projeto->setId(id);
    projetos[id] = *projeto;
    return true;
};

Projeto *ProjetoDAO::buscar(int id)
{
    for (int i = 0; i <= this->tamanho; i++)
    {
        if (this->projetos[i].getId() == id)
        {
            return &this->projetos[i];
        }
    }

    return NULL;
};

void ProjetoDAO::imprimirProjeto(int id)
{
    Projeto projeto;
    for (int i = 0; i <= this->tamanho; i++)
    {
        if (this->projetos[i].getId() == id)
        {
            projeto = this->projetos[i];
        }
    }
    cout << "Projeto: " + projeto.getTitulo() << endl;
};