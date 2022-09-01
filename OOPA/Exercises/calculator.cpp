#include <iostream>

enum Digit{
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
};

enum Signal{POSITIVE, NEGATIVE};

class Display{
    public:
        void addDigit(Digit){
            printf("Display\n");
        };
        void setSignal(Signal){};
        void clear(){};
};

class Cpu{
    public:
        void receiveDigit(int);
        void setDisplay(Display);
};

class Key;

class Keyboard{
    private:
        void receiveDigit(int);
        Key findKey(char);
        void setCpu(Cpu);

};

class Key{
    public:
        void press();
        void setKeyboard(Keyboard);

};

int main()
{
    Display display;
    display.addDigit(ONE);
    display.addDigit(ZERO);
    display.setSignal(NEGATIVE);
    display.clear();
}
