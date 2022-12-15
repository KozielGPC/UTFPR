#pragma once
#include <string>
#include "Aluno.hpp"

using namespace std;

class AlunoDAO
{
private:
    Aluno alunos[10];
    int tamanho = 0;

public:
    bool criar(Aluno *);
    Aluno *buscar(int id);
};