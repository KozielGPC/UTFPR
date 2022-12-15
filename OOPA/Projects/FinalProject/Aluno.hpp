#pragma once
#include <string>

using namespace std;

enum STATUS
{
    CURSANDO,
    FORMADO,
    TRANCADO
};

class Aluno
{
private:
    int ra;
    string nome;
    int periodo;
    string curso;
    STATUS status = CURSANDO;

public:
    int getRa();
    int getPeriodo();
    string getNome();
    string getCurso();
    STATUS getStatus();

    void setRa(int);
    void setPeriodo(int);
    void setNome(string);
    void setCurso(string);
    void setStatus(STATUS);
};