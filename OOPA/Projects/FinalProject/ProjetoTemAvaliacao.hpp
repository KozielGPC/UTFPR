#pragma once
#include <string>
#include "Projeto.hpp"

using namespace std;

class ProjetoTemAvaliacao
{
private:
    int id;
    int id_avaliador;
    int id_projeto;
    STATUS avaliacao;
    string *motivo = NULL;

public:
    int getId();
    int getIdAvaliador();
    int getIdProjeto();
    STATUS getAvaliacao();
    string getMotivo();

    void setId(int);
    void setIdAvaliador(int);
    void setIdProjeto(int);
    void setAvaliacao(STATUS);
    void setMotivo(string);
};