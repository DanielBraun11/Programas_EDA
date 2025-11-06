#include <iostream>
#include <array>

using namespace std;

#define DIM 10  // Dimension del array para almacenar datos

struct TipoDato {
    int num;
};


// CLASE Cola
class Cola {
public:
    Cola():front(DIM-1), end(DIM-1){}
    Cola(const Cola &Q):front(Q.front), end(Q.end), datos(Q.datos){}

    // Determina si la cola esta vacia o no
    bool empty() const  {
        return (front == end);
    }

    // Determina si la cola esta llena o no
    bool full() const  {
        return (posSiguiente(end) == front);
    }

    // Determina la posicion siguiente a una dada
    int posSiguiente (int p)const{
        int size = datos.size();
        if (p < size-1) {
            return ++p;
        }
        else {
            return 0;
        }
    }

    // Inserta un elemento en la cola
    void push(TipoDato const &e) {
        if (!full()){
            end = posSiguiente(end);
            datos.at(end)=e;
        }
    }

    // Elimina el primer elemento de la cola
    void pop()  {
        front = posSiguiente(front);
    }

    // Devuelve el primer elemento de la cola
    const TipoDato &first() const  {
        return datos.at(posSiguiente(front));
    }

    // Determina el numero de elementos de la cola
    int sizeCola() const{
        if (front == end){
            return 0;
        }
        else{
            if (posSiguiente(end) == front){
                return datos.size()-1;
            }
            else{
                if (front < end){
                    return end-front;
                }
                else{
                    return (end) + (datos.size()-front);
                }
            }
        }
    }

    // Muestra los datos de la cola
    void mostrarCola() const{
        int i{front};
        while( i != end) {
            i = posSiguiente(i);
            cout << " " << datos.at(i).num;
        }
    }

    // Determina el elemento mayor de la cola
    TipoDato mayorCola() const{
        int i{front};
        TipoDato mayor{-1}; // Siver el -1 porque no hay valores negativos en la cola
        while( i != end) {
            i = posSiguiente(i);
            if(mayor.num < datos.at(i).num){
                mayor = datos.at(i);
            }
        }

        return mayor;
    }

    // Determina si existe un elemento determinado en la cola
    bool existeEnCola(TipoDato const &e) const{
        int i{front};
        bool esta{false}; // Siver el -1 porque no hay valores negativos en la cola
        while( i != end  && !esta) {
            i = posSiguiente(i);
            if(e.num == datos.at(i).num){
                esta = true;
            }
        }

        return esta;
    }

    // Determina las veces que un elemento determinado esta en la cola
    int vecesEnCola(TipoDato const &e) const{
        int i{front};
        int veces{0}; // Siver el -1 porque no hay valores negativos en la cola
        while( i != end) {
            i = posSiguiente(i);
            if(e.num == datos.at(i).num){
                veces++;
            }
        }

        return veces;
    }
private:
    int front, end;
    array<TipoDato, DIM> datos;
};

// PROTOTIPOS DE FUNCIONES

// Funcion para escribir el menu en pantalla
int menu () {
    const int OPCIONES{5};
    string opcion;
    int miOpcion;

    do {
        cout << "\n\n\t1. Introducir elemento en la Cola.";
        cout << "\n\n\t2. Mostrar todos los datos de la Cola.";
        cout << "\n\n\t3. Buscar elemento Mayor de la Cola.";
        cout << "\n\n\t4. Buscar un elemento en la Cola.";
        cout << "\n\n\t5. Numero de veces de un elemento en la Cola.";

        cout << "\n\n\t0. Salir Programa.";
        cout << "\n\n\t   Teclee la opcion: ";
        cin >> miOpcion;
        cin.ignore();   // Limpia el buffer de entrada

        if (miOpcion < 0 || miOpcion > OPCIONES)
            cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;

    } while (miOpcion < 0 || miOpcion > OPCIONES);

    return miOpcion;
}

// Funcion que incorpora datos en la cola
void introducirElemCola(Cola  &Q) {
    TipoDato dato;
    do {
        cout << "\n\n\tIntroduzca un numero (para terminar teclee un numero negativo) ";
        cin >> dato.num;
        if (dato.num >= 0 && !Q.full()) {
            Q.push(dato);
        }
    } while (dato.num >= 0 && !Q.full());

    if(Q.full()){
        cout << "\n\n\tLa cola se ha llenado." << endl;
    }
}

// Funcion que muestra los datos de la cola como funcion general
void mostrarElemCola(Cola const &Q) {
    Cola paux(Q);

    while (!paux.empty())  {
        cout << " " << paux.first().num;
        paux.pop();
    }
}

// Funcion que determina el mayor valor que esta en la cola
TipoDato elementoMayorCola (Cola const &Q) {
    Cola paux(Q);
    TipoDato elmayor;

    elmayor = Q.first();
    while (!paux.empty())  {
        if (elmayor.num < paux.first().num) {
            elmayor = paux.first();
        }
        paux.pop();
    }

    return elmayor;
}

// Funcion que determina si un determinado valor esta en la cola
bool buscarElementoCola (Cola const &Q, const TipoDato &elem) {
    Cola paux(Q);
    bool esta{false};

    while (!paux.empty() && !esta)  {
        if (elem.num == paux.first().num) {
            esta = true;
        }
        paux.pop();
    }

    return esta;
}

// Funcion que determina las veces que un determinado valor esta en la cola
int vecesElementoCola (Cola const &Q, const TipoDato &elem) {
    int veces{0};
    Cola paux(Q);

    while (!paux.empty())  {
        if (elem.num == paux.first().num) {
            veces++;
        }
        paux.pop();
    }

    return veces;
}

// PROGRAMA PRINCIPAL
int main()
{
    int opcion;
    Cola Q;
    TipoDato elmayor;
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "\n\n\tOPCION Introducir numeros enteros.";
            if (!Q.full()){
                introducirElemCola(Q);
            }
            else{
                cout << "\n\n\tLa cola esta completa." << endl;
            }
            cout << "\n\n\n";
            break;
        case 2:
            cout << "\n\n\tOPCION Mostrar contenido de la Cola.";
            if (!Q.empty()) {
                cout << "\n\n\tLa cola tiene " << Q.sizeCola() << " elementos.";
                cout << "\n\n\tMostrar como funcion general: ";
                mostrarElemCola(Q);
                cout << "\n\n\tMostrar como miembro de la clase: ";
                Q.mostrarCola();
            }
            else {
                cout << "\n\n\tLa cola no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;

        case 3:
            cout << "\n\n\tOPCION Determinar el elemento MAYOR de la Cola.";

            if (!Q.empty()) {
                cout << "\n\n\tMayor como funcion general: ";
                cout << "\n\n\tEl elemento mayor de la Cola es " << elementoMayorCola (Q).num;

                cout << "\n\n\tMayor como miembro de la clase: ";
                cout << "\n\n\t\tEl elemento mayor de la Cola es " << Q.mayorCola().num;
            }
            else {
                cout << "\n\n\tLa cola no tiene datos." << endl;
            }

            cout << "\n\n\n";
            break;

        case 4:
            cout << "\n\n\tOPCION Buscar elemento en la Cola.";

            if (!Q.empty()) {
                TipoDato elem;
                cout << "\n\n\tIndique el elemento que quiere buscar en la Cola: ";
                cin >> elem.num;

                cout << "\n\n\tBuscar como funcion general: ";
                if (buscarElementoCola (Q, elem)) {
                    cout << "\n\n\tEl elemento " << elem.num << " esta en la Cola";
                }
                else {
                    cout << "\n\n\tEl elemento " << elem.num << " NO esta en la Cola";
                }

                cout << "\n\n\tBuscar como miembro de la clase: ";
                if (Q.existeEnCola(elem)) {
                    cout << "\n\n\tEl elemento " << elem.num << " esta en la Cola";
                }
                else {
                    cout << "\n\n\tEl elemento " << elem.num << " NO esta en la Cola";
                }
            }
            else {
                cout << "\n\n\tLa cola no tiene datos." << endl;
            }


            cout << "\n\n\n";
            break;

        case 5:
            cout << "\n\n\tOPCION Numero de veces de un elemento en la Cola.";

            if (!Q.empty()) {
                TipoDato elem;
                cout << "\n\n\tIndique el elemento que quiere buscar en la Cola: ";
                cin >> elem.num;

                cout << "\n\n\tMostrar veces como funcion general: ";
                cout << "\n\n\tEl elemento " << elem.num << " esta " << vecesElementoCola(Q, elem) << " veces en la Cola";

                cout << "\n\n\tMostrar veces como miembro de la clase: ";
                cout << "\n\n\tEl elemento " << elem.num << " esta " << Q.vecesEnCola(elem) << " veces en la Cola";
            }
            else {
                cout << "\n\n\tLa cola no tiene datos." << endl;
            }


            cout << "\n\n\n";
            break;

        case 0: cout << "\n\n\tGracias y hasta pronto";
            break;
        default: cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;
        }
        cout << "\n\n\t";

    } while (opcion != 0);


    cout << "\n\n\t";
    return 0;
}


























