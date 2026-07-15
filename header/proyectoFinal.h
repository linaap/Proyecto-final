#ifndef PROYECTOFINAL_H

#define PROYECTOFINAL_H
#include <string>

struct Neurona{

	double w0;
	double b;
};

void entrenarNeurona(Neurona &n, double x[], double y[], int N, double TA, int epocas);
double predecir(const Neurona &n, double x);


#define PI 3.14159265358979323846
#define REP_TRIG 20  
#define REP_LOG 50

int resolverLaberinto(int arr[][7], int tamFila, int tamCol, int fila, int columna, int &contador);
void mainLaberinto();

void pruebaCaluladora();
double reducirRango(double x);
double miSeno(double x);
double miCoseno(double x);
double miLn(double x);
double miTangente(double x);


#endif
