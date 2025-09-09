/*Reynaldo Hassan Juarez Aranda
09/09/2025*/

#include <stdio.h>
#include <math.h>
float fx(float x);

int main() {
  //Declarar variables
float a,b, Emax,Err, kold;
float k=(a+b)/2;
//pedir al ussuario 
printf("Escribe el valor de a:");
scanf("%f", &a);
printf("Escribe el valor de b:");
scanf("%f", &b);

//Pedir funcion
float fx(float x) {
  float f;
  printf("Ingresa la funcion f:");
  scanf("%f", &f);
  return f;
}

}
