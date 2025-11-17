//Reynaldo Hassan Juarez Aranda Proyecto
//Ejercicio 1 inciso a: Resultados a continuacion
/*
Leer la dimensión del sistema: 4
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
Matriz después de Gauss-Jordan (forma diagonal):
   1.000    0.000    0.000    0.000   26.250 
   0.000    1.000    0.000    0.000   17.500 
  -0.000   -0.000    1.000    0.000    8.750 
  -0.000   -0.000   -0.000    1.000   17.500 
Solución del sistema:
x1=26.250
x2=17.500
x3=8.750
x4=17.500
Número de condición aproximado: 1.000
El sistema está bien condicionado.*/



#include <stdio.h>
#include <math.h>

int main(){
    int N;
    printf(" Leer la dimensión del sistema: ");
    scanf("%d",&N);

    double A[N][N+1];
    double x[N];
    int i,j,k;

    // Leer coeficientes de A y b
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

    printf("\nMatriz inicial:\n");
    for(i=0;i<N;i++){
        for(j=0;j<=N;j++)
            printf("%8.3f ",A[i][j]);
        printf("\n");
    }

    // 3) Gauss-Jordan con pivoteo parcial
    for(i=0;i<N;i++){
        // Pivoteo parcial
        int max=i;
        for(k=i+1;k<N;k++){
            if(fabs(A[k][i])>fabs(A[max][i]))
                max=k;
        }
        if(max!=i){
            for(j=0;j<=N;j++){
                double temp=A[i][j];
                A[i][j]=A[max][j];
                A[max][j]=temp;
            }
        }

        // Normalizar la fila del pivote
        double pivote=A[i][i];
        if(fabs(pivote)<1e-12){
            printf("Pivote muy pequeño (%.6f). Mal condicionamiento.\n",pivote);
            return 1;
        }
        for(j=0;j<=N;j++)
            A[i][j]/=pivote;

        // Eliminación en toda la columna (arriba y abajo)
        for(k=0;k<N;k++){
            if(k!=i){
                double factor=A[k][i];
                for(j=0;j<=N;j++)
                    A[k][j]-=factor*A[i][j];
            }
        }
    }

    // 4) Extraer solución
    for(i=0;i<N;i++)
        x[i]=A[i][N];

    // 5) Imprimir matriz final y solución
    printf("\nMatriz después de Gauss-Jordan (forma diagonal):\n");
    for(i=0;i<N;i++){
        for(j=0;j<=N;j++)
            printf("%8.3f ",A[i][j]);
        printf("\n");
    }

    printf("\nSolución del sistema:\n");
    for(i=0;i<N;i++)
        printf("x%d=%.3f\n",i+1,x[i]);

    // Evaluar condición del sistema (heurístico)
    double minPivote=fabs(A[0][0]);
    double maxPivote=fabs(A[0][0]);
    for(i=1;i<N;i++){
        double p=fabs(A[i][i]);
        if(p<minPivote) minPivote=p;
        if(p>maxPivote) maxPivote=p;
    }
    double condicion=maxPivote/minPivote;
    printf("\nNúmero de condición aproximado: %.3f\n",condicion);
    if(condicion>1e6)
        printf("El sistema está mal condicionado.\n");
    else
        printf("El sistema está bien condicionado.\n");

    return 0;
}