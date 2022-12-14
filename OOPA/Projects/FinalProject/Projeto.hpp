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

enum STATUS
{
    APROVADO,
    REPROVADO,
    PENDENTE
};

class Projeto
{
private:
    int id;
    string titulo;
    int id_coordenador_de_atividade;
    Modalidade modalidade;
    OFH ofh;
    STATUS status = PENDENTE;
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
    int getCoordenador();
    string getTitulo();
    Modalidade getModalidade();
    OFH getOFH();
    string getObjetivoGeral();
    STATUS getStatus();

    void setId(int);
    void setCoordenador(int);
    void setTitulo(string);
    void setModalidade(Modalidade);
    void setOFH(OFH);
    void setObjetivoGeral(string);
    void setStatus(STATUS);
};