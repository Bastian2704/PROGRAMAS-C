#include <stdio.h>
#include "funciones.h"

float calcularDeterminante(float matrizprincipal[3][3]) {
    float det;
    
    det = (matrizprincipal[0][0] * matrizprincipal[1][1] * matrizprincipal[2][2]) +
          (matrizprincipal[0][1] * matrizprincipal[1][2] * matrizprincipal[2][0]) +
          (matrizprincipal[0][2] * matrizprincipal[1][0] * matrizprincipal[2][1]) -
          (matrizprincipal[0][2] * matrizprincipal[1][1] * matrizprincipal[2][0]) -
          (matrizprincipal[0][1] * matrizprincipal[1][0] * matrizprincipal[2][2]) -
          (matrizprincipal[0][0] * matrizprincipal[1][2] * matrizprincipal[2][1]);
    
    return det;
}

void calcular_posiciones(float matrizprincipal[3][3], float matrizrespuesta[3]) {
    float det, det_x, det_y, det_z;

    det = (matrizprincipal[0][0] * matrizprincipal[1][1] * matrizprincipal[2][2]) + (matrizprincipal[0][1] * matrizprincipal[1][2] * matrizprincipal[2][0]) +
          (matrizprincipal[0][2] * matrizprincipal[1][0] * matrizprincipal[2][1]) - (matrizprincipal[0][2] * matrizprincipal[1][1] * matrizprincipal[2][0]) -
          (matrizprincipal[0][1] * matrizprincipal[1][0] * matrizprincipal[2][2]) - (matrizprincipal[0][0] * matrizprincipal[1][2] * matrizprincipal[2][1]);

    det_x = (matrizrespuesta[0] * matrizprincipal[1][1] * matrizprincipal[2][2]) + (matrizprincipal[0][1] * matrizprincipal[1][2] * matrizrespuesta[2]) +
            (matrizprincipal[0][2] * matrizrespuesta[1] * matrizprincipal[2][1]) - (matrizprincipal[0][2] * matrizprincipal[1][1] * matrizrespuesta[2]) -
            (matrizprincipal[0][1] * matrizrespuesta[1] * matrizprincipal[2][2]) - (matrizrespuesta[0] * matrizprincipal[1][2] * matrizprincipal[2][1]);

    det_y = (matrizprincipal[0][0] * matrizrespuesta[1] * matrizprincipal[2][2]) + (matrizrespuesta[0] * matrizprincipal[1][2] * matrizprincipal[2][0]) +
            (matrizprincipal[0][2] * matrizprincipal[1][0] * matrizrespuesta[2]) - (matrizprincipal[0][2] * matrizrespuesta[1] * matrizprincipal[2][0]) -
            (matrizrespuesta[0] * matrizprincipal[1][0] * matrizprincipal[2][2]) - (matrizprincipal[0][0] * matrizprincipal[1][2] * matrizrespuesta[2]);

    det_z = (matrizprincipal[0][0] * matrizprincipal[1][1] * matrizrespuesta[2]) + (matrizprincipal[0][1] * matrizrespuesta[1] * matrizprincipal[2][0]) +
            (matrizrespuesta[0] * matrizprincipal[1][0] * matrizprincipal[2][1]) - (matrizrespuesta[0] * matrizprincipal[1][1] * matrizprincipal[2][0]) -
            (matrizprincipal[0][1] * matrizprincipal[1][0] * matrizrespuesta[2]) -
 (matrizprincipal[0][0] * matrizrespuesta[1] * matrizprincipal[2][1]);

    if (det != 0) {
        float x = (float)det_x / det;
        float y = (float)det_y / det;
        float z = (float)det_z / det;

        printf("Las respuesta para X,Y y Z son:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
        printf("z = %.2f\n", z);
    } else {
        printf("El sistema de ecuaciones no tiene solución única.\n");
    }
}