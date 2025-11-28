#include <stdio.h>
#include <math.h>

int main(){

    // Parámetros 
    double c=12.5;      // coeficiente de arrastre (kg/s)
    double m=68.1;      // masa (kg)
    double a=8.3;       // parámetro del modelo
    double b=2.2;       // exponente del modelo
    double Vmax=46.0;   // velocidad máxima (m/s)
    double g=9.81;      // gravedad (m/s^2)

    // Condición inicial
    double V=0;       // velocidad inicial
    double t=0;       // tiempo inicial

    
    double dt=0.1;      // paso de tiempo
    double h=2;      // tiempo final 

    // Encabezado de resultados
    printf("t (s)\tV (m/s)\n");
    printf("----------------------\n");

    while(t<=h+1e-9){

        // Imprimir estado actual 
        printf("%.1f\t%.5f\n",t,V);

        //           k1
        // Evaluar f(t,V)
        double term1=V+a*pow(V/Vmax,b);   // término completo de la ecuación
        double k1=g-(c/m)*term1;          // primera pendiente

        //           k2
        // Evaluar en (t+dt/2 , V+k1·dt/2)
        double V2=V+0.5*k1*dt;
        double term2=V2+a*pow(V2/Vmax,b);
        double k2=g-(c/m)*term2;          // segunda pendiente

       
        //           k3
        // Evaluar nuevamente en (t+dt/2 , V+k2·dt/2)
        double V3=V+0.5*k2*dt;
        double term3=V3+a*pow(V3/Vmax,b);
        double k3=g-(c/m)*term3;          // tercera pendiente

        
        //           k4
        // Evaluar en (t+dt , V+k3·dt)
        double V4=V+k3*dt;
        double term4=V4+a*pow(V4/Vmax,b);
        double k4=g-(c/m)*term4;          // cuarta pendiente

       
        //        Actualizar V
        
        // Formula de Runge–Kutta de cuarto orden:
        // V{n+1} = V + dt/6 (k1 + 2k2 + 2k3 + k4)
        V=V+(dt/6.0)*(k1+2*k2+2*k3+k4);

        // Avanzar el tiempo
        t+=dt;
    }

    return 0;
}
