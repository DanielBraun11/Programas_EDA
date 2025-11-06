#include <iostream>
#include "TADPilaDIN.h"

using namespace std;

// PROTOTIPOS DE FUNCIONES
int menu ();

void introducirElemPila(Stack &P);

void mostrarElemPila(const Stack &P);

int elementoMayorPila (const Stack &P);

bool buscarElementoPila (const Stack &P, int elem);

int vecesElementoPila (const Stack &P, int elem);

Stack interseccion(const Stack &P1, const Stack &P2);

// PROGRAMA PRINCIPAL
int main(){
    int opcion;
    Stack P;
    Stack P2;

    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "\n\n\tOPCION Introducir numeros enteros.";
            introducirElemPila(P);
            cout << "\n\n\n";
            break;
        case 2:
            cout << "\n\n\tOPCION Mostrar contenido de la Pila.";
            if (!P.empty()) {
                cout << "\n\n\tLa pila tiene " << P.sizePila() << " elementos.";
                cout << "\n\n\tMostrar como funcion general: ";
                mostrarElemPila(P);
                cout << "\n\n\tMostrar como miembro de la clase: ";
                P.mostrarPila();

                // Metodo NO adecuado porque destruye la pila
                cout << "\n\n\tMostrar2 como miembro de la clase: ";
                //Si descomento y se ejcuta mostrara ero se borrara la pila y el resto dara vacia
                //P.mostrarPila2Destruida();
                cout << "\n\n\tMostrar como miembro de la clase: ";
                P.mostrarPila();
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;

        case 3:{
            cout << "\n\n\tOPCION Determinar el elemento MAYOR de la Pila.";
            if (!P.empty()) {
                cout << "\n\n\tMayor como funcion general: ";
                cout << "\n\n\tEl elemento mayor de la Pila es " << elementoMayorPila (P);

                cout << "\n\n\tMayor como miembro de la clase: ";
                cout << "\n\n\tEl elemento mayor de la Pila es " << P.mayorPila();
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;
        }

        case 4:{
            cout << "\n\n\tOPCION Buscar elemento en la Pila.";
            if (!P.empty()) {
                int elem;
                cout << "\n\n\tIndique el elemento que quiere buscar en la Pila: ";
                cin >> elem;

                cout << "\n\n\tBuscar como funcion general: ";
                if (buscarElementoPila (P, elem)) {
                    cout << "\n\n\tEl elemento " << elem << " esta en la Pila";
                }
                else {
                    cout << "\n\n\tEl elemento " << elem << " NO esta en la Pila";
                }

                cout << "\n\n\tBuscar como miembro de la clase: ";
                if (P.existeEnPila(elem)) {
                    cout << "\n\n\tEl elemento " << elem << " esta en la Pila";
                }
                else {
                    cout << "\n\n\tEl elemento " << elem << " NO esta en la Pila";
                }
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;
        }

        case 5:{
            cout << "\n\n\tOPCION Numero de veces de un elemento en la Pila.";
            if (!P.empty()) {
                int elem;
                cout << "\n\n\tIndique el elemento que quiere buscar en la Pila: ";
                cin >> elem;

                cout << "\n\n\tMostrar veces como funcion general: ";
                cout << "\n\n\tEl elemento " << elem << " esta " << vecesElementoPila(P, elem) << " veces en la Pila ";

                cout << "\n\n\tMostrar veces como miembro de la clase: ";
                cout << "\n\n\tEl elemento " << elem << " esta " << P.vecesEnPila(elem) << " veces en la Pila ";

            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;
        }

        case 6:{
            cout << "\n\n\tOPCION Introducir numeros enteros.";
            introducirElemPila(P2);
            cout << "\n\n\n";
            break;
        }

        case 7:{
            cout << "\n\n\tOPCION Optener interseccion de pila P y P2.";
            Stack P3 = interseccion(P,P2);
            P3.mostrarPila();
            cout << "\n\n\n";
            break;
        }

        case 0: cout << "\n\n\tGracias y hasta pronto";
            break;

        default: cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;
        }
        cout << "\n\n\t";

    } while (opcion != 0);


    cout << "\n\n\t";
    return 0;
}


// Funcion para escribir el menu en pantalla
int menu () {
    const int OPCIONES{7};
    string opcion;
    int miOpcion;

    do {
        cout << "\n\n\t1. Introducir elemento en la Pila.";
        cout << "\n\n\t2. Mostrar todos los datos de la Pila.";
        cout << "\n\n\t3. Buscar elemento Mayor de la Pila.";
        cout << "\n\n\t4. Buscar un elemento en la Pila.";
        cout << "\n\n\t5. Numero de veces de un elemento en la Pila.";
        cout << "\n\n\t6. Introducir elemento en la Pila P2.";
        cout << "\n\n\t7. Calcular la interseccion d elas pilas.";

        cout << "\n\n\t0. Salir Programa.";
        cout << "\n\n\t   Teclee la opcion: ";
        cin >> miOpcion;
        cin.ignore();   // Limpia el buffer de entrada

        if (miOpcion < 0 || miOpcion > OPCIONES)
            cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;

    } while (miOpcion < 0 || miOpcion > OPCIONES);

    return miOpcion;
}

// Funcion que incorpora datos en la pila
void introducirElemPila(Stack  &P) {
    int dato;
    do {
        cout << "\n\n\tIntroduzca un numero (para terminar teclee un numero negativo) ";
        cin >> dato;
        if (dato >= 0) {
            P.push(dato);
        }
    } while (dato >= 0);
}


// Funcion que muestra los datos de la pila como funcion general
void mostrarElemPila(const Stack &P) {
    Stack paux(P);

    while (!paux.empty())  {
        cout << " " << paux.top();
        paux.pop();
    }
}


// Funcion que determina el mayor valor que esta¡ en la pila
int elementoMayorPila (const Stack &P) {
    Stack paux(P);
    int elmayor;

    elmayor = P.top();
    while (!paux.empty())  {
        if (elmayor < paux.top()) {
            elmayor = paux.top();
        }
        paux.pop();
    }

    return elmayor;
}


// Funcion que determina si un determinado valor esta en la pila
bool buscarElementoPila (const Stack &P, int elem) {
    Stack paux(P);
    bool esta{false};

    while (!paux.empty() && !esta)  {
        if (elem == paux.top()) {
            esta = true;
        }
        paux.pop();
    }

    return esta;
}


// Funcion que determina las veces que un determinado valor esta en la pila
int vecesElementoPila (const Stack &P, int elem) {
    int veces{0};
    Stack paux(P);

    while (!paux.empty())  {
        if (elem == paux.top()) {
            veces++;
        }
        paux.pop();
    }

    return veces;
}

// Funcion para agregar los Nodos comunes entre las 2 pilas (Interseccion)
Stack interseccion(const Stack &P1, const Stack &P2){
    Stack P3;
    if(P1.sizePila() > P2.sizePila()){
        Stack P2aux(P2);

        while(!P2aux.empty()){
            if(P1.existeEnPila(P2aux.top())){
                P3.push(P2aux.top());
            }
            P2aux.pop();
        }

    }else{
        Stack P1aux(P1);

        while(!P1aux.empty()){
            if(P2.existeEnPila(P1aux.top())){
                P3.push(P1aux.top());
            }
            P1aux.pop();
        }
    }

    return P3;
}

