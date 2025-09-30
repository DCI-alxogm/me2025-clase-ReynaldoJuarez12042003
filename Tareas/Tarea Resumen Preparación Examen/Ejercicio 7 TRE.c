#include <stdio.h>
#include <math.h>

 float concentracion;
float f(float c);

int main(){
   
    float Err_max=0.0001;
    float a=270,b=280,Err,kold=INFINITY,k, fk, Eapr;
    concentracion=14.621;
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
    printf("f(c_raíz)=%f\n", f(k));
    printf("La temperatura en !C es: %f\n", k-273.15);

    concentracion=6.413;
    a=308.15;
    b=318.15;
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
    printf("f(c_raíz)=%f\n", f(k));
    printf("La temperatura en !C es: %f\n", k-273.15);

    
}

float f(float c){
  return (-139.34411f +
            (1.575701e5f / c) -
            (6.642308e7f / powf(c, 2)) +
            (1.243800e10f / powf(c, 3)) -
            (8.621949e11f / powf(c, 4))) - log(concentracion);
}