// Declaracion de las clases necesarias para
// crear un TAD Pila en estatica

#ifndef TADPILAESTA_H
#define TADPILAESTA_H


#include <iostream>
#include <vector>

using namespace std;

struct TipoDato {
    int num;
};

class Stack {
public:
    Stack():front(-1){}
    Stack(Stack const &S):datos(S.datos), front(S.front){}

    bool empty() const;
    void push(const TipoDato &dato);
    void pop();
    const TipoDato &top() const;
    int sizePila() const;
    void mostrarPila() const;
    TipoDato mayorPila() const;
    bool existeEnPila(const TipoDato &dato) const;
    int vecesEnPila(const TipoDato &dato) const;

private:
    vector<TipoDato> datos;
    int front;
};

#endif // TADPILAESTA_H

