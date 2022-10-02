#include "Calculator.hpp"

#define MAX_DIGITS 8
class CpuMarcio : public Cpu
{
private:
  Display *display;
  Digit digitsOperand1[MAX_DIGITS];
  Digit digitsOperand2[MAX_DIGITS];
  char digitsOperand1Count = 0;
  char digitsOperand2Count = 0;
  Operation operation = NOOP;
  int isFirstOperand = 1;
  float memory = 0;
  float getOperand(Digit *digits, int count);

public:
  void receiveDigit(Digit);
  void receiveOperation(Operation);
  void receiveControl(Control);
  void setDisplay(Display &);
};