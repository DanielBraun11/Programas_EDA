//Daniel Braun Sandino
//Hoja 1 - Ejercicio 3 - Recursividad
//Calcular el valor de un determinado término de la serie definida como: An = An-2 – 2 An-1 siendo A0 = 1 y A1 = 3 ∀n ≥ 2
#include <iostream>

using namespace std;

int calculo(int num){
    if(num == 0){
        return 1;
    }else if(num == 1){
        return 3;
    }else{
        return (calculo((num - 2)) - ((calculo(num - 1))*2));
    }
}

void programa(){
    int num;

    cout<<"Introduce el numero: "<<endl;
    cin>>num;

    cout<<"El numero es: "<<calculo(num)<<endl;
}


int main(){
    programa();

    return 0;
}
