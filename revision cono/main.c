#include <stdio.h> 
#include <math.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    float puntos[3][3];
    
    for (int i = 0; i < 3; i++)
    {
        puntos[i][0]= ingresarComponente('X',i+1);
        puntos[i][1]= ingresarComponente('Y',i+1);
        puntos[i][2]= ingresarComponente('Z',i+1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", puntos[i][j]);
    }
    }
    printf("\n");

  float base =  calcularDistancia(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
printf("base: %.2f \n",base);

    float altura = calcularDistancia(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    printf("altura: %.2f \n",altura);

    float hipotenusa=calcularDistancia(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    printf("hipotenusa: %.2f \n",hipotenusa);

    imprimirAreayvolumen(base,altura,hipotenusa);


}