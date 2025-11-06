#include <iostream>
#include <memory>

#include "TADArbolDIN.h"
#include "TADColaDIN.h"


using namespace std;

//  Clase NodoCola

const Arbol &NodoCola::getElem() const {
    return elem;
}
void NodoCola::setElem(const Arbol &newElem) {
    elem = newElem;
}

const shared_ptr<NodoCola> &NodoCola::getSig() const {
    return sig;
}
void NodoCola::setSig(const shared_ptr<NodoCola> &newSig) {
    sig = newSig;
}

// Clase Cola

// Inserta un elemento en la posiciÃ³n final de la cola
void Cola::push(const Arbol &dato) {
    shared_ptr<NodoCola> ptraux = make_shared<NodoCola>(NodoCola(dato, nullptr));

    if (this->empty()) {
        ppio = ptraux;
    }
    else  {
        final->setSig(ptraux);
    }
    final = ptraux;  // El puntero final de la cola debe seÃ±alar siempre al elemento incluido
}

// Elimina un elemento de la primera posiciÃ³n de la cola
void Cola::pop()  {
    ppio = ppio->getSig();
    if (ppio == nullptr) {
        final = nullptr;  // La cola queda vacÃ­a
    }
}

// Devuelve el elemento de la primera posiciÃ³n de la cola
const Arbol &Cola::first() const {
    return (ppio->getElem());
}

// Determina si la cola estÃ¡ vacÃ­a o no
bool Cola::empty() const  {
    return (ppio == nullptr && final == nullptr);
}
