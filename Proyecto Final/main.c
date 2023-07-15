#include <stdio.h>
#include <string.h>
//El código se actualizó con pequeñas modificaciones estéticas

int menuPrincipal();
void crearArchivo(char nombreArchivo[]);
void guardarNombresArchivo(char nombreArchivo[], char ID[6][5][50]);
int verProductos(char ID[6][5][50], int var);
int nuevoProducto(FILE *archivo, char ID[6][5][50], char nombreArchivo[]);
int modificarProductos(FILE *archivo, char ID[6][5][50], char nombreArchivo[]);
int eliminarProducto(FILE *archivo, char ID[6][5][50], int var, char nombreArchivo);

int main(int argc, char *argv[])
{
    int menu;
    char ID[6][5][50] = {
        {"01", "Lambor", "Huracan", "3", "1.5"},
        {"02", "Porshe", "911 GT", "8", "1"},
        {"03", "Pagani", "Utopia", "2", "2.6"},
        {"04", "AstonM", "Valky", "1", "3.2"},
        {"05", "Ferrari", "Enzo", "4", "4.2"},
        {"06", "", "", "", ""},
    };

    char nombreArchivo[20] = "productos.txt";
    FILE *archivo;

    archivo = fopen(nombreArchivo, "r+");
    int var = 5;

    if (archivo == NULL)
    {
        crearArchivo(nombreArchivo);
        guardarNombresArchivo(nombreArchivo, ID);
    }
else{
    do
    {
        menu = menuPrincipal();
        switch (menu)
        {
        case 1:
            menu = verProductos(ID, var);
            break;
        case 2:
            menu = nuevoProducto(archivo, ID, nombreArchivo);
            var++;
            break;
        case 3:
            menu = modificarProductos(archivo, ID, nombreArchivo);
            break;
        case 4:
            menu = eliminarProducto(archivo, ID, var, nombreArchivo);
            var--;
            break;
        default:
            printf("No se ingresó ninguna opción válida.\n");
            menu = 0;
            break;
        }
    } while (menu !=5);
}
    fclose(archivo);
    return 0;
}

int menuPrincipal()
{
    int menu;
    printf("--------------------------------------INVENTARIO--------------------------------------\n");
    printf("1.-VER PRODUCTOS  \t 2.-INGRESAR PRODUCTOS \t\t 3.-MODIFICACION DE PRODUCTOS\t4.-ELIMINAR PRODUCTO\n");
    scanf("%d", &menu);
    return menu;
}

void crearArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("No se puede crear el archivo\n");
        return;
    }
    else
    {
        printf("Se ha creado el archivo: %s\n", nombreArchivo);
        fclose(archivo);
    }
}

void guardarNombresArchivo(char nombreArchivo[], char ID[6][5][50])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede guardar en el archivo\n");
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            fprintf(archivo, "%s %s %s %s %s\n", ID[i][0], ID[i][1], ID[i][2], ID[i][3], ID[i][4]);
        }
        fclose(archivo);
    }
}

int verProductos(char ID[6][5][50], int var)
{
    FILE *archivo;
    archivo = fopen("productos.txt", "r");
    int menu;

    printf("-------\tPRODUCTOS\t-------\n");
    printf("ID   NOMBRE\t\tDESCRIPCION\tCANTIDAD\tPRECIO\n");

    for (int i = 0; i < var; i++)
    {
        printf("%s\t%s\t\t%s\t\t%s\t\t\t%s M\n", ID[i][0], ID[i][1], ID[i][2], ID[i][3], ID[i][4]);
    }

    menu = 0;
    printf("\n");
    fclose(archivo);
    return menu;
}

int nuevoProducto(FILE *archivo, char ID[6][5][50], char nombreArchivo[])
{
    int menu;
    int i=5;
    printf("Ingrese el nuevo producto\n");
    printf("Nombre:");
    scanf("%s", ID[i][1]);
    printf("Descripcion:");
    scanf("%s", ID[i][2]);
    printf("Cantidad:");
    scanf("%s", ID[i][3]);
    printf("Precio: ");
    scanf("%s", ID[i][4]);

    fseek(archivo, 0, SEEK_END);
    ftell(archivo) / (sizeof(float) * 6 + sizeof(char) * 30);

    fprintf(archivo, "%.0f %.0f %.1f %s %s\n", (ID[i][0]), (ID[i][1]), (ID[i][2]), ID[i][3], ID[i][4]);
    guardarNombresArchivo(nombreArchivo, ID);
    fclose(archivo);
    printf("\n");
    menu = 0;
    return menu;
}

int modificarProductos(FILE *archivo, char ID[6][5][50], char nombreArchivo[])
{
    int var1, menu;

    printf("Ingrese el ID del producto a modificar:\n");
    scanf("%d", &var1);
    var1 = var1 - 1;

    fseek(archivo, var1 * (sizeof(float) * 3 + sizeof(char) * 30), SEEK_SET);
    fscanf(archivo, "%f %f %f %s %s\n", &ID[var1][0], &ID[var1][1], &ID[var1][2], ID[var1][3], ID[var1][4]);

    printf("Ingrese el nuevo nombre del producto:");
    scanf("%s", ID[var1][1]);
    printf("Ingrese la nueva descripcion del producto:");
    scanf("%s", ID[var1][2]);
    printf("Ingrese la cantidad de productos:");
    scanf("%s", ID[var1][3]);
    printf("Ingrese el nuevo precio del producto:");
    scanf("%s", ID[var1][4]);

    fseek(archivo, var1 * (sizeof(float) * 3 + sizeof(char) * 30), SEEK_SET);
    fprintf(archivo, "%s %s %s %s %s\n", ID[var1][0], ID[var1][1], ID[var1][2], ID[var1][3], ID[var1][4]);
    guardarNombresArchivo(nombreArchivo, ID);
    fclose(archivo);
    menu = 0;
    return menu;
}
int eliminarProducto(FILE *archivo, char ID[6][5][50], int var, char nombreArchivo)
{
    printf("------ ELIMINAR PRODUCTO ------\n");
    int var1, var2;

    printf("Ingrese el ID del producto a eliminar:\n");
    scanf("%d", &var1);
    fflush(stdin);
    var1 = var1 - 1;
    var2 = 0;

    printf("Presione 1 para confirmar o 2 para cancelar la eliminacion del producto con ID %d\n", var1 + 1);
    scanf("%d", &var2);

     if (var2 == 1)
{
    for (int i = var1; i < var; i++)
    {
        strcpy(ID[i][0], ID[i + 1][0]);
        strcpy(ID[i][1], ID[i + 1][1]);
        strcpy(ID[i][2], ID[i + 1][2]);
        strcpy(ID[i][3], ID[i + 1][3]);
        strcpy(ID[i][4], ID[i + 1][4]);
    }
    var--;

    fseek(archivo, 0, SEEK_SET);
    for (int i = 0; i < var; i++)
    {
        fprintf(archivo, "%s %s %s %s %s\n", ID[i][0], ID[i][1], ID[i][2], ID[i][3], ID[i][4]);
    }

    printf("Producto eliminado exitosamente.\n\n");
}
else
{
    printf("Eliminación cancelada.\n\n");
}

guardarNombresArchivo(nombreArchivo, ID);

int menu = 0;
return menu;
}
