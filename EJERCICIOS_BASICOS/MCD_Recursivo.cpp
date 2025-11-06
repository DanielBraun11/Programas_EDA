//Daniel Braun Sandino
//Ejercicio recursividad . calcular el mcd de 2 numeros dados o pedidos
#include <iostream>

using namespace std;

void recopilarDatos(int &a, int &b){
    cout<<"Introduce el primer valor: "<<endl;
    cin>>a;

    cout<<"Introduce el segundo valor: "<<endl;
    cin>>b;
}

int funcionRecursiva(int a, int b){
    int resto;

    //mcd(a,b)
    if(b == 0){
        return a;
    }else{
        resto = a % b;
        
        // a -> b  y b -> resto
        return funcionRecursiva(b, resto);
    }
}

int main(){
    //mcd(a,b)
    int a = 30;
    int b = 54;
    
    //Pruebas
    //recopilarDatos(a,b);

    cout<<"M.C.D:"<<funcionRecursiva(a,b)<<endl;

    return 0;
}
