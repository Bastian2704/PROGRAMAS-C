#include <stdio.h>
#include <math.h>
#include "funciones.h"

float ingresarCoordenadas(char componente, int num)
{
    float punto;
    printf("Ingrese la componente %c del punto %d\n", componente, num);
    scanf("%f", &punto);
    return punto;
}
float obtenerDistancia(float x1, float y1, float x2, float y2)
{
    float dis=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return dis;
}
void areaCirculo(float a,float b, float c){
    float radio=(a+b-c)/2;
    float area= 3.14 * radio*radio;
    printf("El area es: %.2f\n",area);
}