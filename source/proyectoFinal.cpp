#include "proyectoFinal.h"
#include <stdio.h>


const int filas = 7;
const int columnas = 7;

int laberinto[filas][columnas] = {
    {1,1,1,2,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,1,0,0,1,1},
    {1,1,0,1,0,0,1},
    {1,0,0,1,0,1,1},
    {1,0,1,1,0,0,1},
    {1,0,1,1,1,0,3}
};

bool resolverLaberinto(int arr[][7], int tamFila, int tamCol, int fila, int columna){
    if( fila < 0 || fila >= tamFila || columna < 0 || columna >= tamCol) return false;
    if(arr[fila][columna] == 1 || arr[fila][columna] == 4) return false;
    if(arr[fila][columna] == 3) return true;

    if(arr[fila][columna] == 0 || arr[fila][columna] == 2){
        arr[fila][columna] = 4;
    }

    
    if(resolverLaberinto(arr, tamFila, tamCol, fila+1, columna)) return true;
    if(resolverLaberinto(arr, tamFila, tamCol, fila-1, columna)) return true;
    if(resolverLaberinto(arr, tamFila, tamCol, fila, columna+1)) return true;
    if(resolverLaberinto(arr, tamFila, tamCol, fila, columna-1)) return true;
    
    arr[fila][columna] = 0;
    return false;

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
