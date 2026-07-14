#include "proyectoFinal.h"
#include <stdio.h>



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
