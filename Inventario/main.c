#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    int menu, contador;
    contador = 5;
    float ID[3][8] = {{1, 2, 3, 4, 5, 6, 7, 8}, {3, 8, 2, 1, 4, 0}, {1.5, 1, 2.7, 3.2, 4.2, 0}};
    char nombre[8][15] = {"Lambor", "Porshe", "Pagani", "AstonM", "Ferrari", "", ""};
    char nuevoNombre[15];
    char descripcion[8][15] = {"Huracan", "911 GT", "Utopia", "Valky", "Enzo", "", ""};
    char nuevaDescripcion[15];
    float precio, cantidad;
    // RollsR Swep 3 2          Buggati Chiron 4 7.2

    do
    {
        menu = menuPrincipal();
        switch (menu)
        {
        case 1:
            menu = verProductos(ID, nombre, descripcion, contador);
            break;
        case 2:
            menu = nuevoProducto(nombre, nuevoNombre, nuevaDescripcion, descripcion, ID, contador);
            contador += 1;
            break;
        case 3:
            menu=modificarProductos(nombre, nuevoNombre, nuevaDescripcion, descripcion, ID);
            break;

        default:
            printf("No se ingreso ninguna opcion valida\n");
            menu = 0;
            break;
        }

    } while (menu == 0);
}
