#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>

int pedirnum()
{
    int num;

    printf("Escriba el numero hasta donde llegara el algoritmo(no puede ingresar numeros menores a 1)\n");
    scanf("%d", &num);
    return num;
}

void imprimirPrimos(int num)
{
    int contador1 = 0;
    int contador2 = 0;
    if (num <= 0)
    {
        printf("El numero ingresado es menor a 1\n");
    }
    if (num == 2)
    {
        printf("Los numeros 1 y 2 son primos\n");
    }

    if (num > 2)
    {
        for (int i = 1; i < num + 1; i++)
        {
            for (int j = 1; j < i + 1; j++)
            {
                if (i % (j) == 0)
                {
                    contador1 += 1;
                }

                if (contador1 == 3)
                {
                    break;
                }
            }
            if (contador1 <= 2)
            {
                printf("%d ", i);
                contador2 += 1;
            }
            contador1 = 0;
        }
        printf("\n");
        printf("Hubieron %d numeros primos hasta %d", contador2, num);
    }
}