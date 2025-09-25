//Reynaldo Hassan Juarez Aranda 
// Ejercicio 5 Inciso b)
/*Desarrolla un algoritmo ax^2+bx+c=0*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (){
  //Definir las variables en tipo float
  float a,b,c,x1,x2,discri;
  float xi1,xi2;
  //Definir variable tipo caracter para poder 
  //continuar con otros valores en el scanf
  char decision;
  //Se aplica ciclo do while
  do {

  //Solicitar y guardar los valores de a, b y c
  printf("Escribe el valor de a:");
  scanf("%f", &a);

  printf("Escribe el valor de b:");
  scanf("%f", &b);

  printf("Escribe el valor de c:");
  scanf("%f", &c);

  /*Primer condición, si a=0 no se resuelve por
  la ecuación general, pero si se puede obtener
  valor de x1 eliminando ax^2 y despejando para
  x, x=-c/b siempre y cuando b no sea 0*/
  if (a==0) {
    if (b!=0) {
      x1=-c/b;
      printf("El resultado de x1 es:%f\n",x1);

    } else {
      printf("El resultado es indefinido, trivial\n");
    }
  }else {
    /*Si a no es 0 se hace cuadratica, asignamos
    discri a lo que va dentro de la raiz para 
    reducir la complejidad y analizar los casos
    para indeterminación y resultados imaginarios*/
    discri=(b*b)-4*a*c;
    /*Segundo condicional, si discri es mayor
    de 0 se puede hacer si es igual a 0 o menor se hace compleja*/ 

    if(discri>=0) {
      x1=(-b+sqrt(discri))/(2*a);
      x2=(-b-sqrt(discri))/(2*a);
      printf("Resultados reales\n");
      printf("x1=%f\n",x1);
      printf("x2=%f\n",x2);
    }
    else {
      x1=(-b)/(2*a);
      x2=x1;
      xi1=(sqrt(abs(discri)))/(2*a);
      xi2=-xi1;
      printf("x1=%f\n",x1);
      printf("x2=%f\n",x2);
      printf("xi1=%f\n",xi1);
      printf("xi2=%f\n",xi2);
      printf("Las soluciones imaginarias son:\n");
      printf("%f+%fi y %f+%fi\n", x1,xi1,x2,xi2);
      
    }

  }
    //Volver a preguntar si queremos insertar
    //nuevos numeros 
    printf("¿Probar con otros valores? si o no (s/n): \n");
    scanf(" %c", &decision);

    }while(decision== 's' || decision== 'S' );
    
    return 0;


}
/*El resultado de las raices de la funcion f(x)=-0.5x^2+2.5x+4.5 son
Escribe el valor de a:-0.5
Escribe el valor de b:2.5
Escribe el valor de c:4.5
Resultados reales
x1=-1.405125
x2=6.405125
¿Probar con otros valores? si o no (s/n): 
n*/
