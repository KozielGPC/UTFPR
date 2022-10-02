#include "DisplayMarcio.hpp"
using namespace std;
#include <iostream>
#include <stdio.h>

void DisplayMarcio::refresh()
{
  if (signal == NEGATIVE)
  {
    this->showDigitShape("    ", "    ", "████", "    ", "    ", 0);
  }
  else
  {
    // this->showDigitShape("    ","  █ ", " ███", "  █ ","    ",0);
    this->showDigitShape("    ", "    ", "    ", "    ", "    ", 0);
  }

  for (int i = 1; i <= this->digitsCount; i++)
  {
    this->showDigit(this->digits[i - 1]);
    printf(dots[i - 1] ? "█" : " ");
  }
}

void DisplayMarcio::showDigit(Digit digit)
{
  switch (digit)
  {
  case ZERO:
    cout << "0";
    break;
  case ONE:
    cout << "1";
    break;
  case TWO:
    cout << "2";
    break;
  case THREE:
    cout << "3";
    break;
  case FOUR:
    cout << "4";
    break;
  case FIVE:
    cout << "5";
    break;
  case SIX:
    cout << "6";
    break;
  case SEVEN:
    cout << "7";
    break;
  case EIGHT:
    cout << "8";
    break;
  case NINE:
    cout << "9";
    break;
  default:
    cout << "?";
  }
};

void DisplayMarcio::showDigitShape(const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, unsigned char column)
{
  this->console.set_cursor(1, 1 + column * 6);
  printf(line1);
  this->console.set_cursor(2, 1 + column * 6);
  printf(line2);
  this->console.set_cursor(3, 1 + column * 6);
  printf(line3);
  this->console.set_cursor(4, 1 + column * 6);
  printf(line4);
  this->console.set_cursor(5, 1 + column * 6);
  printf(line5);
}

DisplayMarcio::DisplayMarcio()
{
  this->clear();
}

void DisplayMarcio::addDigit(Digit digit, bool withDot)
{
  if (this->digitsCount < MAX_DIGITS)
  {
    dots[this->digitsCount] = withDot;
    digits[this->digitsCount++] = digit;
    this->refresh();
  }
}

void DisplayMarcio::setSignal(Signal signal)
{
  this->signal = signal;
  this->refresh();
}

void DisplayMarcio::clear()
{
  this->digitsCount = 0;
  this->signal = POSITIVE;
  this->refresh();
}
