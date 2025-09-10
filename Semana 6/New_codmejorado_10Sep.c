/*Reynaldo Hassan Juarez Aranda 09/sep/2025
Metodo grafico bisección*/

#include <stdio.h>
#include <math.h>

float f(float c);

int main(){
    float Err_max=0.001;
    float a=4,b=20,Err,kold=INFINITY,k, fk, Eapr;
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
    
}

float f(float c){
  return ((9.81*68.1)/c)*(1-exp(-(c/68.1)*10))-40;
}