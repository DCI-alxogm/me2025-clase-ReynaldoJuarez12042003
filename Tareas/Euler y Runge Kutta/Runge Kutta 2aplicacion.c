#include <stdio.h>
#include <math.h>

int main(){

    // Condiciones iniciales (libras de sal)
    double x1=15, x2=0, x3=0;

    // Parámetros numéricos
    double h=0.1, tf=5, t=0;

    // Encabezado
    printf("t\tx1\t\tx2\t\tx3\n");
    printf("--------------------------------------\n");

    while(t<=tf+1e-9){

        // Imprimir valores actuales
        printf("%.1f\t%.6f\t%.6f\t%.6f\n",t,x1,x2,x3);

        // k1 = f(t, x)
        double k1_x1=-(0.5)*x1;
        double k1_x2=(0.5)*x1-(0.25)*x2;
        double k1_x3=(0.25)*x2-(0.2)*x3;

        // Estimación: x_est = x + k1*h
        double x1_est=x1+k1_x1*h;
        double x2_est=x2+k1_x2*h;
        double x3_est=x3+k1_x3*h;

        // k2 = f(t+h, x_est)
        double k2_x1=-(0.5)*x1_est;
        double k2_x2=(0.5)*x1_est-(0.25)*x2_est;
        double k2_x3=(0.25)*x2_est-(0.2)*x3_est;

        // Actualización final RK2
        x1=x1+0.5*h*(k1_x1+k2_x1);
        x2=x2+0.5*h*(k1_x2+k2_x2);
        x3=x3+0.5*h*(k1_x3+k2_x3);

        // Avanza tiempo
        t+=h;
    }

    return 0;
}
