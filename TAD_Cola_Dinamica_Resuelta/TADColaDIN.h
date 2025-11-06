#ifndef TADCOLADIN_H
#define TADCOLADIN_H

#include <iostream>
#include <memory>

using namespace std;


struct TipoDato {
    int num;
};

class Nodo {
private:
    TipoDato dato;
    shared_ptr<Nodo> next;
public:
    Nodo():next(nullptr){}
    Nodo(const TipoDato &d, const shared_ptr<Nodo> &ptr):dato(d),next(ptr){}
    ~Nodo(){}

    const TipoDato &getDato() const;
    void setDato(const TipoDato &newDato);
    const shared_ptr<Nodo> &getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

class Cola {
public:
    Cola():front(nullptr), end(nullptr){}
    Cola(const Cola &Q);
    ~Cola();

    bool empty() const;
    void push(const TipoDato &dato);
    void pop();
    const TipoDato &first() const;

    int sizeCola() const;
    void mostrarCola() const;

    TipoDato mayorCola() const;
    bool existeEnCola(const TipoDato &dato) const;
    int vecesEnCola(const TipoDato &dato) const;

    Cola invertirCola();

private:
    shared_ptr<Nodo> front, end;
};

#endif // TADCOLADIN_H
