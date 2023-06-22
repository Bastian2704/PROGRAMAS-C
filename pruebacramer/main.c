#include <stdio.h>

int main(int argc, char *argv[])
{

    float matriz[3][6]{(0,0,0),(0,0,0),(0,0,0)};
    float diap[3];
    float dias[3];
    int i, j;
    float detx = 1;
    diap[1] = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("Ingrese el numero de la posicion [%d][%d]\n", i + 1, j + 1);
            if (j == 3)
            {
                j = 5;
            }
            scanf("%f", &matriz[i][j]);
            if (j < 2)
            {
                scanf("%f", &matriz[i][j]);
                matriz[i][j + 3] = matriz[i][j];
            }
        }
    }
printf("------Matriz Extendida------\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 6; j++)
        {

            printf("%.2f  ", matriz[i][j]);
        }
    }
    printf("\n");
    j = 1;
    printf("Determinante del sistema:\n");
  
    for (i = 0; i < 3; i++)
    {
        j = i + 1;
        if (j == 4)
        {
            j = 1;
        }

        diap[2] = diap[2] * matriz[i][j];

        printf("%.2f", detx);
    }
    
}