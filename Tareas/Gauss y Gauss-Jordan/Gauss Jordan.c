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
