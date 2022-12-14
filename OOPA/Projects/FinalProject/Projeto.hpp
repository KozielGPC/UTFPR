#pragma once
#include <string>
#include <ctime>

using namespace std;

enum Modalidade
{
    ESPORTIVO,
    CULTURAL
};

// Opcao Fluxo Homologacao
enum OFH
{
    CONTINUA
};

class Projeto
{
private:
    int id;
    // std::string coordenador_de_atividade;
    string titulo;
    Modalidade modalidade;
    OFH ofh;
    // std::time_t data_inicio;
    // std::time_t data_fim;
    string objetivo_geral;
    // std::string area;
    // std::string objetivos_desenvolvimento_sustentavel;
    // int qtd_pessoas_diretamente_atendidas;
    // int qtd_pessoas_indiretamente_atendidas;
    // bool restrito_ao_publico_participante;
    // std::string parceiros;
    // std::string contrapartida;
    // std::string introducao;
    // std::string objetivos_especificos;
    // std::string justificativa;
    // std::string metodos_e_procedimentos;
    // bool gera_produto;
    // std::string resultados_e_produtos_esperados;
    // std::string referencias_bibliograficas;
public:
    int getId();
    string getTitulo();
    Modalidade getModalidade();
    OFH getOFH();
    string getObjetivoGeral();

    void setId(int);
    void setTitulo(string);
    void setModalidade(Modalidade);
    void setOFH(OFH);
    void setObjetivoGeral(string);
};