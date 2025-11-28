#include <stdio.h>
#include <math.h>

int main(){

    // Parámetros 
    double c=12.5;      // coeficiente de arrastre (kg/s)
    double m=68.1;      // masa del paracaidista (kg)
    double a=8.3;       // parámetro del modelo
    double b=2.2;       // exponente del modelo
    double Vmax=46.0;   // velocidad máxima (m/s)
    double g=9.81;      // gravedad (m/s^2)

    // Condición inicial
    double V=0.0;       // velocidad inicial
    double t=0.0;       // tiempo inicial

    // Parámetros numéricos
    double dt=0.1;      // paso de tiempo
    double h=2;         // tiempo final 

    // Encabezado de resultados 
    printf("t (s)\tV (m/s)\n");
    printf("----------------------\n");

    while(t<=h+1e-9){

        // Imprimir valores actuales
        printf("%.1f\t%.5f\n",t,V);

        // k1 = f(t,V)
        double term1=V+a*pow(V/Vmax,b);   
        double k1=g-(c/m)*term1;          

        // Estimación intermedia: V_est=V+k1·dt
        double V_est=V+k1*dt;

        // k2 = f(t+dt,V_est)
        double term2=V_est+a*pow(V_est/Vmax,b);
        double k2=g-(c/m)*term2;

        // Actualización RK2: V=V+(dt/2)(k1+k2)
        V=V+0.5*(k1+k2)*dt;

        // Avanzar el tiempo
        t+=dt;
    }

    return 0;
}
