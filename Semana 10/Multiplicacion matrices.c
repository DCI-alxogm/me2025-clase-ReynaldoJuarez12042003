#include <stdio.h>

// Definición de las dimensiones de las matrices
#define FILAS_A 3
#define COLS_A 3 // Esto debe ser igual a FILAS_B para la multiplicación
#define FILAS_B 3
#define COLS_B 2
#define FILAS_C FILAS_A
#define COLS_C COLS_B

int main() {
    // 1. Declaración e inicialización de las matrices A y B
    // Matriz A (3x3)
    int A[FILAS_A][COLS_A] = {
        {5, 1, 2},
        {1, 3, 7},
        {2, 7, 8}
    };

    // Matriz B (3x2)
    int B[FILAS_B][COLS_B] = {
        {3, 4},
        {7, 3},
        {8, 1}
    };

    // Matriz C para almacenar el resultado (3x2)
    int C[FILAS_C][COLS_C];
    
    // Variables para los índices de los ciclos
    int i, j, k;

    // 2. Comprobación de la posibilidad de la multiplicación
    // (Ya sabemos que es posible, ya que COLS_A == FILAS_B)
    if (COLS_A != FILAS_B) {
        printf("Error: Las matrices no se pueden multiplicar. El número de columnas de A debe ser igual al número de filas de B.\n");
        return 1; // Salir con error
    }

    // 3. Lógica de la Multiplicación de Matrices (A x B)
    // El elemento C[i][j] se calcula como la suma de los productos 
    // de la fila i de A por la columna j de B.

    // Ciclo para las filas de la matriz resultante C (i)
    for (i = 0; i < FILAS_C; i++) {
        // Ciclo para las columnas de la matriz resultante C (j)
        for (j = 0; j < COLS_C; j++) {
            // Inicializar el elemento C[i][j] a 0 antes de la suma
            C[i][j] = 0; 
            
            // Ciclo para la multiplicación y suma (k)
            for (k = 0; k < COLS_A; k++) { // O FILAS_B, es el mismo valor
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 4. Impresión de la Matriz Resultante C
    printf("Matriz A (3x3):\n");
    for (i = 0; i < FILAS_A; i++) {
        for (j = 0; j < COLS_A; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B (3x2):\n");
    for (i = 0; i < FILAS_B; i++) {
        for (j = 0; j < COLS_B; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nLa Matriz Resultante C = A x B (3x2) es:\n");
    for (i = 0; i < FILAS_C; i++) {
        for (j = 0; j < COLS_C; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}