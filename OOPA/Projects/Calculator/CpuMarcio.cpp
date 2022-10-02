#include "CpuMarcio.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

void CpuMarcio::receiveDigit(Digit digit)
{
  // Guardo o dígito no operanto correspondente
  if (this->isFirstOperand == 1)
  {
    this->digitsOperand1[this->digitsOperand1Count] = digit;
    this->digitsOperand1Count += 1;
  }
  else
  {
    this->digitsOperand2[this->digitsOperand2Count] = digit;
    this->digitsOperand2Count += 1;
  }
  // Envio o dígito para o Display
  this->display->addDigit(digit);
}

float CpuMarcio::getOperand(Digit *digits, int count)
{
  float result = 0;
  int multiplier = 1;
  for (int i = count - 1; i >= 0; i--)
  {
    float number = (float)(digits[i]);
    result += number * multiplier;
    multiplier *= 10;
  }
  return result;
}

// ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, EQUAL, NOOP
void CpuMarcio::receiveOperation(Operation operation)
{
  if (this->isFirstOperand)
  {
    switch (operation)
    {
    case ADDITION:
      this->memory += this->getOperand(this->digitsOperand1, this->digitsOperand1Count);
      break;
    }
    this->isFirstOperand = 0;
  }
  else
  {
    switch (operation)
    {
    case ADDITION:
      this->memory += this->getOperand(this->digitsOperand2, this->digitsOperand2Count);
      break;

      this->isFirstOperand = 0;
    }
    printf("memory: %f \n", this->memory);
  }

  // Guardo a operação, mas antes verificar se já existe uma definida e já exisite um operand2
}

void CpuMarcio::receiveControl(Control control)
{
  switch (control)
  {
  case ON_CLEAR_ERROR:
    this->display->clear();
    break;
  }
}

void CpuMarcio::setDisplay(Display &display)
{
  this->display = &display;
}
