// FICHERO INICIAL PARA LA PRÃCTICA nÂº4 DE EDA

// Participante nÂº1
// Participante nÂº2

#include <iostream>
#include <vector>
#include <memory>
#include <array>

using namespace std;

// TAD LISTAS DINAMICAS

#include <iostream>
#include <memory>

using namespace std;

//---------------Clase Examen
class Examen {
private:
    string nom;
    string fecha;
    int paginas;
    double nota;
public:
    Examen():paginas(0), nota(0.0){}
    Examen(const string &_na, const string &_f, int _p, double _n):
        nom(_na),  fecha(_f),paginas(_p), nota(_n){}

    const string &getNom() const;
    void setNom(const string &newNom);
    const string &getFecha() const;
    void setFecha(const string &newFecha);
    int getPaginas() const;
    void setPaginas(int newPaginas);
    double getNota() const;
    void setNota(double newNota);
};

// CLASE Pila
class Stack {
public:
    Stack():front(-1){}
    Stack(const Examen &_e):front(0){
        datos.push_back(_e);
    }

    bool empty() const;

    void push(const Examen &dato);
    void pop();
    const Examen &top() const;

private:
    vector<Examen> datos;
    int front;
};


//---------------Clase Nodo
class Nodo {
private:
    Examen dato;
    shared_ptr<Nodo> next = nullptr;
public:
    Nodo():next(nullptr){}
    Nodo(const Examen &d, const shared_ptr<Nodo> &ptr):dato(d),next(ptr){}
    Nodo(const Examen &d):dato(d){}
    ~Nodo(){}


    const Examen &getDato() const;
    void setDato(const Examen &newDato);
    const shared_ptr<Nodo> &getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

//---------------Clase Lista
class Lista {
private:
    shared_ptr<Nodo> first;
public:
    Lista():first(nullptr){}
    Lista(const Lista &L);

    ~Lista();

    bool empty() const;

    void push_front(const Examen&);
    const Examen &front() const;
    const Examen &back() const;
    void pop_front();
    void pop_back();
    void push_back(const Examen &e);

    const shared_ptr<Nodo> &getFirst() const;
    void setFirst(const shared_ptr<Nodo> &newFirst);

    //METODO PARA INSERTAR ELEMENTOS EN LA LISTA ORDENADOS
    void insertarElemListaOrd(const Examen &E){
        shared_ptr<Nodo> ptr = make_shared<Nodo>(E,nullptr);
        shared_ptr<Nodo> pAux{first}, pAnt;

        if (first == nullptr) {
            first = ptr;
        }
        else if (E.getNom() < first->getDato().getNom()) {
            push_front(E);
        }
        else {
            while (pAux != nullptr && pAux->getDato().getNom() < E.getNom()) {
                pAnt = pAux;
                pAux = pAux->getNext();
            }
            ptr->setNext(pAux);
            pAnt->setNext(ptr);
        }
    }


    //METODO PARA MOSTRAR LOS DATOS DE LA LISTA
    void mostrarLista()const {
        shared_ptr<Nodo> pAux{first};

        while(pAux != nullptr){
            cout << "Nombre y Apellido: "<<pAux->getDato().getNom() << endl;
            cout << "Fecha: "<<pAux->getDato().getFecha() << endl;
            cout << "Paginas entregadas: "<<pAux->getDato().getPaginas() << endl;
            cout << "Nota: "<<pAux->getDato().getNota() << endl;
            cout << "---------------------------" << endl;
            pAux = pAux->getNext();
        }
    }

    //CALCULAR EL TAMAÑO DE LA LISTA (EXAMENES ALMACENADOS EN LA LISTA)
    int sizeLista() const {
        int contador = 0;
        shared_ptr<Nodo> pAux = first;

        while (pAux != nullptr) {
            contador++;
            pAux = pAux->getNext();
        }

        return contador;
    }


};

//FUNCION GENERAL PARA CREAR LISTA EXAMEN ORDENADA A PARTIR DE LOS DATOS DE LA PILA
Lista crearListaExamOrd(Stack &S){
    Lista L;

    while(!S.empty()){
        L.insertarElemListaOrd(S.top());
        S.pop();    //La pila se destruye
    }

    return L;
}

//FUNCION GENERAL PARA CALCULAR EL PORCENTAJE DE NP DE LA LISTA DE EXAMENES
float calcularPorcentajeNP(const Lista &L) {
    float total = L.sizeLista();
    if (total == 0){
        return 0.0;
    }

    float npCount = 0;
    shared_ptr<Nodo> pAux{L.getFirst()};

    while (pAux != nullptr) {
        if (pAux->getDato().getNota() == 0.0) //Si la nota es 0 damos por echo que es NP
            npCount++;
        pAux = pAux->getNext();
    }

    float media = (npCount / total) * 100;  //(numero de NP / total de examenes) * 100

    return media;
}


int main(){
    array<Examen,10> examenEDA{{{"Ana Perez", "28042025", 5, 7.0},
                                 {"Paula Lopez", "28042025", 3, 8.5},
                                 {"Carlos Arias", "28042025", 6, 5.5},
                                 {"Marcos Sanchez", "28042025", 5, 0.0},    //Cambio a 0.0
                                 {"Mara Lis", "28042025", 4, 6.5},
                                 {"Andres Martinez", "28042025", 6, 0.0},   //Cambio a 0.0
                                 {"Luis Velasco", "28042025", 5, 4.0},
                                 {"Nuria Gonzalez", "28042025", 7, 8.0},
                                 {"Carla Cuesta", "28042025", 3, 7.5},
                                 {"Eloy Rodriguez", "28042025", 5, 8.5}}};

    Stack pilaExamenes;

    for(const Examen &unExamen:examenEDA){
        pilaExamenes.push(unExamen);
    }

    Lista L = crearListaExamOrd(pilaExamenes);

    //CHECKEO PARA VER SI LA LISTA TIENE DATOS O NO
    if(L.empty()){
        cout<<"La lista esta vacia."<<endl;
    }else{
        L.mostrarLista();
    }

    cout<<endl;

    //PORCENTAJE DE NP EN LA LISTA DE EXAMENES
    //CHECKEO PARA VER SI LA LISTA TIENE DATOS O NO
    if(L.empty()){
        cout<<"La lista esta vacia."<<endl;
    }else{
        cout<<"El porcentaje de NP de la lista es "<<calcularPorcentajeNP(L)<<"%"<<endl;
    }


    cout << "\n\n\tFIN PROCESO\n\n";

    return 0;
}


//------------------Clase Examen
const string &Examen::getNom() const{
    return nom;
}

void Examen::setNom(const string &newNom){
    nom = newNom;
}

const string &Examen::getFecha() const{
    return fecha;
}

void Examen::setFecha(const string &newFecha){
    nom = newFecha;
}

int Examen::getPaginas() const{
    return paginas;
}

void Examen::setPaginas(int newPaginas){
    if (newPaginas<=0){
        throw string("\n\ERROR, el valor de las pÃ¡ginas debe ser positivo.");
    }
    paginas = newPaginas;
}

double Examen::getNota() const{
    return nota;
}

void Examen::setNota(double newNota){
    if (newNota<0 || newNota >10){
        throw string("\n\ERROR, el valor de nota no es valido.");
    }
    nota = newNota;
}


// CLASE Pila
// Inserta un elemento en la cima de la pila
void Stack::push(const Examen &dato) {
    front++;
    datos.push_back(dato);
}

// Elimina un elemento en la cima de la pila
void Stack::pop()  {
    front--;
    datos.pop_back();
}

// Devuelve el elemento cima de la pila
const Examen &Stack::top() const {
    return (datos.back());
}

// Determina si la pila estÃ¡ vacÃ­a o no
bool Stack::empty() const  {
    return (front == -1);
}


//--------------------Clase Nodo
const Examen &Nodo::getDato() const{
    return dato;
}

void Nodo::setDato(const Examen &newDato){
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getNext() const{
    return next;
}

void Nodo::setNext(const shared_ptr<Nodo> &newNext){
    next = newNext;
}


//-------------------Clase Lista

// Constructor Copia Lista
Lista::Lista(const Lista &L){
    shared_ptr<Nodo> pL{L.first}, pN, pant;

    if (L.first == nullptr){
        first = nullptr;
    }
    else{
        pN = make_shared<Nodo>();
        *pN=Nodo(L.first->getDato(),nullptr);
        first = pN;

        pL = pL->getNext();

        while(pL != nullptr){
            pant = pN;

            pN = make_shared<Nodo>();
            pN->setDato(pL->getDato());
            pN->setNext(nullptr);

            pant->setNext(pN);

            pL = pL->getNext();
        }
    }

}

const shared_ptr<Nodo> &Lista::getFirst() const{
    return first;
}

void Lista::setFirst(const shared_ptr<Nodo> &newFirst){
    first = newFirst;
}

// Determina si la lista estÃ¡ vacÃ­a o no
bool Lista::empty() const{
    return (first == nullptr);
}

// Inserta un elemento al principio de la lista
void Lista::push_front(const Examen& dato) {
    shared_ptr<Nodo> ptr;
    ptr = make_shared<Nodo>();
    *ptr = Nodo(dato, nullptr);

    if (empty()) {
        first = ptr;  // Ahora solo hay un elemento en la lista
    }
    else {
        ptr->setNext(first);
        first = ptr;
    }
}


// Devuelve el dato del primer elemento de la lista
const Examen &Lista::front() const{
    return first->getDato();
}


// Elimina el primer elemento de la lista
void Lista::pop_front() {
    first = first->getNext();
}


// Elimina el Ãºltimo elemento de la lista
void Lista::pop_back(){

    if (first->getNext()==nullptr){
        first=nullptr;
    }
    else{
        shared_ptr<Nodo> pAux{first}, pAnt;

        while(pAux->getNext()!=nullptr){
            pAnt = pAux;
            pAux = pAux->getNext();
        }
        pAnt->setNext(nullptr);
    }
}


// AÃ±adir un elemento al final de la lista
void Lista::push_back(const Examen &e){
    shared_ptr<Nodo> pAux{first}, pAnt, pNew;

    pNew = make_shared<Nodo>();
    *pNew = Nodo(e, nullptr);

    if (pAux == nullptr){
        first = pNew;
    }
    else{
        while(pAux!=nullptr){
            pAnt = pAux;
            pAux = pAux->getNext();
        }
        pAnt->setNext(pNew);
    }
}


// Destructor
Lista::~Lista() {
    while (first != nullptr){
        first = first->getNext();
    }
}



