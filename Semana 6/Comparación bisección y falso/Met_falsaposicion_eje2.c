/*Reynaldo Hassan Juarez Aranda 12/sep/2025
Metodo falsa posicion ejercicio 2 */
/*Fue menos eficiente, se ocupo mas iteraciones y el f(c_raix) 
fue mas lejano de la interseccion de cero*/

#include <stdio.h>
#include <math.h>

float f(float c);

int main(){
    float Err_max=0.0001;
    float a=0,b=1.3,Err,kold=INFINITY,k, fk, Eapr;
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
    
}

float f(float c){
  return pow(c,10)-1;
}