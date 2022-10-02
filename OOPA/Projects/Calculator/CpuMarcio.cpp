#include "CpuMarcio.hpp"
#include <iostream>

void CpuMarcio::receiveDigit(Digit digit)
{
  // Guardo o dígito no operanto correspondente
  if (this->isFirstOperand)
  {
    this->digitsOperand1[this->digitsOperand1Count] = digit;
  }
  // Envio o dígito para o Display
  this->display->addDigit(digit);
}

void CpuMarcio::receiveOperation(Operation)
{
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
