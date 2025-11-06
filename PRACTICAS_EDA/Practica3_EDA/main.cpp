// Practica N3 de EDA - Manejo del TAD COLA DINAMICA

// Participante 1: Daniel Braun Sandino
// Participante 2: Daniel Marcos Gonzalez


#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Estructuras para ajustar la definiciÃ³n de los datos del contenedor dado a los elementos de la Pila
struct Registro{
    int num;
    string fecha;
};

struct Paquete {
    Registro local;
    char estado;
    double peso;
};

// Clase Nodo
class Nodo {
private:
    Paquete dato;
    shared_ptr<Nodo> next;
public:
    Nodo():next(nullptr){}
    Nodo(const Paquete &d, const shared_ptr<Nodo> &ptr):dato(d),next(ptr){}
    ~Nodo(){}

    const Paquete &getDato() const;
    void setDato(const Paquete &newDato);
    const shared_ptr<Nodo> &getNext() const;
    void setNext(const shared_ptr<Nodo> &newNext);
};

class Cola {
public:
    Cola():front(nullptr), end(nullptr){}
    Cola(const Cola &Q);
    ~Cola();

    bool emptyQ() const;
    void pushQ(const Paquete &dato);
    void popQ();
    const Paquete &firstQ() const;

    //MÉTODO MOSTRAR DATOS DE LA COLA
    void mostrarDatos() const{
        shared_ptr<Nodo>aux{front};
        while (aux!=nullptr) {
            cout<<"Numero: "<<aux->getDato().local.num<<" ";
            cout<<"Fecha: "<<aux->getDato().local.fecha<<" ";
            cout<<"Estado: "<<aux->getDato().estado<<" ";
            cout<<"Peso: "<<aux->getDato().peso<<" "<<endl;

            aux = aux->getNext();
        }
    }

    //METODO ENVIAR URGENTE UN PAQUETE AL PRINCIPIO (FRONT) DE LA COLA
    void enviarUrgenteCola(const Paquete &p){
        if(comprobarExisteCola(p)){
            cout<<"EL PAQUETE YA EXISTE EN LA COLA"<<endl;
        }else{


            shared_ptr<Nodo> Pnew = make_shared<Nodo>(p,front);

            front = Pnew;
        }
    }

    //METODO PARA ELIMINAR UN ELEMENTO (PAQUETE) DE LA COLA
    void eliminarElemCola(Paquete const &p){
        shared_ptr<Nodo> auxF{front}, auxF2{front};

        if(auxF->getDato().local.num == p.local.num && auxF->getDato().local.fecha == p.local.fecha){
            front = auxF->getNext();
            auxF->setNext(nullptr);
        }else{
            auxF2 = auxF2->getNext();
            while (auxF2 != nullptr) {
                if(auxF2->getDato().local.num == p.local.num && auxF2->getDato().local.fecha == p.local.fecha){
                    auxF->setNext(auxF2->getNext());
                    auxF2->setNext(nullptr);
                }
                auxF = auxF2;
                auxF2 = auxF2->getNext();
            }
        }


    }

private:
    shared_ptr<Nodo> front, end;

    //DEVOLVER TRUE SI EXISTE UN PAQUETE EN LA COLA
    bool comprobarExisteCola(const Paquete &p){
        shared_ptr<Nodo>aux{front};

        while(aux != nullptr){
            if(aux->getDato().local.num == p.local.num && aux->getDato().local.fecha == p.local.fecha){
                return true;
            }
            aux = aux->getNext();
        }

        return false;
    }
};

//-------------------------------------------------------------------------------------------------
//FUNCION GENERAL

void cargarPaquetes(const vector<Paquete> &pedidosRegistrados, Cola &C){
    for(Paquete p : pedidosRegistrados){
        C.pushQ(p);
    }
}

int procesarPaquetesAnulados(Cola &C){
    Cola Caux(C);
    int suma{0};

    while (!Caux.emptyQ()){
        if(Caux.firstQ().estado == 'A'){
            suma += Caux.firstQ().peso;
            C.eliminarElemCola(Caux.firstQ());

        }
        Caux.popQ();
    }

    return suma;
}


// PROGRAMA PRINCIPAL
int main(){
    Cola C;

    cout << "\n\n\tPROGRAMA PRINCIPAL\n";

    vector<Paquete> pedidosRegistrados{
                                       {{11, "01022025"}, 'A', 50.0}, {{1, "01012025"}, 'A', 20.0}, {{12, "11012025"}, 'L', 25.0},
                                       {{41, "01032025"}, 'L', 60.0}, {{8, "31012025"}, 'A', 40.0}, {{21, "21022025"}, 'E', 15.0},
                                       {{24, "15012025"}, 'E', 30.0}, {{52, "05022025"}, 'L', 35.0}, {{3, "03032025"}, 'E', 50.0},
                                       {{26, "10102025"}, 'A', 15.0}, {{32, "07012025"}, 'L', 10.0}, {{48, "25022025"}, 'A', 20.0}};


    //CARGAR PAQUETES EN COLA
    cargarPaquetes(pedidosRegistrados,C);

    //MOSTRAR DATOS DE PAQUETE EN COLA
    C.mostrarDatos();

    cout<<endl;

    //INCORPORAR PEDIDO YA EXISTENTE CON URGENCIA
    C.enviarUrgenteCola({{11, "01022025"}, 'A', 50.0});

    //INCORPORAR PEDIDO NO EXISTENTE CON URGENCIA
    C.enviarUrgenteCola({{99, "01032025"}, 'L', 60.0});

    //MOSTRAR DATOS DESPUES DE AÑADIR PAQUETE DE URGENCIA
    C.mostrarDatos();

    cout<<endl;

    //SUMA DE PESOS DE PAQUETES PROCESADOS DE ESTADO 'A'
    cout<<"LA SUMA DE LOS PESOS PROCESADOS ES: "<<procesarPaquetesAnulados(C)<<endl;

    //MOSTRAR DATOS DE COLA DESPUES DE ELIMINAR LOS PAQUETES DE ESTADO 'A'
    C.mostrarDatos();

    cout<<endl;


    cout << "\n\n\t";
    return 0;
}

//================================================
// IMPLENTACIÃ“N DE LOS MÃ‰TODOS DE LA CLASE NODO
//================================================
void Nodo::setNext(const shared_ptr<Nodo> &newNext) {
    next = newNext;
}

const Paquete &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const Paquete &newDato) {
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getNext() const {
    return next;
}

//================================================
// IMPLENTACIÃ“N DE LOS MÃ‰TODOS DE LA CLASE COLA
//================================================

// Determina si la cola esta vaciÂ­a o no
bool Cola::emptyQ() const  {
    return (front == nullptr && end == nullptr);
}

// Inserta un elemento en la posicion final de la cola
void Cola::pushQ(const Paquete &dato) {
    shared_ptr<Nodo> ptraux = make_shared<Nodo>(Nodo(dato, nullptr));

    if (this->emptyQ()) {
        front = ptraux;
    }
    else  {
        end->setNext(ptraux);
    }
    // El puntero final de la cola debe seÃ±alar siempre al elemento incluido
    end = ptraux;
}


// Elimina un elemento de la primera posicion de la cola
void Cola::popQ()  {
    front = front->getNext();
    if (front == nullptr) {
        end = nullptr;  // La cola queda vaciÂ­a
    }
}

// Devuelve el elemento de la primera posicion de la cola
const Paquete &Cola::firstQ() const {
    return (front->getDato());
}

// Constructor Copia
Cola::Cola(const Cola &Q){
    if (Q.emptyQ()) {
        front = nullptr;
        end = nullptr;
    }
    else {
        shared_ptr<Nodo> ptrNew , pQ{Q.front};
        ptrNew = make_shared<Nodo>();
        *ptrNew = Nodo(Q.front->getDato(), nullptr);

        end = ptrNew;
        front = ptrNew;

        pQ=pQ->getNext();

        while (pQ!=nullptr){
            ptrNew = make_shared<Nodo>();
            *ptrNew = Nodo(pQ->getDato(), nullptr);
            end->setNext(ptrNew);
            end=ptrNew;
            pQ=pQ->getNext();
        }
    }
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


