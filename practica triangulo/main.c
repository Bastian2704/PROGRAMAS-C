#include <stdio.h>
#include <math.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    float puntos[3][2];
    float baricentro[2];
    for (int i = 0; i < 3; i++)
    {
        puntos[i][0] = ingresarCoordenadas('X', i+1);
        puntos[i][1] = ingresarCoordenadas('Y', i+1);
    }

    
    float catetoa= obtenerDistancia(puntos[0][0],puntos[0][1],puntos[1][0],puntos[1][1]);
    float catetob= obtenerDistancia(puntos[0][0],puntos[0][1],puntos[2][0],puntos[2][1]);
    float hipotenusa= obtenerDistancia(puntos[2][0],puntos[2][1],puntos[1][0],puntos[1][1]);
      for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f ", puntos[i][j]);
    }
    }
    printf("\n");
    printf("Catetoa: %.2f\n",catetoa);
    printf("Catetob: %.2f\n",catetob);
     printf("Hipotenusa: %.2f\n",hipotenusa);
areaCirculo(catetoa,catetob,hipotenusa);

}