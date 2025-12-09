#include <stdio.h>
#include <math.h>

int main(){
    // Parámetros
    double k=0.45;         // constante cinética (L/mol·min)
    double Cmax=1;       // concentración máxima (mol/L)

    // Condición inicial
    double C=0.02;         // concentración inicial (mol/L)
    double t=0;          // tiempo inicial (min)

    // Parámetros numéricos
    double dt=0.01;        // paso de tiempo
    double h=25.0;         // tiempo final (min)

    // Encabezado
    printf("t (min)\tC (mol/L)\n");
    printf("----------------------\n");

    while(t<=h+1e-9){
        // Imprimir valores actuales
        printf("%.2f\t%.6f\n",t,C);

        //k1=f(t,C)
        double k1=k*C*(Cmax-C);

        // Estimación intermedia: C_est=C+k1·dt
        double C_est=C+k1*dt;

        //k2=f(t+dt,C_est)
        double k2=k*C_est*(Cmax-C_est);

        //Actualización RK2:C=C+(dt/2)(k1+k2)
        C=C+0.5*(k1+k2)*dt;

        //Avanzar el tiempo
        t+=dt;
    }

    return 0;
}
