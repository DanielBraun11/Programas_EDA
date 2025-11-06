//Daniel Braun Sandino
//Hoja 1 - Ejercicio 1 - Recursividad
//Calcular la suma de los numeros anteriores al dado (Factorial)
#include <iostream>

using namespace std;

int calcular_factorial(int i){

    if(i == 0){
        return 0;
    }else{
        return(i + contador(i - 1));
    }

}

void devolver_factorial(int i){
    cout<<"La suma es: "<<contador(i)<<endl;
}

void programa(){
    int num;
    cout<<"Introduce un numero: "<<endl;
    cin>>num;
    devolverRespuesta(num);
}

int main(){
    programa();

    return 0;
}
