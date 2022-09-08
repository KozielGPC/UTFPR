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
    void addDigit(Digit digit)
    {
        printf("Display lucio \n");
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
private:
    std::string text;

public:
    void addDigit(Digit digit)
    {
        switch (digit)
        {
        case ZERO:
            setText(getText() + "0");
            break;
        case ONE:
            setText(getText() + "1");
            break;
        case TWO:
            setText(getText() + "2");
            break;
        case THREE:
            setText(getText() + "3");
            break;
        case FOUR:
            setText(getText() + "4");
            break;
        case FIVE:
            setText(getText() + "5");
            break;
        case SIX:
            setText(getText() + "6");
            break;
        case SEVEN:
            setText(getText() + "7");
            break;
        case EIGHT:
            setText(getText() + "8");
            break;
        case NINE:
            setText(getText() + "9");
            break;

        default:
            setText(getText() + " ?");
            break;
            break;
        };
        this->showText();
    };
    void setSignal(Signal){};
    void clear(){};

    void setText(std::string text)
    {
        this->text = text;
    }

    std::string getText()
    {
        return this->text;
    }
    void showText()
    {
        printf("%s\n", this->getText());
    }
};

int main()
{
    DisplayMarcio display;
    display.addDigit(ONE);
    // display.addDigit(ZERO);
    // display.setSignal(NEGATIVE);
    display.clear();
}
