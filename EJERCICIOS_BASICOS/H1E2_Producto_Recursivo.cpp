//Daniel Braun Sandino
//Hoja 1 - Ejercicio 2 - Recursividad 
//Calcular el producto de 2 enteros
#include <iostream>

using namespace std;

int multiplicar(int num1, int num2){

        if(num2 == 0){
            return 0;
        }else{
            return num1 + multiplicar(num1, num2 - 1);
        }
}

void programa(){
    int num1,num2;
    cout<<"Introduce el primer numero: "<<endl;
    cin>>num1;

    cout<<"Introduce el segundo numero: "<<endl;
    cin>>num2;

    cout<<"El producto es: "<<multiplicar(num1,num2)<<endl;
}


int main(){
    programa();

    return 0;
}
