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
