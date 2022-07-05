#pragma once

#include <iostream>
#include <string>

using namespace std;

// Иерархия классов, определяющая алгоритмы сжатия файлов
class Compression
{
public:
    virtual ~Compression() {}
    virtual void compress(const string& file) = 0;
};

class ZIP_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "ZIP compression" << endl;
    }
};

class TGZ_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "TGZ compression" << endl;
    }
};

class RAR_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "RAR compression" << endl;
    }
};


// Класс для использования
class Compressor
{
public:
    Compressor(Compression* comp) : p(comp) {}
    ~Compressor() { delete p; }
    void compress(const string& file) {
        p->compress(file);
    }
private:
    Compression* p;
};


int strategy()
{
    Compressor* p = new Compressor(new ZIP_Compression);
    p->compress("file.txt");
    delete p;
    return 0;
}

/*
+
1. Горячая замена алгоритмов на лету.
2. Изолирует код и данные алгоритмов от остальных классов.
3. Уход от наследования к делегированию.
4. Реализует принцип открытости/закрытости.

-
1. Усложняет программу за счёт дополнительных классов.
2. Клиент должен знать, в чём состоит разница между стратегиями, чтобы выбрать подходящую.
*/