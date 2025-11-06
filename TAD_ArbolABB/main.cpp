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
public:
    CDato dato;
    shared_ptr<Nodo> hizq;
    shared_ptr<Nodo> hdch;
public:
    Nodo(){hizq = nullptr; hdch = nullptr;}
    Nodo(const CDato& d):dato{d}{
        hizq = nullptr; hdch = nullptr;}

    const CDato &getDato() const;
    void setDato(const CDato &newDato);

    const shared_ptr<Nodo> &getHizq() const;
    void setHizq(const shared_ptr<Nodo> &newHizq);

    const shared_ptr<Nodo> &getHdch() const;
    void setHdch(const shared_ptr<Nodo> &newHdch);

    void procesarNodo () const;
};


//---------------Clase Arbol Binario Busqueda

class Arbol {
private:
    shared_ptr<Nodo> raiz;
public:
    Arbol():raiz(nullptr){}
    Arbol(const CDato &dato);

    bool empty() const;

    void addHizq(const Arbol &Ai);
    void addHdch(const Arbol &Ad);

    void construirArbol (const Arbol &Ai, const Arbol &Ad,
                        const CDato &dato);

    const shared_ptr<Nodo> &getRaiz() const;
    void setRaiz(const shared_ptr<Nodo> &newRaiz);

    shared_ptr<Nodo> busquedaNodoABBRec(shared_ptr<Nodo> A, const CDato &dato) const;
    shared_ptr<Nodo> buscarNodoABBRec(const CDato &dato) const;

    void insertadoNodoABBRec(shared_ptr<Nodo> &A, const CDato &dato);
    void insertarNodoABBRec(const CDato &dato);

    void InOrden(shared_ptr<Nodo> A) const;
    void recorrerInOrden() const;

    void eliminarNodoABB(const CDato &dato);

    const CDato &elMAYORdeMENORES(const shared_ptr<Nodo> &A);
    const CDato &elMAYORdeMENORESIter (shared_ptr<Nodo> A);
};


int main()
{   CDato dato;
    int n;
    Arbol A;

    do {
        cout << "\n\tIntroduzca un numero (negativo para terminar): ";
        cin >> n;
        dato.setN(n);
        if (n > 0) {
            A.insertarNodoABBRec(dato);
        }
    } while (n > 0);

    cout << "\n\n\tRecorrido InOrden\n";
    A.recorrerInOrden();

    if (A.buscarNodoABBRec(20)!=nullptr){
        cout << "\n\n\tEl nodo " << 20 << " Existe.";
        cout << "\n\tBORRAMOS EL 20";
        A.eliminarNodoABB(20);
    }
    else {
        cout << "\n\n\tEl nodo " << 20 << " No existe.";
    }


    if (A.buscarNodoABBRec(25)!=nullptr){
        cout << "\n\n\tEl nodo " << 25 << " Existe.";
        cout << "\n\tBORRAMOS EL 25";
        A.eliminarNodoABB(25);
    }
    else {
        cout << "\n\n\tEl nodo " << 25 << " No existe.";
    }


    if (A.buscarNodoABBRec(45)!=nullptr){
        cout << "\n\n\tEl nodo " << 45 << " Existe.";
        cout << "\n\tBORRAMOS EL 45";
        A.eliminarNodoABB(45);
    }
    else {
        cout << "\n\n\tEl nodo " << 45 << " No existe.";
    }

    cout << "\n\n\tRecorrido InOrden\n";
    A.recorrerInOrden();

    cout << "\n\n\t";
    return 0;
}




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


//-------------------Clase Arbol
bool Arbol::empty() const {
    return (raiz == nullptr);
}

const shared_ptr<Nodo> &Arbol::getRaiz() const  {
    return raiz;
}

void Arbol::setRaiz(const shared_ptr<Nodo> &newRaiz)  {
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

void Arbol::construirArbol (const Arbol &Ai, const Arbol &Ad, const CDato &dato) {
    raiz = make_shared<Nodo>(Nodo{dato});
    raiz->setHizq(Ai.raiz);
    raiz->setHdch(Ad.raiz);
}

shared_ptr<Nodo> Arbol::busquedaNodoABBRec(shared_ptr<Nodo> A, const CDato &dato) const {
    if (A != nullptr) {
        if (A->getDato().getN() > dato.getN()) {
            A = busquedaNodoABBRec(A->getHizq(), dato);
        }
        else if (A->getDato().getN() < dato.getN()) {
            A = busquedaNodoABBRec(A->getHdch(), dato);
        }
    }

    return A;
}

shared_ptr<Nodo> Arbol::buscarNodoABBRec(const CDato &dato) const {
    if (!empty()) {
        return busquedaNodoABBRec(raiz, dato);
    }
    else{
        return nullptr;
    }
}

//--------------INSERTAR EN ORDEN RECURSIVO

void Arbol::insertadoNodoABBRec(shared_ptr<Nodo> &A, const CDato &dato)   {
    if (A == nullptr) {
        //        A = make_shared<Nodo>(Nodo{dato});
        A = make_shared<Nodo>();
        *A = Nodo(dato);
    }
    else {
        if (A->getDato().getN() > dato.getN()) {
            insertadoNodoABBRec(A->hizq, dato);
        }
        else if (A->getDato().getN() <= dato.getN()) {
            insertadoNodoABBRec(A->hdch, dato);
        }
    }
}

void Arbol::insertarNodoABBRec(const CDato &dato)  {
    insertadoNodoABBRec(raiz, dato);
}

// Recorrido InOrden compacto, sin varibles auxiliares
void Arbol::InOrden(shared_ptr<Nodo> A) const {
    if (A != nullptr) {
        InOrden (A->getHizq());		// I
        A->procesarNodo();             // R
        InOrden (A->getHdch());        // D
    }
}

void Arbol::recorrerInOrden() const {
    if (!empty()) {
        InOrden (raiz);
    }
}

void Arbol::eliminarNodoABB(const CDato &dato) {
    shared_ptr<Nodo> A{raiz};
    shared_ptr<Nodo> Apadre{nullptr};
    bool enc {false};

    // Buscamos el nodo que se quiere borrar y
    // se guarda la referencia del nodo padre en Apadre
    while ((A != nullptr) && !enc) {
        if (A->dato.getN() == dato.getN()) {
            enc = true;
        }
        else {
            Apadre = A;
            if (dato.getN() < A->dato.getN()) {
                A = A->hizq;
            }
            else {
                A = A->hdch;
            }
        }
    }

    // El proceso continua siempre que se encuentre el dato
    if (A != nullptr) {

        // El nodo tiene los dos hijos,
        // luego se sustituye por el mayor de los menores
        if (A->hizq != nullptr && A->hdch != nullptr) {
            //A->dato = elMAYORdeMENORESIter(A->hizq);
            A->dato = elMAYORdeMENORES(A->hizq);

            // Se busca el nodo con el mayor de los menores
            Apadre = A;
            A = A->hizq;
            while (A->hdch != nullptr) {
                Apadre = A;
                A = A->hdch;
            }
        }

        // El nodo No tiene los dos descendiente
        // Tambien incluye el borrado del mayor de menores
        shared_ptr<Nodo> Anext;
        if (A->hizq != nullptr) {
            cout << "\n\tNext es hijo Izq";
            Anext = A->hizq;
        }
        else {
            cout << "\n\tNext es hijo Dch";
            Anext = A->hdch;
        }

        // Se actualiza el nodo padre del nodo borrado
        if (Apadre == nullptr) {
            // Cuando se borra el nodo raiz del Arbol
            raiz = Anext;
        }
        else {
            if (Apadre->hizq == A) {
                Apadre->hizq = Anext;
            }
            else {
                Apadre->hdch = Anext;
            }
        }
    }
}


const CDato &Arbol::elMAYORdeMENORES(const shared_ptr<Nodo> &A) {
    if (A->hdch != nullptr) {
        return elMAYORdeMENORES(A->hdch);
    }
    else {
        return A->dato;
    }
}


// Busca el menor de los nodos mayores iterativamente.
const CDato &Arbol::elMAYORdeMENORESIter (shared_ptr<Nodo> A) {
    while (A->hdch != nullptr) {
        // Bajamos por la rama derecha
        A = A->hdch;
    }
    return A->dato;
}

