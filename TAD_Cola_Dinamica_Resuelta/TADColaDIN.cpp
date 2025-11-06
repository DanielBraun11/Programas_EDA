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

// Muestra los datos de la cola sin destruirla
void Cola::mostrarCola() const{
    shared_ptr<Nodo> qAux{front};

    while (qAux != nullptr) {
        cout << " " << qAux->getDato().num;
        qAux = qAux->getNext();
    }
}

// Determina el nÃºmero de elementos de la cola
int Cola::sizeCola() const{
    int size{0};
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr) {
        size++;
        paux =paux->getNext();
    }
    return size;
}

TipoDato Cola::mayorCola() const{
    TipoDato dato{-1};
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr) {
        if (dato.num < paux->getDato().num){
            dato.num = paux->getDato().num;
        }
        paux =paux->getNext();
    }
    return dato;
}


bool Cola::existeEnCola(const TipoDato &dato) const{
    bool esta{false};
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr && !esta) {
        if (dato.num == paux->getDato().num){
            esta = true;
        }
        paux =paux->getNext();
    }
    return esta;
}


int Cola::vecesEnCola(const TipoDato &dato) const{
    int veces{0};
    shared_ptr<Nodo> paux{front};

    while (paux != nullptr) {
        if (dato.num == paux->getDato().num){
            veces++;
        }
        paux =paux->getNext();
    }
    return veces;

}

Cola Cola::invertirCola(){

    if(!*this.empty()){
        Cola Caux(*this);
        return Caux;  //Cola vacia
    }else if(*this.front == *this.end){
        Cola Caux(*this);
        return Caux;  //Cola con 1 nodo
    }else{
        shared_ptr<Nodo> paux{*this.front};

        shared_ptr<Nodo> pNew = make_shared<Nodo>(paux->getDato(), nullptr);

        paux = paux->getNext();

        while(paux != nullptr){
            pNew = make_shared<Nodo>(paux->getDato(), Caux.front);
            front = pNew;
            paux = paux->getNext();
        }

        return Caux;
    }





}


// Destructor
Cola::~Cola(){
    //    while (!empty()){
    //      pop();
    //    }

    while (!(front == nullptr && end == nullptr)){
        front = front->getNext();
        if (front == nullptr) {
            end = nullptr;  // La cola queda vacÃ­a
        }
    }
}
