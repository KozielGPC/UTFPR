#include "Projeto.hpp"
#include "ProjetoDAO.hpp"
#include "ProjetoManager.hpp"
#include <iostream>

int main()
{

    ProjetoDAO *projetoDAO = new ProjetoDAO();

    ProjetoManager *projetoManager = new ProjetoManager();
    projetoManager->setProjetoDAO(projetoDAO);

    Projeto *p1 = new Projeto();
    p1->setTitulo("Projeto de teste");
    p1->setCoordenador(1);
    p1->setObjetivoGeral("testar o projeto");
    p1->setModalidade(CULTURAL);
    p1->setOFH(CONTINUA);
    projetoManager->criar(p1);

    projetoManager->imprimirProjeto(p1->getId());

    return 0;
};