//Daniel Braun Sandino
//Práctica 1 - EDA - Ejercicio 2

#include <iostream>
#include <vector>

using namespace std;

string solicitarFrase(){
    string resultado;
    cout<<"Introduce una frase superior a 10 caracteres: ";
    getline(cin, resultado);
    cout<<endl;
    while (resultado.size()<10) {
        cout<<"Introducce una frase correcta: ";
        getline(cin,resultado);
        cout<<endl;
    }
    return resultado;

}

bool vocalCheck(char caracter){
    char letra = toupper(caracter);

    if(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
        return true;
    }

    return false;
}

vector<char> determinarVocalesFrase_Iter(const string &texto){
    vector<char> almacen;
    cout<<"Impresion Iterativa: ";
    for(int i{texto.size() - 1} ; i>0 ; i--){
        if(vocalCheck(texto.at(i))){
            almacen.push_back(texto.at(i));
            cout<<texto.at(i)<<",";
        }
    }

    cout<<endl;

    return almacen;
}

void determinarVocalesFrase_Recu(const string &texto, int longitud, vector<char> &almacen){

    if(longitud > 0){

        char c = texto.at(longitud - 1);

        if(vocalCheck(c)){
            almacen.push_back(c);
            cout<<c<<", ";
        }

        determinarVocalesFrase_Recu(texto,--longitud, almacen);

    }
}

void mostrarVocales(const vector<char> &almacen){
    cout<<"Impresion check: ";
    for(auto elem : almacen){
        cout<<elem<<",";
    }
    cout<<endl;
}

int main(){

    string texto = solicitarFrase();

    vector<char> almacenIter = determinarVocalesFrase_Iter(texto);

    mostrarVocales(almacenIter);

    cout<<"---------------------------------------"<<endl;

    cout<<"Impresion check: ";
    vector<char> almacenRecu;
    determinarVocalesFrase_Recu("Hola Mundo", 10,almacenRecu);
    cout<<endl;

    mostrarVocales(almacenRecu);

    return 0;
}
