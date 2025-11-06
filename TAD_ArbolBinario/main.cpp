#include <iostream>
#include <memory>

#include "TADArbolDIN.h"
#include "TADColaDIN.h"

using namespace std;

int main() {
    // Construir Arbol del Nivel 3
    //    CDato dato(2);
    //    Arbol N3DII(dato);
    //    dato.setN(1);
    //    Arbol N3DDD(dato);

    // Construir Arbol del Nivel 2
    //    dato.setN(6);
    //    Arbol N2II(dato);
    //    dato.setN(5);
    //    Arbol N2ID(dato);
    //    dato.setN(4);
    //    Arbol N2DI(dato);
    //    N2DI.addHizq(N3DII);
    //    dato.setN(3);
    //    Arbol N2DD(dato);
    //    N2DD.addHdch(N3DDD);


    // Construir Arbol del Nivel 1
    //    dato.setN(8);
    //    Arbol N1I(dato);
    //    N1I.addHizq(N2II);
    //    N1I.addHdch(N2ID);
    //    dato.setN(7);
    //    Arbol N1D(dato);
    //    N1D.addHizq(N2DI);
    //    N1D.addHdch(N2DD);

    // Construir Arbol del Nivel 0
    //    dato.setN(9);
    //    Arbol N0(dato);
    //    N0.addHizq(N1I);
    //    N0.addHdch(N1D);


    Arbol N0, Nizq, Ndch, N1, N2, N3;
    CDato dato(2);
    N1.construirArbol(Nizq, Ndch, dato);
    dato.setN(4);
    N2.construirArbol(N1, Ndch, dato);

    dato.setN(1);
    N1.construirArbol(Nizq, Ndch, dato);
    dato.setN(3);
    N3.construirArbol(Nizq, N1, dato);

    dato.setN(7);
    N1.construirArbol(N2, N3, dato);

    dato.setN(6);
    N2.construirArbol(Nizq, Ndch, dato);
    dato.setN(5);
    N0.construirArbol(Nizq, Ndch, dato);

    dato.setN(8);
    N3.construirArbol(N2, N0, dato);

    dato.setN(9);
    N0.construirArbol(N3, N1, dato);

    cout << "\n\n\n\tRecorrido InOrden";
    cout << "\n\t====================";
    N0.recorrerInOrden();


    cout << "\n\n\n\tRecorrido PreOrden";
    cout << "\n\t====================";
    N0.recorrerPreOrden();


    cout << "\n\n\n\tRecorrido PostOrden";
    cout << "\n\t====================";
    N0.recorrerPostOrden();

    cout << "\n\n\n\tRecorrido en ANCHURA";
    cout << "\n\t====================";
    N0.recorrerAnchura();

    cout << "\n\n\t";
    return 0;
}



