/*Usa el método de bisección para encontrar todas la raices de la función 
f(x)=Sin(10x)-Cos(3x) en el rango de x=3 a x=5, con un error relativo máximo entre iteraciones de Er=0.001. 
Determina si la relación Ea=\delta x/2^n  se satisface para cada raíz encontrada.*/

/*Reynaldo Hassan Juarez Aranda 09/sep/2025
En todas las raices se cumple la relacion pero en este caso la raiz 4 sael
que no y es por la tolerancia de los decimales que toma el programa 
*/


#include <stdio.h>
#include <math.h>

float f(float c); // Declarar la funcion

int main(){
    float Err_max=0.0001;
    float xi=3,xf=5,Err,kold,k, fk, Eapr, a, b;
    float paso=0.005;
    int contador=0;


    for(a=xi;a<xf;a+=paso) {
      b=a+paso;
      if (f(a)*f(b)<0){
        kold=INFINITY; 
        float ai=a;
        float bi=b;
        int n=0;
        printf("Raiz\t\t f(k)\t\t Eapr\t\t Err\n");

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
         n++;
        printf("%f\t %f\t %f\t %f\n", k, fk, Eapr, Err);
    } while (Err>Err_max);
     printf("La ráiz aproximada es:%f\n", k);
     printf("f(c_raíz)=%f\n\n", f(k));

     //Relacion 
     float Ea=(bi-ai)/(pow(2,n));
     printf("Numero de iteraciones (n): %d\n", n);
     printf("Ea (deltax/2^n)=%f\n ", Ea);
     printf("Valor final de Eapr=%f\n", fabsf(Eapr));

     
     if(fabsf(Eapr)<=Ea) {
      printf("Se cumple la relacion Ea\n");
     }else{
      printf("No se cumple la realacion Ea\n");
     }

     printf("-------------------------------------------------------------\n");





     contador ++;

      }
    }
    
    printf("Se encontraron %d raices en el intervalo [3,5]\n", contador);
    return 0;
    
}

float f(float c){
  return sin(10*c)-cos(3*c);
}