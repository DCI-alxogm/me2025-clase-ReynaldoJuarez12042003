/*Reynaldo Hassan Juarez Aranda
Newton-Raphson 29/sep/25 ejercicio 10*/

#include <stdio.h>
#include <math.h>


/*Declaramos f(x) y f´(x)*/
double f(double x) {
  return (9*3.141592654*pow(x,2))-(3.141592654*pow(x,3))-90;
}

double df(double x) {
  return (18*3.141592654*x)-(3*3.141592654*pow(x,2));
}

int main() {
  int i;
  double E_max=1e-3, x0=1.5, x1, Error;
  int contador=0;

  printf("Los resultados para encontrar la raiz de f(x)=(e^-x) -x son:\n");

  do{
    x1=x0-(f(x0)/df(x0));
    Error=fabs((x1-x0)/x1);
    contador++;

    printf("Iteracion %d:\n", contador);
    printf("x%d=%.9lf\n", contador, x1);
    printf("Error relativo=%.9lf \n\n", Error);

    x0=x1;

  }while(Error>=E_max);
   printf("Se alcanzo el Emax establecido: %.9lf\n", E_max);
  printf("Ultima aproximacion a la raiz: x=%.9lf\n", x1);
  printf("La diferencia entre la tercera iteracion de este metodo y el de falsa posición es: %f", x1-2.026906);
  return 0;



}