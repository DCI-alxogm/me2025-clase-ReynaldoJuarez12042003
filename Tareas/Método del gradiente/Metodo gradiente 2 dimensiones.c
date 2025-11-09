/* Reynaldo Hassan Juarez Aranda 10/11/2025
 Metodo gradiente con diferencias finitas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// FUNCION OBJETIVO f(X, N)
// Aqui se puede cambiar tanto funcion como dimencion
// En este caso se usa de ejemplo el mismo ejercicio f(x,y)=2xy+2x-x^2-2y^2
double f(double *X, int N){
    double x=X[0];
    double y=X[1];
    return 2*x*y+2*x-x*x-2*y*y;
}

// Gradiente de la funcion
void gradiente(double *X, double *G, int N, double h){
    double *Xp=malloc(N*sizeof(double));
    double *Xm=malloc(N*sizeof(double));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Xp[j]=X[j];
            Xm[j]=X[j];
        }
        Xp[i]+=h;
        Xm[i]-=h;
        G[i]=(f(Xp,N)-f(Xm,N))/(2*h);
    }
    free(Xp);
    free(Xm);
}

// HESSIANO 
// Usa diferencias finitas centradas de segundo orden
void hessiano(double *X, double **H, int N, double h){
    double *Xp=malloc(N*sizeof(double));
    double *Xm=malloc(N*sizeof(double));
    double *XpYp=malloc(N*sizeof(double));
    double *XpYm=malloc(N*sizeof(double));
    double *XmYp=malloc(N*sizeof(double));
    double *XmYm=malloc(N*sizeof(double));

    //Diagonales: d2f/dxi2 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Xp[j]=Xm[j]=X[j];
        }
        Xp[i]+=h;
        Xm[i]-=h;
        H[i][i]=(f(Xp,N)-2*f(X,N)+f(Xm,N))/(h*h);
    }

    //Términos cruzados: d2f/dxidxj
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0;k<N;k++){
                XpYp[k]=XpYm[k]=XmYp[k]=XmYm[k]=X[k];
            }
            XpYp[i]+=h; XpYp[j]+=h;
            XpYm[i]+=h; XpYm[j]-=h;
            XmYp[i]-=h; XmYp[j]+=h;
            XmYm[i]-=h; XmYm[j]-=h;

            H[i][j]=H[j][i]=(f(XpYp,N)-f(XpYm,N)-f(XmYp,N)+f(XmYm,N))/(4*h*h);
        }
    }

    free(Xp); free(Xm);
    free(XpYp); free(XpYm); free(XmYp); free(XmYm);
}

// Funcion g(h) = f(X + h*G)
double g(double h, double *X, double *G, int N){
    double *Xt=malloc(N*sizeof(double));
    for(int i=0;i<N;i++) Xt[i]=X[i]+h*G[i];
    double val=f(Xt,N);
    free(Xt);
    return val;
}

int main(){
    int N;
    printf("Dimension N de la funcion: ");
    scanf("%d",&N);

    double *X=malloc(N*sizeof(double));  
    double *G=malloc(N*sizeof(double));  

    printf("Ingrese punto inicial (%d valores):\n",N);
    for(int i=0;i<N;i++) scanf("%lf",&X[i]);

    double dh=0.1;         
    double hgrad=1e-5;     
    int iter=1;

    printf("\nMétodo del gradiente (con derivadas por diferencias finitas)\n");

    while(iter<=20){
        gradiente(X,G,N,hgrad);

        printf("\nITERACION %d\n",iter);
        printf("Punto actual:\n");
        for(int i=0;i<N;i++) printf("X[%d] = %.6lf\n",i,X[i]);
        printf("f(X) = %.6lf\n",f(X,N));

        printf("Gradiente:\n");
        for(int i=0;i<N;i++) printf("G[%d] = %.6lf\n",i,G[i]);

        double g0=g(0,X,G,N);
        double g1=g(dh,X,G,N);
        double g2=g(2*dh,X,G,N);

        double a=(g2-2*g1+g0)/(2*dh*dh);
        double b=(-3*g0+4*g1-g2)/(2*dh);
        double c=g0;

        double h_opt;
        if(fabs(a)<1e-12) h_opt=dh;
        else h_opt=-b/(2*a);

        printf("h* = %.6lf\n",h_opt);

        double cambio=0.0;
        for(int i=0;i<N;i++){
            double old=X[i];
            X[i]=X[i]+h_opt*G[i];
            cambio+=fabs(X[i]-old);
        }

        printf("Nuevo punto:\n");
        for(int i=0;i<N;i++) printf("X[%d] = %.6lf\n",i,X[i]);

        double **H=malloc(N*sizeof(double*));
        for(int i=0;i<N;i++) H[i]=malloc(N*sizeof(double));

        hessiano(X,H,N,hgrad);

        printf("Hessiano:\n");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) printf("%10.6lf ",H[i][j]);
            printf("\n");
        }

        if(N==2){
            double D=H[0][0]*H[1][1]-H[0][1]*H[1][0];
            if(D>0 && H[0][0]>0) printf(" Mínimo local\n");
            else if(D>0 && H[0][0]<0) printf(" Máximo local\n");
            else if(D<0) printf(" Punto de silla\n");
            else printf(" Indeterminado\n");
        }

        for(int i=0;i<N;i++) free(H[i]);
        free(H);

        if(cambio<1e-6) break;
        iter++;
    }

    printf("\nResultado final\n");
    for(int i=0;i<N;i++) printf("X[%d] = %.6lf\n",i,X[i]);
    printf("f(X) = %.6lf\n",f(X,N));

    free(X);
    free(G);
    return 0;
}

        