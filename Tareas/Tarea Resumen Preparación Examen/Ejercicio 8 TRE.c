/*Reynaldo Hassan Juarez Aranda
Ejercicio 8 Tarea Secante modificada*/

#include <stdio.h>
#include <math.h>



double f(double x) {
  return (1e6)-(1e5*x)-(0.25*1e6*pow(x,0.5)) ;
}

int main() {
  double E_max=1e-6, xi=4, s=0.5,ximas1, Error;
  int contador=0;

printf("Los resultados para encontrar la raiz de f(c)=W-Qc-kV(c)^0.5 son:\n");
do{
  ximas1=xi-((s*xi*f(xi))/(f(xi+(s*xi))-f(xi)));
  Error=fabs((ximas1-xi)/ximas1)*100;
  contador ++;

   printf("Iteracion %d:\n", contador);
    printf("x%d=%.9lf\n", contador, ximas1);
    printf("Error aproximado=%.9lf %% \n\n", Error);
    xi=ximas1;

}while(Error>=E_max);
printf("Se alcanzo el Emax establecido: %.9lf %%\n", E_max);
  printf("Ultima aproximacion a la raiz: x=%.9lf\n", ximas1);
  return 0;


}