// Fichero inicial para el ejercicio nÂº1 de la prÃ¡ctica nÂº5 de EDA

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//---------------Clase CDato

class CDato {
private:
    string nom, apel;
    int aa;
public:
    CDato():aa(0){};
    CDato(const string &_nom, const string &_apel, int _aa):
        nom(_nom), apel(_apel), aa(_aa){};

    int getN() const;
    void setN(int newN);
    const string &getNom() const;
    void setNom(const string &newNom);
    const string &getApel() const;
    void setApel(const string &newApel);
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

    void procesarNodo() const;
};


//---------------Clase Arbol Binario Busqueda

class Arbol {
private:
    shared_ptr<Nodo> raiz;
public:
    Arbol():raiz(nullptr){};
    Arbol(const CDato &dato);

    bool empty() const;

    const shared_ptr<Nodo> &getRaiz() const;
    void setRaiz(const shared_ptr<Nodo> &newRaiz);

    void insertarNodoABBIter(const CDato &dato);

    void InOrden(shared_ptr<Nodo> A) const;
    void recorrerInOrden() const;

    //METODO PARA CALCULAR LOS ELEMENTOS SITUADOS EN EL CAMINO HASTA ENCONTRAR UN DATO EN EL ARBOL
    int calcularAnterioresHastaApellidoITER(const string &apellido){
        shared_ptr<Nodo> pAux = raiz;
        int contador = 0;

        if(empty()){
            cout<<"El arbol esta vacio."<<endl;
        }else{
            while(pAux != nullptr){
                contador++;
                if(pAux->getDato().getApel() == apellido){
                    return contador;
                }else{
                    if(apellido < pAux->getDato().getApel()){
                        pAux = pAux->getHizq();  //Avanzo a la izquierda
                    }else{
                        pAux = pAux->getHdch();  //Avanzo a la derecha
                    }
                }
            }
        }
        return -1;      //Si no lo encuentra
    }

    //METODO PARA CONSTRUIR UN ABB SIMETRICO AL DE PARTIDA
    Arbol determinarABBSimetricoREC(){

    }
};

//FUNCION GENERAL PARA CREAR EL ARBOL ABB
void crearABB(Arbol &A,const vector<CDato> &v){
    if(A.empty()){
        cout<<"El arbol esta vacio."<<endl;
    }

    for(CDato dato : v){
        A.insertarNodoABBIter(dato);
    }

    cout<<"Arbol rellenado con exito."<<endl;

}


int main(){
    Arbol A;

    vector<CDato> v{{"Maria", "Garcia",40}, {"Samuel", "Sanchez",20}, {"Ana", "Gil",70},
                    {"David", "Hoz",15}, {"Manuel", "Diaz",30}, {"Macarena", "Sanz",60},
                    {"Eloy", "Perez",80}, {"Antonio", "Garcia",75}, {"Nuria", "Gonzalez",90},
                    {"Jose", "Espada",10}, {"Javier", "Arias",25}, {"Almudena", "Casal",35}};


    //CREAR EL ARBOL CON LOS DATOS DEL VECTOR
    crearABB(A,v);

    //MOSTRAR LOS DATOS ORDENADOS DEL ARBOL ABB - CHECK
    A.recorrerInOrden();

    cout<<endl;
    cout<<"------------------------------------------"<<endl;

    //CALCULAR LOS ELEMENTOS SITUADOS EN EL CAMINO HASTA ENCONTRAR UN DATO EN EL ARBOL
    cout<<"Hay "<<A.calcularAnterioresHastaApellidoITER("Diaz")<<" elementos hasta Diaz."<<endl;    //Si esta
    cout<<"Hay "<<A.calcularAnterioresHastaApellidoITER("Braun")<<" elementos hasta Braun."<<endl;   //No esta

    //Raiz del arbol
    cout<<"Raiz: "<<A.getRaiz()->getDato().getApel()<<endl;



    cout << "\n\n\t";
    return 0;
}


//------------------Clase CDato

const string &CDato::getNom() const{
    return nom;
}

void CDato::setNom(const string &newNom){
    nom = newNom;
}

const string &CDato::getApel() const{
    return apel;
}

void CDato::setApel(const string &newApel){
    apel = newApel;
}

int CDato::getN() const{
    return aa;
}

void CDato::setN(int newN){
    aa = newN;
}


//--------------------Clase Nodo

const CDato &Nodo::getDato() const{
    return dato;
}

void Nodo::setDato(const CDato &newDato){
    dato = newDato;
}

const shared_ptr<Nodo> &Nodo::getHizq() const{
    return hizq;
}

void Nodo::setHizq(const shared_ptr<Nodo> &newHizq){
    hizq = newHizq;
}

const shared_ptr<Nodo> &Nodo::getHdch() const{
    return hdch;
}

void Nodo::setHdch(const shared_ptr<Nodo> &newHdch){
    hdch = newHdch;
}

void Nodo::procesarNodo() const{
    cout << "\n\n\t" << getDato().getApel() << " " << getDato().getNom() << " " << getDato().getN();
}


//-------------------Clase Arbol

bool Arbol::empty() const{
    return (raiz == nullptr);
}

const shared_ptr<Nodo> &Arbol::getRaiz() const{
    return raiz;
}

void Arbol::setRaiz(const shared_ptr<Nodo> &newRaiz){
    raiz = newRaiz;
}

Arbol::Arbol(const CDato &dato){
    raiz = make_shared<Nodo>(Nodo{dato});
}

// Metodo que permite insertar un nuevo nodo en un ABB
void Arbol::insertarNodoABBIter(const CDato &dato){
    shared_ptr<Nodo> Anew;
    Anew = make_shared<Nodo>();
    *Anew = Nodo(dato);

    if (raiz == nullptr) {
        raiz = Anew;
    }
    else {
        shared_ptr<Nodo> Ant, A = raiz;

        while (A != nullptr) {
            Ant = A;
            if (A->getDato().getApel() > dato.getApel()) {
                A = A->hizq;
            }
            else {
                A = A->hdch;
            }
        }

        if (Ant->getDato().getApel() > dato.getApel()) {
            Ant->hizq = Anew;
        }
        else {
            Ant->hdch = Anew;
        }
    }
}

// Recorrido InOrden para mostrar los nodos ordenadamente de un ABB
void Arbol::InOrden(shared_ptr<Nodo> A) const{
    if (A != nullptr) {
        InOrden (A->getHizq());		// I
        A->procesarNodo();             // R
        InOrden (A->getHdch());        // D
    }

}

void Arbol::recorrerInOrden() const{
    if (!empty()) {
        InOrden (raiz);
    }
}

