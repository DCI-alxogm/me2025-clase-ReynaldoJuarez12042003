/* Sistema de 3 tanques con sal - Método de Euler */

#include <stdio.h>
#include <math.h>

int main(){

    // Condiciones iniciales (libras de sal)
    double x1=15;   // tanque 1
    double x2=0;    // tanque 2
    double x3=0;    // tanque 3

    // Parámetros numéricos
    double h=0.01;     // paso de tiempo
    double tf=5;   // tiempo final
    double t=0;     // tiempo inicial

    // Encabezado
    printf("t(s)\tx1(lb)\tx2(lb)\tx3(lb)\n");
    printf("--------------------------------------\n");

    // Iteración del método de Euler
    while(t<=tf+1e-9){

        // Imprimir valores actuales
        printf("%.2f\t%.5f\t%.5f\t%.5f\n",t,x1,x2,x3);

        // Ecuaciones diferenciales del sistema
        double dx1dt=-(1.0/2.0)*x1;
        double dx2dt=(1.0/2.0)*x1-(1.0/4.0)*x2;
        double dx3dt=(1.0/4.0)*x2-(1.0/5.0)*x3;

        // Actualizar variables con Euler
        x1=x1+dx1dt*h;
        x2=x2+dx2dt*h;
        x3=x3+dx3dt*h;

        // Avanzar el tiempo
        t+=h;
    }

    return 0;
}
