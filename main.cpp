#include "header/proyectoFinal.h"
#include <iostream>
#include <stdio.h>

using namespace std;
 


int main(){
	double angulo_rad = PI / 6.0; // 30 grados
    double valor_log = 2.718281828; // Aproximación de 'e'

    printf("=== CALCULADORA CIENTÍFICA (Sin math.h) ===\n\n");

    printf("Evaluando funciones trigonometricas para PI/6 (30 grados):\n");
    printf("Seno(PI/6)     = %.6f (Esperado: 0.500000)\n", mi_seno(angulo_rad));
    printf("Coseno(PI/6)   = %.6f (Esperado: 0.866025)\n", mi_coseno(angulo_rad));
    printf("Tangente(PI/6) = %.6f (Esperado: 0.577350)\n\n", mi_tangente(angulo_rad));

    printf("Evaluando logaritmos:\n");
    printf("ln(e)          = %.6f (Esperado: 1.000000)\n", mi_ln(valor_log));
    printf("ln(10)         = %.6f (Esperado: 2.302585)\n", mi_ln(10.0));
    printf("ln(0.5)        = %.6f (Esperado: -0.693147)\n\n", mi_ln(0.5));

    // Prueba de reducción de rango (ángulos mayores a 2PI)
    printf("Prueba de angulo grande (Seno de 2PI + PI/6):\n");
    printf("Seno(13*PI/6)  = %.6f (Esperado: 0.500000)\n", mi_seno(13.0 * PI / 6.0));
    return 0;
}
