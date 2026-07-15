#include <iostream>
#include "proyectoFinal.h"

using namespace std;

int main(){

    mainLaberinto();
    
    // Ejercicio 1
    double X[] = {0, 1, 2, 3, 4};
    double Y[] = {1, 3, 5, 7, 9};
    int N = 5;
	double prueba;
	
    Neurona miNeurona;
    miNeurona.w0 = 1.0; 
    miNeurona.b = 0.0;

	//Entrenando la neurona
    
    entrenarNeurona(miNeurona, X, Y, N, 0.02, 1000); // Los datos de tasa de aprendizaje y epocas son arbitrarios

	//Resultado de la neurona entrenada
	
    cout << "f(x) = " << miNeurona.w0 << "x + " << miNeurona.b << endl;

	cout << "Ingrese un dato a predecir ";
	cin >> prueba;
	cout << "Para el dato de entrada " << prueba << " su resultado es " << predecir(miNeurona, prueba);
    
    // pruebaCaluladora();
    return 0;
}
