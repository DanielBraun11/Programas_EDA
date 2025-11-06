#include <iostream>
#include "TADColaDIN.h"

using namespace std;

// PROTOTIPOS DE FUNCIONES
int menu ();

//introducirElemCola();

//mostrarElemCola();

//elementoMayorCola();

//buscarElementoCola();

//vecesElementoCola();

// PROGRAMA PRINCIPAL
int main()
{
    int opcion;
    Cola Q;
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "\n\n\tOPCION Introducir numeros enteros.";
            //                  introducirElemCola
            cout << "\n\n\n";
            break;
        case 2:
            cout << "\n\n\tOPCION Mostrar contenido de la Cola.";
            if (!Q.empty()) {
                //                        cout << "\n\n\tLa cola tiene " << Q.sizeCola() << " elementos.";
                cout << "\n\n\tMostrar como funcion general: ";
                //                        mostrarElemCola
                cout << "\n\n\tMostrar como miembro de la clase: ";
                //                        Q.mostrarCola()
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
                //                        cout << "\n\n\tEl elemento mayor de la Cola es " << elementoMayorCola;

                cout << "\n\n\tMayor como miembro de la clase: ";
                //                        cout << "\n\n\t\tEl elemento mayor de la Cola es " << Q.mayorCola();
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
                //                        if (buscarElementoCola()) {
                cout << "\n\n\tEl elemento " << elem.num << " esta en la Cola";
                //                        }
                //                        else {
                cout << "\n\n\tEl elemento " << elem.num << " NO esta en la Cola";
                //                        }

                cout << "\n\n\tBuscar como miembro de la clase: ";
                //                        if (Q.existeEnCola()) {
                cout << "\n\n\tEl elemento " << elem.num << " esta en la Cola";
                //                        }
                //                        else {
                cout << "\n\n\tEl elemento " << elem.num << " NO esta en la Cola";
                //                        }
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
                //                        cout << "\n\n\tEl elemento " << elem.num << " esta " << vecesElementoCola() << " veces en la Cola";

                cout << "\n\n\tMostrar veces como miembro de la clase: ";
                //                        cout << "\n\n\tEl elemento " << elem.num << " esta " << Q.vecesEnCola() << " veces en la Cola";
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

