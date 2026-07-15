#include "proyectoFinal.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//Ejercicio 1
void entrenarNeurona (Neurona &n, double x[], double y[], int N, double TA, int epocas){
	for (int epoca = 1; epoca <= epocas; epoca++){
		double errorTotal = 0;
		double gradw0 = 0;
		double gradb = 0;
		
		for (int i = 0; i < N; i++){
			double a = n.w0 * x[i] + n.b;
			double error = a - y[i];
			
			errorTotal += pow(error,2);
			
			gradw0 += error * x[i];
			gradb += error;
		}
		
		gradw0 = (2.0 / N) * gradw0;
		gradb = (2.0 / N) *gradb;
		
		n.w0 = n.w0 - TA * gradw0;
		n.b = n.b - TA * gradb;
	}
}

double predecir(const Neurona &n, double x){
	return n.w0 * x + n.b;
}


//funciones ejercicio laberinto
void mainLaberinto(){
	
	const int filas = 7;
	const int columnas = 7;

	// Representación del laberinto:
	// 0 = Camino libre, 1 = Pared, 2 = Entrada, 3 = Salida, 4 = Camino ya visitado
	
	int laberinto[filas][columnas] = {
    {1,1,1,2,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,1,0,0,1,1},
    {1,1,0,1,0,0,1},
    {1,0,0,0,0,1,1},
    {1,0,1,1,0,0,1},
    {1,1,1,1,1,0,3}
	};
	//registro de cuántas soluciones encontramos
	int contador = 0;


	printf("Pasos para resolver el laberinto(orden descendente):\n\n");
	// Iniciamos la búsqueda en la posición [0][3] (donde está el '2' de entrada)
	resolverLaberinto(laberinto, filas, columnas, 0, 3, contador);
	
	// Evaluamos cuántas soluciones encontró la función
	if (contador == 0) {
    	printf("\n No hay solucion para el laberinto.\n");
	} else if (contador == 1) {
    	printf("\n Hay solucion unica para el laberinto \n");
	} else {
    	printf("\n Hay varias soluciones para el laberinto (Total: %d)\n", contador);
	}
	return;
	
}

int resolverLaberinto(int arr[][7], int tamFila, int tamCol, int fila, int columna, int &contador){
    
    int exito = 0; // Variable para saber si por este camino se llega a la salida (0 -> No, 1 -> Sí)
    //si nos salimos de los límites del laberinto, este camino no sirve
    if( fila < 0 || fila >= tamFila || columna < 0 || columna >= tamCol) return 0;
    //si nos topamos con una pared o con un camino ya marcado, regresamos
    if(arr[fila][columna] == 1 || arr[fila][columna] == 4) return 0;
    //si llegamos a la salida, el contador de soluciones aumenta
    if(arr[fila][columna] == 3){
    	contador++;
    	return 1; //indica que el camino funcionó
	}

	//si hay espacio para moverse o es el inicio del laberinto, se marca con un 4, para no volver a pasar por ahí
    if(arr[fila][columna] == 0 || arr[fila][columna] == 2){
        arr[fila][columna] = 4;
    }

	//intentamos ir abajo, y si el camino es válido retorna 1 (exitoso)
    if(resolverLaberinto(arr, tamFila, tamCol, fila+1, columna, contador)){
    	printf("Moverse abajo a la posicion [%d][%d]\n", fila +1, columna);
    	exito = 1;
	};
    //ahora vamos arriba
    if(resolverLaberinto(arr, tamFila, tamCol, fila-1, columna, contador)){
    	printf("Moverse arriba a la posicion [%d][%d]\n", fila - 1, columna);
		exito = 1;
	}
    //derecha
    if(resolverLaberinto(arr, tamFila, tamCol, fila, columna+1, contador)){
    	printf("Moverse a la derecha a la posicion [%d][%d]\n", fila, columna + 1);
    	exito = 1;
	}
    //izquierda
    if(resolverLaberinto(arr, tamFila, tamCol, fila, columna-1, contador)){
    	printf("Moverse a la izquierda a la posicion [%d][%d]\n", fila, columna - 1);
    	exito = 1;
	}

    /*como ya exploramos todas las direcciones, se limpian las casillas marcadas con 4 previamente,
	para que el algoritmo busque otra solución de ser necesario, y pueda volver a pasar por ahí*/
	
    arr[fila][columna] = 0;
  
  	//se retorna si hubo éxito o no en la posición analizada
    return exito;
}

double reducirRango(double x) 
{
    while (x > PI) 
	{
        x -= 2.0 * PI;
    }
    while (x < -PI) 
	{
        x += 2.0 * PI;
    }
    return x;
}

double miSeno(double x) 
{
    x = reducirRango(x);
    double termino = x;
    double suma = termino;
    
    for (int n = 1; n < REP_TRIG; n++) 
	{
        termino = -termino * (x * x) / ((2 * n) * (2 * n + 1));
        suma += termino;
    }
    return suma;
}

double miCoseno(double x)
{
    x = reducirRango(x);
    double termino = 1.0;
    double suma = termino;
    
    for (int n = 1; n < REP_TRIG; n++) {
        termino = -termino * (x * x) / ((2 * n - 1) * (2 * n));
        suma += termino;
    }
    return suma;
}

double miTangente(double x) 
{
    double cos_x = miCoseno(x);
    if (cos_x > -0.000000001 && cos_x < 0.000000001) {
        printf("Error: Tangente indefinida\n");
        return 0.0; 
    }
    return miSeno(x) / cos_x;
}

double miLn(double x) 
{
    if (x <= 0.0) 
	{
        printf("Error: El logaritmo solo está definido para números positivos\n");
        return 0.0;
    }
    
    double y = (x - 1.0) / (x + 1.0);
    double y2 = y * y;
    double termino = y;
    double suma = termino;
    
    for (int n = 1; n < REP_LOG; n++) 
	{
        termino *= y2;
        suma += termino / (2 * n + 1);
    }
    
    return 2.0 * suma;
}

void pruebaCaluladora()
{
	double anguloRad = PI / 6.0; 
    double e = 2.718281828;


    printf("Seno(PI/6)     = %.6f (Esperado: 0.500000)\n", miSeno(anguloRad));
    printf("Coseno(PI/6)   = %.6f (Esperado: 0.866025)\n", miCoseno(anguloRad));
    printf("Tangente(PI/6) = %.6f (Esperado: 0.577350)\n\n", miTangente(anguloRad));

    printf("ln(e)          = %.6f (Esperado: 1.000000)\n", miLn(e));
    printf("ln(10)         = %.6f (Esperado: 2.302585)\n", miLn(10.0));
    printf("ln(0.5)        = %.6f (Esperado: -0.693147)\n\n", miLn(0.5));

    printf("Seno(13*PI/6)  = %.6f (Esperado: 0.500000)\n", miSeno(13.0 * PI / 6.0));
}

