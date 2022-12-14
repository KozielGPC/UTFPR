#pragma once
#include <string>
#include <ctime>
#include "Projeto.hpp"
#include "ProjetoDAO.hpp"

using namespace std;

class ProjetoManager
{
private:
    ProjetoDAO *projetoDAO;

public:
    bool criar(Projeto *);
    Projeto *buscar(int id);
    void setProjetoDAO(ProjetoDAO *);
};