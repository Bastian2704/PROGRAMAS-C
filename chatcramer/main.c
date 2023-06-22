#include <stdio.h>
#include "funciones.h"

float main()
{
    float matrizprincipal[3][3];
    float matrizrespuesta[3];

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Ingrese el elemento %d %d:\n", i + 1, j + 1);
            scanf("%f", &matrizprincipal[i][j]);
        }
    }

    printf("Ingrese los elementos de la matriz respuesta:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese el elemento %d:\n", i + 1);
        scanf("%f", &matrizrespuesta[i]);
    }

    printf("\n");
    printf("Matriz Extendida\n");
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("( ");
            }

            printf("%.2f ", matrizprincipal[i][j]);

            if (j == 2)
            {
                printf(") (%.2f) ", matrizrespuesta[i]);
            }
        }
    }
    printf("\n");

    float determinante = calcularDeterminante(matrizprincipal);

    printf("La determinante de la matriz es: %.2f\n", determinante);

    calcular_posiciones(matrizprincipal, matrizrespuesta);

    return 0;
}