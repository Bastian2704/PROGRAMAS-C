#include <stdio.h> 
#include <math.h> 
#include "funciones.h" 

float ingresarCoordenadaX()  
{ 
    float cordx; 
    printf("Ingrese la coordenada en x: \n"); 
    scanf("%f", &cordx); 
    return cordx; 

} 


float ingresarCoordenadaY() 
{ 
    float cordy; 
    printf("Ingrese la coordenada en y: \n"); 
    scanf("%f", &cordy); 
    return cordy; 
} 

void obtenerArea(float x1, float y1, float x2,float y2,float x3,float y3){ 

float barx=(x1+x2+x3)/3; 
float bary=(y1+y2+y3)/3; 
if (x1!=x3 || y1!=y2) 
{ 
    printf("No es un triangulo rectángulo\n"); 
} 

if (x1==x3&& y1==y2) 
{ 
float h=sqrt(pow(x1-barx,2)); 
float pax=x1; 
float pay=bary; 
float dislado=sqrt(pow(x1-x3,2)+pow(y1-y3,2)); 
float areatri=(h*dislado)/2; 
printf("El area es: %f", areatri); 

} 
} 