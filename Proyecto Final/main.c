#include <stdio.h>
#include <string.h>

int menuPrincipal();
void crearArchivo(char nombreArchivo[]);
void guardarNombresArchivo(char nombreArchivo[], char ID[7][5][50]);
int verProductos(char ID[7][5][50],int var);
int nuevoProducto(FILE *archivo, char ID[7][5][50],int var);
int modificarProductos(FILE *archivo, char ID[7][5][50]);

int main(int argc, char *argv[])
{
    int menu;
    char ID[7][5][50] = {
        {"01", "Lambor", "Huracan", "3", "1.5"},
        {"02", "Porshe", "911 GT", "8", "1"},
        {"03", "Pagani", "Utopia", "2", "2.7"},
        {"04", "AstonM", "Valky", "1", "3.2"},
        {"05", "Ferrari", "Enzo", "4", "4.2"},
        {"06", "", "", "", ""}, 
        {"07", "", "", "", ""}  
    };

    char nombreArchivo[20] = "productos.txt";
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    int var=5;

    if (archivo == NULL)
    {
        crearArchivo(nombreArchivo);
        guardarNombresArchivo(nombreArchivo, ID);
    }

    do
    {
        menu = menuPrincipal();
        switch (menu)
        {
        case 1:
            menu = verProductos(ID,var);
            break;
        case 2:
            menu = nuevoProducto(archivo, ID, var);
            var++;
            break;
        case 3:
            menu = modificarProductos(archivo, ID);
            break;
        default:
            printf("No se ingresó ninguna opción válida.\n");
            menu = 0;
            break;
        }
    } while (menu == 0);

    fclose(archivo);
    return 0;
}

int menuPrincipal()
{
    int menu;
    printf("--------------------------------------INVENTARIO--------------------------------------\n");
    printf("1.-VER PRODUCTOS  \t 2.-INGRESAR PRODUCTOS \t\t 3.-MODIFICACION DE PRODUCTOS\n");
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

void guardarNombresArchivo(char nombreArchivo[], char ID[7][5][50])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede guardar en el archivo\n");
    }
    else
    {
        for (int i = 0; i < 7; i++) // Corregido el límite del bucle
        {
            fprintf(archivo, "%s %s %s %s %s\n", ID[i][0], ID[i][1], ID[i][2], ID[i][3], ID[i][4]);
        }
        fclose(archivo);
    }
}

int verProductos(char ID[7][5][50],int var)
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

int nuevoProducto(FILE *archivo, char ID[7][5][50],int var)
{
    int menu;
    int i = var; 
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
    ftell(archivo) / (sizeof(float) * 7 + sizeof(char) * 30); 

    fprintf(archivo, "%.0f %.0f %.1f %s %s\n", atof(ID[i][0]), atof(ID[i][1]), atof(ID[i][2]), atof(ID[i][3]), atof(ID[i][4])); 

    printf("\n");
    menu = 0;
    return menu;
}

int modificarProductos(FILE *archivo, char ID[7][5][50])
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
        fprintf(archivo, " %s %s %s %s\n", ID[var1][1],ID[var1][2], ID[var1][3], ID[var1][4]);

        menu = 0;
        break;
    case 2:
        printf("Ingrese el ID del producto a eliminar:\n");
        scanf("%d", &var1);
        var1 = var1 - 1;
        var2 = 0;
        printf("Presione 1 para confirmar o 2 para cancelar la eliminacion del producto con ID %d\n", var1 + 1);
        scanf("%d", &var2);
        if (var2 == 1)
        {
            fseek(archivo, var1 * (sizeof(float) * 3 + sizeof(char) * 30), SEEK_SET);
            fprintf(archivo, "%s 0 0 Vacio Vacio\n",ID[var1][0]);
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