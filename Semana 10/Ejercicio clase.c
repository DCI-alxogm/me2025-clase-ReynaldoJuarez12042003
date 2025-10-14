#include <stdio.h>

#define N 3 // Número de ecuaciones

int main() {
    
    double A[N][N + 1] = {
        {3.0, -0.1, -0.2, 7.85},
        {0.1, 7.0, -0.3, -19.3},
        {0.3, -0.2, 10.0, 71.4}
    };

    int i, j, k;
    double factor;
    double x[N]; //Se guarda los valores de x

    // Imprimir matriz original
    printf("Matriz inicial de entrada:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }

    // Eliminación hacia adelante
    for (i = 0; i < N - 1; i++) {
        for (k = i + 1; k < N; k++) {
            factor = A[k][i] / A[i][i];
            for (j = i; j <= N; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // Sustitución hacia atrás
    for (i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Imprimir matriz final
    printf("\nMatriz después de la eliminación:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }

    // Imprimir resultados
    printf("\nSolución del sistema:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    return 0;
}
