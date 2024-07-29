#ifndef CAFETERA_H
#define CAFETERA_H

#include <iostream>
using namespace std;

class Cafetera {
public:
    virtual ~Cafetera() = default;
    virtual void Capuchino() = 0;
    virtual void Tinto() = 0;
};

class Oster : public Cafetera {
public:
    void Capuchino() {
        cout << "La cafetera Oster está preparando un Capuchino" << endl;
    }
    void Tinto() {
        cout << "La cafetera Oster está preparando un tinto" << endl;
    }
};

class Haceb : public Cafetera {
public:
    void Capuchino() {
        cout << "La cafetera Haceb está preparando un Capuchino" << endl;
    }
    void Tinto() {
        cout << "La cafetera Haceb está preparando un tinto" << endl;
    }
};

#endif // CAFETERA_H

int main() {
    Cafetera* C_Oster = new Oster();
    Cafetera* C_Haceb = new Haceb();

    C_Oster->Capuchino();
    C_Oster->Tinto();

    C_Haceb->Capuchino();
    C_Haceb->Tinto();

    delete C_Oster;
    delete C_Haceb;

    return 0;
}