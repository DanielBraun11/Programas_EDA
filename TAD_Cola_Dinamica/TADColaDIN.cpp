#include "TADColaDIN.h"

// IMPLEMENTACIÃ“N CLASE Nodo

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

const TipoDato &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const TipoDato &newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getNext() const {
    return next;
}

// IMPLENTACIÃ“N CLASE COLA

// Constructor Copia
Cola::Cola(const Cola &Q){
    if (Q.empty()) {
        front = nullptr;
        end = nullptr;
    }
    else {
        // Se declaran 2 punteros.
        // ptrNew sirve para crear los nodos de la Cola
        // qS sirve para recorrer los nodos de la Cola que se quiere copiar.
        // Se inicializa seÃ±alando al primer elemento de la Cola
        shared_ptr<Nodo> ptrNew, qS{Q.front};

        // Creamos el primer nodo y copiamos el valor del primer elemento de la cola que se quiere copiar
        ptrNew = make_shared<Nodo>();
        *ptrNew = Nodo(Q.front->getDato(), nullptr);

        // SeÃ±alamos el primer elemento creado a travÃ©s de pNew como el primer elemento y el Ãºltimo
        // de la cola copia
        end = ptrNew;
        front = ptrNew;

        // Se avanza en la cola que se quiere copiar
        qS=qS->getNext();

        // Bucle para procesar y copiar los diferente nodos de la cola que se quiere copiar
        while (qS!=nullptr){
            // 1.- Se crea un nuevo nodo
            ptrNew = make_shared<Nodo>();
            *ptrNew = Nodo(qS->getDato(), nullptr);
            //  ptrNew->setDato(qS->getDato());
            //  ptrNew->setNext(nullptr);

            // 2.- Se enlazan los dos nodos del final
            end->setNext(ptrNew);
            end=ptrNew;

            // 3.- Se avanza en la cola que se quiere copiar
            qS=qS->getNext();
        }
    }
}

// Inserta un elemento en la posiciÃ³n final de la cola
void Cola::push(const TipoDato &dato) {
    shared_ptr<Nodo> qAux;
    qAux = make_shared<Nodo>();
    *qAux = Nodo(dato, nullptr);

    //    if (this->empty()) {
    if (front == nullptr && end == nullptr) {
        front = qAux;
    }
    else  {
        end->setNext(qAux);
    }
    // El puntero final de la cola debe seÃ±alar siempre al elemento incluido
    end = qAux;
}

// Elimina un elemento de la primera posiciÃ³n de la cola
void Cola::pop()  {
    front = front->getNext();
    if (front == nullptr) {
        end = nullptr;  // La cola queda vacÃ­a
    }
}

// Devuelve el elemento de la primera posiciÃ³n de la cola
const TipoDato &Cola::first() const {
    return (front->getDato());
}

// Determina si la cola estÃ¡ vacÃ­a o no
bool Cola::empty() const  {
    return (front == nullptr && end == nullptr);
}

// Destructor
Cola::~Cola(){
    while (!(front == nullptr && end == nullptr)){
        front = front->getNext();
        if (front == nullptr) {
            end = nullptr;  // La cola queda vacÃ­a
        }
    }
}
