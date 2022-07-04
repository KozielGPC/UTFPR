#include <stdio.h>
int main(void)
{
    double salario_liquido, valor_hora, horas_trabalhadas, imposto_de_renda, salario_anual;

    printf("Quantidade de horas trabalhadas: ");
    scanf(" %lf", &horas_trabalhadas);

    printf("Valor por hora: ");
    scanf(" %lf", &valor_hora);

    salario_liquido = (horas_trabalhadas * valor_hora) * 0.915;
    salario_anual = 12 * salario_liquido;

    printf("Salário liquido: R$%.2lf\n", salario_liquido);
    printf("Salário anual: R$%.2lf\n", salario_anual);

    if (salario_anual <= 2345.66)
    {
        imposto_de_renda = 0;
    }
    else if (salario_anual < 3456.79)
    {
        imposto_de_renda = salario_anual * 0.075;
    }
    else if (salario_anual < 4567.90)
    {
        imposto_de_renda = salario_anual * 0.15;
    }
    else if (salario_anual < 5678.91)
    {
        imposto_de_renda = salario_anual * 0.225;
    }
    else
    {
        imposto_de_renda = salario_anual * 0.275;
    }

    printf("Imposto de renda: R$%.2lf\n", imposto_de_renda);

    return 0;
}