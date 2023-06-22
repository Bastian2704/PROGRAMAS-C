#include <stdio.h> 
#include "funciones.h" 

int main (int argc, char *argv[]) { 

    float x1 = ingresarCoordenadaX();  
    float y1 = ingresarCoordenadaY(); 
    float x2 = ingresarCoordenadaX();  
    float y2 = ingresarCoordenadaY(); 
    float x3 = ingresarCoordenadaX(); 
    float y3 = ingresarCoordenadaY(); 

   
    obtenerArea(x1,y1,x2,y2,x3,y3);
 

    return 0;
}
