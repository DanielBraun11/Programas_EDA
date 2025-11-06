#ifndef TADCOLADIN_H
#define TADCOLADIN_H

#include <iostream>
#include <memory>
#include "TADArbolDIN.h"


using namespace std;

//class Arbol;

//---------------Clase NodoCola
class NodoCola {
private:
    Arbol elem;
    shared_ptr<NodoCola> sig;
public:
    NodoCola():sig(nullptr) {};
    NodoCola(const Arbol &d, const shared_ptr<NodoCola> &ptr):elem(d),sig(ptr){}

    const Arbol &getElem() const;
    void setElem(const Arbol &newElem);

    const shared_ptr<NodoCola> &getSig() const;
    void setSig(const shared_ptr<NodoCola> &newSig);
};

//---------------Clase Cola
class Cola {
private:
    shared_ptr<NodoCola> ppio;
    shared_ptr<NodoCola> final;

public:
    Cola():ppio(nullptr), final(nullptr){};

    bool empty() const;
    void push(const Arbol &dato);
    void pop();
    const Arbol &first() const;
};

#endif // TADCOLADIN_H
