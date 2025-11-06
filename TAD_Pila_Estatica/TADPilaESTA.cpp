// Implementacion de las funciones basicas miembro necesarias para
// crear un TAD Pila en estatica

#include <iostream>
#include <memory>
#include "TADPilaESTA.h"

using namespace std;

// CLASE Pila

// Inserta un elemento en la cima de la pila
void Stack::push(const TipoDato& dato) {
    front++;
    datos.push_back(dato);
}

// Elimina un elemento en la cima de la pila

void Stack::pop()  {
    front--;
    datos.pop_back();
}

// Devuelve el elemento cima de la pila
const TipoDato &Stack::top() const {
    return (datos.at(front));
}

// Determina si la pila esta vaci­a o no
bool Stack::empty() const  {
    return (front == -1);
}

// Determina el numero de elementos que tiene la pila sin destruirla
int Stack::sizePila() const {
    return datos.size();
}

// Muestra los datos de la pila sin destruirla
void Stack::mostrarPila() const{

    for(int i{front}; i >=0; i--) {
        cout << " " << datos.at(i).num;
    }
}

// Devuelve el mayor elemento de la pila sin destruirla
TipoDato Stack::mayorPila() const{
    TipoDato elmayor;

    if (front != -1){
        elmayor = datos.at(front);
        for(int i{front-1}; i >=0; i--) {
            if (elmayor.num < datos.at(i).num) {
                elmayor = datos.at(i);
            }
        }
    }

    return elmayor;
}

// Devuelve true si se encuentra el elemento en la pila sin destruirla
bool Stack::existeEnPila(const TipoDato &dato) const{
    bool esta{false};

    for(int i{front}; i >=0; i--) {
        if (dato.num == datos.at(i).num) {
            esta = true;
            break;
        }
    }

    return esta;
}

// Devuelve el numero de veces que se encuentra el elemento en la pila sin destruirla
int Stack::vecesEnPila(const TipoDato &dato) const{
    int veces{0};

    for(int i{front}; i >=0; i--) {
        if (dato.num == datos.at(i).num) {
            veces++;
        }
    }

    return veces;
}




