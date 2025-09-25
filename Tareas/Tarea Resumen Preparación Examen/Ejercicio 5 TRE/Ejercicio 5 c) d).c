
/*Reynaldo Hassan Juarez Aranda * Inciso c) y d)/
/*En este ejercicio se calcularon las raices dentro del rango -2,7
y se encontraron las dos raices incluyendo la raiz mas grandes, y el error aproximado y el real */
/*Raiz		 f(k)		 Eapr		 Err
-1.407501	 -0.009280	 -inf	 -inf
La ráiz aproximada es:-1.407501
f(c_raíz)=-0.009280

Numero de iteraciones (n): 1
Ea (deltax/2^n)=0.002500
 Valor final de Eapr=inf
No se cumple la realacion Ea
-------------------------------------------------------------
Raiz		 f(k)		 Eapr		 Err
6.405097	 0.000107	 -inf	 inf
6.406347	 -0.004775	 0.001250	 0.000195
6.405723	 -0.002335	 -0.000625	 0.000098
La ráiz aproximada es:6.405723
f(c_raíz)=-0.002335

Numero de iteraciones (n): 3
Ea (deltax/2^n)=0.000625
 Valor final de Eapr=0.000625
Se cumple la relacion Ea
-------------------------------------------------------------
Se encontraron 2 raices en el intervalo [3,5]*/




#include <stdio.h>
#include <math.h>

float f(float c); // Declarar la funcion

int main(){
    float Err_max=0.0001;
    float xi=-2,xf=7,Err,kold,k, fk, Eapr, a, b;
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
  return -0.5*pow(c,2)+2.5*c+4.5;
}
