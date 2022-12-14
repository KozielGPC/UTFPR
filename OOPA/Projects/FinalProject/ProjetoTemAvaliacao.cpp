#pragma once
#include <string>
#include "ProjetoTemAvaliacao.hpp"

using namespace std;

int ProjetoTemAvaliacao::getId()
{
    return this->id;
};

int ProjetoTemAvaliacao::getIdAvaliador()
{
    return this->id_avaliador;
};

int ProjetoTemAvaliacao::getIdProjeto()
{
    return this->id_projeto;
};
string ProjetoTemAvaliacao::getMotivo()
{
    return this->motivo != NULL ? *this->motivo : "";
};

void ProjetoTemAvaliacao::setId(int id)
{
    this->id = id;
};

void ProjetoTemAvaliacao::setAvaliacao(STATUS status)
{
    this->avaliacao = status;
};

void ProjetoTemAvaliacao::setMotivo(string motivo)
{
    *this->motivo = motivo;
};