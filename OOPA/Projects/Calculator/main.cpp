#include "Calculator.hpp"
#include <iostream>

void testDisplay(Display &display)
{
  std::cout << "Testing DISPLAY...\n";
  display.setSignal(NEGATIVE);
  display.addDigit(ZERO, true);
  display.addDigit(ZERO, true);
  display.clear();
  display.addDigit(ZERO);
  display.addDigit(ZERO);
  display.addDigit(ONE);
  display.addDigit(TWO);
  display.addDigit(THREE, true);
  display.addDigit(FOUR);
  display.addDigit(FIVE);
  display.addDigit(ZERO);
  display.addDigit(ONE);
}

void testCpu(Cpu &cpu)
{
  std::cout << "Testing CPU...\n";
  cpu.receiveControl(ON_CLEAR_ERROR);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(TWO);
  cpu.receiveDigit(THREE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(FOUR);
  cpu.receiveDigit(FIVE);
  cpu.receiveDigit(SIX);
  cpu.receiveOperation(EQUAL);

  cpu.receiveDigit(FIVE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(FIVE);
  cpu.receiveOperation(SUBTRACTION);
  cpu.receiveOperation(EQUAL);
  /* -5 */
}

void testKeyboard(Keyboard &keyboard)
{
  try
  {
    keyboard.findKey('1').press();
    keyboard.findKey('2').press();
    keyboard.findKey('4').press();
    keyboard.findKey('5').press();
    keyboard.findKey('6').press();
    keyboard.findKey('7').press();
    keyboard.findKey('8').press();
    keyboard.findKey('9').press();
    keyboard.findKey('0').press();
    // keyboard.findKey('=').press();
  }
  catch (const char *exception)
  {
    std::cerr << exception;
  }
}
/* Coloque aqui a referência para suas implementações */
#include "CpuMarcio.hpp"
#include "DisplayMarcio.hpp"
#include "KeyboardMarcio.hpp"
#include "KeyMarcio.hpp"

int main()
{
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayMarcio d1;
  CpuMarcio c1;
  KeyboardMarcio kb1;

  KeyMarcio keyOne('1', ONE);
  KeyMarcio keyTwo('2', TWO);
  KeyMarcio keyThree('3', THREE);
  KeyMarcio keyFour('4', FOUR);
  KeyMarcio keyFive('5', FIVE);
  KeyMarcio keySix('6', SIX);
  KeyMarcio keySeven('7', SEVEN);
  KeyMarcio keyEight('8', EIGHT);
  KeyMarcio keyNine('9', NINE);
  KeyMarcio keyZero('0', ZERO);

  KeyMarcio keyAddition('+', ADDITION);
  KeyMarcio keyEqual('=', EQUAL);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

  kb1.addKey(keyOne);
  kb1.addKey(keyTwo);
  kb1.addKey(keyThree);
  kb1.addKey(keyFour);
  kb1.addKey(keyFive);
  kb1.addKey(keySix);
  kb1.addKey(keySeven);
  kb1.addKey(keyEight);
  kb1.addKey(keyNine);
  kb1.addKey(keyZero);

  kb1.addKey(keyAddition);
  kb1.addKey(keyEqual);

  /* Fase de testes */
  // testDisplay(d1);
  // testCpu(c1);
  testKeyboard(kb1);
}