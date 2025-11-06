#include <iostream>
#include <memory>

#include "TADColaDIN.h"
#include "TADArbolDIN.h"

using namespace std;


//------------------Clase CDato
int CDato::getN() const {
    return n;
}

void CDato::setN(int newN) {
    n = newN;
}


//--------------------Clase Nodo
const CDato &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const CDato &newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getHizq() const {
    return hizq;
}

void Nodo::setHizq(const shared_ptr<Nodo> &newHizq) {
    hizq = newHizq;
}

const shared_ptr<Nodo> &Nodo::getHdch() const {
    return hdch;
}

void Nodo::setHdch(const shared_ptr<Nodo> &newHdch) {
    hdch = newHdch;
}

void Nodo::procesarNodo () const {
    cout << "\n\n\tNodo: " << getDato().getN();
}

//-------------------Clase Ãrbol


bool Arbol::empty() const {
    return (raiz == nullptr);
}


const shared_ptr<Nodo> &Arbol::getRaiz() const {
    return raiz;
}

void Arbol::setRaiz(const shared_ptr<Nodo> &newRaiz) {
    raiz = newRaiz;
}

Arbol::Arbol(const CDato &dato) {
    raiz = make_shared<Nodo>(Nodo{dato});
}


void Arbol::addHizq(const Arbol &Ai) {
    raiz->setHizq(Ai.raiz);
}

void Arbol::addHdch(const Arbol &Ad) {
    raiz->setHdch(Ad.raiz);
}


const CDato &Arbol::getDatoNodo () const {
    return raiz->getDato();
}

const shared_ptr<Nodo> &Arbol::getHiNodo() const {
    return raiz->getHizq();
}

const shared_ptr<Nodo> &Arbol::getHdNodo() const {
    return raiz->getHdch();
}


void Arbol::construirArbol (const Arbol &Ai, const Arbol &Ad, const CDato &dato) {
    raiz = make_shared<Nodo>(Nodo{dato});
    raiz->setHizq(Ai.raiz);
    raiz->setHdch(Ad.raiz);
}

// Recorrido InOrden compacto, sin varibles auxiliares
void Arbol::InOrden(const shared_ptr<Nodo> &A) const {
    if (A != nullptr) {
        InOrden (A->getHizq());		// I
        A->procesarNodo();             // R
        InOrden (A->getHdch());        // D
    }
}

// Recorrido InOrden con varibles auxiliares
//        void Arbol::InOrden(const shared_ptr<Nodo> &A) const {
//            shared_ptr<Nodo> Ai, Ad;
//            CDato dato;

//            if (A != nullptr) {
//                 Ai = A->getHizq();
//                 Ad = A->getHdch();
//                 dato = A->getDato();

//                 InOrden (Ai);          //  I
//                 A->procesarNodo();     //  R
//                 InOrden (Ad);          //  D
//            }
//        }

void Arbol::recorrerInOrden() const {
    if (!empty()) {
        InOrden (raiz);
    }
}

// Recorrido PreOrden compacto, sin varibles auxiliares
void Arbol::PreOrden(const shared_ptr<Nodo> &A) const {
    if (A != nullptr) {
        A->procesarNodo();             // R
        PreOrden (A->getHizq());		// I
        PreOrden (A->getHdch());       // D
    }
}

void Arbol::recorrerPreOrden() const {
    if (!empty()) {
        PreOrden (raiz);
    }
}


// Recorrido PostOrden compacto, sin varibles auxiliares
void Arbol::PostOrden(const shared_ptr<Nodo> &A) const {
    if (A != nullptr) {
        PostOrden (A->getHizq());		// I
        PostOrden (A->getHdch());      // D
        A->procesarNodo();             // R
    }
}

void Arbol::recorrerPostOrden() const {
    if (!empty()) {
        PostOrden (raiz);
    }
}

void Arbol::recorrerAnchura() const{
    Arbol Bi, Bd, B;
    Cola Niveles;
    CDato dato;

    if (!empty()) {
        Niveles.push(*this);    // Se aÃ±ade el nodo raÃ­z del Ã¡rbol, 1er. Nivel
    }

    while(!Niveles.empty()) {
        B = Niveles.first();  // Se extrae un elemento de la cola
        Niveles.pop();

        dato = B.getDatoNodo();
        Bi.setRaiz(B.getHiNodo());
        Bd.setRaiz(B.getHdNodo());
        cout << "\n\n\tNodo: " << dato.getN();

        //  Se aÃ±aden al final de la cola el hi y hd, si es que existen.
        //  Siempre se procesan despuÃ©s de hacerlo los del nivel anterior.
        if (!Bi.empty()) {
            Niveles.push(Bi);
        }

        if (!Bd.empty()) {
            Niveles.push(Bd);
        }
    }
}
