/*Primera parte de mi codigo */
#include <stdio.h>

#define N 3 // Número de ecuaciones

int main() {
    /* Declaración de la matriz aumentada [A | b], cuarta columna son los
    valores de b (resultados de cada ecuacion) */
    double A[N][N + 1] = {
        {3.0,  -0.1, -0.2,  7.85},
        {0.1,   7.0, -0.3, -19.3},
        {0.3,  -0.2,   10, 71.4}
    };
    int i,j,k;
    double factor;
    double x[N]; //En este vector se guardara la solucion 


    /*Imprimir la matriz inicial para comprobar vaores correctos */
    printf("Matriz inicial a resolver A: \n");
    for (i = 0; i < N; i++) {
      for (j = 0; j <= N; j++) {
        printf("%8.2f ", A[i][j]);
      }
      printf("\n");
    }





    }