#include <stdio.h>
#include <math.h>

int main(){
    // Parámetros 
    double k=0.45;       // constante cinética (L/mol·min)
    double Cmax=1;       // concentración máxima (mol/L)

    // Condición inicial
    double C=0;          // concentración inicial (mol/L)
    double t=0;          // tiempo inicial

    // Ajuste del valor real de C(0)
    C=0.02;

    double dt=0.1;       // paso de tiempo
    double h=25;         // tiempo final (min)

    // Encabezado de resultados
    printf("t (min)\tC (mol/L)\n");
    printf("----------------------\n");

    while(t<=h+1e-9){
        // Imprimir estado actual 
        printf("%.1f\t%.6f\n",t,C);

        //           k1
        // Evaluar f(t, C)
        double k1=k*C*(Cmax-C);

        //           k2
        // Evaluar en (t+dt/2 , C+k1·dt/2)
        double C2=C+0.5*k1*dt;
        double k2=k*C2*(Cmax-C2);

        //           k3
        // Evaluar nuevamente en (t+dt/2 , C+k2·dt/2)
        double C3=C+0.5*k2*dt;
        double k3=k*C3*(Cmax-C3);

        //           k4
        // Evaluar en (t+dt , C+k3·dt)
        double C4=C+k3*dt;
        double k4=k*C4*(Cmax-C4);

        //        Actualizar C
        // Fórmula de Runge–Kutta de cuarto orden:
        // C{n+1} = C + dt/6 (k1 + 2k2 + 2k3 + k4)
        C=C+(dt/6.0)*(k1+2*k2+2*k3+k4);

        // Avanzar el tiempo
        t+=dt;
    }
    return 0;
}

