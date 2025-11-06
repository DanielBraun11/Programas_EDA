#include <iostream>
#include <string>
#include <array>
#include <set>
#include <memory>

// Numero de nodos del Grafo
#define nMax 5

using namespace std;

//---------------Clase CDato
class CDato {
private:
    int vertice;
public:
    CDato():vertice(0){}

    int getVertice() const;
    void setVertice(int newV);
};

//---------------Clase Nodo
class Nodo {
private:
    CDato dato;
    shared_ptr<Nodo> next = nullptr;
public:
    Nodo();
    Nodo(CDato const &d): dato(d){}

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

    void incluirVertice (int v, string const &l);
    void incluirAdyacentes (int v, Lista const &ady);

    void mostrarGrafo() const;

    void profundidadRec (set<int> &visitados, int V);
    void recorrerProfundidad (int V);
};

int main()
{
    Grafo G;
    Lista L;
    CDato elem;

    //  CREACION DEL GRAFO CON 5 NODOS Y SUS CORRESPONDIENTES NODOS ADYACENTES
    G.incluirVertice(0, "Nodo 0");
    // Nodos adyacentes al vertice Nodo 0: 2 y 3
    elem.setVertice(3);
    L.push_front(elem);
    elem.setVertice(2);
    L.push_front(elem);
    G.incluirAdyacentes(0,L);

    G.incluirVertice(1, "Nodo 1");
    // Nodos adyacentes al vertice Nodo 1: 4 2 y 3
    L.listaVacia();
    elem.setVertice(3);
    L.push_front(elem);
    elem.setVertice(4);
    L.push_front(elem);
    G.incluirAdyacentes(1,L);

    G.incluirVertice(2, "Nodo 2");
    // Nodos adyacentes al vertice Nodo 2: 3 4 y 0
    L.listaVacia();
    elem.setVertice(3);
    L.push_front(elem);
    elem.setVertice(4);
    L.push_front(elem);
    elem.setVertice(0);
    L.push_front(elem);
    G.incluirAdyacentes(2,L);

    G.incluirVertice(3, "Nodo 3");
    // Nodos adyacentes al vertice Nodo 3: 1 0 2 y 4
    L.listaVacia();
    elem.setVertice(1);
    L.push_front(elem);
    elem.setVertice(0);
    L.push_front(elem);
    elem.setVertice(2);
    L.push_front(elem);
    elem.setVertice(4);
    L.push_front(elem);
    G.incluirAdyacentes(3,L);

    G.incluirVertice(4, "Nodo 4");
    // Nodos adyacentes al vertice Nodo 4: 2 1 y 3
    L.listaVacia();
    elem.setVertice(2);
    L.push_front(elem);
    elem.setVertice(1);
    L.push_front(elem);
    elem.setVertice(3);
    L.push_front(elem);
    G.incluirAdyacentes(4,L);

    //  MOSTRAR EL CONTENIDO DEL GRAFO
    G.mostrarGrafo();

    //  RECORRIDO DEL GRAFO PARTIENDO DE UN DETERMINADO Nodo
    cout << "\n\n\tRecorrido desde Nodo 3: ";
    G.recorrerProfundidad (3);

    cout << "\n\n\t";
    return 0;
}


//------------------Clase CDato
int CDato::getVertice() const {
    return vertice;
}

void CDato::setVertice(int newV) {
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
        throw std::runtime_error("La lista estÃ¡ vacÃ­a.");
}


// Muestra el contenido de los nodos de la lista
void Lista::mostrarLista() const {
    shared_ptr<Nodo> aux = first;

    while(aux != nullptr) {
        cout <<"\n\t\tnodo:"<< aux->getDato().getVertice();
        aux = aux->getNext();
    }
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
Grafo::Grafo() {
    VerticeG inicializar;

    for(int i{0};i<nMax;i++) {
        cArcos.at(i)=inicializar;
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

// Mostrar los nodos del grafo, cada vÃ©rtice (nombre del nombre)
// con sus adyacentes (vÃ©rtice y distancia)
void Grafo::mostrarGrafo() const {
    Lista L;
    for (int i{0}; i < nMax; i++) {
        cout <<"Nodo "<<i<<": "<< cArcos.at(i).getnombre();
        cout<<"\n\tAdyacentes:";

        L.setFirst(cArcos.at(i).getNext());
        L.mostrarLista();
        cout << endl;
    }
}


// Realiza el recorrido del grafo partiendo de un determinado nodo
// y muestra en quÃ© orden se visitan los nodos
void Grafo::profundidadRec (set<int> &visitados, int V) {
    if (visitados.find(V) == visitados.end()) {
        visitados.insert(V);
        cout << "\n\n\tEl nodo "<< visitados.size()
             << " visitado es " << cArcos.at(V).getnombre();

        shared_ptr<Nodo> aux = cArcos.at(V).getNext();
        while(aux != nullptr) {
            profundidadRec(visitados, aux->getDato().getVertice());
            aux=aux->getNext();
        }
    }
}

// MÃ©todo que llama al proceso recursivo para recorrer el grafo partiendo
// de un determinado vertice
void Grafo::recorrerProfundidad	(int V) {
    set<int> visitados;
    profundidadRec(visitados, V);
}


