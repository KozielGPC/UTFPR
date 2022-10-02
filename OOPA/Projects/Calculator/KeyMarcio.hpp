#pragma once

#include "Calculator.hpp"

class KeyMarcio : public Key
{
private:
  Keyboard *keyboard;
  char symbol;
  Digit digit;
  Operation operation;
  Control control;
  bool isDigit = false;
  bool isOperation = false;
  bool isControl = false;

public:
  KeyMarcio(char, Digit);
  KeyMarcio(char, Operation);
  KeyMarcio(char, Control);
  void press();
  void setKeyboard(Keyboard &);
  char getSymbol();
};
