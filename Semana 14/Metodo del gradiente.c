/*Reynaldo Hassanb Juarez Aranda 05/*11/2025*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Funcion
double f(double x, double y) {
  return (2*x*y)+(2*x)-(pow(x,2))-(2*pow(y,2));
}
//Parcial respecto a x
double dfx(double x, double y) {
  return (2*y)+2-(2*x);
}
//Parcial respecto a y
double dfy(double x, double y) {
  return (2*x)-(4*y);
}
int main () {

double x=-1, y=1; 




//DIRECCION VECTOR GRADIENTE 
fevaluada=f(x,y);
dfxevaluada=dfx(x,y);
dfyevaluada=dfy(x,y);
gh=







}
