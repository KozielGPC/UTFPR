#pragma once
#include <string>
#include "Projeto.hpp"

using namespace std;

int Projeto::getId()
{
    return this->id;
};

int Projeto::getCoordenador()
{
    return this->id_coordenador_de_atividade;
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

STATUS Projeto::getStatus()
{
    return this->status;
};

void Projeto::setId(int id)
{
    this->id = id;
};
void Projeto::setCoordenador(int id)
{
    this->id_coordenador_de_atividade = id;
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

void Projeto::setStatus(STATUS status)
{
    this->status = status;
};