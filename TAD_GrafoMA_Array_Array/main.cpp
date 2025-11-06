#include <iostream>
#include <array>
#include <set>

using namespace std;

#define nMax 4  // Constante que indica el numero de nodos del grafo

class Grafo {
private:
    array<bool, nMax> cVertices;
    array<array<bool,nMax>, nMax> cArcos;

public:
    // Constructor para crear un objeto Grafo vacÃ­o
    Grafo() {
        cVertices.fill(false);
        for (int i{0}; i < nMax; i++) {
            cArcos.at(i).fill(false);
        }
    }

    void incluir_arco(int origen, int final);
    void borrar_arco(int origen, int final);
    void incluir_vertice(int v);
    bool haycVertices() const;

    const array<bool, nMax> &getCVertices() const;
    void setCVertices(const array<bool, nMax> &newCVertices);
    const array<array<bool,nMax>, nMax> &getCArcos() const;
    void setCArcos(const array<array<bool,nMax>, nMax> &newCArcos);

    void profundidadRec (set<int> &visitados, int V);
    void recorrerProfundidad (int V);
    void mostraGrafo() const;
};

int main() {

    set<int> visitados;

    try {
        Grafo g;

        cout << "\n\n\tLa matriz de adyacencia del grafo es: " << endl;
        if (g.haycVertices()){
            g.mostraGrafo();
        }
        else{
            cout << "\n\tGrafo vacio." << endl;
        }

        g.incluir_arco(0, 3);
        g.incluir_arco(0, 2);
        g.incluir_arco(1, 2);
        g.incluir_arco(2, 0);
        g.incluir_arco(2, 3);
        g.incluir_arco(3, 1);

        cout << "\n\n\tLa matriz de adyacencia del grafo es: " << endl;
        if (g.haycVertices()){
            g.mostraGrafo();
        }
        else{
            cout << "\n\tGrafo vacio." << endl;
        }

        // Se recorre el grafo en profundidad comenzando desde cada uno de los vertices que lo forman
        if (g.haycVertices()){
            for (int vertice{0}; vertice < g.getCVertices().size(); vertice++) {
                cout << "\n\n\tRecorrido en profundida del grafo partiendo del vertice " << vertice << " :" << endl;
                g.recorrerProfundidad(vertice);
            }
        }
        else{
            cout << "\n\tGrafo vacio." << endl;
        }

    }
    catch (const string &msg){
        cerr << msg;
    }

    cout << "\n\n\t";
    return 0;
}

// Constructor para crear un objeto Grafo vacÃ­o
const array<bool, nMax> &Grafo::getCVertices() const
{
    return cVertices;
}

void Grafo::setCVertices(const array<bool, nMax> &newCVertices)
{
    cVertices = newCVertices;
}

const array<array<bool,nMax>, nMax> &Grafo::getCArcos() const
{
    return cArcos;
}

void Grafo::setCArcos(const array<array<bool,nMax>, nMax> &newCArcos)
{
    cArcos = newCArcos;
}

void Grafo::incluir_vertice(int v){
    cVertices.at(v)=true;
}

// Se inserta un arco a la matriz de adyacencia
void Grafo::incluir_arco(int origen, int final) {
    incluir_vertice(origen);
    incluir_vertice(final);
    cArcos.at(origen).at(final) = true;
}

// Se borra un arco de la matriz de adyacencia
void Grafo::borrar_arco(int origen, int final) {
    cArcos.at(origen).at(final) = false;
}

bool Grafo::haycVertices() const{
    for(bool e:cVertices){
        if (e){
            return e;
        }
    }
    return false;
}

// Mostrar la matriz de adyacencia
void Grafo::mostraGrafo() const {
    cout << "\n";
    for (int i{0}; i < cArcos.size(); i++) {
        cout << "\t\t|  ";
        for (int j{0}; j < cArcos.at(i).size(); j++) {
            cout << cArcos.at(i).at(j) << "  ";
        }
        cout << "|\n";
    }
}

// Recorrido en profundidad del grafo comenzando en el vertice V
void Grafo::profundidadRec (set<int> &visitados, int V) {

    // El vertice V se incluye en el conjunto de vertices visitados (procesados)
    visitados.insert(V);

    // Proceso que se hace sobre el vertice, en este caso se muestra por pantalla
    cout << "\n\tEl vertice " << visitados.size() << " visitado es " << V << endl;

    for (unsigned int W{0}; W < cVertices.size() ; W++) {
        // Se comprueba si el vertice W no esta en visitados y es adyacente a V
        if (cArcos.at(V).at(W) && (visitados.find(W)==visitados.end())) {
            // W es el vertice adyacente desde el que se repite
            // el recorrido en profundidad
            profundidadRec (visitados, W);
        }
    }
}

// Metodo que llama al proceso recursivo para recorrer el grafo
void Grafo::recorrerProfundidad	(int V) {
    // Conjunto para guardar y saber los vertices del grafo
    //  que se han procesado o visitado ya.
    set<int> visitados;

    profundidadRec (visitados, V);
}





