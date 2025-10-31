#include <stdio.h>
#include <math.h>

/*Declaramos f(x), f´(x) y f´´(x)*/
double f(double x){
  return 2*sin(x)-(pow(x,2)/10);
}

double df(double x){
  return 2*cos(x)-(x/5);
}
 
double ddf(double x){
  return -2*sin(x)-(1/5);
}

int main(){
  int i;
  double E_max=0.0001, x0=1, x1, Error;
  int contador=0;

  printf("Metodo de Newton-Raphson para encontrar el MAXIMO de \n");

  do{
    x1=x0-(df(x0)/ddf(x0));
    Error=fabs((x1-x0)/x1);
    contador++;

    printf("Iteracion %d:\n", contador);
    printf("x%d=%.6lf\n", contador, x1);
    printf("Error aproximado=%.6lf\n\n", Error);

    x0=x1;

  }while(Error>=E_max);

  printf("Se alcanzo el Emax establecido: %.6lf\n", E_max);
  printf("El MAXIMO se encuentra en x=%.6lf\n", x1);
  printf("Valor maximo f(x)=%.6lf\n", f(x1));

  return 0;
}