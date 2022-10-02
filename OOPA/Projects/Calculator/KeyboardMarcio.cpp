#include "KeyboardMarcio.hpp"

void KeyboardMarcio::receiveDigit(Digit digit)
{
  this->cpu->receiveDigit(digit);
}
void KeyboardMarcio::receiveOperation(Operation operation)
{
  this->cpu->receiveOperation(operation);
}
void KeyboardMarcio::receiveControl(Control control)
{
  this->cpu->receiveControl(control);
}

void KeyboardMarcio::addKey(Key &key)
{
  this->keys[this->keysCount++] = &key;
  key.setKeyboard(*this);
}

Key &KeyboardMarcio::findKey(char symbol)
{
  for (int i = 0; i < this->keysCount; i++)
    if (this->keys[i]->getSymbol() == symbol)
      return *this->keys[i];

  throw "KEY_NOT_FOUND";
}

void KeyboardMarcio::setCpu(Cpu &cpu)
{
  this->cpu = &cpu;
}
