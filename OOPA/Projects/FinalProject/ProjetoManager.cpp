#include "ProjetoDAO.hpp"
#include "ProjetoManager.hpp"

bool ProjetoManager::criar(Projeto *projeto)
{
    return this->projetoDAO->criar(projeto);
};

Projeto *ProjetoManager::buscar(int id)
{
    return this->projetoDAO->buscar(id);
};

void ProjetoManager::setProjetoDAO(ProjetoDAO *projetoDAO)
{
    this->projetoDAO = projetoDAO;
};

void ProjetoManager::imprimirProjeto(int id)
{
    this->imprimirProjeto(id);
};
