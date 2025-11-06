#ifndef TADARBOLDIN_H
#define TADARBOLDIN_H

#include <iostream>
#include <memory>

using namespace std;

//---------------Clase CDato
class CDato {
private:
    int n;
public:
    CDato():n(0){};
    CDato(int d):n(d){};

    int getN() const;
    void setN(int newN);
};

//---------------Clase Nodo
class Nodo {
private:
    CDato dato;
    shared_ptr<Nodo> hizq;
    shared_ptr<Nodo> hdch;
public:
    Nodo(const CDato& d):dato(d){
        hizq = nullptr; hdch = nullptr;};

    const CDato &getDato() const;
    void setDato(const CDato &newDato);

    const shared_ptr<Nodo> &getHizq() const;
    void setHizq(const shared_ptr<Nodo> &newHizq);

    const shared_ptr<Nodo> &getHdch() const;
    void setHdch(const shared_ptr<Nodo> &newHdch);

    void procesarNodo () const;
};

//---------------Clase Ãrbol Binario
class Arbol {
private:
    shared_ptr<Nodo> raiz;
public:
    Arbol():raiz(nullptr){};
    Arbol(const CDato &dato);

    bool empty() const;

    void addHizq(const Arbol &Ai);
    void addHdch(const Arbol &Ad);

    const CDato &getDatoNodo () const;
    const shared_ptr<Nodo> &getHiNodo() const;
    const shared_ptr<Nodo> &getHdNodo() const;

    void construirArbol (const Arbol &Ai, const Arbol &Ad, const CDato &dato);

    void InOrden(const shared_ptr<Nodo> &A) const;
    void recorrerInOrden() const;

    void PreOrden(const shared_ptr<Nodo> &A) const;
    void recorrerPreOrden() const;

    void PostOrden(const shared_ptr<Nodo> &A) const;
    void recorrerPostOrden() const;

    void recorrerAnchura () const;

    const shared_ptr<Nodo> &getRaiz() const;
    void setRaiz(const shared_ptr<Nodo> &newRaiz);
};


#endif // TADARBOLDIN_H
