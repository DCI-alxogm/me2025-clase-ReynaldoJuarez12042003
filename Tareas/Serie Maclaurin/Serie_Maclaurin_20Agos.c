/*Reynaldo Hassan Juarez Aranda
Serie de Maclaurin e^x, entrega: 22/agosto/2025*/

#include <stdio.h>
#include <math.h>
//Calcular el factorial de un numero entero con for
    int factorial(int n) {
      int facto=1;
      for (int i=1;i<=n;i=i+1) {
        facto=facto*i;
      }
      return facto;
    }

int main () {


  /*Declarar tipos de variables*/
  float x, Ea, Es, valoranterior, valoractual;
  int n, i, resultadofinal;
  char iniciar;

  /*Se aplica ciclo do-while*/
  do {
    //Solicitar el valor de x y Es
    printf("Escribe el valor de x:");
    scanf("%f", &x);
    printf("Escribe el valor de Es:");
    scanf("%f", &Es); 
    // Condicional if-else
    n=0;
    valoractual=1;
    valoranterior=0;
    Ea=100;
    printf("%-5s %-10s %-10s\n", "n", "Aprox", "Ea (%)");
    printf("---------------------------\n");

    if(n==0) {
      valoractual=1;  //x^0/0!
      Ea=100;        //Error limite
      printf("%-3d %-10.3f %-10s\n", n, valoractual, "---");
    }
    else {
      valoractual=pow(x,n)/factorial(n);
      Ea=fabs(((valoractual-valoranterior)/valoractual)*100);
    }

    //Ciclo for para continuar con suma de la ecuacion
    //hasta que el error Ea<Es
    for(n=1; Ea>Es; n++) {
      valoranterior=valoractual;
      valoractual=valoranterior+pow(x,n)/factorial(n);

      //Error Ea entre cada componente
      Ea=fabs(((valoractual-valoranterior)/valoractual)*100);
      printf("%-3d %-10.3f %-10.2f\n", n, valoractual, Ea);

      /*Ciclo if else dentro de for para controlar la convergencia*/
      if(Ea>Es) {
      }
      else {
        break;
      }
    }
    
    /*Impresión de resultados */
  
    printf("Valor real con exp(x):%.3f\n", exp(x));

    /*Continuar con otros valores*/
    printf("\n¿Realizar otro calculo? (s/n): ");
    scanf(" %c", &iniciar);
  }while (iniciar=='s' || iniciar== 'S');
  printf("\n Fin del calculo.\n");
  return 0;
}