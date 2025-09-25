


/*Reynaldo Hassan Juarez Aranda
25/09/2025 Ejercicio 4 */

#include <stdio.h>
#include <math.h>
//Definimos funcion f(x)
float fx(float x) {
  float f;
  f=(25*(x*x*x))-(6*(x*x))+(7*x)-88;
  return f;
}
//Definimos la funcion f´(x) para comparar con el valor real 
float dfx_exacto(float x) {
  float df;
  df=(75*(x*x))-(12*x)+7;
  return df;
}


int main() {
  int i;
  float x=2, h=0.20;
  float valor_exacto=dfx_exacto(x);
  float  fpa, fpb, fpc;//Primera derivada
  
  //Primera derivada 
  printf("Aproximaciones primera derivada (x, adelante, atras, centrada):\n");
  
    fpa=(fx(x+h)-fx(x))/h;
    float error_adelante=fabs(valor_exacto-fpa);

    fpb=(fx(x)-fx(x-h))/h;
    float error_atras=fabs(valor_exacto-fpb);


    fpc=(fx(x+h)-fx(x-h))/(2*h);
    float error_centrado=fabs((valor_exacto-fpc)/valor_exacto)*100;


    printf("Valor exacto de la derivada real: %f\n\n", valor_exacto);

    printf("Valor aproximado hacia adelante: %f\n\n", fpa);
    printf("Error de aproximacion en : %f%%\n\n", error_adelante);

    printf("Valor aproximado hacia atras: %f\n\n", fpb);
    printf("Error de aproximacion: %f%%\n\n", error_atras);

    printf("Valor aproximado centrado: %f\n\n", fpc);
    printf("Error de aproximacion: %f%%\n\n", error_centrado);

    printf("La aproximación central es mejor por su termino residual de orden O(h^2)\n");
    printf("y para un h=0.02 h es menor, cuanto mas pequeña e el error de orden converge mas rapido");
    

    
    
    }

