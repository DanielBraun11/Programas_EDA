// Implementacion de las funciones basicas miembro necesarias para
// crear un TAD Pila en dinamica

#include <iostream>
#include <memory>
#include "TADPilaDIN.h"

using namespace std;

// CLASE Nodo

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

int Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(int newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getNext() const {
    return next;
}

// CLASE Pila

// Constructor copia
Stack::Stack(const Stack &S){
    if (S.empty()){
        front = nullptr;
    }
    else{
        // Se declaran 3 punteros.
        // pNew sirve para crear el primer nodo y dejarlo fijo senialando el primer elemento de la Pila
        // pS sirve para recorrer los nodos de la pila que se quiere copiar
        // pAux para dejar rastro para enlazar los nodos de la nueva pila
        //       shared_ptr<Nodo> pNew = make_shared<Nodo>(Nodo(S.top(), nullptr)), pAux, pS{S.front};
        shared_ptr<Nodo> pNew, pAux, pS{S.front};

        // Creamos el primer nodo y copiamos el valor de la cima de la pila que se quiere copiar
        pNew = make_shared<Nodo>();
        *pNew = Nodo(S.top(), nullptr);

        // Dejamos la cima de la pila que se esta copiando fijada al primer elemento creado a traves de pNew
        front = pNew;

        // Se avanza en la pila que se quiere copiar
        pS=pS->getNext();

        // Bucle para procesar y copiar los diferente nodos de la pila que se quiere copiar
        while (pS!=nullptr){
            pAux = pNew;
            // 1.- Se crea un nuevo nodo
            pNew = make_shared<Nodo>();
            *pNew = Nodo(pS->getDato(), nullptr);
            //  pNew->setDato(pS->getDato());
            //  pNew->setNext(nullptr);

            // 2.- Se enlazan los dos nodos
            pAux->setNext(pNew);

            // 3.- Se avanza en la pila que se quiere copiar
            pS=pS->getNext();
        }
    }
}

// Inserta un elemento en la cima de la pila
void Stack::push(int dato) {
    //    shared_ptr<Nodo> elem = make_shared<Nodo>(Nodo(dato, nullptr));
    shared_ptr<Nodo> elem;
    elem = make_shared<Nodo>();
    *elem = Nodo(dato, nullptr);

    if (front != nullptr) {
        elem->setNext(front);
    }
    front = elem;  // La pila debe senialar siempre al elemento incluido
}

// Elimina un elemento en la cima de la pila
void Stack::pop()  {
    front = front->getNext();
}

// Devuelve el elemento cima de la pila
int Stack::top() const {
    return (front->getDato());
}

// Determina si la pila esta vaci­a o no
bool Stack::empty() const  {
    return (front == nullptr);
}

// Determina el numero de elementos que tiene la pila sin destruirla
int Stack::sizePila() const {
    shared_ptr<Nodo> pAux(front);
    int cont{0};

    while(pAux != nullptr){
        cont++;
        pAux = pAux->getNext();
    }

    return cont;
}

// Muestra los datos de la pila sin destruirla
void Stack::mostrarPila() const{
    shared_ptr<Nodo> pAux(front);

    while(pAux != nullptr){
        cout << pAux->getDato() << " ";
        pAux = pAux->getNext();
    }
}

// OJO- Muestra los datos de la pila pero la destruye.
// No es valido, lo he hecho para que se entienda la diferencia
void Stack::mostrarPila2Destruida() {
    while (!(front == nullptr)){
        cout << " " << front->getDato();
        front = front->getNext();
    }
}

// Devuelve el mayor elemento de la pila sin destruirla
int Stack::mayorPila() const{
    shared_ptr<Nodo> pAux(front);

    int mayor{-1};

    while(pAux != nullptr){
        if (mayor < pAux->getDato()){
            mayor = pAux->getDato();
        }
        pAux = pAux->getNext();
    }

    return mayor;
}

// Devuelve true si se encuentra el elemento en la pila sin destruirla
bool Stack::existeEnPila(int dato) const{
    shared_ptr<Nodo> pAux(front);

    bool esta{false};

    while(pAux != nullptr  && !esta){
        if (dato == pAux->getDato()){
            esta = true;
        }
        pAux = pAux->getNext();
    }

    return esta;
}

// Devuelve el numero de veces que se encuentra el elemento en la pila sin destruirla
int Stack::vecesEnPila(int dato) const{
    shared_ptr<Nodo> pAux(front);

    int veces{0};

    while(pAux != nullptr){
        if (dato == pAux->getDato()){
            veces++;
        }
        pAux = pAux->getNext();
    }

    return veces;
}


// Destructor
Stack::~Stack() {
    //    while (!empty()){
    //        pop();
    //    }

    while (!(front == nullptr)){
        cout << " " << front->getDato();
        front = front->getNext();
    }
}

