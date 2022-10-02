#pragma once
#include "Calculator.hpp"
#include "Console.hpp"
#define MAX_DIGITS 8

class DisplayMarcio : public Display
{
private:
  Console console;
  Digit digits[MAX_DIGITS];
  bool dots[MAX_DIGITS];
  unsigned char digitsCount;
  Signal signal;
  void refresh();
  void showDigitShape(const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, unsigned char column);
  void showDigit(Digit digit);

public:
  DisplayMarcio();
  void addDigit(Digit, bool withDot = false);
  void setSignal(Signal signal);
  void clear();
};
