/*Reynaldo Hassan Juarez Aranda
Secante 19/sep/25    f(x)=(e^-x) -x*/

#include <stdio.h>
#include <math.h>


/*Declaramos nuestra funcion en su forma g(x)*/
double f(double x) {
  return exp(-x)-x;
}

int main() {
  double E_max=1e-8, ximenos1=0, xi=0.1, ximas1, Error;
  int contador=0;

printf("Los resultados para encontrar la raiz de f(x)=(e^-x) -x son:\n");
do{
  ximas1=xi-((f(xi)*(ximenos1-xi))/(f(ximenos1)-f(xi)));
  Error=fabs((ximas1-xi)/ximas1);
  contador ++;

   printf("Iteracion %d:\n", contador);
    printf("x%d=%.9lf\n", contador, ximas1);
    printf("Error aproximado=%.9lf \n\n", Error);
    xi=ximas1;

}while(Error>=E_max);
printf("Se alcanzo el Emax establecido: %.9lf\n", E_max);
  printf("Ultima aproximacion a la raiz: x=%.9lf\n", ximas1);
  return 0;


}