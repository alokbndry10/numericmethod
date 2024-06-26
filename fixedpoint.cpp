#include<stdio.h>
// #include<conio.h>
#include<math.h>

int a3, a2, a1, a0;

float g(float x){
    // Define the iterative function for fixed-point method
    return (a3*x*x*x + a2*x*x + a1*x + a0);
}

int main(){
    float x0, x1, gx0, E;

    printf("Enter the coefficients of a3, a2, a1, and a0: \n");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);

    printf("Enter initial guess and E : \n");
    scanf("%f%f", &x0, &E);

    int iteration = 1;

    while(1){
        gx0 = g(x0);
        x1 = gx0;

        printf("Iteration %d: x = %f\n", iteration, x1);

        if (fabs(x1 - x0) < E) {
            printf("Root = %f\n", x1);
            break;
        }

        x0 = x1;

    }
}