#pragma once

#include "KeyMarcio.hpp"
KeyMarcio::KeyMarcio(char symbol, Digit digit)
{
  this->symbol = symbol;
  this->digit = digit;
  this->isDigit = true;
}
KeyMarcio::KeyMarcio(char symbol, Operation operation)
{
  this->symbol = symbol;
  this->operation = operation;
  this->isOperation = true;
}

KeyMarcio::KeyMarcio(char symbol, Control control)
{
  this->symbol = symbol;
  this->control = control;
  this->isControl = true;
}

void KeyMarcio::press()
{
  if (this->isDigit)
    this->keyboard->receiveDigit(this->digit);
  if (this->isOperation)
    this->keyboard->receiveOperation(this->operation);
  if (this->isControl)
    this->keyboard->receiveControl(this->control);
}

void KeyMarcio::setKeyboard(Keyboard &keyboard)
{
  this->keyboard = &keyboard;
}

char KeyMarcio::getSymbol()
{
  return this->symbol;
}
