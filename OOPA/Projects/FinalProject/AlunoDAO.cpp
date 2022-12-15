#pragma once

#include "AlunoDAO.hpp"
#include <string>
#include <iostream>

using namespace std;

bool AlunoDAO::criar(Aluno *aluno)
{
    int id = this->tamanho;
    if (id == 10)
        return false;
    aluno->setRa(id);
    alunos[id] = *aluno;
    return true;
};

Aluno *AlunoDAO::buscar(int id)
{
    for (int i = 0; i <= this->tamanho; i++)
    {
        if (this->alunos[i].getRa() == id)
        {
            return &this->alunos[i];
        }
    }

    return NULL;
};