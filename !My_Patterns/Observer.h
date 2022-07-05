#pragma once
/*
Реализация паттерна Observer по шагам
1.Смоделируйте "независимую" функциональность с помощью абстракции "субъект".
2.Смоделируйте "зависимую" функциональность с помощью иерархии "наблюдатель".
3.Класс Subject связан только c базовым классом Observer.
4.Наблюдатели регистрируются у субъекта.
5.Субъект извещает всех зарегистрированных наблюдателей.
6.Наблюдатели "вытягивают" необходимую им информацию от объекта Subject.
7.Клиент настраивает количество и типы наблюдателей.
*/
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Observer//интерфейс слушателя
{
public:
    virtual void update(int value) = 0;
};

class Subject//издатель
{
    int m_value;
    vector<Observer*> m_views;
public:
    void attach(Observer* obs)//регистрация подписки
    {
        m_views.push_back(obs);
    }
    void set_val(int value)
    {
        m_value = value;

        notify();
    }
    void notify()//рассылка спама
    {
        for (int i = 0; i < m_views.size(); ++i)
            m_views[i]->update(m_value);
    }
};

class DivObserver : public Observer
{
    int m_div;
public:
    DivObserver(Subject* model, int div)
    {
        model->attach(this);//оформление подписки
        m_div = div;
    }
    void update(int v) override
    {
        cout << v << " div " << m_div << " is " << v / m_div << '\n';
    }
};

class ModObserver : public Observer
{
    int m_mod;
public:
    ModObserver(Subject* model, int mod)
    {
        model->attach(this);//оформление подписки
        m_mod = mod;
    }
    void update(int v) override
    {
        cout << v << " mod " << m_mod << " is " << v % m_mod << '\n';
    }
};

void observer()
{
    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    ModObserver modObs3(&subj, 3);
    subj.set_val(14);

}



/*
+
 Издатели не зависят от конкретных классов подписчиков и наоборот.
 Вы можете подписывать и отписывать получателей на лету.
 Реализует принцип открытости/закрытости.
-
 Подписчики оповещаются в случайном порядке.
*/