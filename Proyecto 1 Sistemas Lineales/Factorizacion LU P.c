//Reynaldo Hassan Juarez Aranda 
//Ejercicio 1 inciso a: Resultados a continuacion Con LU
/*Leer la dimensión del sistema: 4
2) Introduce los coeficientes de la matriz A y del vector b:
A[1][1]: 0.07
A[1][2]: 0.18
A[1][3]: 0.15
A[1][4]: 0.24
b[1]: 10.5
A[2][1]: 0.04
A[2][2]: 0.24
A[2][3]: 0.10
A[2][4]: 0.65
b[2]: 17.5
A[3][1]: 0.54
A[3][2]: 0.42
A[3][3]: 0.54
A[3][4]: 0.10
b[3]: 28
A[4][1]: 0.35
A[4][2]: 0.16
A[4][3]: 0.21
A[4][4]: 0.01
b[4]: 14
Matriz inicial:
   0.070    0.180    0.150    0.240   10.500 
   0.040    0.240    0.100    0.650   17.500 
   0.540    0.420    0.540    0.100   28.000 
   0.350    0.160    0.210    0.010   14.000 
Matriz L:
   1.000    0.000    0.000    0.000 
   0.571    1.000    0.000    0.000 
   7.714   -7.062    1.000    0.000 
   5.000   -5.396    0.897    1.000 
Matriz U:
   0.070    0.180    0.150    0.240 
   0.000    0.137    0.014    0.513 
   0.000    0.000   -0.516    1.871 
   0.000    0.000    0.000   -0.100 
Solución del sistema (por descomposición LU):
x1 = 26.250
x2 = 17.500
x3 = 8.750
x4 = 17.500*/



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