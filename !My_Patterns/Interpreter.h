#pragma once
/*
Рассмотрим задачу интерпретирования (вычисления) значений строковых 
представлений римских чисел. Используем следующую грамматику.

romanNumeral ::= {thousands} {hundreds} {tens} {ones}
thousands,hundreds,tens,ones ::= nine | four | {five} {one} {one} {one}
nine ::= "CM" | "XC" | "IX"
four ::= "CD" | "XL" | "IV"
five ::= 'D' | 'L' | 'V'
one  ::= 'M' | 'C' | 'X' | 'I'

Для проверки и интерпретации строки используется иерархия классов с общим
базовым классом RNInterpreter, имеющим 4 под-интерпретатора. Каждый 
под-интерпретатор получает "контекст" (оставшуюся неразобранную часть строки
и накопленное вычисленное значение разобранной части) и вносит свой вклад в 
процесс обработки. Под-переводчики просто определяют шаблонные методы,
объявленные в базовом классе RNInterpreter.
*/

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Thousand;
class Hundred;
class Ten;
class One;

class RNInterpreter //TemplateMethod
{
public:
    RNInterpreter(); // ctor for client
    RNInterpreter(int) {}
    // ctor for subclasses, avoids infinite loop
    int interpret(string&); // interpret() for client
    virtual void interpret(string input, int& total)
    {
        // for internal use
        int index;
        index = 0;
        if (!nine().compare(0,2,input))
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (!four().compare(0, 2, input))
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
                index = 0;
            for (int end = index + 3; index < end; index++)
                if (input[index] == one())
                    total += 1 * multiplier();
                else
                    break;
        }
        input= input.substr(index);
    } // remove leading chars processed
protected:
    // cannot be pure virtual because client asks for instance
    virtual char one() { return '\0'; }
    virtual string four() { return ""; }
    virtual char five() { return '\0'; }
    virtual string nine() { return ""; }
    virtual int multiplier() { return 0; }
private:
    RNInterpreter* thousands;
    RNInterpreter* hundreds;
    RNInterpreter* tens;
    RNInterpreter* ones;
};

class Thousand : public RNInterpreter
{
public:
    // provide 1-arg ctor to avoid infinite loop in base class ctor
    Thousand(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'M';
    }
    string four()
    {
        return "";
    }
    char five()
    {
        return '\0';
    }
    string nine()
    {
        return "";
    }
    int multiplier()
    {
        return 1000;
    }
};

class Hundred : public RNInterpreter
{
public:
    Hundred(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'C';
    }
    string four()
    {
        return "CD";
    }
    char five()
    {
        return 'D';
    }
    string nine()
    {
        return "CM";
    }
    int multiplier()
    {
        return 100;
    }
};

class Ten : public RNInterpreter
{
public:
    Ten(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'X';
    }
    string four()
    {
        return "XL";
    }
    char five()
    {
        return 'L';
    }
    string nine()
    {
        return "XC";
    }
    int multiplier()
    {
        return 10;
    }
};

class One : public RNInterpreter
{
public:
    One(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'I';
    }
    string four()
    {
        return "IV";
    }
    char five()
    {
        return 'V';
    }
    string nine()
    {
        return "IX";
    }
    int multiplier()
    {
        return 1;
    }
};

RNInterpreter::RNInterpreter()
{
    // use 1-arg ctor to avoid infinite loop
    thousands = new Thousand(1);
    hundreds = new Hundred(1);
    tens = new Ten(1);
    ones = new One(1);
}

int RNInterpreter::interpret(string& input)
{
    int total;
    total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input, total);
    ones->interpret(input, total);
    if (input== "")
        // if input was invalid, return 0
        return 0;
    return total;
}

void intepreter()
{
    RNInterpreter interpreter;
    string input;
    cout << "Enter Roman Numeral: ";
    while (cin >> input)
    {
        cout << "   interpretation is "
            << interpreter.interpret(input) << endl;
        cout << "Enter Roman Numeral: ";
    }
}
