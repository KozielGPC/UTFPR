#include "CpuMarcio.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

void CpuMarcio::receiveDigit(Digit digit)
{
  // Guardo o dígito no operanto correspondente
  // printf("First operand %d\n", this->isFirstOperand);
  if (this->isFirstOperand == 1)
  {
    // printf("Is first digit\n");
    this->digitsOperand1[this->digitsOperand1Count] = digit;
    this->digitsOperand1Count += 1;
  }
  else
  {
    printf("Is second digit\n");
    this->digitsOperand2[this->digitsOperand2Count] = digit;
    this->digitsOperand2Count += 1;
  }
  // Envio o dígito para o Display
  this->display->addDigit(digit);
}

void CpuMarcio::proccessOperation()
{
  switch (this->operation)
  {
  case ADDITION:
    printf("ADDITION\n");
    this->memory += this->getOperand(this->digitsOperand2, this->digitsOperand2Count);
    break;
  case SUBTRACTION:
    printf("SUBTRACTION\n");
    this->memory -= this->getOperand(this->digitsOperand2, this->digitsOperand2Count);
    break;
  case MULTIPLICATION:
    printf("MULTIPLICATION\n");
    this->memory *= this->getOperand(this->digitsOperand2, this->digitsOperand2Count);
    break;
  case DIVISION:
    printf("DIVISION\n");
    this->memory /= this->getOperand(this->digitsOperand2, this->digitsOperand2Count);
    break;
  case NOOP:
    printf("NOOP\n");
    break;
  case EQUAL:
    printf("equal\n");
    break;
  default:
    printf("Default \n");
    break;
  }
}

float CpuMarcio::getOperand(Digit *digits, int count)
{
  float result = 0;
  int multiplier = 1;
  for (int i = count - 1; i >= 0; i--)
  {
    float number = (float)(digits[i]);
    // printf("Number: %f \n", number);
    result += number * multiplier;
    // printf("result: %f \n", result);
    multiplier *= 10;
  }
  return result;
}

// ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, EQUAL, NOOP
void CpuMarcio::receiveOperation(Operation operation)
{

  printf("memory start: %f \n", this->memory);
  printf("Digits: [");
  for (int i = 0; i < this->digitsOperand1Count; i++)
  {
    printf("%d, ", this->digitsOperand1[i]);
  }
  printf("]\n");
  if (this->isFirstOperand == 1)
  {
    this->memory = this->getOperand(this->digitsOperand1, this->digitsOperand1Count);
    this->isFirstOperand = 0;
    this->operation = operation;
  }
  else
  {
    printf("Is second \n");
    if (operation == EQUAL)
    {
      printf("operation: %d \n", this->operation);
      this->proccessOperation();
    }
    else
    {

      this->isFirstOperand = 0;
    }
  }

  printf("memory: %f \n", this->memory);
  this->digitsOperand1Count = 0;
  this->display->clear();
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
