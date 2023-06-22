#include <stdio.h> 
#include "funciones.h" 
 
int main (int argc, char *argv[]) { 
    /*Hacer un algoritmo que imprima todos los números primos que hay desde la unidad
hasta un número que introducimos por teclado. El programa debe poder ejecutarse
mientras el usuario lo requiera.*/

int num = pedirnum();
imprimirPrimos(num);
}
