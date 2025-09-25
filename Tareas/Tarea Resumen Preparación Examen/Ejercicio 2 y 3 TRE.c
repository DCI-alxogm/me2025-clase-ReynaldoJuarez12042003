/*Reynaldo Hassan Juarez Aranda 
Serie de Taylor 31/08/2025*/

#include <stdio.h>
#include <math.h>

/* Calcular el factorial de un número entero con for */
int factorial(int n) {
    int facto=1;
    for (int i=1; i<=n; i++) {
        facto=facto*i;
    }
    return facto;
}
// Declaramos las variables principales con float, int y un char
int main() {
    float x, xi, valoractual, valoranterior, Ea, Es;
    int n, opcion, k;
    char iniciar;
//Iniciamos un ciclo do-while para poder inicar la copilacion al terminar
    do {
      //Aqui pedimos valores iniciales y la funcion que desean escoger 
        printf("Identifica la funcion que deseas, adelante la podras seleccionar:log(x), x-1-(0.5*sin(x)), 2^x, log10(x),cos(x)\n ");
        printf("Escribe el valor de x: ");
        scanf("%f", &x);
        printf("Escribe el valor de xi: ");
        scanf("%f", &xi);
        printf("Escribe el valor de Es: ");
        scanf("%f", &Es);
        printf("¿Cuántas n quieres en la iteración?: ");
        scanf("%d", &n);
        //tambien definimos h y epsilon

        float h=x-xi;
        float epsilon=(x+xi)/2;
        float epsixi=xi;

        // Guardar cada funcion en un arregl hasta la sexta derivada evaluada en xi
        float funcion1[7];
        funcion1[0]=log(xi);
        funcion1[1]=1/xi;
        funcion1[2]=-(1/pow(xi,2));
        funcion1[3]=2/pow(xi,3);
        funcion1[4]=-6/pow(xi,4);
        funcion1[5]=24/pow(xi,5);
        funcion1[6]=-120/pow(xi,6);

        float funcion2[7];
        funcion2[0]=xi-1-(0.5*sin(xi));
        funcion2[1]=1-(cos(xi)/2);
        funcion2[2]=sin(xi)/2;
        funcion2[3]=cos(xi)/2; 
        funcion2[4]=-sin(xi)/2;
        funcion2[5]=-cos(xi)/2;
        funcion2[6]=sin(xi)/2;

        float funcion3[7];
        funcion3[0]=pow(2,xi);
        funcion3[1]=log(2)*pow(2,xi);
        funcion3[2]=pow(log(2),2)*pow(2,xi);
        funcion3[3]=pow(log(2),3)*pow(2,xi);
        funcion3[4]=pow(log(2),4)*pow(2,xi);
        funcion3[5]=pow(log(2),5)*pow(2,xi);
        funcion3[6]=pow(log(2),6)*pow(2,xi);

        float funcion4[7];
        funcion4[0]=log10(xi);
        funcion4[1]=1/(log(10)*xi);
        funcion4[2]=-1/(log(10)*pow(xi,2));
        funcion4[3]=2/(log(10)*pow(xi,3));
        funcion4[4]=-6/(log(10)*pow(xi,4));
        funcion4[5]=24/(log(10)*pow(xi,5));
        funcion4[6]=-120/(log(10)*pow(xi,6));

        float funcion5[7];
        funcion5[0]=cos(xi);
        funcion5[1]=-sin(xi);
        funcion5[2]=-cos(xi);
        funcion5[3]=sin(xi);
        funcion5[4]=cos(xi);
        funcion5[5]=-sin(xi);
        funcion5[6]=-cos(xi);

        /*Definir arreglos para derivadas evaluadas en epsilon para el calculo de residuo*/
        float funcion1e[7];
        funcion1e[0]=log(epsilon);
        funcion1e[1]=1/epsilon;
        funcion1e[2]=-(1/pow(epsilon,2));
        funcion1e[3]=2/pow(epsilon,3);
        funcion1e[4]=-6/pow(epsilon,4);
        funcion1e[5]=24/pow(epsilon,5);
        funcion1e[6]=-120/pow(epsilon,6);

        float funcion2e[7];
        funcion2e[0]=epsixi-1-(0.5*sin(epsixi));
        funcion2e[1]=1-(cos(epsixi)/2);
        funcion2e[2]=sin(epsixi)/2;
        funcion2e[3]=cos(epsixi)/2; 
        funcion2e[4]=-sin(epsixi)/2;
        funcion2e[5]=-cos(epsixi)/2;
        funcion2e[6]=sin(epsixi)/2;

        float funcion3e[7];
        funcion3e[0]=pow(2,epsilon);
        funcion3e[1]=log(2)*pow(2,epsilon);
        funcion3e[2]=pow(log(2),2)*pow(2,epsilon);
        funcion3e[3]=pow(log(2),3)*pow(2,epsilon);
        funcion3e[4]=pow(log(2),4)*pow(2,epsilon);
        funcion3e[5]=pow(log(2),5)*pow(2,epsilon);
        funcion3e[6]=pow(log(2),6)*pow(2,epsilon);

        float funcion4e[7];
        funcion4e[0]=log10(epsilon);
        funcion4e[1]=1/(log(10)*epsilon);
        funcion4e[2]=-1/(log(10)*pow(epsilon,2));
        funcion4e[3]=2/(log(10)*pow(epsilon,3));
        funcion4e[4]=-6/(log(10)*pow(epsilon,4));
        funcion4e[5]=24/(log(10)*pow(epsilon,5));
        funcion4e[6]=-120/(log(10)*pow(epsilon,6));

        float funcion5e[7];
        funcion5e[0]=cos(epsilon);
        funcion5e[1]=-sin(epsilon);
        funcion5e[2]=-cos(epsilon);
        funcion5e[3]=sin(epsilon);
        funcion5e[4]=cos(epsilon);
        funcion5e[5]=-sin(epsilon);
        funcion5e[6]=-cos(epsilon);

        // Desplegar el menu donde se muestran cada funcion para que el usuario escoja 1
        float* funcionseleccionada;
        float valorverdadero;
        printf("\nSelecciona la funcion que deseas evaluar con la serie de Taylor:\n");
        printf("1. f(x) = In(x)\n");
        printf("2. f(x) = x-1-0.5sin(x)\n");
        printf("3. f(x) = pow(2,x)\n");
        printf("4. f(x) = log10(x)\n");
        printf("5. f(x) = cos(x)\n");
        printf("Opcion (1-5): ");
        scanf("%d", &opcion);

        /*Calculamos el valor verdadero de cada funcion, aqui se resuelve para la elejida,
        la funcionoriginal se evalua en x*/
        switch (opcion) {
            case 1: funcionseleccionada=funcion1; valorverdadero=log(x); break;
            case 2: funcionseleccionada=funcion2; valorverdadero=x-1-(0.5*sin(x)); break;
            case 3: funcionseleccionada=funcion3; valorverdadero=pow(2,x); break;
            case 4: funcionseleccionada=funcion4; valorverdadero=log10(x); break;
            case 5: funcionseleccionada=funcion5; valorverdadero=cos(x); break;
            default: printf("No existe esa opcion. Fin del programa.\n"); return 1;
        }
        
        /*Para n=0 el valoractual es igual a la funcion inicial evaluada en xi*/
        if (n==0) {
            switch (opcion) {
                case 1: valoractual=log(x); break;
                case 2: valoractual= x-1-(0.5*sin(x)); break;
                case 3: valoractual=pow(2,xi); break;
                case 4: valoractual=log10(xi); break;
                case 5: valoractual=cos(xi); break;
            }
           
        } else {
            valoractual=0;
            /*ciclo for para aplicar la iteracion de Tylor, depues de n=0 se usa un incremento
            para llegar hasta el n registrado*/
            float residuo=0;
            for (int k=0; k<=n; k++) {
                valoranterior=valoractual;
                
                valoractual+=(funcionseleccionada[k]*pow(h,k))/factorial(k);
                Ea=fabs(valorverdadero-valoractual);

                

                /*Calculo de residuo solo para n de 0 a 5 ya que para n>5 se ocupa septima derivada*/
                if (k>=0 && k<=5) {
                    float derivadasuma;
                    switch(opcion){
                        case 1: derivadasuma=funcion1e[k+1]; break;
                        case 2: derivadasuma=funcion2e[k+1]; break;
                        case 3: derivadasuma=funcion3e[k+1]; break;
                        case 4: derivadasuma=funcion4e[k+1]; break;
                        case 5: derivadasuma=funcion5e[k+1]; break;
                        default: derivadasuma=0; break;
                    }
                    residuo=(derivadasuma*pow(h,k+1))/factorial(k+1);
                } else {
                    printf("n=%d: No se puede obtener el Rn para un n>5 porque no hay suficientes derivadas definidas.\n", k);
                    residuo=0;
                }

                printf("n= %d:, Valor aproximado = %f, Ea=%f, Rn= %f\n", k, valoractual, Ea, residuo);
                if(Ea<Es){
                  printf("El error deseado se alcanzo en la iteracion n=%d\n", k);
                  break;
                }
            }
        }

        printf("Valor verdadero de la funcion en x = %f\n", valorverdadero);
        printf("¿Deseas escoger otra funcion? (s/n): ");
        scanf(" %c", &iniciar);

    } while(iniciar=='s' || iniciar=='S');

    return 0;
}



//RESULTADOS EJERCICIO 2: al escoger la funcion y darle sus respectivos valores se obtiene lo siguiente pero se observa que el metodo diverge para esta funcion
/*Selecciona la funcion que deseas evaluar con la serie de Taylor: Funcion 1 Ejercicio 2 de la tarea
Resultados ejercicio 2 usando:
Escribe el valor de x: 3
Escribe el valor de xi: 1
Escribe el valor de Es: 0.0001
¿Cuántas n quieres en la iteración?: 5
Opcion (1-5): 1
n= 0:, Valor aproximado = 0.000000, Ea=1.098612, Rn= 1.000000
n= 1:, Valor aproximado = 2.000000, Ea=0.901388, Rn= -0.500000
n= 2:, Valor aproximado = 0.000000, Ea=1.098612, Rn= 0.333333
n= 3:, Valor aproximado = 2.666667, Ea=1.568054, Rn= -0.250000
n= 4:, Valor aproximado = -1.333333, Ea=2.431946, Rn= 0.200000
n= 5:, Valor aproximado = 5.066667, Ea=3.968054, Rn= -0.166667
Valor verdadero de la funcion en x = 1.098612
¿Deseas escoger otra funcion? (s/n): n*/
//----------------------------------------------------------------------------------------------------------------

//RESULTADOS EJERCICIO 3: al escoger la funcion y darle sus respectivos valores se obtiene lo siguiente
/*Escribe el valor de x: 3.141592
Escribe el valor de xi: 1.570796
Escribe el valor de Es: 0.015
¿Cuántas n quieres en la iteración?: 5

Selecciona la funcion que deseas evaluar con la serie de Taylor:
1. f(x) = In(x)
2. f(x) = x-1-0.5sin(x)
3. f(x) = pow(2,x)
4. f(x) = log10(x)
5. f(x) = cos(x)
Opcion (1-5): 2
n= 0:, Valor aproximado = 0.070796, Ea=2.070796, Rn= 1.570796
n= 1:, Valor aproximado = 1.641592, Ea=0.500000, Rn= 0.616850
n= 2:, Valor aproximado = 2.258442, Ea=0.116850, Rn= 0.000000
n= 3:, Valor aproximado = 2.258442, Ea=0.116850, Rn= -0.126835
n= 4:, Valor aproximado = 2.131607, Ea=0.009984, Rn= -0.000000
El error deseado se alcanzo en la iteracion n=4
Valor verdadero de la funcion en x = 2.141592
¿Deseas escoger otra funcion? (s/n): n*/