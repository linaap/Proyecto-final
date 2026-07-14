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

int resolverLaberinto(int arr[][7], int tamFila, int tamCol, int fila, int columna, int &contador){
    
    if( fila < 0 || fila >= tamFila || columna < 0 || columna >= tamCol) return false;
    if(arr[fila][columna] == 1 || arr[fila][columna] == 4) return false;
    if(arr[fila][columna] == 3) contador++;

    if(arr[fila][columna] == 0 || arr[fila][columna] == 2){
        arr[fila][columna] = 4;
    }

    printf("Moverse abajo a la posicion [%d][%d]", fila +1, columna);
    resolverLaberinto(arr, tamFila, tamCol, fila+1, columna, contador);
    printf("Moverse arriba a la posicion [%d][%d]", fila - 1, columna);
    resolverLaberinto(arr, tamFila, tamCol, fila-1, columna, contador);
    printf("Moverse arriba a la posicion [%d][%d]", fila, columna + 1);
    resolverLaberinto(arr, tamFila, tamCol, fila, columna+1, contador);
    printf("Moverse arriba a la posicion [%d][%d]", fila, columna - 1);
    resolverLaberinto(arr, tamFila, tamCol, fila, columna-1, contador);

    
    arr[fila][columna] = 0;
    printfprintf("No hay salida en la posicion [%d][%d], retroceder", fila, columna);
    return contadorSoluciones;

}
