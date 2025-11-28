/* Problema del paracaidista - Euler */

#include <stdio.h>
#include <math.h>

int main(){

    double c=12.5;      // coeficiente de arrastre (kg/s)
    double m=68.1;      // masa del paracaidista (kg)
    double a=8.3;       // parámetro del modelo
    double b=2.2;       // exponente del modelo
    double Vmax=46.0;   // velocidad máxima (m/s)
    double g=9.81;      // gravedad (m/s^2)

    
    double V=0.0;       // velocidad inicial
    double t=0.0;       // tiempo inicial

    // Parámetros numéricos del método de Euler
    double h=0.1;       // paso de tiempo
    double tf=2.0;      // tiempo final

    // Encabezado de resultados
    printf("t (s)\tV (m/s)\n");
    printf("----------------------\n");

    // Ciclo while para las iteraciones
    while(t<=tf+1e-9){

        // Imprimir el tiempo actual y la velocidad actual
        printf("%.1f\t%.5f\n",t,V);

        // Calcular el término interior
        double term=V+a*pow(V/Vmax,b);

        //Exterior por interior 
        double dVdt=g-(c/m)*term;

        // Actualizar velocidad con el método de Euler
        V=V+dVdt*h;

        // Avanzar el tiempo
        t+=h;
    }

    return 0;
}
