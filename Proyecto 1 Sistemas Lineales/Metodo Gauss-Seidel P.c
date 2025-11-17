//Reynaldo Hassan Juarez Aranda Ejercicio 2
//Rsultados a continucacion 
/*Matriz inicial:
   6.000    0.000   -1.000    0.000    0.000   50.000 
   3.000   -3.000    0.000    0.000    0.000    0.000 
   0.000   -1.000    9.000    0.000    0.000  160.000 
   0.000    1.000    8.000  -11.000    2.000    0.000 
   3.000    1.000    0.000    0.000   -4.000    0.000 
Iteraciones del método de Gauss-Seidel:
Iter   1: x1=8.333333 x2=8.333333 x3=18.703704 x4=14.360269 x5=8.333333  | Error=1.870370e+01
Iter   2: x1=11.450617 x2=11.450617 x3=19.050069 x4=16.410712 x5=11.450617  | Error=3.117284e+00
Iter   3: x1=11.508345 x2=11.508345 x3=19.056483 x4=16.987404 x5=11.508345  | Error=5.766917e-01
Iter   4: x1=11.509414 x2=11.509414 x3=19.056602 x4=16.998083 x5=11.509414  | Error=1.067948e-02
Iter   5: x1=11.509434 x2=11.509434 x3=19.056604 x4=16.998281 x5=11.509434  | Error=1.977681e-04
Iter   6: x1=11.509434 x2=11.509434 x3=19.056604 x4=16.998285 x5=11.509434  | Error=3.662372e-06
Iter   7: x1=11.509434 x2=11.509434 x3=19.056604 x4=16.998285 x5=11.509434  | Error=6.782170e-08
Convergencia alcanzada en 7 iteraciones.
Solución aproximada del sistema (Gauss-Seidel):
x1 = 11.509434
x2 = 11.509434
x3 = 19.056604
x4 = 16.998285
x5 = 11.509434*/

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