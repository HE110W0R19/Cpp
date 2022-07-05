#pragma once
#include <iostream>
using namespace std;

class State;
class Machine //автомат
{
    State* current;
    //int state;
public:
    Machine();
    void setCurrent(State* s)
    {
        current = s;
    }
    void on();
    void off();
};

class State //состо€ние
{
public:
    virtual void on(Machine* m)
    {
        cout << "   already ON\n";
    }
    virtual void off(Machine* m)
    {
        cout << "   already OFF\n";
    }
};


class ON : public State
{
public:
    ON()
    {
        cout << "   ON-ctor ";
    };
    ~ON()
    {
        cout << "   dtor-ON\n";
    };
    void off(Machine* m);
};

class OFF : public State
{
public:
    OFF()
    {
        cout << "   OFF-ctor ";
    };
    ~OFF()
    {
        cout << "   dtor-OFF\n";
    };
    void on(Machine* m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Machine* m)
{
    cout << "   going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}

Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

inline void Machine::on()
 { current->on(this);    }

inline void Machine::off()
{
    current->off(this);
}


int state()
{
    void(Machine:: * ptrs[])() =
    {
      &Machine::off, &Machine::on
    };
    
    Machine fsm;
    int num;
    while (1)
    {
        cout << "Enter 0/1: ";
        cin >> num;
        (fsm.*ptrs[num])();
    }
    return 0;
}

/*
+
1. »збавл€ет от множества больших условных операторов машины состо€ний.
2.  онцентрирует в одном месте код, св€занный с определЄнным состо€нием.
3. ”прощает код контекста.

-
1. ћожет неоправданно усложнить код, если состо€ний мало и они редко мен€ютс€.
*/