#include <stdio.h> 


int main (int argc, char *argv[]) { 
    float matriz[3][4];
    int i=0;
    for ( i = 0; i < 3; i++)
    {
for ( int j = 0; i < 4; i++)
{
printf("Ingrese la posición %d %d\n",i+1,j+1);
scanf("%f", &matriz[i][j]);
}
    }
  
}