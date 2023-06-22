#include <stdio.h>
#include <math.h>
#include "funciones.h"

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dist = sqrt(pow(x1 - x2, 2) + pow((y1 - y2), 2) + pow(z1 - z2, 2));
    return dist;
}

float calcularAreaS(float puntos[3][3], float *a, float *b, float *c, float *d, float *e, float *f, float *g)
{
    // float puntos[5][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}, {1, 0, 1}};
    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *g = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[4][0], puntos[4][1], puntos[4][2]);
    float areaSup = 0;
    return areaSup;
}

float calcularArea(float a, float b, float c)
{
    float s = 0;
    s=(a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
float calcularVolumen(float g,float area1){
float volumen=(g*(area1))/3;
return volumen;
}