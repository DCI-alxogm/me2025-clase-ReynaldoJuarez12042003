#include <stdio.h>
#include <math.h>

int main(){

    // Condiciones iniciales (libras de sal)
    double x1=15;  // tanque 1
    double x2=0.0;   // tanque 2
    double x3=0.0;   // tanque 3

    // Parámetros numéricos
    double dt=0.1;   // paso de tiempo
    double tf=5.0;   // tiempo final
    double t=0.0;    // tiempo inicial

    // Encabezado
    printf("t\tx1\t\tx2\t\tx3\n");
    printf("--------------------------------------\n");

    while(t<=tf+1e-9){

        // Imprimir estado actual
        printf("%.1f\t%.6f\t%.6f\t%.6f\n",t,x1,x2,x3);

        //  k1 
        double k1_1=-(0.5)*x1;
        double k1_2=(0.5)*x1-(0.25)*x2;
        double k1_3=(0.25)*x2-(0.2)*x3;

        // estimaciones intermedias
        double x1_2=x1+0.5*k1_1*dt;
        double x2_2=x2+0.5*k1_2*dt;
        double x3_2=x3+0.5*k1_3*dt;

        //  k2 
        double k2_1=-(0.5)*x1_2;
        double k2_2=(0.5)*x1_2-(0.25)*x2_2;
        double k2_3=(0.25)*x2_2-(0.2)*x3_2;

        // nuevas estimaciones
        double x1_3=x1+0.5*k2_1*dt;
        double x2_3=x2+0.5*k2_2*dt;
        double x3_3=x3+0.5*k2_3*dt;

        //  k3 
        double k3_1=-(0.5)*x1_3;
        double k3_2=(0.5)*x1_3-(0.25)*x2_3;
        double k3_3=(0.25)*x2_3-(0.2)*x3_3;

        // estimaciones para k4
        double x1_4=x1+k3_1*dt;
        double x2_4=x2+k3_2*dt;
        double x3_4=x3+k3_3*dt;

        //  k4 
        double k4_1=-(0.5)*x1_4;
        double k4_2=(0.5)*x1_4-(0.25)*x2_4;
        double k4_3=(0.25)*x2_4-(0.2)*x3_4;

        //  Actualización RK4 
        x1=x1+(dt/6.0)*(k1_1+2*k2_1+2*k3_1+k4_1);
        x2=x2+(dt/6.0)*(k1_2+2*k2_2+2*k3_2+k4_2);
        x3=x3+(dt/6.0)*(k1_3+2*k2_3+2*k3_3+k4_3);

        // avanzar tiempo
        t+=dt;
    }

    return 0;
}
