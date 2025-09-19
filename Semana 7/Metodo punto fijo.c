/*Reynaldo Hassan Juarez Aranda
Punto fijo 19/sep/25    f(x)=(e^-x) -x*/
#include <stdio.h>
#include <math.h>

/*Declaramos nuestra funcion en su forma g(x)*/
double g(double x) {
  return exp(-x);
}

int main() {
  int i;
  double E_max=1e-8, x0=0, x1, Error;
  int contador=0;


  printf("Los resultados para encontrar la raiz de f(x)=(e^-x) -x son:\n");
  
  do{
    x1=g(x0);
    Error=fabs((x1-x0)/x1);
    contador++;
    printf("Iteracion %d:\n", contador);
    printf("x%d=%.9lf\n", contador, x1);
    printf("Error aproximado=%.9lf \n\n", Error);
    x0=x1;

  }while(Error>=E_max);

  printf("Se alcanzo el Emax establecido: %.9lf\n", E_max);
  printf("Ultima aproximacion a la raiz: x=%.9lf\n", x1);
  return 0;
}
