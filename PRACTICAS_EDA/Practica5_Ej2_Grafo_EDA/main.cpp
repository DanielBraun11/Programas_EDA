// Fichero inicial para el ejercicio n2 de la practica n5 de EDA
//Daniel Braun Sandina
//Daniel Marcos Gonzalez

#include <iostream>
#include <string>
#include <array>
#include <set>
#include <memory>

// Numero de nodos del Grafo
#define nMax 11

using namespace std;

//---------------Clase CDato
class CDato {
private:
    int vertice;
    string nombre;
public:
    CDato():vertice(0){}

    const string &getNom() const;
    void setNom(const string &newN);
    int getVertice() const;
    void setVertice(int newV);

};

//---------------Clase Nodo
class Nodo {
private:
    CDato dato;
    shared_ptr<Nodo> next;
public:
    Nodo();
    Nodo(CDato const &d): dato(d), next(nullptr){}

    const CDato &getDato() const;
    void setDato(const CDato &newDato);
    shared_ptr<Nodo> getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

//---------------Clase Lista
class Lista {
private:
    shared_ptr<Nodo> first;
public:
    Lista():first(nullptr){}
    Lista(const shared_ptr<Nodo> &f):first(f){}

    const shared_ptr<Nodo> &getFirst() const;
    void setFirst(const shared_ptr<Nodo> &newFirst);

    bool empty() const;
    void listaVacia();
    void push_front(const CDato&);
    const CDato &front() const;
    void mostrarLista() const;

    int contarLista() const;
};

//---------------Clase VerticeG
class VerticeG {
private:
    string nombre;
    shared_ptr<Nodo> next;
public:
    VerticeG():next(nullptr){}
    VerticeG(string const &l):nombre(l), next(nullptr){}

    const string &getnombre() const;
    void setnombre(const string &newnombre);
    shared_ptr<Nodo> getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

class Grafo {
private:
    array<VerticeG, nMax> cArcos;
public:
    Grafo();

    void incluirVertice (int v, const string &l);
    void incluirAdyacentes (int v, const Lista &ady);

    void mostrarGrafo() const;
    int contarConexionesDirectas(const string &estacion) const;
    const array<VerticeG, nMax> &getCArcos() const;
};

Grafo inicializarGrafo(){
    Grafo G;
    Lista L;
    CDato elem;

    //  CREACION DEL GRAFO CON 5 NODOS Y SUS CORRESPONDIENTES NODOS ADYACENTES
    G.incluirVertice(0, "SOL");
    // Nodos adyacentes al vertice Sol: Gran Via, Callao, Tirso de Molina, Lavapies
    elem.setNom("Gran Via");
    elem.setVertice(1);
    L.push_front(elem);
    elem.setNom("Callao");
    elem.setVertice(5);
    L.push_front(elem);
    elem.setNom("Tirso de Molina");
    elem.setVertice(2);
    L.push_front(elem);
    elem.setNom("Lavapies");
    elem.setVertice(3);
    L.push_front(elem);
    G.incluirAdyacentes(0,L);

    G.incluirVertice(1, "Gran Via");
    // Nodos adyacentes al vertice Gran Via: Sol, Callao, Chueca, Trubunal
    L.listaVacia();
    elem.setNom("Sol");
    elem.setVertice(0);
    L.push_front(elem);
    elem.setNom("Callao");
    elem.setVertice(5);
    L.push_front(elem);
    elem.setNom("Chueca");
    elem.setVertice(7);
    L.push_front(elem);
    elem.setNom("Tribunal");
    elem.setVertice(4);
    L.push_front(elem);
    G.incluirAdyacentes(1,L);

    G.incluirVertice(2, "Tirso de Molina");
    // Nodos adyacentes al vertice Tirso de Molina: Sol y Anton Martin
    L.listaVacia();
    elem.setNom("Sol");
    elem.setVertice(0);
    L.push_front(elem);
    elem.setNom("Anton Martin");
    elem.setVertice(8);
    L.push_front(elem);
    G.incluirAdyacentes(2,L);

    G.incluirVertice(3, "Lavapies");
    // Nodos adyacentes al vertice Lavapies: Sol y Embajadores
    L.listaVacia();
    elem.setNom("Sol");
    elem.setVertice(0);
    L.push_front(elem);
    elem.setNom("Embajadores");
    elem.setVertice(9);
    L.push_front(elem);
    G.incluirAdyacentes(3,L);

    G.incluirVertice(4, "Tribunal");
    // Nodos adyacentes al vertice Tribunal: Alonso Martinez, Plaza EspaÃ±a, Gran Via
    L.listaVacia();
    elem.setNom("Alonso Martinez");
    elem.setVertice(10);
    L.push_front(elem);
    elem.setNom("Plaza EspaÃ±a");
    elem.setVertice(6);
    L.push_front(elem);
    elem.setNom("Gran Via");
    elem.setVertice(1);
    L.push_front(elem);
    G.incluirAdyacentes(4,L);

    G.incluirVertice(5, "Callao");
    // Nodos adyacentes al vertice Callao: Sol, Plaza EspaÃ±a, Gran Via
    L.listaVacia();
    elem.setNom("Sol");
    elem.setVertice(0);
    L.push_front(elem);
    elem.setNom("Plaza EspaÃ±a");
    elem.setVertice(6);
    L.push_front(elem);
    elem.setNom("Gran Via");
    elem.setVertice(1);
    L.push_front(elem);
    G.incluirAdyacentes(5,L);

    G.incluirVertice(6, "Plaza EspaÃ±a");
    // Nodos adyacentes al vertice Plaza EspaÃ±a: Callao, Tribunal, Principe Pio y Ventura Rodriguez
    L.listaVacia();
    elem.setNom("Callao");
    elem.setVertice(5);
    L.push_front(elem);
    elem.setNom("Tribunal");
    elem.setVertice(4);
    L.push_front(elem);
    G.incluirAdyacentes(6,L);

    G.incluirVertice(7, "Chueca");
    // Nodos adyacentes al vertice Chueca: Gran Via
    L.listaVacia();
    elem.setNom("Gran Via");
    elem.setVertice(1);
    L.push_front(elem);
    G.incluirAdyacentes(7,L);

    G.incluirVertice(8, "Anton Martin");
    // Nodos adyacentes al vertice Anton Martin: Tirso de Molina
    L.listaVacia();
    elem.setNom("Tirso de Molina");
    elem.setVertice(2);
    L.push_front(elem);
    G.incluirAdyacentes(8,L);

    G.incluirVertice(9, "Embajadores");
    // Nodos adyacentes al vertice Embajadores: Lavapies
    L.listaVacia();
    elem.setNom("Lavapies");
    elem.setVertice(3);
    L.push_front(elem);
    G.incluirAdyacentes(9,L);

    G.incluirVertice(10, "Alonso Martines");
    // Nodos adyacentes al vertice Embajadores: Lavapies
    L.listaVacia();
    elem.setNom("Chueca");
    elem.setVertice(7);
    L.push_front(elem);
    G.incluirAdyacentes(10,L);

    return G;
}
void mostrarConexionesDirectasGrafo(const Grafo &g){
    for(auto elem:g.getCArcos()){
        cout<<"Estacion: "<<elem.getnombre()<<" = "<<g.contarConexionesDirectas(elem.getnombre())<<" Conexiones Directas"<<endl;
    }
}

int main()
{
    Grafo miGrafo;

    miGrafo = inicializarGrafo();

    miGrafo.mostrarGrafo();

    cout<<"Estacion: SOl = "<<miGrafo.contarConexionesDirectas("SOL")<<" Conexiones Directas"<<endl;
    cout<<"Estacion: Gran Via = "<<miGrafo.contarConexionesDirectas("Gran Via")<<" Conexiones Directas"<<endl;
    cout<<"Estacion: Alonso Martines = "<<miGrafo.contarConexionesDirectas("Alonso Martines")<<" Conexiones Directas"<<endl;

    cout<<endl;
    mostrarConexionesDirectasGrafo(miGrafo);

    cout << "\n\n\t";
    return 0;
}


//------------------Clase CDato
const string &CDato::getNom() const {
    return nombre;
}

void CDato::setNom(const string &newN) {
    nombre = newN;
}

int CDato::getVertice() const{
    return vertice;
}
void CDato::setVertice(int newV){
    vertice = newV;
}

//--------------------Clase Nodo
Nodo::Nodo() {
    dato.setVertice(0);
}

const CDato &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const CDato &newDato) {
    dato = newDato;
}

shared_ptr<Nodo> Nodo::getNext() const {
    return next;
}

void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

//-------------------Clase Lista
const shared_ptr<Nodo> &Lista::getFirst() const {
    return first;
}

void Lista::setFirst(const shared_ptr<Nodo> &newFirst) {
    first = newFirst;
}


bool Lista::empty() const {
    return (first == nullptr);
}

void Lista::listaVacia() {
    first = nullptr;
}


// Inserta un elemento al principio de la lista
void Lista::push_front(const CDato& dato) {
    shared_ptr<Nodo> aux = make_shared<Nodo>();
    aux->setDato(dato);
    aux->setNext(first);
    first = aux;
}


// Devuelve el dato del primer elemento de la lista
const CDato & Lista::front() const {
    if(!empty())
        return first->getDato();
    else
        throw std::runtime_error("La lista esta vacia");
}


// Muestra el contenido de los nodos de la lista
void Lista::mostrarLista() const {
    shared_ptr<Nodo> aux = first;

    while(aux != nullptr) {
        cout <<"\n\t\tnodo:"<< aux->getDato().getVertice();
        aux = aux->getNext();
    }
}


int Lista::contarLista() const {
    shared_ptr<Nodo> aux = first;
    int n{0};

    while(aux != nullptr) {
        n++;
        aux = aux->getNext();
    }

    return n;
}

//--------------------Clase VerticeG
const string &VerticeG::getnombre() const {
    return nombre;
}

void VerticeG::setnombre(const string &newnombre) {
    nombre = newnombre;
}

shared_ptr<Nodo> VerticeG::getNext() const {
    return next;
}

void VerticeG::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

//--------------------Clase Grafo
// Constructor para inicializar el grafo
const array<VerticeG, nMax> &Grafo::getCArcos() const
{
    return cArcos;
}

Grafo::Grafo() {
    VerticeG inicial;

    for(int i{0};i<nMax;i++) {
        cArcos.at(i)=inicial;
    }
}

// Metodo para incluir el nombre del vertice en el grafo
void Grafo::incluirVertice (int v, string const &l) {
    cArcos.at(v).setnombre(l);
}

// Metodo para incluir la lista de vertices adyacente de un
// determinado vertice del grafo
void Grafo::incluirAdyacentes (int v, Lista const &ady) {
    cArcos.at(v).setNext(ady.getFirst());
}


void Grafo::mostrarGrafo() const{
    for (auto elem:cArcos){
        cout<<"Vertice: "<<elem.getnombre()<<endl;
        shared_ptr<Nodo> aux = {elem.getNext()};
        while (aux != nullptr) {
            cout<<"Adyacente: "<<aux->getDato().getNom()<<endl;
            aux = aux->getNext();
        }
        cout<<endl;
    }
}

int Grafo::contarConexionesDirectas(const string &estacion) const{
    int contador{0};
    for(auto elem:cArcos){
        if(elem.getnombre() == estacion){

            shared_ptr<Nodo> aux = {elem.getNext()};
            while (aux!=nullptr) {
                contador++;
                aux= aux->getNext();
            }
            break;
        }
    }
    return contador;
}

