#pragma once
#include <string>
#include "Projeto.hpp"

using namespace std;

int Projeto::getId()
{
    return this->id;
};

string Projeto::getTitulo()
{
    return this->titulo;
};

Modalidade Projeto::getModalidade()
{
    return this->modalidade;
};

OFH Projeto::getOFH()
{
    return this->ofh;
};

string Projeto::getObjetivoGeral()
{
    return this->objetivo_geral;
};

void Projeto::setId(int id)
{
    this->id = id;
};
void Projeto::setTitulo(string titulo)
{
    this->titulo = titulo;
};

void Projeto::setModalidade(Modalidade modalidade)
{
    this->modalidade = modalidade;
};

void Projeto::setOFH(OFH ofh)
{
    this->ofh = ofh;
};

void Projeto::setObjetivoGeral(string objetivo_geral)
{
    this->objetivo_geral = objetivo_geral;
};