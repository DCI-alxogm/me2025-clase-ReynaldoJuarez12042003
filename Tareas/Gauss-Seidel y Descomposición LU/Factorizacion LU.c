#include <stdio.h>
#include <math.h>

int main(){
   /* Pedir al usuario la dimension(ejemplo: 3 para un sistema de 3*3*/
    int N;
    printf(" Leer la dimensión del sistema: ");
    scanf("%d",&N);
   //Se especifica la matriz aumentada, la ultima columna es para los valores de b
    double A[N][N+1];  // Matriz aumentada [A|b]
    double L[N][N], U[N][N], x[N], y[N];
    int i, j, k;

    //Se crea un archivo para guardar los resultados  
    FILE *archivo;
    archivo = fopen("resultado_LU.txt", "w");
    if(archivo == NULL){
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Leer coeficientes de A y b
    //El usuario ingresa los valores de la matriz 
    printf("\n2) Introduce los coeficientes de la matriz A y del vector b:\n");
    for(i=0;i<N;i++){
        for(j=0;j<=N;j++){
            if(j<N)
                printf("A[%d][%d]: ",i+1,j+1);
            else
                printf("b[%d]: ",i+1);
            scanf("%lf",&A[i][j]);
        }
    }
    //Impresion de la matriz inicial para verificar que se ingrresaron bien
    printf("\nMatriz inicial:\n");
    for(i=0;i<N;i++){
        for(j=0;j<=N;j++)
            printf("%8.3f ",A[i][j]);
        printf("\n");
    }

    // Se ponen los valores de L y U en 0 
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    //  Descomposicion LU 
    for(i=0;i<N;i++){
        // Calcular elementos de U
        for(j=i;j<N;j++){
            double suma = 0.0;
            for(k=0;k<i;k++)
                suma += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - suma;
        }

        // Calcular elementos de L
        for(j=i;j<N;j++){
            if(i==j)
                L[i][i] = 1.0; // Diagonal unitaria
            else{
                double suma = 0.0;
                for(k=0;k<i;k++)
                    suma += L[j][k] * U[k][i];
                if(fabs(U[i][i]) < 1e-12){
                    printf("Error: pivote muy pequeño en la posición (%d,%d)\n",i+1,i+1);
                    fclose(archivo);
                    return 1;
                }
                L[j][i] = (A[j][i] - suma) / U[i][i];
            }
        }
    }

    //  Sustitución progresiva (Ly = b) 
    for(i=0;i<N;i++){
        double suma = 0.0;
        for(j=0;j<i;j++)
            suma += L[i][j] * y[j];
        y[i] = A[i][N] - suma;
    }

    //  Sustitución regresiva (Ux = y) 
    for(i=N-1;i>=0;i--){
        double suma = 0.0;
        for(j=i+1;j<N;j++)
            suma += U[i][j] * x[j];
        if(fabs(U[i][i]) < 1e-12){
            printf("Error: pivote muy pequeño en U(%d,%d)\n",i+1,i+1);
            fclose(archivo);
            return 1;
        }
        x[i] = (y[i] - suma) / U[i][i];
    }

    // Mostrar y guardar en txt la solucion final 
    printf("\nMatriz L:\n");
    fprintf(archivo, "Matriz L:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%8.3f ",L[i][j]);
            fprintf(archivo, "%8.3f ",L[i][j]);
        }
        printf("\n");
        fprintf(archivo, "\n");
    }

    printf("\nMatriz U:\n");
    fprintf(archivo, "\nMatriz U:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%8.3f ",U[i][j]);
            fprintf(archivo, "%8.3f ",U[i][j]);
        }
        printf("\n");
        fprintf(archivo, "\n");
    }

    printf("\nSolución del sistema (por descomposición LU):\n");
    fprintf(archivo, "\nSolución del sistema (por descomposición LU):\n");
    for(i=0;i<N;i++){
        printf("x%d = %.3f\n",i+1,x[i]);
        fprintf(archivo, "x%d = %.3f\n",i+1,x[i]);
    }

    // Se cierra el archivo 
    fclose(archivo);

    return 0;
}
