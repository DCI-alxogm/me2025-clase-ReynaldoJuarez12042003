/*Reynaldo Hassan Juarez Aranda 
Resumen de metodos para encontrar raices 19/09/25
f(x)=2sin(x^1/2)-x*/

#include <stdio.h>
#include <math.h>

float f(float x);

float g(float x) {
  return 2*sin(sqrt(x));
}

float df(float x) {
  return ((cos(sqrt(x)))/(sqrt(x)))-1;
}

float df2(float x) {
  return -((sqrt(x)*sin(x))+(cos(sqrt(x))))/(2*x*sqrt(x));
}

int main(){
    float Err_max=0.0001;
    float a=0.1,b=2.5,Err,kold=INFINITY,k, fk, Eapr;
    printf("METODO BISECCION\n\n");
    printf("raiz\t f(k)\t Eapr \t Err\n");
    do{
        k=(a+b)/2;
        fk=f(k); 
        
        if (f(k)*f(a)<0){
          b=k;
        }else{
          a=k;
        }
        Eapr=k-kold;
        Err=fabsf(Eapr)/k;
         kold=k;
        printf("%f\t %f\t %f\t %f\n", k, fk, Eapr, Err);
    } while (Err>Err_max);
    printf("La ráiz aproximada es:%f\n", k);
    printf("f(c_raíz)=%f\n\n", f(k));
    printf("-------------------------------------------------------\n\n");

    //Metodo falsa posicion
    a=0.1;
    b=2.5;
    kold=k;
    Err_max=0.0001;
    printf("METODO FALSA POSICION\n\n");
    printf("raiz\t f(k)\t Eapr \t Err\n");
    do{
    k=((f(b)*a)-(f(a)*b))/(f(b)-f(a));
        fk=f(k);
        
        if (f(k)*f(a)<0){
          b=k;
        }else{
          a=k;
        }
        Eapr=k-kold;
        Err=fabsf(Eapr)/k;
         kold=k;
        printf("%f\t %f\t %f\t %f\n", k, fk, Eapr, Err);
    } while (Err>Err_max);
    printf("La ráiz aproximada es:%f\n", k);
    printf("f(c_raíz)=%f\n", f(k));

    printf("-------------------------------------------------------\n\n");

    //Metodo punto fijo
    float Error;
    float x0=0.8, x1;
    int contador=0;
    float E_max=0.0001;
    printf("METODO PUNTO FIJO\n\n");
    printf("Los resultados para encontrar la raiz de f(x)=2sin(x^1/2)-x son:\n");
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

  printf("-------------------------------------------------------\n\n");
  //Metodo Newton Raphson
   x0=0.8;
   contador=0;
    
    printf("METODO NEWTON RHAPSON\n\n");
    printf("Los resultados para encontrar la raiz de f(x)=2sin(x^1/2)-x son:\n");
    
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

  printf("-------------------------------------------------------\n\n");
  //METODO NEWTON MODIFICADO
   x0=0.8;
   contador=0;
   printf("METODO NEWTON RHAPSON MODIFICADO\n\n");
   printf("Los resultados para encontrar la raiz de f(x)=2sin(x^1/2)-x son:\n");
   do{
    x1=x0-(f(x0)*df(x0))/((df(x0)*df(x0))-(f(x0)*(df2(x0))));
    Error=fabs((x1-x0)/x1);
    contador++;

    printf("Iteracion %d:\n", contador);
    printf("x%d=%.9lf\n", contador, x1);
    printf("Error aproximado=%.9lf \n\n", Error);

    x0=x1;
  }while(Error>=E_max);
  printf("Se alcanzo el Emax establecido: %.9lf\n", E_max);
  printf("Ultima aproximacion a la raiz: x=%.9lf\n", x1);

  printf("-------------------------------------------------------\n\n");
  //METODO SECANTE
  float ximenos1=0.5, xi=0.8, ximas1;
  contador=0;
  printf("METODO DE LA SECANTE\n\n");
  printf("Los resultados para encontrar la raiz de f(x)=2sin(x^1/2)-x son:\n");
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














}

  



float f(float x){
  return 2*sin(sqrt(x)) - x;
}