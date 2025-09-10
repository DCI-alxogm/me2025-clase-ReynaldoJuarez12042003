/*Reynaldo Hassan Juarez Aranda*/


#include <stdio.h>
#include <math.h>

float f(float c);

int main(){
    float Err_max=1e-6;
    float a=4,b=20,Err,kold,k;

    kold=a;
    do{
        k=(a+b)/2;
        Err=fabs(k-kold)/k;
        if (f(k)*f(a)<0){
          b=k;
        }else{
          a=k;
          kold=k;
        }
    } while (Err>Err_max);
    printf("La ráiz aproximada es:%f\n", k);
    printf("f(c_raíz)=%f\n", f(k));
}
float f(float c){
  return ((9.81*68.1)/c)*(1-exp(-(c/68.1)*10))-40;
}