#include <stdio.h>
#define N 2 //Numero de ecuaciones
 
int main() {
    double A[N][N + 1] = {
        {1, 2, 10},
        {1.05, 2, 10.4},
        
    };
 
    double pivot[N];
    double temp;
    double x[N];
    int i, j, k;
 
    printf("Matriz inicial de entrada:\n");
    for (i= 0;i<N;i++) {
        for (j=0;j<=N;j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
 
    //pivote--------------------------------------------------------------------------------
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            if (i==j) {
                // Si el pivote es cero, intercambiar con la fila siguiente
                if(A[i][j]==0) {
                    for (k=0;k<N+1;k++) {
                        pivot[k]=A[i][k];              // Guardar fila i
                        A[i][k]=A[i+1][k];          // Fila siguiente sube
                        A[i + 1][k]=pivot[k];         // Guardar fila original
                    }
                }
            }
        }
    }
   //-----------------------------------------------------------------------------------
    //Eliminacion hacia adelante 
    for (i=0;i<N-1;i++) {
        for(k=i+1;k<N;k++) {
            double factor=A[k][i]/A[i][i];
            for (j=i;j<=N;j++) {
                A[k][j]-=factor*A[i][j];
            }
        }
    }
 
    // Sustitucion hacia atras 
    for(i=N-1;i>=0;i--) {
        x[i]=A[i][N];
        for(j=i+1;j<N;j++) {
            x[i]-=A[i][j]*x[j];
        }
        x[i]/=A[i][i];
    }
 
    // Imprimir matriz final 
    printf("\nMatriz después del pivoteo y eliminación:\n");
    for(i=0;i<N;i++) {
        for(j=0;j<=N;j++) {
            printf("%8.2f",A[i][j]);
        }
        printf("\n");
    }
    //Imprimir resultados 
    printf("\nSolución del sistema:\n");
    for(i=0;i<N;i++) {
        printf("x%d = %.4f\n", i+1,x[i]);
    }
 
    return 0;
}