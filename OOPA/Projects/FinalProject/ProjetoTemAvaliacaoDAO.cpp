#pragma once

#include "ProjetoTemAvaliacaoDAO.hpp"
#include <string>
#include <iostream>

using namespace std;

bool ProjetoTemAvaliacaoDAO::criar(ProjetoTemAvaliacao *avaliacao)
{
    int id = this->tamanho;
    if (id == 10)
        return false;
    avaliacao->setId(id);
    avaliacoes[id] = *avaliacao;
    return true;
};

ProjetoTemAvaliacao *ProjetoTemAvaliacaoDAO::buscar(int id)
{
    for (int i = 0; i <= this->tamanho; i++)
    {
        if (this->avaliacoes[i].getId() == id)
        {
            return &this->avaliacoes[i];
        }
    }

    return NULL;
};

void ProjetoTemAvaliacaoDAO::imprimirAvaliacao(int id)
{
    ProjetoTemAvaliacao avaliacao;
    for (int i = 0; i <= this->tamanho; i++)
    {
        if (this->avaliacoes[i].getId() == id)
        {
            avaliacao = this->avaliacoes[i];
        }
    }
    string status;
    switch (avaliacao.getAvaliacao())
    {
    case APROVADO:
        status = "Aprovado";
        break;
    case REPROVADO:
        status = "Reprovado";
        break;
    case PENDENTE:
        status = "Pendente";
        break;
    }
    cout << "Status do Projeto: " + status << endl;
};