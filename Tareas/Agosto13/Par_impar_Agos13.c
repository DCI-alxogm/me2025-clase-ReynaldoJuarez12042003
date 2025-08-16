//Reynaldo Hassan Juarez Aranda 
//Tarea 13/08/2025 Dado un número imprimir si es 
//par o impar. 

#include <stdio.h>
#include <math.h>

int main () {
  //Declaramos nuestras variables (valores enteros)
  int valor, residuo;
  printf("Escribe un numero:");

//&valor es donde se guarda el valor escrito
  scanf("%d", &valor);

  //Operador de modulo (regresa el residuo de la division entre dos)
  residuo=valor%2;
  //Se usa un condicional para comparar el residuo de la division
  // y determinar si es par o impar. 
  //Si el residuo es igual a 0 es par, si es diferente de 0 es impar.

  if (residuo==0){
    printf("El numero es par\n");
  }
  else {
    printf("El numero es impar\n");
  }
  //Se repite lo anterior para que vuelva a pedir un numero 

  printf("Ingresa otro numero:\n");
  scanf("%d", &valor);
  residuo=valor%2;

  if (residuo==0){
    printf("El numero es par\n");
  }
  else {
    printf("El numero es impar\n");
  }

}

  





