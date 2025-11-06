#include <iostream>
#include "TADPilaESTA.h"
//#include "TADPilaD.h"

using namespace std;

// PROTOTIPOS DE FUNCIONES
int menu ();

void introducirElemPila(Stack &P);

void mostrarElemPila(const Stack &P);

TipoDato elementoMayorPila (const Stack &P);

bool buscarElementoPila (const Stack &P, int elem);

int vecesElementoPila (const Stack &P, int elem);

// PROGRAMA PRINCIPAL
int main()
{
    int opcion;
    Stack P;
    TipoDato elmayor;
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
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;

        case 3:
            cout << "\n\n\tOPCION Determinar el elemento MAYOR de la Pila.";
            if (!P.empty()) {
                elmayor = elementoMayorPila (P);
                cout << "\n\n\tMayor como funcion general: ";
                cout << "\n\n\tEl elemento mayor de la Pila es " << elementoMayorPila (P).num;  //elmayor.num;

                cout << "\n\n\tMayor como miembro de la clase: ";
                cout << "\n\n\tEl elemento mayor de la Pila es " << P.mayorPila().num;
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;

        case 4:
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

                TipoDato elem1{elem};
                cout << "\n\n\tBuscar como miembro de la clase: ";
                if (P.existeEnPila(elem1)) {
                    cout << "\n\n\tEl elemento " << elem1.num << " esta en la Pila";
                }
                else {
                    cout << "\n\n\tEl elemento " << elem1.num << " NO esta en la Pila";
                }
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
            }
            cout << "\n\n\n";
            break;

        case 5:
            cout << "\n\n\tOPCION Numero de veces de un elemento en la Pila.";
            if (!P.empty()) {
                int elem;
                cout << "\n\n\tIndique el elemento que quiere buscar en la Pila: ";
                cin >> elem;
                cout << "\n\n\tMostrar veces como funcion general: ";
                cout << "\n\n\tEl elemento " << elem << " esta en la Pila " << vecesElementoPila(P, elem);

                TipoDato elem1{elem};
                cout << "\n\n\tMostrar veces como miembro de la clase: ";
                cout << "\n\n\tEl elemento " << elem << " esta en la Pila " << P.vecesEnPila(elem1);
            }
            else {
                cout << "\n\n\tLa pila no tiene datos." << endl;
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


// Funcion para escribir el menu en pantalla
int menu () {
    const int OPCIONES{5};
    string opcion;
    int miOpcion;

    do {
        cout << "\n\n\t1. Introducir elemento en la Pila.";
        cout << "\n\n\t2. Mostrar todos los datos de la Pila.";
        cout << "\n\n\t3. Buscar elemento Mayor de la Pila.";
        cout << "\n\n\t4. Buscar un elemento en la Pila.";
        cout << "\n\n\t5. Numero de veces de un elemento en la Pila.";

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
    TipoDato dato;
    do {
        cout << "\n\n\tIntroduzca un numero (para terminar teclee un numero negativo) ";
        cin >> dato.num;
        if (dato.num >= 0) {
            P.push(dato);
        }
    } while (dato.num >= 0);
}


// Funcion que muestra los datos de la pila como funcion general
void mostrarElemPila(const Stack &P) {
    Stack paux(P);

    while (!paux.empty())  {
        cout << " " << paux.top().num;
        paux.pop();
    }
}


// Funcion que determina el mayor valor que esta en la pila
TipoDato elementoMayorPila (const Stack &P) {
    Stack paux(P);
    TipoDato elmayor;

    elmayor = P.top();
    while (!paux.empty())  {
        if (elmayor.num < paux.top().num) {
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
        if (elem == paux.top().num) {
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
        if (elem == paux.top().num) {
            veces++;
        }
        paux.pop();
    }

    return veces;
}

