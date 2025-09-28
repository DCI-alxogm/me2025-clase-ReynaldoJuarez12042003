/*Reynaldo Hassan Juarez Aranda 27/sep/2025
Metodo falsa posicion ejercicio 6 */
/*Sustituyendo los valores en la formula y dividiendo entre tres
ambos lados la funcion queda f(x)=(9*pi*h^2)-(pi*h^3)-90
Resultados
Consideraciones para la raiz:
-. La profundidad maxima es cuando se llena d=6 m por lo tanto, 
la raiz no puede ser mayor a esto, y graficando la funcion
el valor verdadero esta entre 2 y 3 
raiz	     f(k)	       Eapr 	    Err
2.024919	 -0.150769	 -inf	     inf
2.026761	 -0.010980	 0.001842	 0.000909
2.026895	 -0.000793	 0.000134	 0.000066
2.026905	 -0.000051	 0.000010	 0.000005
2.026906	 -0.000015	 0.000000	 0.000000
2.026906	  0.000004	 0.000000	 0.000000
2.026906	  0.000004	 0.000000	 0.000000
La ráiz aproximada es:2.026906
f(c_raíz)=0.000004
El resultado es h=2.026906 m para que el volumen del tanque
sean 30 m^3*/

#include <stdio.h>
#include <math.h>

float f(float c);

int main(){
    float Err_max=0.00000001;
    float a=2,b=3,Err,kold=INFINITY,k, fk, Eapr;
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
  return (9*3.141592654*pow(c,2))-(3.141592654*pow(c,3))-90;
}