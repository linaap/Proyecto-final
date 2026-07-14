#ifndef PROYECTOFINAL_H

#define PROYECTOFINAL_H
#include <string>

#define PI 3.14159265358979323846
#define ITERACIONES_TRIG 20  
#define ITERACIONES_LOG 50

bool resolverLaberinto(int arr[][7], int tamFila, int tamCol, int fila, int columna);

double reducir_rango(double x);
double mi_seno(double x);
double mi_coseno(double x);
double mi_ln(double x);
double mi_tangente(double x);


#endif
