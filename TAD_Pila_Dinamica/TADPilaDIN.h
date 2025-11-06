#ifndef TADPILADIN_H
#define TADPILADIN_H

#include <iostream>
#include <memory>

using namespace std;

class Nodo {
private:
    int dato;
    shared_ptr<Nodo> next;
public:
    Nodo():next(nullptr){}
    Nodo(int d, shared_ptr<Nodo> const &ptr):dato(d),next(ptr){}
    ~Nodo(){}

    int getDato() const;
    void setDato(int newDato);
    const shared_ptr<Nodo> &getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

class Stack {
public:
    Stack():front(nullptr){}
    Stack(Stack const &S);
    ~Stack();

    bool empty() const;
    void push(int dato);
    void pop();
    int top() const;
    int sizePila() const;
    void mostrarPila() const;

    void mostrarPila2Destruida();

    int mayorPila() const;
    bool existeEnPila(int dato) const;
    int vecesEnPila(int dato) const;

private:
    shared_ptr<Nodo> front;
};

#endif // TADPILADIN_H
