//Daniel Braun Sandino
//Práctica 1 - EDA - Ejercicio 1

#include <iostream>

using namespace std;


bool par(int num){
    if(num % 2 == 0){
        return true;
    }
    return false;
}

int solicitarNumero(){
    int numero;

    cout<<"Dime un numero: "<<endl;
    cin>>numero;

    while(numero < 1000){
        cout<<"Numero no valido, introduce un numero > 1000"<<endl;
        cin>>numero;
    }

    return numero;
}

int calcularSumaRestaCifras_Rec(int n, int &cifras){
    int operacion{0};

    if(n == 0){
        return operacion;
    }else{
        int resto = n % 10;
        int cociente = n / 10;

        if(par(resto)){
            operacion += resto;
            cifras++;
        }else{
            operacion -= resto;
            cifras++;
        }

        operacion +=  calcularSumaRestaCifras_Rec(cociente,cifras);
    }

    return operacion;

}

int calcularSumaRestaCifras_Iter(int n, int &cifras){
    int operacion{0};

    string aux = to_string(n);

    for(int i{0} ; i<aux.size() ; i++){
        int resto = n % 10;
        int cociente = n / 10;


        if(par(resto)){
            operacion += resto;
            cifras++;
        }else{
            operacion -= resto;
            cifras++;
        }

        n = cociente;
    }
    return operacion;
}

int main(){
    int numero = solicitarNumero();
    int cifrasIter{0};
    int cifrasRec{0};

    //OPERACION ITERATIVA
    int operacionIter = calcularSumaRestaCifras_Iter(numero,cifrasIter);

    cout<<"Operacion: "<<operacionIter<<endl;
    cout<<"Cifras: "<<cifrasIter<<endl;

    cout<<"--------------------------------------------"<<endl;

    //OPERACION RECURSIVA
    int operacionRec = calcularSumaRestaCifras_Rec(numero,cifrasRec);

    cout<<"Operacion: "<<operacionRec<<endl;
    cout<<"Cifras: "<<cifrasRec<<endl;

    return 0;
}
