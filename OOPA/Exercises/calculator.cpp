#include <iostream>

class CPU
{
private:
    std::string expressao;
    float resultado;

public:
    CPU();
    float getResultado();
    float setResultado(float resultado);
    std::string getExpressao();
    std::string setExpressao(std::string expressao);
};

class Display
{
private:
    std::string exibido;

public:
    Display();
    std::string getExibido();
    std::string setExibido(std::string exibido);
};

class Teclado
{
private:
    std::string *botoesNumericos[10];
    std::string *botoesExpressao[6];
    std::string *botoesApagar[2];
    bool botaoPower;

public:
    Teclado()
    {
        std::string botoesNumericos[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        std::string botoesExpressao[6] = {"+", "-", "/", "*", "=", "."};
        std::string botoesApagar[6] = {"C", "CE"};
        this->setBotaoPower(!this->botaoPower);
        this->setBotoesApagar(botoesApagar);
        this->setBotoesExpressao(botoesExpressao);
        this->setBotoesNumericos(botoesNumericos);
    }
    void setBotoesNumericos(std::string *botoesNumericos);
    void setBotoesExpressao(std::string *botoesExpressao);
    void setBotoesApagar(std::string *botoesApagar);
    void setBotaoPower(bool power);
    void apertarBotaoExpressao(std::string botao);
    void apertarBotoesNumericos(std::string botao);
    void apertarBotoesApagar(std::string botao);
    void apertarBotaoPower();
};
class Calculadora
{
private:
    bool ligado;
    CPU cpu;
    Display display;
    Teclado teclado;

public:
    Calculadora()
    {
        Display *display = new Display();
        Teclado *teclado = new Teclado();
        CPU *cpu = new CPU();

        setCpu(cpu);
        setTeclado(teclado);
        setDisplay(display);
    };
    void ligar();
    void desligar();
    void setCpu(CPU *cpu);
    void setTeclado(Teclado *teclado);
    void setDisplay(Display *display);
};

int main()
{
    std::cout << "Hello World!\n";
}