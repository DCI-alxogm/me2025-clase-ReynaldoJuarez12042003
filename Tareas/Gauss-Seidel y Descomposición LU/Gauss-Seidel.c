#include <stdio.h>
#include <math.h>

int main(){
    //Por ejemplo si N=3 la matriz es de 3*3
    int N;
    printf(" Leer la dimensión del sistema: ");
    scanf("%d",&N);
    //Se especifica la matriz aumentada, la ultima columna es para los valores de b
    double A[N][N+1];
    double x[N],x_old[N];
    int i,j,iter,maxIter=1000;
    double tol=1e-6;
    double suma,error;

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

    // Como lo indica el metodo se inicializan las estimaciones con x=0
    for(i=0;i<N;i++){
        x[i]=0.0;
        x_old[i]=0.0;
    }

    printf("\nIteraciones del método de Gauss-Seidel:\n");

    // Método de Gauss-Seidel (se abre un for para que se repitan las iteraciones)
    for(iter=1;iter<=maxIter;iter++){
        //Verificacion del pivote no sea cero y actualiza el valor con la formula 
        for(i=0;i<N;i++){
            suma=0.0;
            for(j=0;j<N;j++){
                if(j!=i)
                    suma+=A[i][j]*x[j];
            }
            if(fabs(A[i][i])<1e-12){
                printf("Error: pivote muy pequeño en A(%d,%d)\n",i+1,i+1);
                return 1;
            }
            x_old[i]=x[i]; // Guardar valor anterior
            x[i]=(A[i][N]-suma)/A[i][i];
        }

        // Se calcula el error entre la iteracion actual y la anterior
        error=0.0;
        for(i=0;i<N;i++){
            double diff=fabs(x[i]-x_old[i]);
            if(diff>error)
                error=diff;
        }
        // Imprimir cada iteracion junto a su error 
        printf("Iter %3d: ",iter);
        for(i=0;i<N;i++)
            printf("x%d=%.6f ",i+1,x[i]);
        printf(" | Error=%.6e\n",error);
        //Se establecio un error limite para detener la convergencia 
        if(error<tol){
            printf("\nConvergencia alcanzada en %d iteraciones.\n",iter);
            break;
        }
    }
    /*En dado caso de no alcanzar el valor en el error propuesto y con las iteraciones
    se imprime que no convergio*/
    if(iter>maxIter)
        printf("\nNo se alcanzó la convergencia en %d iteraciones.\n",maxIter);

    // Mostrar solución final 
    printf("\nSolución aproximada del sistema (Gauss-Seidel):\n");
    for(i=0;i<N;i++)
        printf("x%d = %.6f\n",i+1,x[i]);

    return 0;
}
