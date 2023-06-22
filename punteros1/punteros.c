#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[])

{
    float puntos[5][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}, {1, 0, 1}};
    float a, b, c, d, e, f, g;
    float perimetro = calcularAreaS(puntos, &a, &b, &c, &d, &e, &f, &g);
    float area1 = calcularArea(a, b, c);
    float area2 = calcularArea(b, d, e);
    float area3 = calcularArea(a, e, f);
    float area4 = calcularArea(d, f, c);
    float areaS = area1 + area2 + area3 + area4;
    float volumen= calcularVolumen(g,area1);
    printf("El area superficial es: %.2f \n", areaS);
    printf("El area 1 es: %.2f \n", area1);
    printf("El area 2 es: %.2f \n", area2);
    printf("El area 3 es: %.2f \n", area3);
    printf("El area 4 es: %.2f \n", area4);
    printf("La altura es: %.2f \n", g);
    printf("Lado a es: %.2f \n", a);
    printf("El volúmen es: %.2f \n", volumen);
    
    return 0;
}

