#include <iostream>

enum Digit
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

enum Signal
{
    POSITIVE,
    NEGATIVE
};

class Key;

class Display
{
public:
    void addDigit(Digit)
    {
        printf("Display\n");
    };
    void setSignal(Signal){};
    void clear(){};
};

class Cpu
{
public:
    void receiveDigit(int);
    void setDisplay(Display);
};

class Keyboard
{
private:
    void receiveDigit(int);
    Key findKey(char);
    void setCpu(Cpu);
};

class Key
{
public:
    void press();
    void setKeyboard(Keyboard);
};

class DisplayMarcio : public Display
{
public:
    void addDigit(Digit digit)
    {
        Display::addDigit(digit);
        printf("Display Marcio\n");
    };
    void setSignal(Signal){};
    void clear(){};
};

int main()
{
    DisplayMarcio display;
    display.addDigit(ONE);
    display.addDigit(ZERO);
    display.setSignal(NEGATIVE);
    display.clear();
}
