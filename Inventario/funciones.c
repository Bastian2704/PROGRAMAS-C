#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menuPrincipal()
{
    int menu;
    printf("--------------------------------------INVENTARIO--------------------------------------\n");
    printf("1.-VER PRODUCTOS  \t 2.-INGRESAR PRODUCTOS \t\t 3.-MODIFICACION DE PRODUCTOS\n");
    scanf("%d", &menu);
    return menu;
}

int verProductos(float ID[3][8], char nombre[8][15], char descripcion[8][15], int contador)
{
    int menu;
    printf("-------\tPRODUCTOS\t-------\n");
    printf("ID   NOMBRE\t\tDESCRIPCION\tCANTIDAD\tPRECIO\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%0.f    %s\t\t%s\t\t%.0f\t\t%.1f M\n", ID[0][i], nombre[i], descripcion[i], ID[1][i], ID[2][i]);
    }

    menu = 0;
    printf("\n");
    return menu;
}

int nuevoProducto(char nombre[8][15], char nuevoNombre[15], char nuevaDescripcion[15], char descripcion[8][15], float ID[3][8], int contador)
{
    int menu;
    if (contador <= 7)
    {
        printf("Ingrese el nuevo producto\n");
        printf("Nombre:");
        scanf("%s", nuevoNombre);
        strcpy(nombre[contador], nuevoNombre);
        printf("Descripcion:");
        scanf("%s", nuevaDescripcion);
        strcpy(descripcion[contador], nuevaDescripcion);
        printf("Cantidad:");
        scanf("%f", &ID[1][contador]);
        printf("Precio: ");
        scanf("%f", &ID[2][contador]);
        printf("\n");
    }
    else if (contador > 7)
    {
        printf("Se ha alcanzado el numero MAXIMO de articulos en el invertario\n");
        printf("Para ingresar un nuevo articulo, elimine o modifique uno ya existente");
        printf("\n");
    }

    menu = 0;
    return menu;
}

int modificarProductos(char nombre[8][15], char nuevoNombre[15], char nuevaDescripcion[15], char descripcion[8][15], float ID[3][8])
{
    int cambio, var1, var2, menu;
    printf("Elegir accion a realizar.\n");
    printf("1.-Modificar producto                                         2.-Eliminar producto \n");
    scanf("%d", &cambio);

    switch (cambio)
    {
    case 1:
        printf("Ingrese el ID del producto a modificar:\n");
        scanf("%d", &var1);
        var1 = var1 - 1;
        printf("Ingrese el nuevo nombre del producto:");
        scanf("%s", nuevoNombre);
        strcpy(nombre[var1], nuevoNombre);
        printf("Ingrese la nueva descripcion del producto:");
        scanf("%s", nuevaDescripcion);
        strcpy(descripcion[var1], nuevaDescripcion);
        printf("Ingrese la cantidad de productos:");
        scanf("%f", &ID[1][var1]);
        printf("Ingrese el nuevo precio del producto:");
        scanf("%f", &ID[2][var1]);
        menu = 0;
        break;
    case 2:
        printf("Ingrese el ID del producto a eliminar:\n");
        scanf("%d", &var1);
        var1 = var1 - 1;
        var2 = 0;
        printf("Presione 1 para confirmar o 2 para cancelar la eliminacion del producto %.2f: %c\n", ID[var1][0], nombre[var1]);
        scanf("%d", &var2);
        if (var2 == 1)
        {
            ID[1][var1] = 0;
            ID[2][var1] = 0;
            strcpy(nombre[var1], "Vacio");
            strcpy(descripcion[var1], "Vacio");
        }
        printf("\n");
        menu = 0;
        break;
    default:
        printf("No se ingreso ninguna opcion valida\n");
        menu = 0;
        break;
    }
    return menu;
}