#pragma once
#include <string>
#include "Aluno.hpp"

using namespace std;

int Aluno::getRa()
{
    return this->ra;
};
string Aluno::getNome()
{
    return this->nome;
};
int Aluno::getPeriodo()
{
    return this->periodo;
};
string Aluno::getCurso()
{
    return this->curso;
};
STATUS Aluno::getStatus()
{
    return this->status;
};

void Aluno::setRa(int ra)
{
    this->ra = ra;
};
void Aluno::setPeriodo(int periodo)
{
    this->periodo = periodo;
};
void Aluno::setNome(string nome)
{
    this->nome = nome;
};
void Aluno::setCurso(string curso)
{
    this->curso = curso;
};
void Aluno::setStatus(STATUS status)
{
    this->status = status;
};