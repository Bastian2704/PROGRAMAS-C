#include <stdio.h>
#include <math.h>
#include "funciones.h"
#define pi 3.14

float ingresarComponente(char componente, int i)
{
    float num;
    printf("Ingrese la componente %c del punto %d: ", componente, i);
    scanf("%f",&num);
    return num;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dist = sqrt((pow(x1-x2, 2)) + (pow(y1-y2, 2) )+ (pow(z1-z2, 2)));
    printf("sqrt((pow(%f-%f, 2)) + (pow(%f-%f, 2) )+ (pow(%f-%f, 2)\n",x1,x2,y1,y2,z1,z2);
    return dist;
}

float hipotenus(float base, float altura)
{
    float hipo = sqrt(pow(altura, 2) + pow(base, 2));
    return hipo;
}

void imprimirAreayvolumen(float base, float altura, float hipotenusa)
{
    float areaSuperficial = ((3.14) * base * hipotenusa)+(pi*base*base);
    float volumen = ( pi *base*base* altura)/3;
    printf("El area superficial es: %.2f\n", areaSuperficial);
    printf("El volumen es: %.2f\n", volumen);
}
